theta_true = 10
sig_true = 3.5
N = 75

y = rnorm(N, theta_true, sig_true)
ybar = mean(y)
Sy = sum((y - ybar)^2)

# Prior for 1/sigma2 ~ InvGamma(d/2, eta2/2)
d = 1
eta2 = 1

# Prior for theta: super vague N(mu, tau2)
mu_theta = 0
tau2_theta = 10^2
gamma_theta = 1/tau2_theta

### Method 1: a simple Gibbs sampler

# Number of Monte Carlo draws
NMC = 5000
theta_save = rep(0, NMC)
sigma2_save = rep(0, NMC)

# Initial state
sigma2 = 1
for(i in 1:NMC) {
	
	# Conjugate update for theta, given sigma2
	theta_var = 1/{N/sigma2 + gamma_theta}  # sum of precisions
	theta_hat = theta_var * {(N/sigma2)*ybar + mu_theta * gamma_theta}
	theta = rnorm(1, theta_hat, sqrt(theta_var))
	
	# Conjugate update for sigma2, given theta
	omega = rgamma(1, (d + N)/2, rate = {eta2 + sum((y - theta)^2)}/2)
	sigma2 = 1/omega
	
	# Save draws
	theta_save[i] = theta
	sigma2_save[i] = sigma2
}

# Posteriors
hist(theta_save, 50, prob=TRUE);  abline(v = theta_true, col='blue', lwd=2)
hist(sigma2_save, 50, prob=TRUE); abline(v = sig_true^2, col='red', lwd=2)


