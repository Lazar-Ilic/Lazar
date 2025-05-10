library(invgamma)

mathtest = read.csv('../data/mathtest.csv')

# Take a subset:
# fewer schools will illustrate effect of prior
mathtest = subset(mathtest, school <= 10)

# extract summary statistics
y = mathtest$mathscore
ybari = aggregate(mathscore ~ school, data= mathtest, FUN = mean)$mathscore
Ni = aggregate(mathscore ~ school, data= mathtest, FUN = length)$mathscore
Vari = aggregate(mathscore ~ school, data= mathtest, FUN = var)$mathscore
SSi = Vari*(Ni-1)  # sum of squares for each group
SStot = sum(SSi) # total sum of squares
Ntot = sum(Ni) # total sample size
P = length(ybari)

#######
# First with an inverse-gamma prior
#######

# Initialize
sigma2 = mean(Vari)
tau2 = var(ybari)/sigma2
mu = mean(ybari)

NMC = 10000
burn = 500

theta_save = matrix(0, nrow=NMC, ncol=P)
school_mean_save = matrix(0, nrow=NMC, ncol=P)
mu_save = rep(0, NMC)
tau2_save = rep(0, NMC)
sigma2_save = rep(0, NMC)

for(it in 1:(NMC+burn)) {
	if(it %% 1000 == 0) cat("Iteration ", it, "\n")
	
	# Update mu
	mu_var = 1/sum( Ni/(Ni*tau2 + sigma2) )
	mu_mean = mu_var*sum( Ni/(Ni*tau2 + sigma2) * ybari)
	mu = rnorm(1, mu_mean, sqrt(mu_var))
	
	# Block-update theta
	theta_var = sigma2/(Ni + 1/tau2)
	theta_mean = (Ni*(ybari-mu))/(Ni + 1/tau2)
	theta = rnorm(P, theta_mean, sqrt(theta_var))

	# Now update Tau^2
	# Inverse-gamma(1/2, 1/2) prior
	a_star = 1 + P
	b_star = 1 + sum(theta^2/sigma2)
	tau2 = 1/rgamma(1, a_star/2, rate = b_star/2)
	
	# Now update Sigma2 under Jeffreys' prior
	school_mean = mu + theta
	ss_extra = (Ni/tau2)/(Ni + 1/tau2) * (ybari - school_mean)^2
	eta_star = SStot + sum(ss_extra)
	omega = rgamma(1, Ntot/2, rate=eta_star/2)
	sigma2 = 1/omega
	
	if(it > burn) {
		theta_save[it-burn,] = theta
		school_mean_save[it-burn,] = theta+mu
		mu_save[it-burn] = mu
		tau2_save[it-burn] = tau2
		sigma2_save[it-burn] = sigma2
	}
}

# Posterior means
school_hat = colMeans(school_mean_save)
kappa = (school_hat - ybari)/ybari
plot(Ni, abs(kappa))

hist(tau2_save)

plot(ybari, school_hat)
abline(0,1)

#########
# Half-Cauchy prior on tau
# via a redundant parameterization (PX), see Gelman 2006
# y_it = mu + eta*sigma*beta_i + e_it
# eta ~ N(0,1)
# beta_i ~ N(0, g2)
# g2 ~ IG(1/2, 1/2)
# thus theta_i = eta*sigma*beta_i under older parameterization
# tau = abs(eta)*g, which marginally has a half-Cauchy prior
#########

NMC = 10000
burn = 500

theta_save2 = matrix(0, nrow=NMC, ncol=P)
school_mean_save2 = matrix(0, nrow=NMC, ncol=P)
mu_save2 = rep(0, NMC)
tau2_save2 = rep(0, NMC)
sigma2_save2 = rep(0, NMC)

# initials
sigma2 = mean(Vari)
tau2 = var(ybar)/sigma2
mu = mean(ybari)
betai = ybari
g2 = 1

for(it in 1:(NMC+burn)) {
	if(it %% 1000 == 0) cat("Iteration ", it, "\n")
	
	# Update mu
	mu_var = 1/sum( Ni/(Ni*tau2 + sigma2) )
	mu_mean = mu_var*sum( Ni/(Ni*tau2 + sigma2) * ybari)
	mu = rnorm(1, mu_mean, sqrt(mu_var))
	
	# update eta
	v_eta = 1/(1 + sum(Ni*betai^2))
	mu_eta = v_eta * sum(Ni*betai*(ybari-mu)/sqrt(sigma2))
	eta = rnorm(1, mu_eta, sqrt(v_eta))
	
	# update beta
	v_beta = 1/(1/g2 + Ni*eta^2)
	mu_beta = Ni*eta*(ybari - mu)/sqrt(sigma2)
	betai = rnorm(P, mu_beta, sqrt(v_beta))
	
	# Block-update theta
	theta = eta*sqrt(sigma2)*betai

	# Now update G^2
	# Inverse-gamma(1/2, 1/2) prior
	a_star = 1 + P
	b_star = 1 + sum(betai^2)
	g2 = 1/rgamma(1, a_star/2, rate = b_star/2)
	tau2 = eta^2 * g2
	
	# Now update Sigma2 under Jeffreys' prior
	school_mean = mu + theta
	ss_extra = (Ni/tau2)/(Ni + 1/tau2) * (ybari - school_mean)^2
	eta_star = SStot + sum(ss_extra)
	omega = rgamma(1, Ntot/2, rate=eta_star/2)
	sigma2 = 1/omega
	
	if(it > burn) {
		theta_save2[it-burn,] = theta
		school_mean_save2[it-burn,] = theta+mu
		mu_save2[it-burn] = mu
		tau2_save2[it-burn] = tau2
		sigma2_save2[it-burn] = sigma2
	}
}

# Posterior means
school_hat2 = colMeans(school_mean_save2)
kappa2 = (school_hat2 - ybari)/ybari
plot(Ni, abs(kappa2))

# Posterior draws under tau2 ~ IG(1/2, 1/2)
hist(tau2_save, 100, prob=TRUE)
curve(dinvgamma(x, 1/2, 1/2), n=1000, add=TRUE, col='red')
curve(2*dt(x, 1), n=1000, add=TRUE, col='blue')

# Posterior draws under tau ~ C+(0,1)
# More stacked against zero, but also a heavier tail
hist(tau2_save2, 100, prob=TRUE)
curve(dinvgamma(x, 1/2, 1/2), n=1000, add=TRUE, col='red')
curve(2*dt(x, 1), n=1000, add=TRUE, col='blue')

# autocorrelation functions
acf(tau2_save)
acf(tau2_save2)

# Significantly more shrinkage under the half-Cauchy prior
plot(abs(kappa), abs(kappa2))
abline(0,1)



