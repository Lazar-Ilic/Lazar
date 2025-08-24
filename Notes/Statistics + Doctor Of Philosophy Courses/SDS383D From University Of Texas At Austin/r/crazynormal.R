library(mvtnorm)


sigma = matrix(c(1,0.75, 0.75, 1), nrow=2)

y = rmvnorm(10000, sigma=sigma)

plot(y)
ind1 = which(y[,1] > 0 & y[,1] < 2 & y[,2] > 0 & y[,2] < 2)
points(y[ind1,], col='red')

ind2 = which(y[,1] > -2 & y[,1] < 0 & y[,2] > -2 & y[,2] < 0)
points(y[ind2,], col='blue')

y[ind1,1] = -y[ind1,1]
y[ind2,1] = -y[ind2,1]

plot(y)

hist(y[,1])
hist(y[,2])
plot(y)