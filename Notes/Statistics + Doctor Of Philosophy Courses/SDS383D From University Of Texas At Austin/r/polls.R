# Data from http://www.stat.columbia.edu/~gelman/arm/
library(lme4)


polls = read.csv("polls.csv", header=TRUE)
summary(polls)

# "Alabama first" on the edu variable.
# Re-order the factor levels
levels(polls$edu) = c("NoHS", "HS", "SomeColl", "Bacc")

# glm doesn't blow up...
glm1 = glm(bush~black + female + state, family=binomial(link="logit"), data=polls)

# But does give nonsense answers for some of the coefficients
summary(glm1)

xtabs(~state, data=polls)


# A hierarchical models works well here...
# partially pool across states
hglm1 = glmer(bush ~ black + female + (1 | state), family=binomial(link="logit"), data=polls)

hist(predict(hglm1))


coef(hglm1)
r = ranef(hglm1, condVar = TRUE)
d = dotplot(r)
names(d)
plot(d$state)
summary(hglm1)


# More advanced model specifications

hglm2 = glmer(bush ~ black + female + (1 | state) + (1 | edu), family=binomial(link="logit"), data=polls)
anova(hglm1, hglm2)
r = ranef(hglm2, postVar = TRUE)
d = dotplot(r)
names(d)
plot(d$state)
plot(d$edu)

hglm3 = glmer(bush ~ black + female + edu + (1 | state) + (female | edu) , family=binomial(link="logit"), data=polls)

hist(predict(hglm3, type='response'))