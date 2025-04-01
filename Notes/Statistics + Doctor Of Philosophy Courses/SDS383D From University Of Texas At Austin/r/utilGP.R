library(Rcpp)
library(mvtnorm)

utilities = read.csv('utilities.csv')

cppFunction('
  NumericMatrix ExpKernelC(NumericVector x, NumericVector y, double b, double tau) {
    int d1 = x.size();
    int d2 = y.size();
    NumericMatrix C(d1,d2);
    double arg = 0.;
    for(int i = 0; i < d1; i++) {
    	for(int j=0; j<d2; j++) {
    		arg = (x[i] - y[j])/b;
    		C(i,j) = tau*exp(-0.5*arg*arg);
    	}
    }
    return C;
  }
')


marginal = function(y, x, b, tau, sigma2) {
	Cxx = ExpKernelC(x,x,b,tau)
	V = Cxx + diag(sigma2, length(x))
	dmvnorm(y, sigma=V, log=TRUE)
}

postmean = function(y, x, b, tau, sigma2) {
	Cxx = ExpKernelC(x,x,b,tau)
	V = Cxx + diag(sigma2, length(x))
	drop(Cxx %*% solve(V) %*% y)
}


y = utilities$gasbill/utilities$billingdays
y = y - mean(y)
x = utilities$temp

fhat = postmean(y,x,20,10000,1)
sig2 = var(y-fhat)

plot(x,y)
points(x, fhat, pch=19, col='blue')

D = 200
ML = matrix(0, D,D)
bgrid = seq(50,60, length=D)
taugrid = seq(15,35,length=D)
for(i in seq_along(bgrid)) {
	for(j in seq_along(taugrid)) {
		ML[i,j] = marginal(y,x,bgrid[i],taugrid[j], sig2)
	}
}
R = cbind(expand.grid(1:D, 1:D), as.numeric(ML))
maxind = which.max(R[,3])
R[maxind,]

bhat = bgrid[R[maxind,1]]
tauhat = taugrid[R[maxind,2]]

fhat = postmean(y,x,bhat, tauhat,sig2)
sig2 = var(y-fhat)


par(mfrow=c(1,2))
plot(x,y)
points(x, fhat, pch=19, col='blue')
contour(bgrid, taugrid, ML, nlevels=20)
