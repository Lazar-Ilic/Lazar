library(mosaic)
library(lme4)	# will also need to have Matrix and lattice installed


ut2000 = read.csv("../data/ut2000.csv", header=TRUE)
ut2000$GPA = ut2000$GPA*100

# Main effects
lm0 = lm(GPA~SAT.V + SAT.Q, data=ut2000)
lm1 = lm(GPA~SAT.V + SAT.Q + School, data=ut2000)
summary(lm1)
anova(lm1)

# A mixed-effects model with hierarchical structure for school
hlm1 = lmer(GPA ~ SAT.V + SAT.Q + (1 | School), data=ut2000)
summary(hlm1)	

coef(lm1)
coef(hlm1)
fixef(hlm1)
ranef(hlm1)	

# Compare the estimated School intercepts under both models

# Add the intercept to the dummies
batch1 = coef(lm1)[1] + c(0, coef(lm1)[4:12])
batch2 = coef(hlm1)$School[,1]

# Plot the estimated School-specific intercepts
# pretty similar
plot(batch1, batch2)
abline(0,1)



# Rescale the quantitative variables
# Subtract the mean and divide by the standard deviation
# Mixed models work best with standardized variables
ut2000s = ut2000
ut2000s[,c(1,2,3,5)] = scale(ut2000s[,c(1,2,3,5)])

# With interaction b/t school and SAT math scores
lm2 = lm(GPA~SAT.V + SAT.Q + School + SAT.Q:School, data=ut2000s)
anova(lm2)
summary(lm2)


# Now a mixed-effects model
# This says allow the intercept and SAT.Q slopes to change among the groups
hlm2 = lmer(GPA ~ SAT.V + SAT.Q + (1+SAT.Q | School), data=ut2000s)
coef(hlm2)
summary(hlm2)

r = ranef(hlm2, condVar=TRUE)
dotplot(r)
dotplot(r, scales=list(relation='free'))

# Look at the posterior variance of each block of random effects
attr(r$School,"postVar")

# Compare the estimated SAT.Q slopes
# Notice that the slope of the SAT.Q variable for Social Work
# is estimated to be negative!
coef(lm2)

# This is probably explained by the small sample size for Social Work
xtabs(~School, data=ut2000)
xyplot(GPA ~ SAT.Q | School, data=ut2000)

# Add the overall slope to the interaction terms
batch1 = coef(lm2)[2] + c(0, coef(lm2)[13:21])
batch2 = coef(hlm2)$School[,3]

# Pulling the coefficients toward a group mean = shrinkage
plot(batch1, batch2, xlim=c(-0.45,0.3), ylim=c(-0.45,0.3))
abline(0,1)

dotplot(ranef(hlm2, condVar = TRUE))

