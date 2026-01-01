library(lme4)
library(mosaic)
library(lmtest)
library(lattice)

semicon = read.csv("../data/semicon.csv", header=TRUE)
summary(semicon)

# material is categorical
semicon$material=factor(semicon$material)

plot(rate ~ material, data=semicon)

plot(rate ~ pass1, data=semicon)

# What about for individual materials?
plot(rate ~ pass1, data=subset(semicon, material==9))

lm1 = lm(rate ~ split, data=subset(semicon, material==9))
summary(lm1)

# Paneled plot
xyplot(rate ~ split | material, data=semicon)


# Baseline: no interaction
lm1 = lm(rate ~ split+material, data=semicon)
summary(lm1)

# Now with different split slopes
lm2 = lm(rate ~ split*material, data=semicon)
summary(lm2)


# Now a hierarchical model
hlm1 = lmer(rate ~ (1 + split | material), data=semicon)
summary(hlm1)


coef(hlm1)
ranef(hlm1)
dotplot(ranef(hlm1, postVar=TRUE), scales=list(relation='free'))



######################
# Advanced stuff below
# Roll your own lattice plot
######################


par(mfrow=c(3,3), mar=c(4,4,3,0.5))
lmlist=list()
myxlab = c("Split of Exposure Sequence", rep("",8))
myylab = c("PhoRes Dev Rate (nm/s)", rep("",8))
for(i in 1:9) {
	# Which material?
	mymat = levels(semicon$material)[i]
	
	# Grab that subset
	mysub = subset(semicon, material==mymat)
	
	# Grab the upper and lower bounds of the y axis
	yl = floor(min(mysub$rate, na.rm=TRUE))
	yu = ceiling(max(mysub$rate, na.rm=TRUE))
	
	# Pick a grid size for the y axis
	myskip = ceiling(diff(range(mysub$rate, na.rm=TRUE))/12)
	
	# Two linear models, including and excluding wafer 1
	lm1a = lm(rate ~ split, data = mysub)
	lm1b = lm(rate ~ split, data = mysub, subset = (wafer != 1))
	
	# Let's use lm1b
	
	# Compute the t-stat and p-value the old fashioned way
	#bhat = coef(lm1b)
	#stderr = sqrt(diag(vcov(lm1b)))	# sqrt of diagonal elements of the variance-covariance matrix
	#pval = 2*pt(bhat[2]/stderr[2], df=nrow(lm1b$model)-2, lower.tail=FALSE)
	
	# Or grab it from the summary
	pval = (summary(lm1b)[4])$coefficients[2,4]
	
	# Plot the data and set the axes
	plot(rate ~split, data=mysub, bty='n', type='p', axes=FALSE,
		pch=19, col=rgb(50,50,180,50,maxColorVal=256),
		ylim=c(yl,yu),
		main=paste("Material ", i, " (p=", round(pval,3), ")", sep=""),
		xlab=myxlab[i], ylab=myylab[i])
	axis(1,at=seq(0,50,by=5), tick=FALSE)
	axis(2,at =seq(yl,yu,by=myskip), las=1, cex.axis=0.8)

	# add lines for the linear model and the hierarchical linear model
	abline(lm1b, lty='solid')
	abline( rev(as.numeric(coef(hlm1)$material[i,])) , lty='dashed', col='darkgrey')
	
	# Add the new linear model to a list in case we want to look at it later
	lmlist[[i]] = lm1b

}
