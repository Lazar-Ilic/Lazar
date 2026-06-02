a = 3
NMC = 10000

# Using the redundant parameterization
tau = rnorm(NMC, 0, 1)*sqrt(1/rgamma(NMC, a/2, rate=a/2))

hist(abs(tau), 500, prob=TRUE, xlim=c(0,5))
curve(2*dt(x, a), add=TRUE)

# Adding a mean
tau = rnorm(NMC, 3, 1)*sqrt(1/rgamma(NMC, a/2, rate=a/2))
hist(abs(tau), 500, prob=TRUE, xlim=c(0,5))
