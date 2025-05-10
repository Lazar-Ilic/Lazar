library(mosaic)
library(MASS)
library(mvtnorm)
data(SaratogaHouses)  # ?SaratogaHouses for info

# for plotting
ghost_grey = rgb(0.5,0.5,0.5,0.2)

# Some obvious variables
lm1 = lm(price ~ livingArea + lotSize + fuel + bedrooms + bathrooms, data=SaratogaHouses)
summary(lm1)



X_raw = model.matrix(lm1)[,-1]
Xs = scale(X_raw, center=TRUE, scale=FALSE)
y = SaratogaHouses$price

# Center y
mu_y = mean(y)
sd_y = sd(y)
ys = (y - mu_y)

lm_scaled = lm(ys ~ Xs-1)
summary(lm_scaled)
plot(ys ~ fitted(lm_scaled), col=ghost_grey, pch=19)
abline(0,1)


# I will use a g prior for beta
# implicitly, the prior is beta ~ N(0, g (omega X'X)^-1)
# a typical choice is g = n

n = length(ys)
p = ncol(Xs)

# Prior hyperparameters
g = n
K = (1/g)*crossprod(Xs)
d_prior = 1
eta_prior = 1
h = 3.5  # for t_h error

# pre-compute what we can
d_star = d_prior + n

# Initial settings for lambda
lambda = rep(1, n)

# MCMC settings
NMC = 5000
burn = 1000

# Pre-allocate storage
beta_save = matrix(0, NMC, p)
omega_save = rep(0, NMC)
lambda_save = matrix(0, NMC, n)
r2_save = rep(0, NMC)

# Main loop
for(i in 1:(NMC + burn)) {
	if(i %% 250 == 0) cat(paste0("Iteration ", i, "\n"))
	
	# Update hyperpars given lambda
	K_star = crossprod(Xs, (lambda + 1/g)*Xs)
	K_star_inv = solve(K_star)
	beta_mu = K_star_inv %*% crossprod(Xs, lambda*ys)
	
	# Draw omega from conditional, given beta
	# (i.e. being lazy and not marginalizing over beta here)
	# yhat = drop(Xs %*% beta_draw)
	# eps = ys - yhat
	# eta_star = eta_prior + sum(eps*lambda*eps) + drop(beta_draw %*% K %*% beta_draw)
	# omega = rgamma(1, (d_star+p)/2, rate = eta_star/2)
	
	# Draw omega from marginal
	eta_star = eta_prior + sum(ys*(lambda*ys)) - drop(crossprod(beta_mu, K_star %*% beta_mu))
	omega = rgamma(1, d_star/2, rate=eta_star/2)
	
	# Draw beta, given omega
	beta_cov = (1/omega)*K_star_inv
	beta_draw = drop(rmvnorm(1, mean=beta_mu, sigma = beta_cov))
	
	# Draw lambda
	yhat = drop(Xs %*% beta_draw)
	eps = ys - yhat
	lambda = rgamma(n, (h+1)/2, rate = (h + omega*(eps^2))/2)
	
	# Save draws
	if(i > burn) {
		beta_save[i-burn,] = beta_draw
		lambda_save[i-burn,] = lambda
		omega_save[i-burn] = omega
		
		# Bayesian R-squared
		r2_save[i-burn] = var(yhat)/var(ys)
	}
}

# Posterior mean vs lm and rlm
beta_hat = colMeans(beta_save)
resid_bayes = ys - drop(Xs %*% beta_hat)
lm_scaled = lm(ys ~ .-1, data=as.data.frame(Xs))
rlm_scaled = rlm(ys ~ .-1, data=as.data.frame(Xs))
data.frame(coef(lm_scaled), coef(rlm_scaled), beta_hat)

# standard errors
sqrt(diag(vcov(lm_scaled)))
sqrt(diag(vcov(rlm_scaled)))
apply(beta_save, 2, sd)

# posterior mean weights
lambda_hat = colMeans(lambda_save)
plot(lambda_hat)

# compare Bayesian weights with OLS residuals
plot(resid(lm_scaled)^2, 1/lambda_hat)

# posterior of residual scale (NOT standard deviation, since t)
hist(1/sqrt(omega_save), 20)

# posterior mean of residual scale
# Correct: E(f(omega))
mean(1/sqrt(omega_save))

# Incorrect f(E(omega))
1/sqrt(mean(omega_save)) 

# Why? Jensen's inequality
# f (strictly) convex and therefore
# f(E(x)) < E(f(X))

# Compare posterior expected standard deviation
# with actual residual standard deviation
# An elementary posterior predictive check
mean(1/sqrt(omega_save)) * sqrt(h/(h-2))
sd(resid_bayes)

# Distribution of residuals
# Not too bad and certainly better than normal
hist(resid_bayes, 50, prob=TRUE)
sigma_hat = mean(sqrt(1/omega_save))
curve((1/sigma_hat) * dt(x/sigma_hat, h), add=TRUE, col='blue')
curve(dnorm(x, 0, sd(resid_bayes)), add=TRUE, col='red')


# Posterior distribution of R^2
hist(r2_save, 30)
abline(v=summary(lm_scaled)$r.squared, lwd=3)


####
# Prediction with Bayes
# Key: must average predictions over posterior for parameters
####

# OLS prediction interval based on Gaussian error
my_samp = sample.int(n, 10)
x_star = Xs[my_samp, ]
y_predOLS = predict(lm_scaled, newdata = data.frame(x_star), interval='prediction', level = 0.95)
data.frame(ys[my_samp], y_predOLS) + mu_y  # adding back in mean for y

# Posterior predictive distribution
# Simple recipe: simulate a data point for each draw
# Take a few random x points
n_star = nrow(x_star)
y_star = matrix(0, NMC, n_star)

# Loop over posterior draws
for(i in 1:NMC) {
	# Form linear predictor from this draw
	# By averaging yhat over posterior draws,
	# we "integrate out" parameters w.r.t. posterior
	y_hat = drop(x_star %*% beta_save[i,])
	
	# Simulate residuals from their marginal distribution,
	# given this omega draw
	e_star = (1/sqrt(omega_save[i]))*rt(n_star, h)
	
	# Form simulated data point
	y_star[i,] = y_hat + e_star
}


# 95% posterior predictive interval
y_int = t(apply(y_star, 2, quantile, probs=c(0.025, 0.975)))
data.frame(ys[my_samp], y_predOLS, bayes_fit=colMeans(y_star), y_int) + mu_y
