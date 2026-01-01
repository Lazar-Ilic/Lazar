# SDS 383D

Welcome to SDS 383D for Spring 2022, a Ph.D.-level course on statistical modeling.  All course materials can be found through this GitHub page.  

Some course logistics   
- Instructor: James Scott, <http://jgscott.github.com>  
- Meets: Mondays and Wednesday, 1:00 to 2:30 PM
- Classroom: UTC 4.120
- Office hours: Tuesday, 1-2 PM, via Zoom (link on Canvas).  Wednesdays in person, 2:30-3:30 PM, CBA 6.478.    

## Exercises 

[You can find all the exercises here.](exercises/)  I'll post them as they become relevant throughout the semester.


## About the course

This course is about building probabilistic models for real-world systems.  Our approach will _primarily_, although not exclusively, be Bayesian.

Formally, this course has SDS 383C as a prerequisite.  But plenty of students have succeeded in the past without having taken that course.  So here's a list of substantive prerequisites.  To succeed, you need to know the following topics:   
- linear algebra  
- how to perform basic data-analysis tasks in R or Python, at the level of Lessons 1-7 in [this undergraduate text](https://bookdown.org/jgscott/DSGI/).  
- multivariable calculus.  To be more specific, we lean often on gradients, Hessians, and Jacobeans, but not on more physics-relevant tools like divergence, curl, Green's theorem, etc.  
- undergraduate probability (measure theory isn't necessary).  You should be comfortable writing down PDFs and understanding what they mean.  You should have seen moment-generating functions and the change-of-variable formula involving Jacobeans.   
- basic inferential statistics: sampling distributions, confidence intervals, p-values, etc.  
- basic regression, at the level of Lessons 14-15 of [this undergraduate text](https://bookdown.org/jgscott/DSGI/)    

If you have any doubt about your preparation for this course, feel free to chat with me on the first day.  

This is a blend between a traditional lecture-based course and a flipped classroom.  Some of the time is spend on lectures in class.  But a lot of the other class time is spent with you in charge.  You will work on the [exercises outside of class](exercises/).  When you come to class, you will share what you've done, and benefit from understanding what others have done.   We will end up covering less than in an exclusively lecture-based course.  But what you learn, you will learn deeply.  The trade-off is more than worth it.   


## Grading

Your grade consists of three pieces: 30% exercises, 30% peer evaluation and 40% final project.

### Exercises

You will turn in a complete copy of all exercises at the end of the semester, in a single PDF document.  

### Peer evaluation

During the semester, you will be expected to do three main things on a recurring basis:  
1) Work on the exercises outside of class, and document your code so that someone else can follow it.  You will post all of your code and materials on your GitHub page.   
2) Present your work in front of class, either up at the board or by hooking up your computer and showing us your code and results.  
3) Provide at least three peer reviews of others' code and analyses from their GitHub pages, so that everyone gets feedback.  You'll do this about once every 3-4 weeks, and I'll assign the reviewers randomly.  

At the end of the semester, everyone will (privately) turn in a document that summarizes their assessment of each person's contribution to the course.  Those who have helped others to learn (e.g. by presenting excellent work in class or by offering thoughtful peer reviews, will presumably get good evaluations).  I'll use these summaries to set the peer-evaluation grades.  Note: I'll still have the final say here.  

### Final project  

Pick some relevant topic that interests you.  Clear it with me ahead of time, and then do it.  Basically, I trust you to choose something that will optimize your own learning experience, and that will dovetail with your research and educational goals.  It certainly can overlap with your own research.  Examples:  

1) Analyze a data set from your own research, using techniques from class or closely related techniques.  
2) Invent a new technique and show how awesome it is.  
3) Prove something interesting about a procedure or algorithm related to what we're studying (admittedly unlikely, but certainly possible!)  
4) Read a paper, or a group of related papers, that expands on some topic we've covered in class.  Implement the method(s) and benchmark it (them) against something else.  

Final projects are due on the last class day of the semester: Friday, May 6.  

Note: you should feel free to work either solo or in pairs for the projects.



## Requirements  

1) Set up a [GitHub](www.github.com) account if you don't already have one.  

2) Learn how to use GitHub, either via the command line or through a source-code browser like GitHub Desktop or SourceTree.   

3) Optional, but recommended: bring your own data!  


## Topics

Here's a partial list of topics that we'll cover.   

- The multivariate normal distribution  
- GLMs  
- Linear smoothing and local regression
- Gaussian processes   
- Hierarchical models and multi-level regression  
- Inference for hyperparameters in hierarchical models  
- Bayesian time-series and/or spatial models
- Mixture models and/or latent factor models (if time)

There are no formally required textbooks, but here are three recommended references:  

- [Data Analysis Using Regression and Multilevel/Hierarchical Models](http://www.stat.columbia.edu/~gelman/arm/), by Andrew Gelman and Jennifer Hill.  An e-book version is available through the [UT Library website](http://www.lib.utexas.edu).  
- _Generalized Linear Models_ by McCullagh and Nelder  
- _All of Statistics_ by Larry Wasserman.   

