a,b,c,d,e,f,g,h=map(int,input().split())
import numpy as np
import scipy.integrate as integrate
def f1(x):
    return min(h,max(f,a*x*x+b*x+c+d))-max(f,min(h,a*x*x+b*x+c-d))
print((h-f)*(g-e)-integrate.quad(f1,e,g)[0])

# Other Submission:

import scipy.integrate as integrate

y=list(map(int,input().split()))

a=y[0]
b=y[1]
c=y[2]
d=y[3]
e=y[4]
f=y[5]
g=y[6]
h=y[7]

# integral from -4 to 1 of min(1,max(-5,x^2+x-2+3))-max(-5,min(1,x^2+x-2-3)) For example in WolframAlpha. In general. In this particular polynomial degree <=4 setting I think there exists a relatively simple lengthy boolean-filled 1-liner solution by discretely solving for actual relevant intervals upon which to formally integrate and evaluate to the precise rational errorless answer representation. Manipulate the inequalities properly and this is a simple O[1] idea.

#a=1
#b=1
#c=-2
#d=3
#e=-4
#f=-5
#g=1
#h=1

def f1(x):
    return min(h,max(f,a*x*x+b*x+c+d))-max(f,min(h,a*x*x+b*x+c-d))
print((h-f)*(g-e)-integrate.quad(f1,e,g)[0])