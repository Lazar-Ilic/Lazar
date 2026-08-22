library(lme4)
library(ggplot2)
library(lattice)

cheese = read.csv("../data/cheese.csv")
summary(cheese)

boxplot(log(vol) ~ disp, data=cheese)

# confounders?
plot(log(vol) ~ log(price), data=cheese)
boxplot(log(price) ~ disp, data=cheese)

xyplot(log(vol) ~ log(price) | store, data=cheese)

# common regression parameters across stores
hlm1 = lmer(log(vol) ~ log(price) + disp + (1 | store), data=cheese)
summary(hlm1)
coef(hlm1)

# different elasticity store by store
hlm2 = lmer(log(vol) ~ disp + (log(price) + 1 | store), data=cheese)
summary(hlm2)
coef(hlm2)


# interactions store by store
hlm3 = lmer(log(vol) ~ (1 + log(price) + disp + log(price):disp | store), data=cheese)
summary(hlm3)
coef(hlm3)

lm_kroger = lm(log(vol) ~ log(price) + disp + log(price):disp,
	data=subset(cheese, store == 'DALLAS/FT. WORTH - KROGER CO'))
coef(hlm3)$store['DALLAS/FT. WORTH - KROGER CO',]

plot(vol ~ price,
	data=subset(cheese, store == 'DALLAS/FT. WORTH - KROGER CO'))
points(vol ~ price,
	pch=19, col='blue',
	data=subset(cheese, store == 'DALLAS/FT. WORTH - KROGER CO'
						& disp == 0))
points(vol ~ price,
	pch=19, col='red',
	data=subset(cheese, store == 'DALLAS/FT. WORTH - KROGER CO'
						& disp == 1))

# Add curves				
curve(exp(9.933197)*x^(-1.800734), add=TRUE, col='blue')
curve(exp(9.933197 + 0.9507379)*x^(-1.800734-0.623256), add=TRUE, col='red')



# What about for a store that didn't use displays often?
xtabs(~store + disp, data=cheese)
coef(hlm3)$store['HARRISBURG/SCRANTN - GIANT FOOD STO',]


plot(vol ~ price,
	data=subset(cheese, store == 'HARRISBURG/SCRANTN - GIANT FOOD STO'))
points(vol ~ price,
	pch=19, col='blue',
	data=subset(cheese, store == 'HARRISBURG/SCRANTN - GIANT FOOD STO'
						& disp == 0))
points(vol ~ price,
	pch=19, col='red',
	data=subset(cheese, store == 'HARRISBURG/SCRANTN - GIANT FOOD STO'
						& disp == 1))

# Add curves				
curve(exp(8.355578)*x^(-1.208426), add=TRUE, col='blue')
curve(exp(8.355578 + 0.5653274)*x^(-1.208426-0.4296085), add=TRUE, col='red')

