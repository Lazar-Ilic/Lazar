theta_true = -1.6
sig_true = 3
N = 17

y = rnorm(N, theta_true, sig_true)
ybar = mean(y)
Sy = sum((y - ybar)^2)

# Prior for 1/sigma2 ~ InvGamma(d/2, eta2/2)
d = 1
eta2 = 1

# Prior for theta: super vague N(mu, tau2*sigma2)
mu_theta = 0
tau2_theta = 10^2
gamma_theta = 1/tau2_theta


# Known posterior from exercises
m_post = (N*ybar + gamma_theta * mu_theta)/(N + gamma_theta)
d_post = d + N
sumsq_post = eta2 + Sy + (N*gamma_theta*(ybar - mu_theta)^2)/(N + gamma_theta)



# Simple Monte Carlo
NMC = 10000

# First omega
omega_post = rgamma(NMC, d_post/2, rate = sumsq_post/2)

# Now theta, given omega
theta_post = rnorm(NMC, m_post, sqrt(1/{omega_post*(N + gamma_theta)}))

# Compare posterior with known functional form

post_scale = sqrt(sumsq_post/{(N + gamma_theta)*(N + d)})
f_theta = function(x) {
	1/post_scale * dt((x - m_post)/post_scale, df=d_post)
}

hist(theta_post, 30, prob=TRUE)
curve(f_theta, col='red', add=TRUE, lwd=2)


