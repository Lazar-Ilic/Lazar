library(lme4)
library(mosaic)

bloodpressure = read.csv("../data/bloodpressure.csv")
head(bloodpressure)

# Naive approach: treat every observation as independent
mu_hat = mean(systolic ~ factor(treatment), data=bloodpressure)
sigma_hat = sd(systolic ~ factor(treatment), data=bloodpressure)
sample_size = tally( ~ factor(treatment), data=bloodpressure)

# naive standard errors
sigma_hat/sqrt(sample_size)


# Notice the structure of the data
xtabs( ~ factor(subject) + factor(treatment), data=bloodpressure)
xtabs( ~ factor(subject), data=bloodpressure)

# Avoiding pseudo-replication

# Naive strategy: average the person-level data
# Treat each average as a single data point
person_mean = mean(systolic ~ factor(subject), data=bloodpressure)
treatment_ind = c(rep(1,10), rep(2,10))

# Mean and standard deviation for each group
mean(person_mean ~ factor(treatment_ind))
sd(person_mean ~ factor(treatment_ind))

# Standard error of the sample mean for each group
sd(person_mean ~ factor(treatment_ind))/sqrt(10)

# Easy to phrase as a linear model
lm1 = lm(person_mean ~ factor(treatment_ind))
summary(lm1)

# Doesn't account for varying sample sizes
tally( ~ factor(subject), data=bloodpressure)

# Much better: a hierarchical model that involves
# a "compound error term"
hlm1 = lmer(systolic ~ treatment + (1 | subject), data=bloodpressure)
summary(hlm1)
r1 = ranef(hlm1, condVar = TRUE)
dotplot(r1)

# This looks structurally similar to a model with dummy variables for subjects
# But it is very different!
# Notice how drastically wrong the answer is for the "fixed effects" model
lm3 = lm(systolic ~ treatment + factor(subject), data=bloodpressure)
summary(lm3)
