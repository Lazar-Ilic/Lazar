

# Exercises

## Exercises 1: Preliminaries

The goals of [Exercises 1](exercises01-SDS383D.pdf) are: 
- to provide you with a review of Bayesian updating in simple conjugate families  
- to treat the multivariate normal distribution in some depth.  Since this distribution is so fundamental to working with hierarchical Bayesian models, it's worth the effort.  

By January 31, please complete the first two sections, on "Bayesian inference in simple conjugate families" and "The multivariate normal distribution".

By February 2, please complete the section on "Multiple regression: three classical principles for inference."  

By Feb 7: please have the section on "Some practical details" ready for class.  Be ready to show code.  


## Exercises 2: GLMs

The goals of [Exercises 2](exercises02-SDS383D.pdf) are: 
- to review (or, depending on your prior training, introduce) exponential families.    
- to construct and understand the basic properties of generalized linear models (GLMs)  
- to fit GLMs "from scratch," comparing gradient descent and Newton's method.  

Expected timeline:  
- By Feb 9: Exponential families, A through D  
- By Feb 14: Generalized linear models, A through C  
- By Feb 16: Fitting GLMs, A through C  
- By Feb 21: Fitting GLMs, D through G  

## Exercises 3: Bayes and the Gaussian linear model  

The goals of [Exercises 3](exercises03-SDS383D.pdf) are: 
- to introduce the normal/inverse-gamma conjugate prior for a location-scale model.    
- to construct and fit a simple Bayesian linear model from scratch, based on normal/inverse-gamma conjugacy.  
- to introduce hierarchical modeling, in the form of a regression model with heteroskedastic error.  

Expected timeline:  
- By Feb 23: the section on "A simple Gaussian location model"  
- By Feb 28: Basics and Example section of "The conjugate Gaussian linear model"  
- By Mar 2: A heavy-tailed error model of "The conjugate Gaussian linear model"  



## Exercises 4: Intro to Hierarchical Models  

The goal of [Exercises 4](exercises04-SDS383D.pdf) is to introduce hierarchical/multilevel models.  We'll start in the context of estimating group-level means.   

The following two papers provide useful background for this section:  

- [Prior distributions for variance parameters in hierarchical models](http://www.stat.columbia.edu/~gelman/research/published/taumain.pdf) by Gelman  
- [On the half-Cauchy prior for a global scale parameter](http://projecteuclid.org/euclid.ba/1354024466), by Polson and Scott.   

Expected timeline:  
- By Mar 7: Math tests example  
- By Mar 9: Blood pressure example  



## Exercises 5: Hierarchical linear models

The goals of [Exercises 5](exercises05-SDS383D.pdf) are to practice fitting hierarchical regression models with a simple two-level grouping structure.  


## Exercises 6: Linear smoothing and Gaussian processes  

The goal of [Exercises 6](exercises06-SDS383D.pdf) is to equip you with some simple building blocks for nonlinear curve fitting and smoothing.  Yes, it turns out that "linear smoothing" is used for nonlinear curve fitting.  This sounds like a contradiction, but you'll see what it entails and why it makes sense.  Here both Bayesian and frequentist approaches feature equally.  Linear smoothers lead us to Gaussian processes, a natural class of Bayesian models for a random function or spatial process.

In the interests of pacing, you are not required to complete the "basic concepts" section at the beginning.  If there's time, I will present this material in class.  

Expected timeline:  
- By April 6: Curve fitting by linear smoothing, cross validation.  Note that to keep the workload from getting unreasonable, I've made the proof of the "leave one out lemma" optional.  
- By April 11: Local polynomical regression, A-D  
- By April 13: Local polynomical regression, E-G   
- By April 18: Gaussian processes, In nonparametric regression and spatial smoothing A-C  
- By April 20: In nonparametric regression and spatial smoothing, D-F  


<!-- 
## Exercises 2: Bayes and the Gaussian linear model  

The goal of [Exercises 2](exercises02-SDS383D.pdf) is to get you comfortable with the use of conjugate priors in Gaussian models.  It finishes with a cool use of hierarchical modeling to fit a regression model with heavy-tailed errors.  


## Exercises 3: Linear smoothing and Gaussian processes



There are a handful of optional problems in these exercises (clearly marked), which I will present in class myself. 

- [The normal-Wishart prior](https://en.wikipedia.org/wiki/Normal-inverse-Wishart_distribution), from Wikipedia (or any similar source).  Kevin Murphy also has [some useful notes](http://www.cs.ubc.ca/~murphyk/Papers/bayesGauss.pdf) that summarize this distribution; see Section 8 in particular.   
- [Bayesian analysis of binary and polychotomous response data](http://www.stat.cmu.edu/~brian/905-2009/all-papers/albert-chib-1993.pdf), by Albert and Chib.  
- [Fitting mixed-effects models by REML](http://web.mit.edu/xiuming/www/docs/tutorials/ReML.pdf).  [How it works in the lme4 R package](https://cran.r-project.org/web/packages/lme4/vignettes/Theory.pdf).  
- [Simon Jackman's paper on spatial voting models](https://academic.oup.com/pan/article-abstract/9/3/227/1453708/Multidimensional-Analysis-of-Roll-Call-Data-via).  You can find an application of this framework in [our paper on family-planning legislation in the Texas Legislature.](https://www.ncbi.nlm.nih.gov/pubmed/26794846)  

 -->

