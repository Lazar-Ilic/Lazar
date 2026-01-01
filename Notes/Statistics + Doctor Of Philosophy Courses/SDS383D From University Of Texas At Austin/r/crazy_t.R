N = 1000
h = 0.02

om = rgamma(N, h/2, rate=h/2)
theta = rnorm(N, 0, sqrt(1/om))

hist(theta)
plot(theta)