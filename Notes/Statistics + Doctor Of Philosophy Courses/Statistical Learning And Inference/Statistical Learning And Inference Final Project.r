# SDS323 Statistical Learning And Inference
# Final Project
# Lazar Ilic
# EID li948
# Sources Referenced: 2 Github R Tutorials, Blogs, and R Documentation

library(tidyverse)
library(tm)
library(ISLR)
#library(ISLR2)
library(e1071)
library(pls)
library(MASS)
library(class)
library(glmnet)
library(leaps)
library(caTools)
library(splines)
library(boot)
library(mgcv)
library(tree)
library(randomForest)
library(gbm)

z=read.csv("../input/inferencedataset/Final.csv")

# "logNO2","logcars","temp","winds","tempd","windd","hour","day"

View(z)
summary(z)

plot(z$logcars,z$logNO2,xlab="logcars",ylab="logNO2",main="logNO2 Versus logcars")
plot(z$temp,z$logNO2,xlab="temp",ylab="logNO2",main="logNO2 Versus temp")
plot(z$winds,z$logNO2,xlab="winds",ylab="logNO2",main="logNO2 Versus winds")
plot(z$tempd,z$logNO2,xlab="tempd",ylab="logNO2",main="logNO2 Versus tempd")
plot(z$windd,z$logNO2,xlab="windd",ylab="logNO2",main="logNO2 Versus windd")
plot(z$hour,z$logNO2,xlab="hour",ylab="logNO2",main="logNO2 Versus hour")
plot((z$day)%%7,z$logNO2,xlab="day",ylab="logNO2",main="logNO2 Versus day")
plot((z$day)%%365,z$logNO2,xlab="day365",ylab="logNO2",main="logNO2 Versus day365")

# It immediately strikes the viewer that logcars looks to be a relatively useful predictor, seems like a plausible non trivial positive linear correlation is present there. temp seems OK maybe a slight negative correlation. winds also seems OK maybe a slight negative linear correlation. The immediate natural idea is to conjunct winds with windd somehow. Now tempd is very interesting because it feels like we would have something useful if say we chose to create a new variable here expunging all tempd values in say [-1,1] or [-1,2] or impunging or whatever replacing those logNO2 values with say the mean or what the model upon the rest of the values would have predicted for a tempd of 0 or something like that at which point we might be left with some useful positive correlation which is to say some linear thing perhaps based upon the aforementioned physics air density theory and ideation or perhaps some other properties of the measurement region local to that precise known unknown. windd is quite interesting to eyeball as there is a gap around ~120 which might suggest that there are buildings in the vicinity blocking wind upon some directions somehow or the actual wind directions tend to be in certain directions. It is a little tricky to evaluate the hour here but eyeballing kind of suggests that mid day is higher which would make sense given increased traffic, other human activities outputting NO2, and temperature perhaps mid day. Certainly day is interesting and I am inspired to produce actual numerics and values to further evaluate and eyeball. In particular it would appear to me that days 0, 1, and 6 may carry lower averages and perhaps in the context of an n=500 model it would be useful to simply produce a binary indicator one hot Boolean dummy variable indicating membership in to that set or the other set for prediction.

# "logNO2","logcars","temp","winds","tempd","windd","hour","day"

z$wind1=ifelse(140<=z$windd & z$windd<=360,1,0)
#View(z)
z$daytime=ifelse(8<=z$hour & z$hour<=18,1,0)
z$day7=(z$day)%%7
z$day365=(z$day)%%365
z$daysplit=ifelse(z$day7<1.5 | z$day7>5.5,1,0)

View(z)

# Do a little bit of the old un hacked eyeballed binary Boolean one hot dummy variable construction here on sighted.

# "logNO2","logcars","temp","winds","tempd","windd","hour","day", "wind1", "daytime", "day7", "day365","daysplit"

Model.logcars=lm(logNO2 ~ logcars,z)
summary(Model.logcars)
plot(Model.logcars$fitted.values,Model.logcars$residuals,main="Residuals For Model.logcars",ylab="Residual",xlab="Fitted Values Of Model.logcars",pch=10)
hist(Model.logcars$residuals)

Model.temp=lm(logNO2 ~ temp,z)
summary(Model.temp)
plot(Model.temp$fitted.values,Model.temp$residuals,main="Residuals For Model.temp",ylab="Residual",xlab="Fitted Values Of Model.temp",pch=10)
hist(Model.temp$residuals)

Model.winds=lm(logNO2 ~ winds,z)
summary(Model.winds)
plot(Model.winds$fitted.values,Model.winds$residuals,main="Residuals For Model.winds",ylab="Residual",xlab="Fitted Values Of Model.winds",pch=10)
hist(Model.winds$residuals)

Model.tempd=lm(logNO2 ~ tempd,z)
summary(Model.tempd)
plot(Model.tempd$fitted.values,Model.tempd$residuals,main="Residuals For Model.tempd",ylab="Residual",xlab="Fitted Values Of Model.tempd",pch=10)
hist(Model.tempd$residuals)

Model.windd=lm(logNO2 ~ windd,z)
summary(Model.windd)
plot(Model.windd$fitted.values,Model.windd$residuals,main="Residuals For Model.windd",ylab="Residual",xlab="Fitted Values Of Model.windd",pch=10)
hist(Model.windd$residuals)

# "logNO2","logcars","temp","winds","tempd","windd","hour","day", "wind1", "daytime", "day7", "day365"

Model.hour=lm(logNO2 ~ hour,z)
summary(Model.hour)
plot(Model.hour$fitted.values,Model.hour$residuals,main="Residuals For Model.hour",ylab="Residual",xlab="Fitted Values Of Model.hour",pch=10)
hist(Model.hour$residuals)

Model.wind1=lm(logNO2 ~ wind1,z)
summary(Model.wind1)
plot(Model.wind1$fitted.values,Model.wind1$residuals,main="Residuals For Model.wind1",ylab="Residual",xlab="Fitted Values Of Model.wind1",pch=10)
hist(Model.wind1$residuals)

Model.daytime=lm(logNO2 ~ daytime,z)
summary(Model.daytime)
plot(Model.daytime$fitted.values,Model.daytime$residuals,main="Residuals For Model.daytime",ylab="Residual",xlab="Fitted Values Of Model.daytime",pch=10)
hist(Model.daytime$residuals)

Model.day7=lm(logNO2 ~ day7,z)
summary(Model.day7)
plot(Model.day7$fitted.values,Model.day7$residuals,main="Residuals For Model.day7",ylab="Residual",xlab="Fitted Values Of Model.day7",pch=10)
hist(Model.day7$residuals)

Model.day365=lm(logNO2 ~ day365,z)
summary(Model.day365)
plot(Model.day365$fitted.values,Model.day365$residuals,main="Residuals For Model.day365",ylab="Residual",xlab="Fitted Values Of Model.day365",pch=10)
hist(Model.day365$residuals)

Model.daysplit=lm(logNO2 ~ daysplit,z)
summary(Model.daysplit)
plot(Model.daysplit$fitted.values,Model.daysplit$residuals,main="Residuals For Model.daysplit",ylab="Residual",xlab="Fitted Values Of Model.daysplit",pch=10)
hist(Model.daysplit$residuals)

# "logNO2","logcars","temp","winds","tempd","windd","hour","day","wind1","daytime","day7","day365"

# logcars seems useful. temp seems useful. winds seems useful. hour seems useful. daytime seems useful. daysplit seems useful.

Model1=lm(logNO2 ~ logcars + temp + winds + hour + daytime + daysplit,z)
summary(Model1)
plot(Model1$fitted.values,Model1$residuals,main="Residuals For Model1",ylab="Residual",xlab="Fitted Values Of Model1",pch=10)
hist(Model1$residuals)

# OK now a huge loss of significance on daytime.

Model2=lm(logNO2 ~ logcars + temp + winds + hour + daysplit,z)
summary(Model2)
plot(Model2$fitted.values,Model2$residuals,main="Residuals For Model2",ylab="Residual",xlab="Fitted Values Of Model2",pch=10)
hist(Model2$residuals)

# Could try more sophisticated things like glm, nls. Or forming more complex models and running Cross Validation. I was thinking if I were to do that I would execute a K-fold Cross Validation with K=5 probably pseudorandomly generated training test sets splits. But the fact of the matter is this is a fairly simple linear model with 5 reasonable seeming input predictor variables and it performs fairly well. I do not see any terrible residuals plot which would inspire me to really attempt ad hoc degree curves hacking fitting on exponentials or other types of transformations functions. One might have expected severe seasonal cyclic effects but that did not seem to be the case and if the data set like extended more than 30 years back we might want auxiliary data sources... say upon the cars types distributions at the time just what sorts of engines and fuels existed in the past and produce better models based upon other metrics over longer time periods where such big shifts can occur also in manufacturing and general other sources of background pollution. Now I am feeling quite content honestly and am hoping that you will grade favorably upon this. The reason that actually attempting to partition and produce a cross product vector of say wind speed and a partition on wind direction... well it does not make sense statistically here for this N=500 dataset to really produce ridiculous bucketing or categorical variables because a categorical variable splitting in to a groups is like a one hot vectors is like a severe blowup in the number of input data points predictors which will be prone to over fitting and hacking. Furthermore I thought the simplest idea was that say we are near a point source of pollution or a road then basically the ambient wind speed itself usually has to do with dispersion in the air and so it would make sense that the higher the wind speed the lower the NO2 as was seen and interpreted. That is to say that cleaner air would be blowing in around the measurement point rather than that this wind hacks the instrument producing the measurements.