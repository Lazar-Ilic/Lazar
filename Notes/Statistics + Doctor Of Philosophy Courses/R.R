# So I now have a fantastic little local repository of files associated with my UT Austin course Statistical Inference which contains much content and is much too large to be useful as a single file in fact it is a folder of folders of files! So learn something from going through that corpus in my own very nice text editor!

?mean
# Get help of a particular function.
help.search('weighted mean')
# Search the help files for a word or phrase.
help(package='dplyr')
# Find help for a package.

str(iris)
# Get a summary of an object's structure.
class(iris)
# Find the class an object belongs to.

install.packages('dplyr')
# Download and install a package from CRAN.
library(dplyr)
# Load the package into the session, making all its functions available to use.
dplyr::select
# Use a particular function from a package.
data(iris)
# Load a built-in dataset into the environment.

getwd()
# Find the current working directory (where inputs are found and outputs are sent).
setwd('C://file/path')
# Change the current working directory. Use projects in RStudio to set the working directory to the folder you are working in. 

c(2, 4, 6) 
# 2 4 6 Join elements into a vector
2:6
# 2 3 4 5 6 An integer sequence
seq(2, 3, by=0.5)
# 2.0 2.5 3.0 A complex sequence
rep(1:2, times=3)
# 1 2 1 2 1 2 Repeat a vector
rep(1:2, each=3)
# 1 1 1 2 2 2 Repeat elements of a vector

# By Postion
x[4]
# The fourth element.
x[-4]
# All but the fourth.
x[2:4]
# Elements two to four.
x[-(2:4)]
# All elements except two to four.
x[c(1, 5)]
# Elements one and five.
x[x == 10]
# Elements which are equal to 10.
x[x < 0]
# All elements less than zero.
x[x %in% c(1, 2, 5)]
#Elements in the set 1, 2, 5.
x['apple']
# Element with name 'apple'3.

a=1
while(a<5){
	print(a)
	a=a+1
}

df=read.table('file.txt')
df <- read.csv('file.csv')
df <- read.csv('file.csv')

write.table(df, 'file.txt')
write.csv(df, 'file.csv')
save(df, file = 'file.Rdata')

# Converting between common data types in R. Can always go from a higher value in the table to a lower value

as.logical
# TRUE, FALSE, TRUE Boolean values (TRUE or FALSE).
as.numeric
# 1, 0, 1 Integers or floating point numbers.
as.character
# '1', '0', '1' Character strings. Generally preferred to factors.
as.factor
#'1', '0', '1', levels: '1', '0'
#Character strings with preset levels. Needed for some statistical models. 

log(x)
exp(x)
max(x)
min(x)
round(x,n) # Precision n Decimal Places
cor(x,y) # Correlation
sum(x)
mean(x)
median(x)
quantile(x)
rank(x)
var(x)
sd(x)

ls()
# List all variables in the environment.
rm(x)
# Remove x from the environment.
rm(list = ls())
# Remove all variables from the environment.

# You can use the environment panel in RStudio to browse variables in your environment.

# Matrices

m=matrix(x, nrow = 3, ncol = 3)
# Create a matrix from x.
m[2,]
# Select a row
m[,1]
# Select a column
m[2,3]
# Select an element
t(m)
# Transpose 
m %*% n
# Matrix Multiplication 
solve(m, n)
# Find x in: m * x = n

l=list(x = 1:5, y = c('a', 'b'))
# A list is a collection of elements which can be of different types. 

l[[2]]
# Second element of l.
l[1]
# New list with only the first element.
l$x
# Element named x.
l['y']
# New list with only element named y.

df=data.frame(x = 1:3, y = c('a', 'b', 'c'))
# A special case of a list where all elements are the same length.

# Understanding A Data Frame
View(df)
# See the full data frame.
head(df)
# See the first 6 rows.

rnorm
rpois
rbinom
runif

dnorm
dpois
dbinom
dunif

pnorm
ppois
pbinom
punif

qnorm
qpois
qbinom
qunif

plot(x)
plot(x,y)
hist(x)

lm(y ~ x, data=df)
# Linear model.
glm(y ~ x, data=df)
# Generalised linear model.
summary
#Get more detailed information out a model.
prop.test
# Test for a difference between proportions.
aov
# Analysis of variance.
t.test(x, y)
# Perform a t-test for difference between means.
pairwise.t.test
# Perform a t-test for paired data.

# Applied Statistics

# I am under the impression that this is bona fide not a flagrant violation of uni policy.

# Create a Vector of Data
x=c(3,4,5)
y=c(5,7,9)
# Create a Table, Barplot, Piechart
table(x)
barplot(table(x))
pie(table(x))
# Summary, Mean, Variance, Standard Deviation, Histogram
summary(x)
mean(x)
var(x)
sd(x)
hist(x)
# Boxplot Side By Side
boxplot(x1,x2,x3)
# Normal Probability Q-Q Plot
qqnorm(x)
# Create Standardized Version of x
z=(x-mean(x))/sd(x)
# Scatterplot and Correlation
plot(x,y)
cor(x,y)
# Linear Model and Plot Residuals
lm(y~x)
alm=lm(y~x)
plot(residuals(alm)~predict(alm))
qqnorm(residuals(alm))
summary(lm(y~x))
# Re Expression
a=log(x)
lm(log(y)~x)
# Generate k Random Integers in [1,2,...,n] With/Without Repeat e.g.
Sample(1:n,k,replace=T)
Sample(1:n,k)
# pdfs and cdfs give P(X=x) and P(X≤x)
dgeom(x,p)
pgeom(x,p)
dbinom(x,n,p)
pbinom(x,n,p)
dpois(x,lambda)
ppois(x,lambda)
dnorm(x,mu,sig)
pnorm(x,mu,sig)
dexp(x,t)
pexp(x,t)
# Example Proportion Test p=0.5 vs. p≠0.5 for 260/500
# "two.sided" or "less" or "greater"
prop.test(x,n,[p=NULL],alternative=c("two.sided"), conf.level=0.95, correct=FALSE)
prop.test(260,500,0.5,alternative=c("two.sided"), conf.level=0.95, correct=FALSE)
# t-Test for Mean e.g.
t.test(x,alternative=c("two.sided"),mu=)
# Chi-Squared Test
chisq.test(x,p=prob)
chisq.test(con.table)
# Linear Regression Project
percfull=100*(fulltime)/(fulltime+parttime)
plot(phd,gradrate,main="Faculty PHD and Graduation",xlab="Faculty PHD Percentage",ylab="Graduation Rate")
plot(percfull,gradrate,main="Percentage Fulltime and Graduation",xlab="Percentage Full Time",ylab="Graduation Rate")
model=lm(gradrate~phd+percfull)
summary(model)
plot(model$fitted.values,model$residuals,main="Residuals for Graduation Rate Model",ylab="Residual",xlab="Estimated Graduation Rate",pch=10)
hist(model$residuals)
# HW1
barplot(matrix(c(322,280,711),nr=1),names=c("1st", "2nd", "3rd"))
legend("topleft", c("Passengers By Class"))
# HW2
boxplot(a,b,names=c("US","Foreign"))
# HW3
hist(a)
qqnorm(a)
qqline(a)
# HW7
plot(LifeE,Income)
lm(Income ~ LifeE)
lm(formula = Income ~ LifeE)
abline(lm(Income ~ LifeE))
cor(LifeE,Income)

# Probability Models

x=1+100
x=3+5*2
x=16^1.346
if(x==0){ # !=    <    >    <=    >=
	y=1
}
else if(x<0){
	y=2
}
else{
	y=3
}
x=sin(1) # Radians
x=asin(1) # arcsin also acos and atan functions.
x=log(5)
x=log2(100)
x=exp(0.5) # e^(0.5)

af=function(a){
	for(i in 1:a){
		b=i^2
		print(b)
	}
}

bf=function(a=1,b=2){ # Lazy Variables
	print(a)
	print(b)
}

bf(3,4)
# 3 4
bf(3)
# 3 2
bf(,3)
# 1 4

# Dummy Variable Encoding Example

# weekdaymorningbegin is an example of a parametrized variable that could be optimised as one of the variable in a model. In this particular case well we'll put it this way, there may have been a little bit of over fitting involved and suboptimal models with suboptimal inputs in terms of resolution because many many many things can be different on weekdays and weekends.

traindata$weekdaymorning=ifelse(1<=traindayindex%%7 & traindayindex%%7<=5 & weekdaymorningbegin<=traintimeofday & traintimeofday<=weekdaymorningend,1,0)