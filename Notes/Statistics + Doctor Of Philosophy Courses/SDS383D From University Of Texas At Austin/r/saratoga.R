library(mosaic)
library(MASS)
data(SaratogaHouses)  # ?SaratogaHouses for info

# for plotting
ghost_grey = rgb(0.5,0.5,0.5,0.2)

# Just pick some obvious variables
lm1 = lm(price ~ livingArea + lotSize + fuel + bedrooms + bathrooms, data=SaratogaHouses)
summary(lm1)

# note: mosaic overloads plot with an lm-like syntax that I prefer
plot(price ~ fitted(lm1), data=SaratogaHouses, pch=19, col=ghost_grey)
abline(0,1)

hist(resid(lm1))

# 4th (influence) plot: house 962 is a super high leverage point
plot(lm1)

SaratogaHouses[962,]
fitted(lm1)[962]
which.max(cooks.distance(lm1))

# Compare with rlm which uses Huber errors
lm2 = MASS::rlm(price ~ livingArea + lotSize + fuel + bedrooms + bathrooms, data=SaratogaHouses)
summary(lm2)

# some big differences in the fitted coefficients
cbind(coef(lm1), coef(lm2))

# and the fitted values
fitted(lm1)[962]
fitted(lm2)[962]


# Time for a Bayesian heavy-tailed error model

# Could extract the model matrix to go into the Bayesian linear model
# word to the wise: scale your covariates if you're
# going to use a common variance parameter for all betas...
X_raw = model.matrix(lm1)[,-1]
X = cbind(1, scale(X_raw))
head(X)


