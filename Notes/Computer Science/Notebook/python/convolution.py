
import math
import sympy
a=[1000000000 for c in range(1048576)]
b=[1000000000 for c in range(1048576)]
c=sympy.discrete.convolutions.convolution_ntt(a,b,prime=18*2**32+1)
print(c[999999]) #77121312980
# Confirmed ACcepted by WolframAlpha: 10^24 modulo (18*2^32+1)
# OKOKOK so this code right here using the sympy auxiliary library takes around uh like 72s means a solution with 500 to 5000 such calls at n ~10^8 is basically way too Time Limit Exceeded for comfort. We could easily be talking ugh like a 100-days runtime in the background. But OKOKOK it is sharper rather than maintaining values in uh the uh 10^26 range of Decimal significance to instead take uh modulo p for like 3 p values around 10^9 or 10^10 and then upstream downstream merge with Chinese Remainder Theorem at the end as needed to be sure.

# Uh OKOKOK
import math
import sympy
a=[1000000000 for c in range(134217728)]
b=[1000000000 for c in range(134217728)]
c=sympy.discrete.convolutions.convolution_ntt(a,b,prime=18*2**32+1)
d=sympy.discrete.convolutions.convolution_ntt(a,b,prime=43*2**32+1)
e=sympy.discrete.convolutions.convolution_ntt(a,b,prime=48*2**32+1)

#OKOKOK in general with more auxiliary memory:
import math
import sympy
a1=[1000000000 for c in range(2**27)]#134217728
b1=[1000000000 for c in range(2**27)]
a2=[1000000000 for c in range(2**27)]#134217728
b2=[1000000000 for c in range(2**27)]
a3=[1000000000 for c in range(2**27)]#134217728
b3=[1000000000 for c in range(2**27)]
c1=sympy.discrete.convolutions.convolution_ntt(a1,b1,prime=18*2**32+1)
c2=sympy.discrete.convolutions.convolution_ntt(a2,b2,prime=43*2**32+1)
c3=sympy.discrete.convolutions.convolution_ntt(a3,b3,prime=48*2**32+1)
print(c1[999999],c2[999999],c3[999999]) # Ought to produce those 3 remainders of 10^24 modulo those 3 relevant topical primes p... which can then be simply merged back together later utilising the Chinese Remainder Theorem and then that taken modulo the initial p-value as needed for the task. In fact we may simply run the initial program 3 times to generate those 3 relevant values prior to a single 1-time ad hoc Sherlock de novo Mathematics forces final break up break down ping.

# This is a fairly interesting task to consider what is going on under-the-hood with respect to precision in the scipy.signal.convolve() call here and the usual Python Decimal auxiliary library. Frankly it might be worth consdiering executing ~10^15 operations via optimised Karatsuba in C especially if one is aiming for convolution modulo p and is concerned even about memory performance potentially on a 128GB RAM machine.
from decimal import *
import math
import scipy
getcontext().prec=32
a=[Decimal(10000000000) for c in range(100000)]
b=[Decimal(10000000000) for c in range(100000)]
c=scipy.signal.convolve(a,b)
print(math.floor(c[99999]))
# Hoping for precisely 10^25 here in reasonable run time but the run time is in fact not really reasonable or viable for some of my current algorithms though it is actually accurate which is A OK and pretty solidly interesting. As for the actual RAM usage here might have spiked up to around uh 16GB so the viability of certain like 128-bit computations does come in to question here really.

from decimal import *
import math
import scipy
getcontext().prec=28
a=[Decimal(1000000000) for c in range(32768)]
b=[Decimal(1000000000) for c in range(32768)]
c=scipy.signal.convolve(a,b)
print(math.floor(c[9999]))
#10000000000000000000000
print(c[9999])
#10000000000000000000000
# Umm OKOKOK I mean one would think that this run time right here would be better and more performant but even it is taking quite a long time really uh 88s 88000ms is pretty mediocre frankly. But at least it will compute so I will uh note this and consider RAM usage and other factors I highly doubt that the uh C or C++ Boost auxiliary libraries would really help me if say I conveniently needed to execute around 1500 or so uh n ~10^8 such convolutions on underlyings of size around 10^9 at precision around 28 digits say.

from decimal import *
import math
import scipy
getcontext().prec=28
a=[Decimal(1000000000) for c in range(131072)]
b=[Decimal(1000000000) for c in range(131072)]
c=scipy.signal.convolve(a,b)
print(math.floor(c[99999]))
#100000000000000000000000
# OKOKOK so this takes 2192s=36m32s and the run time blowup here is much worse than I might have actually thought a priori due to the underlying value blowup which itself might be a huge issue and that comes directly in to the whole trick of the complex double cyclicity argumentations surround Number Theoretic Transformations and Fast Fourier Transformations modulo p and whether or not I can dig up find a very fast C|C++ Faster Fast Fourier Transformation Modulo p code lying around somewhere...:
# https://dsp.stackexchange.com/questions/41770/fast-accurate-convolution-algorithm-like-fft-for-high-dynamic-range
# https://scicomp.stackexchange.com/questions/23867/c-libraries-for-fast-fourier-transform-in-high-
# This particular Stack post here looks like a mighty fine candidate if I want to produce reasonably fast robust modulo p results in a C file for sizes on the order of 10^8 or so and 10^15 operations maybe 10^16.

# As seen in this example it can be tricky to get 26 digits of precision moving from native underlying 80-bit longdouble long double precision in C towards a fast C++ Boost auxiliary library 128-bit implementation which will not Memory Limit Exceeded for n ~ 10^8 on a 32GB RAM machine.
import math
import numpy as np
import scipy

a=np.ones(100000000)
b=np.ones(100000000)
for c in range(100000000):
  a[c]=1000000000
for c in range(100000000):
  b[c]=1000000000
c=a
d=b
a=np.longdouble(c)
b=np.longdouble(d)
c=scipy.signal.convolve(a,b)
#c=np.convolve(a,b) # Takes > 600s
print(math.floor(c[99999999]))

# Wrong but very rapid...
import math
import numpy as np
import scipy

a=np.ones(1000000)
b=np.ones(1000000)
for c in range(1000000):
  a[c]=1000000000
for c in range(1000000):
  b[c]=1000000000
c=a
d=b
a=np.longdouble(c)
b=np.longdouble(d)
c=scipy.signal.convolve(a,b)
print(math.floor(c[999999]))

# Right... but too small ugh...
import math
import numpy as np
import scipy

a=np.ones(1000000)
b=np.ones(1000000)
for c in range(1000000):
  a[c]=100000
for c in range(1000000):
  b[c]=100000
c=a
d=b
a=np.longdouble(c)
b=np.longdouble(d)
c=scipy.signal.convolve(a,b)
print(math.floor(c[999999]))
# 10000000000000000