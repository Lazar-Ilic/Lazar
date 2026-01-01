library(Rcpp)
library(inline)
library(microbenchmark)


# First R version
Exp2Sigma_R1 = function(x, b,tau1sq,tau2sq) {
	eucDist = as.matrix(dist(x,diag=T,upper=T))
	kron.delta = diag(nrow=length(x))
	tau1sq*exp(-.5*(eucDist/b)^2) + tau2sq*kron.delta
}

# Second R version
#intake x vector, hyperparameters b, tau1sq, tau2sq
#output length(x) by length(x) matrix 
Exp2Sigma_R2 <- function(x,b,tau1sq, tau2sq){
  C <- matrix(0,length(x),length(x))
  for(i in 1:length(x)) {
    for(j in 1:length(x)) {
      C[i,j] <- tau1sq*exp(-0.5*{(x[i]-x[j])/b}^2) + tau2sq*(x[i]==x[j])
    }
  }
  return(C)
}


# A compiled C++ version
# Inputs
# kappa: (range b, variance, nugget)
#		a set of covariance parameters for the squared exponential covariance function
# x1: n1-vector of 1D spatial locations
# x2: n2-vector of 1D spatial locations
#
# Returns
# C, a matrix of dimension (n1 x n2)
# C(i,j) is the covariance between f(x1[i]) and f(x2[j])
# where f is a Gaussian process parametrized by kappa
cppFunction('
  NumericMatrix Exp2Sigma_CPP(NumericVector x, NumericVector y, NumericVector kappa) {
  	double arg, distance2;
    int n1 = x.size();
    int n2 = y.size();
    NumericMatrix C(n1,n2);
    for(int i = 0; i < n1; i++) {
    	for(int j=0; j < n2; j++) {
    		arg = (x[i] - y[j])/kappa[0];
    		distance2 = arg*arg;
    		C(i,j) = kappa[1]*exp(-0.5*distance2);
    		if(arg == 0.0) C(i,j) += kappa[2];
    	}
    }
    return C;
  }
')


x = seq(0,1,length=1000)
kappa = c(0.1, 1, 0)

# Check consistency
C1 <- Exp2Sigma_CPP(x, x, kappa)
C2 <- Exp2Sigma_R1(x, kappa[1], kappa[2], kappa[3])
C3 <- Exp2Sigma_R2(x, kappa[1], kappa[2], kappa[3])
any(abs(C1 - C2) > .Machine$double.eps)
any(abs(C1 - C3) > .Machine$double.eps)
any(abs(C2 - C3) > .Machine$double.eps)

# Timings with 10 replicates
microbenchmark(
	Exp2Sigma_CPP(x, x, kappa),
	Exp2Sigma_R1(x, kappa[1], kappa[2], kappa[3]),
	Exp2Sigma_R2(x, kappa[1], kappa[2], kappa[3]),
	times=10)


