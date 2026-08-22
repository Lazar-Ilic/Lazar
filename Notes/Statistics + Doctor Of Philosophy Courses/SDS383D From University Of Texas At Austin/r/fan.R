library(mosaic)
library(foreach)

creatinine = read.csv('http://jgscott.github.io/teaching/data/creatinine.csv')
# see http://www.webmd.com/a-to-z-guides/creatinine-and-creatinine-clearance-blood-tests
n_boot = 1000

# I like foreach for loops because they have a return value
# R's built-in for loops are side-effects only
boot1 = foreach(i = 1: n_boot, .combine='rbind') %do% {
	lm_boot = lm(creatclear ~ age, data = mosaic::resample(creatinine))
	coef(lm_boot)
}

plot(creatclear ~ age, data=creatinine, type='n')
for(i in 1:n_boot) {
	# 4th argument to rgb is opacity on (0,1) scale
	abline(boot1[i,], col=rgb(0.05, 0.05, 0.05, 0.01))
}
points(creatclear ~ age, data=creatinine, pch=19, col='red')

