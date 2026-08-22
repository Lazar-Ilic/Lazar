NMC = 10000

tau = 3.9
nu = 5
x1 = tau*rt(NMC, nu)

om2 = rgamma(NMC, nu/2, rate = tau^2*nu/2)
x2 = rnorm(NMC, 0, sqrt(1/om2))

qqplot(x1, x2); abline(0,1)

ks.test(x1, x2)