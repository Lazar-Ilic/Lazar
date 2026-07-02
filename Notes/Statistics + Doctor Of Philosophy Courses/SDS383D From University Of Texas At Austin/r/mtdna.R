library(mosaic)
library(lattice)
library(lme4)

# Mixed models for partial pooling

mtdna1 = read.csv('../data/mtdna1.csv', header=TRUE)
mtdna2 = read.csv('../data/mtdna2.csv', header=TRUE)
summary(mtdna2)

# Recast the numerical codes as factors
mtdna1$animal = factor(mtdna1$animal)
mtdna1$litter = factor(mtdna1$litter)
mtdna1$tr = factor(mtdna1$tr)
summary(mtdna1)

mtdna2$animal = factor(mtdna2$animal)
mtdna2$litter = factor(mtdna2$litter)
mtdna2$tr = factor(mtdna2$tr)
summary(mtdna2)

# We'll look at log2(copy)
boxplot(log2(copy) ~ tissue, data=mtdna1)

# Fit a model for tissue group
lm1 = lm(log2(copy) ~ tissue, data=mtdna1)
summary(lm1)

# Generate some predictions on the hold-out data
pred1 = predict(lm1, mtdna2)

y2 = log2(mtdna2$copy)
plot(pred1, y2)

# The simple group-wise model predicts
# slightly worse than the grand mean!
grandmean = mean(log2(mtdna1$copy))
sum( (y2 - pred1)^2 )
sum( (y2 - grandmean)^2 )

# What about partial pooling?
shrink1 = 0.5*pred1 + 0.5*grandmean
sum( (y2 - shrink1)^2 )

# Let's examine a range of shrinkage factors
gridsize = 101
mygrid = seq(0,1,length=gridsize)
sse = rep(0, gridsize)  # creates an empty placeholder
for(i in 1:gridsize) {
	w = mygrid[i]
	shrink1 = w*pred1 + (1-w)*grandmean
	sse[i] = sum( (y2 - shrink1)^2 )
}
plot(mygrid, sse)
which.min(sse)
w = mygrid[which.min(sse)]
# Looks like the out of sample error is
# minimized when w = 0.4 or so

shrink1 = w*pred1 + (1-w)*grandmean
plot(pred1, shrink1)
abline(0,1)

#####
# Fit a hierarchical model to a merged data set
#####

# Create a merged data set
mtdna = rbind(mtdna1, mtdna2)

hlm1 = lmer(log2(copy) ~ (1 | tissue), data=mtdna1)
lm0 = lm(log2(copy) ~ tissue - 1, data=mtdna1)
summary(hlm1)

# We have ignored correlation due to litter
boxplot(resid(hlm1) ~ litter, data=mtdna1)

# Soln. 1: fit an ordinary linear model
# with dummy variables for litter
lm2 = lm(log2(copy) ~ tissue + litter, data=mtdna1)
summary(lm2)


# Soln. 2: fit a mixed model that partially pools
# litter-level effects
hlm1 = lmer(log2(copy) ~ tissue + (1 | litter), data=mtdna1)
summary(hlm1)
ranef(hlm1)

# Create a merged data set
mtdna = rbind(mtdna1, mtdna2)

# We can also account for litter-level correlations
# Notice that a similar pattern across tissues holds within
# each litter, but that litters themselves are quite different
boxplot(log2(copy) ~ tissue:litter, data=mtdna, las=2)

hlm2 = lmer(log2(copy) ~ (1 | tissue) + (1 | litter), data=mtdna)
summary(hlm2)

r2.tissue = ranef(hlm2, condVar=TRUE, whichel = 'tissue')
dotplot(r2.tissue)

boxplot(resid(hlm2) ~ tissue:litter, data=mtdna)
