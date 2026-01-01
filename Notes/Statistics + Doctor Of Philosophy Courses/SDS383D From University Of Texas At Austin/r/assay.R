library(mosaic)
library(lme4)
library(ggplot2)


# protocol: 
# A immature rats dosed orally for a period of 3 days
# B immature rats dosed by injection for 3 days # C adult ovariectomized rats dosed by injection for 3 days 
# D adult ovariectomized rats dosed by injection for 7 days weight: body weight of rat in grams 
# uterus: weight of uterus in milligrams 
# EE: dose of estrogen agonist EE in milligrams per kilogram of body 
# weight per day. The doses form (roughly) a geometrically increas- 
# ing sequence: 0 (control), 0.01, 0.03, 0.1, 0.3, 1, 3, and 10. 
# ZM: dose of estrogen antagonist ZM in milligrams per kilogram of 
# body weight per day. The doses form a geometrically increasing 
# sequence: 0 (control), 0.1, and 1. 
# lab: laboratory at the assay was conducted 
# group: lab/protocol replicate group, with 6 rats per group.
# The numbering scheme is hierarchical, in the sense that it
# is specific to a particular lab and particular protocol.
# Thus, for example, rats in group 9 in the Zeneca lab under
# protocol A are not the same as those in group 9 in the
# Zeneca lab under protocol B, even though the group number is the same. 

assay = read.csv('../data/assay.csv', header=TRUE)
summary(assay)

# EDA
xyplot(uterus ~ EE | protocol, data=assay)

# 1) Things look bunched up
# 2) Nonlinear dose-response curve
xyplot(uterus ~ factor(EE) | protocol, data=subset(assay, ZM==0))

# Major differences among the protocols
# A/B: juvenile rats
# C/D: adult rats

# Some preprocessing to take care of some normalization
# Define a new response as log of uterus to bodyweight ratio
assay$ubw = assay$uterus/assay$weight
assay$lubw = log(assay$ubw)

# Look at ubw for controls on a lab-by-protocol basis
# Not all labs did all protocols
controls = subset(assay, EE==0 & ZM==0)
xyplot(lubw ~ factor(group) | lab + protocol, data=controls) 

# An aside: can also use ggplot2
qplot(factor(group), ubw, facets=protocol~lab, data=controls)


# Compute the mean control ubw within each lab/protocol
# "vehicle control"
vehiclecontrol = aggregate(lubw ~ lab + protocol, data=controls, mean) 

# Merge the data sets
assaywc = merge(assay, vehiclecontrol, by = c("lab", "protocol"))
head(assaywc)

# Use some better suffixes
assaywc = merge(assay, vehiclecontrol, by = c("lab", "protocol"), suffixes = c("", ".control"))
head(assaywc)

# Define the ratio of response to vehicle control response
assaywc$ubwnorm = assaywc$lubw - assaywc$lubw.control

# A lot of the starkest lab differences are gone now
xyplot(ubwnorm ~ log10(EE) | lab, data= assaywc)

# Split the data set into the two sub-experiments
# We can leave out the controls in the EE data, which
# have average ubwnorm = 1 by construction
xtabs(~factor(ZM) + factor(EE), data=assaywc)
assayEE = subset(assaywc, ZM==0)
assayZM = subset(assaywc, EE==3)

# By protocol, across all labs
xyplot(ubwnorm ~ log10(EE) | protocol, data=assayEE)

# By lab, regardless of protocol
xyplot(ubwnorm ~ log10(EE) | lab, data=assayEE)
bwplot(ubwnorm ~ factor(EE) | lab, data=assayEE)


xyplot(ubwnorm ~ log10(EE) | lab, data=subset(assayEE, protocol=="A"))
xyplot(ubwnorm ~ log10(EE) | lab, data=subset(assayEE, protocol=="B"))
xyplot(ubwnorm ~ log10(EE) | lab, data=subset(assayEE, protocol=="C"))
xyplot(ubwnorm ~ log10(EE) | lab, data=subset(assayEE, protocol=="D"))


# Start with a mixed model
# Treat EE as a factor as a cheap way
# to handle nonlinearity in the dose-response curve
# Random effects for lab and protocol
hlm1 = lmer(ubwnorm ~ factor(EE) + (1 | lab) + (1 | protocol), data=assayEE)

r1.lab = ranef(hlm1, condVar=TRUE, whichel="lab")
dotplot(r1.lab)

r1.protocol = ranef(hlm1, condVar=TRUE, whichel="protocol")
dotplot(r1.protocol)

# Check the residuals: clear model misfit
bwplot(resid(hlm1) ~ factor(EE) | protocol, data=assayEE)
bwplot(resid(hlm1) ~ factor(EE) | lab, data=assayEE)


# Question: why does the following model break?
hlm2 = lmer(ubwnorm ~ (1 | protocol) + (1 + factor(EE) | lab) + (1 + factor(EE) | protocol), data=assayEE)


# With fixed effects instead: this works
hlm3 = lmer(ubwnorm ~ protocol + factor(EE) + factor(EE):protocol + (1 | lab), data=assayEE)
summary(hlm3)

bwplot(resid(hlm3) ~ factor(EE) | protocol, data=assayEE)
bwplot(resid(hlm3) ~ factor(EE) | lab, data=assayEE)
