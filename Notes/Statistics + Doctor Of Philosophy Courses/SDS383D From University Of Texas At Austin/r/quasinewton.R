library(Matrix)

# Read in data
wdbc = read.csv('../data/wdbc.csv', header=FALSE)
y = wdbc[,2]

# Convert y values to 1/0's.
Y = rep(0,length(y)); Y[y=='M']=1
X = as.matrix(wdbc[,-c(1,2)])

# Select features to keep and scale features.
scrub = 11:30
X = X[,-scrub]
X = scale(X) #Normalize design matrix features.
X = cbind(rep(1,nrow(X)),X)

#Set up vector of sample sizes.  (All 1 for wdbc data.)
m = rep(1,nrow(X))	

#------------------------------------------------------------------
# Binomial Negative Loglikelihood function
	# Inputs:
	#	Design matrix X
	#	vector Y with number of successes per case
	#   coefficient matrix beta
	#   vector of sample sizes m.
	#	smooth: a numerical smoothing factor to avoid P = 0
	# Output:
	#	value of negative log-likelihood function
	#   for binomial logistic regression.
logl = function(X, Y, beta, m, smooth = 1e-6){
	w = 1 / (1 + exp(-X %*% beta))
	logl = - sum(Y*log(w+smooth) + (m-Y)*log(1-w+smooth))
	return(logl)	
}

#------------------------------------------------------------------
#Function for calculating Euclidean norm of a vector.
norm_vec = function(x) sqrt(sum(x^2)) 

#------------------------------------------------------------------
#Gradient Function: 
	# Inputs: Design matrix X, vector of 1/0 vals Y, 
	#   coefficient matrix beta, sample size vector m.
	# Output: Returns value of gradient function for binomial 
	#   logistic regression.
logl_grad = function(X, Y, beta, m) {
	w = 1 / (1 + exp(-X %*% beta))	
	logl_grad = -colSums(X*as.numeric(Y-m*w))
	return(logl_grad)
}

#------------------------------------------------------------------
# Backtracking Line Search Function
	# Inputs:  X = design matrix
	#   Y = vector of 1/0 response values
	#   b = vector of betas
	#   gr = gradient for beta vector
	#   p = search direction vector 
	#   m = sample size vector m
	#   maxalpha = The maximum allowed step size; defaults to 1
  #   c1: constant in (0,1), 1e-4 is Nocedal and Wright's suggested default
  #   rho: multiplier for the step size at each iteration; defaults to 0.5
	# Outputs: alpha = the multiple of the search direction.
linesearch = function(X, Y, b, gr, p, m, maxalpha=1, c1 = 1e-4, rho=0.5) {
	# check Armijo condition
	# see, e.g. https://en.wikipedia.org/wiki/Wolfe_conditions
	# repeatedly shrink alpha if not met 
	armijo = FALSE
	alpha = maxalpha/rho # This will make us try alpha = maxalpha first
	dir_deriv = drop(crossprod(gr, p))
	while(!armijo) {
		alpha = rho*alpha
		b_new = b + alpha*p
		phi = logl(X, Y, b, m)
		phi_new = logl(X, Y, b_new, m)
		armijo = { phi_new < phi + c1*alpha*dir_deriv }
	}
	
	return(alpha)
}

#------------------------------------------------------------------
#Quasi Newton with Backtracking Line Search Algorithm:
#Inputs:
#	X: n x p design matrix.
#	Y: response vector length n.
#	m: vector length n.
#	rel_tol: Tolerance level for evaluating convergence
# lse: whether to perform line search (otherwise step size = 1)
# Outputs:
#	beta_hat: A vector of estimated beta coefficients.
#	iter: The number of iterations until convergence.
#	converged: 1/0, depending on whether algorithm converged.
#	loglik: Log-likelihood function.
quasi_newton = function(X, Y, m, maxiter=500, rel_tol=1e-6, verbose=0, lse=TRUE) {
	
	converged = 0
	
	#1. Initialize matrix to hold beta vector for each iteration.
	betas = matrix(NA,nrow=maxiter+1,ncol=ncol(X)) 
	betas[1,] = rep(0,ncol(X))	# Initialize beta vector to 0 to start.
	
	#2. Initialize values for log-likelihood.
	loglik = rep(NA,maxiter) 	# Initialize vector to hold loglikelihood fctn.
	loglik[1] = logl(X,Y,betas[1,],m)
	
	#3. Initialize matrix to hold gradients for each iteration.				
	grad = matrix(NA,nrow=maxiter,ncol=ncol(X)) 		
	grad[1,] = logl_grad(X,Y,betas[1,],m)
	
	#4. Initialize approximate inverse Hessian, B. 
	#   (Use identity matrix as initial value.)
	B = diag(ncol(betas))

	#5. Start main loop
	i = 2
	while(!converged & i <= maxiter) {
		if(verbose > 0) print(i) # for debugging purposes
		
		# Compute direction and step size for beta update.
		p = -B %*% grad[i-1,]
		if(lse) {
			alpha = linesearch(X,Y,b=betas[i-1,],gr=grad[i-1,],p,m,maxalpha=1)
		} else alpha = 1

		# Update beta values based on step/direction.
		betas[i,] = betas[i-1,] + alpha*p
		
		#Calculate loglikelihood for each iteration.
		loglik[i] = logl(X,Y,betas[i,],m)
		
		#Calculate gradient for new betas.
		grad[i,] = logl_grad(X,Y,betas[i,],m)
		
		#Update values needed for BFGS Hessian inverse approximation.
		s = alpha*p
		z = grad[i,] - grad[i-1,]
		rho = drop(1/(t(z) %*% s))	 # drop to make rho a scalar.
		tau = rho * s %*% t(z)
		I = diag(ncol(grad))
		
		# BFGS update formula for inverse Hessian
		B = (I-tau) %*% B %*% (I-t(tau)) + rho * tcrossprod(s) 
	
		# Check convergence
		delta = abs(loglik[i] - loglik[i-1])/abs(loglik[i-1] + rel_tol)
		if (delta < rel_tol){
			converged = 1;
		} else {
			i = i+1
		}
	
	} #End quasi-newton descent iterations.
		
	betas = na.omit(betas)
	loglik = na.omit(loglik)
	out = list(betas=betas,
			beta_hat=betas[i,],
			iter=i,
			converged=converged,
			loglik=loglik[1:i])
}

#------------------------------------------------------------------
#Run and view results.

#1. Fit glm model for comparison. (No intercept: already added to X.)
glm1 = glm(Y~X-1, family='binomial') #Fits model, obtains beta values.
beta = glm1$coefficients

#2. Call QN function to estimate.
output = quasi_newton(X, Y, m)

#3. Eyeball values for accuracy & display convergence.
beta
output$beta_hat
output$converged
output$iter

#4. Plot the convergence of the beta variables compared to glm.
par(mfrow=c(4,3))
for (j in 1:length(output$beta_hat)) {
	plot(1:nrow(output$betas), output$betas[,j],
		type='l', xlab='iterations', ylab=paste('beta',j))
	abline(h=beta[j],col='red')
}

#5. Plot log-likelihood function for convergence.
plot(1:length(output$loglik), output$loglik,
	type='l', xlab='iterations', col='blue',#log='x',
	main='Quasi-Newton Neg Loglikelihood Function')

