# Python has use value despite appearing inferior to C/C++.

# These are useful import statements which begin many files.

import numpy as np
import scipy as sci
import pandas as pd
import sklearn

# Data Structures

# Integer
# Bitwise Operations: 1

a=1<<5
a=b&c  # bitwise and
a=b|c  # bitwise or
a=~b   # complement
a=b^c  # bitwise exclusive or
a=b**c # exponent b^c

# Array
# Find: 1
# Insert Back: 1
# Delete Back: 1
# Insert: n
# Delete: n

av=[0 for a in range(10)] # creates a list of 0s of length 0
b=av[5] # find the 6th element of the list av
av[5]=1 # change the value to 1
av.append(2) # inserts the new value 2 to the end
b=len(av) # the length of the list av
av[1:] # the subarray from index 1 onwards
b=av.index(0) # the index of the first element with value 0
b=av.count(0) # the number of elements with value 0
av.pop(len(av)-1) # removes the element at position len(av)-1
av.reverse() # reverses the list
print(av) # prints the list
av.clear() # removes all elements from list

# Set
# Insert: log n
# Count: log n
# Delete: log n
# Iterate

# Unordered Hash Set
# Insert: 1
# Count: 1
# Delete: 1

# Python automatically handles increasing input and hash function vector size so that there is a very low P of collisions.

auset={}
auset.add(3) # inserts the element 3
auset.discard(1) # removes the element 1 if it exists
if 3 in auset: # boolean count
	print(3)
print(auset)
cuset=auset-buset # set difference
cuset=auset|buset # set union
cuset=auset&buset # set intersection
cuset=auset^buset # set exclusive or

# Order Statistic Set
# Insert: log n
# Count: log n
# Delete: log n
# Find By Order: log n
# Order Of Key: log n

# Map
# Find: log n
# Insert: log n
# Delete: log n
# Iterate

# Unordered Hash Map
# Find: 1
# Insert: 1
# Delete: 1

# In Python this is insertion order.

amsi={} # a map from strings to integers
avs=['apple','apple','carrot','banana'] # a vector of strings
for bs in avs: # loop through the input vector
	if bs not in amsi: # check if a key exists in map
		amsi[bs]=1
	else:
		amsi[bs]+=1 # iterate the value
print(len(amsi)) # number of keys in map
print(amsi) # prints out the map
bvs=list(amsi) # list of keys
print(bvs)

# Deque
# Find Front: 1
# Find Back: 1
# Insert Front: 1
# Insert Back: 1
# Delete Front: 1
# Delete Back: 1

# Queue
# Find Front: 1
# Find Back: 1
# Insert Back: 1
# Delete Front: 1

# Priority Queue
# Find Extremum: 1
# Delete Extremum: log n
# Insert: log n

import heapq

heapq.heapify(topk)
heapq.heappush(topk,[hashtags[hashtag],topk[0][1]])
heapq.heappop(topk)

# Stack
# Find Top: 1
# Delete Top: 1
# Insert Top: 1

# Lazy Segment Tree
# Range Query: log n
# Range/Value Update: log n

# Code Claimed To Transform Input Matrix Into Mean 0 Variance 1
# For Principal Component Analysis etc.
# I Might Always Do This After Exploratory Data Analysis, Simpler, Easier

import pandas as pd
from sklearn import preprocessing

x = df.values # returns a numpy array
min_max_scaler = preprocessing.MinMaxScaler()
x_scaled = min_max_scaler.fit_transform(x)
df = pd.DataFrame(x_scaled)

# And

# define a method to scale data, looping thru the columns, and passing a scaler
def scale_data(data, columns, scaler):
    for col in columns:
        data[col] = scaler.fit_transform(data[col].values.reshape(-1, 1))
    return data

# Linear Regression Example
# Kaggle Has Great Visualizations Examples To Learn From

import pandas as pd
import matplotlib.pyplot as plt
  
Stock_Market={ # This Is A Map From Name Of Vector To Vector
'Year': [2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016],
'Month': [12, 11,10,9,8,7,6,5,4,3,2,1,12,11,10,9,8,7,6,5,4,3,2,1],
'Interest_Rate': [2.75,2.5,2.5,2.5,2.5,2.5,2.5,2.25,2.25,2.25,2,2,2,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75],
'Unemployment_Rate': [5.3,5.3,5.3,5.3,5.4,5.6,5.5,5.5,5.5,5.6,5.7,5.9,6,5.9,5.8,6.1,6.2,6.1,6.1,6.1,5.9,6.2,6.2,6.1],
'Stock_Index_Price': [1464,1394,1357,1293,1256,1254,1234,1195,1159,1167,1130,1075,1047,965,943,958,971,949,884,866,876,822,704,719]        
}

# Create A Pandas DataFrame From Such A Dataset
df = pd.DataFrame(Stock_Market,columns=['Year','Month','Interest_Rate','Unemployment_Rate','Stock_Index_Price'])

# Simple Plotting Function Of Chosen Input Vectors
plt.scatter(df['Interest_Rate'], df['Stock_Index_Price'], color='red')
plt.title('Stock Index Price Vs Interest Rate', fontsize=14)
plt.xlabel('Interest Rate', fontsize=14)
plt.ylabel('Stock Index Price', fontsize=14)
plt.grid(True)
plt.show()

import pandas as pd
import matplotlib.pyplot as plt
  
Stock_Market = {
'Year': [2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016],
'Month': [12, 11,10,9,8,7,6,5,4,3,2,1,12,11,10,9,8,7,6,5,4,3,2,1],
'Interest_Rate': [2.75,2.5,2.5,2.5,2.5,2.5,2.5,2.25,2.25,2.25,2,2,2,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75],
'Unemployment_Rate': [5.3,5.3,5.3,5.3,5.4,5.6,5.5,5.5,5.5,5.6,5.7,5.9,6,5.9,5.8,6.1,6.2,6.1,6.1,6.1,5.9,6.2,6.2,6.1],
'Stock_Index_Price': [1464,1394,1357,1293,1256,1254,1234,1195,1159,1167,1130,1075,1047,965,943,958,971,949,884,866,876,822,704,719]        
}
 
df = pd.DataFrame(Stock_Market,columns=['Year','Month','Interest_Rate','Unemployment_Rate','Stock_Index_Price'])
 
plt.scatter(df['Unemployment_Rate'], df['Stock_Index_Price'], color='green')
plt.title('Stock Index Price Vs Unemployment Rate', fontsize=14)
plt.xlabel('Unemployment Rate', fontsize=14)
plt.ylabel('Stock Index Price', fontsize=14)
plt.grid(True)
plt.show()

import pandas as pd
from sklearn import linear_model
import statsmodels.api as sm

Stock_Market = {
'Year': [2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2017,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016,2016],
'Month': [12, 11,10,9,8,7,6,5,4,3,2,1,12,11,10,9,8,7,6,5,4,3,2,1],
'Interest_Rate': [2.75,2.5,2.5,2.5,2.5,2.5,2.5,2.25,2.25,2.25,2,2,2,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75,1.75],
'Unemployment_Rate': [5.3,5.3,5.3,5.3,5.4,5.6,5.5,5.5,5.5,5.6,5.7,5.9,6,5.9,5.8,6.1,6.2,6.1,6.1,6.1,5.9,6.2,6.2,6.1],
'Stock_Index_Price': [1464,1394,1357,1293,1256,1254,1234,1195,1159,1167,1130,1075,1047,965,943,958,971,949,884,866,876,822,704,719]        
}

df = pd.DataFrame(Stock_Market,columns=['Year','Month','Interest_Rate','Unemployment_Rate','Stock_Index_Price'])
# Clearly Titled Input/Predictor And Output/Predicted Vectors
X = df[['Interest_Rate','Unemployment_Rate']] # here we have 2 variables for multiple regression. If you just want to use one variable for simple linear regression, then use X = df['Interest_Rate'] for example.Alternatively, you may add additional variables within the brackets
Y = df['Stock_Index_Price']

# With sklearn
regr = linear_model.LinearRegression()
regr.fit(X, Y)

print('Intercept: \n', regr.intercept_)
print('Coefficients: \n', regr.coef_)

# Prediction with sklearn
New_Interest_Rate = 2.75
New_Unemployment_Rate = 5.3
print ('Predicted Stock Index Price: \n', regr.predict([[New_Interest_Rate ,New_Unemployment_Rate]]))

# with statsmodels
X = sm.add_constant(X) # adding a constant

# Can Run Our Model On Whatever Test Dataset For X Input We Want
# This Is Where You Produce Predictions
 
model = sm.OLS(Y, X).fit()
predictions = model.predict(X) 
 
print_model = model.summary()
print(print_model)

# L2 Ridge Example

import matplotlib.pyplot as plt
import numpy as np 
import pandas as pd
import matplotlib

matplotlib.rcParams.update({'font.size': 12})

from sklearn.datasets import load_boston
from sklearn.cross_validation import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import Ridge

boston=load_boston()
boston_df=pd.DataFrame(boston.data,columns=boston.feature_names)

#print boston_df.info()
# add another column that contains the house prices which in scikit learn datasets are considered as target

boston_df['Price']=boston.target

#print boston_df.head(3)

newX=boston_df.drop('Price',axis=1)
print newX[0:3] # check 
newY=boston_df['Price']

#print type(newY)# pandas core frame

X_train,X_test,y_train,y_test=train_test_split(newX,newY,test_size=0.3,random_state=3)
print len(X_test), len(y_test)
lr = LinearRegression()
lr.fit(X_train, y_train)
rr = Ridge(alpha=0.01) 

# higher the alpha value, more restriction on the coefficients; low alpha > more generalization,
# in this case linear and ridge regression resembles

rr.fit(X_train, y_train)
rr100 = Ridge(alpha=100) #  comparison with alpha value
rr100.fit(X_train, y_train)
train_score=lr.score(X_train, y_train)
test_score=lr.score(X_test, y_test)
Ridge_train_score = rr.score(X_train,y_train)
Ridge_test_score = rr.score(X_test, y_test)
Ridge_train_score100 = rr100.score(X_train,y_train)
Ridge_test_score100 = rr100.score(X_test, y_test)
plt.plot(rr.coef_,alpha=0.7,linestyle='none',marker='*',markersize=5,color='red',label=r'Ridge; $\alpha = 0.01$',zorder=7) 
plt.plot(rr100.coef_,alpha=0.5,linestyle='none',marker='d',markersize=6,color='blue',label=r'Ridge; $\alpha = 100$') 
plt.plot(lr.coef_,alpha=0.4,linestyle='none',marker='o',markersize=7,color='green',label='Linear Regression')
plt.xlabel('Coefficient Index',fontsize=16)
plt.ylabel('Coefficient Magnitude',fontsize=16)
plt.legend(fontsize=13,loc=4)
plt.show()

# L1 Lasso Example

import math 
import matplotlib.pyplot as plt 
import pandas as pd
import numpy as np

from sklearn.linear_model import Lasso
from sklearn.linear_model import LinearRegression
from sklearn.datasets import load_breast_cancer
from sklearn.cross_validation import train_test_split

cancer = load_breast_cancer()
#print cancer.keys()
cancer_df = pd.DataFrame(cancer.data, columns=cancer.feature_names)
#print cancer_df.head(3)
X = cancer.data
Y = cancer.target
X_train,X_test,y_train,y_test=train_test_split(X,Y, test_size=0.3, random_state=31)
lasso = Lasso()
lasso.fit(X_train,y_train)
train_score=lasso.score(X_train,y_train)
test_score=lasso.score(X_test,y_test)
coeff_used = np.sum(lasso.coef_!=0)

print "training score:", train_score 
print "test score: ", test_score
print "number of features used: ", coeff_used

lasso001 = Lasso(alpha=0.01, max_iter=10e5)
lasso001.fit(X_train,y_train)
train_score001=lasso001.score(X_train,y_train)
test_score001=lasso001.score(X_test,y_test)
coeff_used001 = np.sum(lasso001.coef_!=0)

print "training score for alpha=0.01:", train_score001 
print "test score for alpha =0.01: ", test_score001
print "number of features used: for alpha =0.01:", coeff_used001

lasso00001 = Lasso(alpha=0.0001, max_iter=10e5)
lasso00001.fit(X_train,y_train)
train_score00001=lasso00001.score(X_train,y_train)
test_score00001=lasso00001.score(X_test,y_test)
coeff_used00001 = np.sum(lasso00001.coef_!=0)

print "training score for alpha=0.0001:", train_score00001 
print "test score for alpha =0.0001: ", test_score00001
print "number of features used: for alpha =0.0001:", coeff_used00001

lr = LinearRegression()
lr.fit(X_train,y_train)
lr_train_score=lr.score(X_train,y_train)
lr_test_score=lr.score(X_test,y_test)

print "LR training score:", lr_train_score 
print "LR test score: ", lr_test_score

plt.subplot(1,2,1)
plt.plot(lasso.coef_,alpha=0.7,linestyle='none',marker='*',markersize=5,color='red',label=r'Lasso; $\alpha = 1$',zorder=7) # alpha here is for transparency
plt.plot(lasso001.coef_,alpha=0.5,linestyle='none',marker='d',markersize=6,color='blue',label=r'Lasso; $\alpha = 0.01$') # alpha here is for transparency

plt.xlabel('Coefficient Index',fontsize=16)
plt.ylabel('Coefficient Magnitude',fontsize=16)
plt.legend(fontsize=13,loc=4)

plt.subplot(1,2,2)

plt.plot(lasso.coef_,alpha=0.7,linestyle='none',marker='*',markersize=5,color='red',label=r'Lasso; $\alpha = 1$',zorder=7) # alpha here is for transparency
plt.plot(lasso001.coef_,alpha=0.5,linestyle='none',marker='d',markersize=6,color='blue',label=r'Lasso; $\alpha = 0.01$') # alpha here is for transparency
plt.plot(lasso00001.coef_,alpha=0.8,linestyle='none',marker='v',markersize=6,color='black',label=r'Lasso; $\alpha = 0.00001$') # alpha here is for transparency
plt.plot(lr.coef_,alpha=0.7,linestyle='none',marker='o',markersize=5,color='green',label='Linear Regression',zorder=2)

plt.xlabel('Coefficient Index',fontsize=16)
plt.ylabel('Coefficient Magnitude',fontsize=16)
plt.legend(fontsize=13,loc=4)
plt.tight_layout()
plt.show()

# Markov Chain Monte Carlo Integration Example

import numpy as np

def f1(x):
	return (15*x**3+21*x**2+41*x+3)**(1/4) * (np.exp(-0.5*x))

def montecarlouniform(func,a=0,b=1,n=1000):
	subsets=np.arange(0,n+1,n/10)
	steps=n/10
	u=np.zeros(n)
	for i in range(10):
		start=int(subsets[i])
		end=int(subsets[i+1])
		u[start:end]=np.random.uniform(low=i/10,high=(i+1)/10,size=end-start)
	np.random.shuffle(u)
	#plt.hist(u)
	#u=np.random.uniform(size=n)
	u_func=func(a+(b-a)*u)
	s=((b-a)/n)*u_func.sum()
	return s

approximation=montecarlouniform(f1,a=0,b=4,n=100)
print(approximation)

# *args and **kwargs Examples

def addition(a, b):
   return a + b

print(addition(3,4))
# 7

def addition(*c):
   result = 0
   for i in c:
      result += i
   return result

print(addition())
# 0
print(addition(1,4))
# 5
print(addition(1,7,3))
# 11

def addition(a, b=2): #a is positional, b is keyword argument
   return a + b

print(addition(1))
# 3

def addition(a, b): #a and b are positional arguments
   return a + b

print(addition(1))
# TypeError: addition() missing 1 required positional argument: 'b'

def arg_printer(a, b, *c):
   print(f'a is {a}')
   print(f'b is {b}')
   print(f'args are {c}')

arg_printer(3, 4, 5, 8, 3)
# a is 3
# b is 4
# args are (5, 8, 3)

# Importing/Exporting
np.loadtxt('file.txt') # From a .txt file
np.genfromtxt('file.csv',delimiter=',') # From a .csv file
np.savetxt('file.txt',arr,delimiter=' ') # Writes to a .txt file
np.savetxt('file.csv',arr,delimiter=',') # Writes to a .csv file

# Creating Arrays
np.array([1,2,3]) # 1 dimensional array
np.array([(1,2,3),(4,5,6)]) # 2 dimensional array
np.zeros(3) # 1D array of length 3 all values 0
np.ones((3,4)) # 3x4 array with all values 1
np.eye(5) # 5x5 I Identity Matrix array of 0 with 1 on diagonal
np.linspace(0,100,6) # Array of 6 evenly divided values from 0 to 100
np.arange(0,10,3) # Array of values from 0 to less than 10 with step 3 [0,3,6,9]
np.full((2,3),8) # 2x3 array with all values 8
np.random.rand(4,5) # 4x5 array of random floats between 0-1
np.random.rand(6,7)*100 # 6x7 array of random floats between 0-100
np.random.randint(5,size=(2,3)) # 2x3 array with random ints between 0-4

# Inspecting Properties
arr.size # Returns number of elements in arr
arr.shape # Returns dimensions of arr (rows,columns)
arr.dtype # Returns type of elements in arr
arr.astype(dtype) # Convert arr elements to type dtype
arr.tolist() # Convert arr to a Python list
np.info(np.eye) # View documentation for np.eye

# Copying/Sorting/Reshaping
np.copy(arr) # Copies arr to new memory
arr.view(dtype) # Creates view of arr elements with type dtype
arr.sort() # Sorts arr
arr.sort(axis=0) # Sorts specific axis of arr
two_d_arr.flatten() # Flattens 2D array two_d_arr to 1D
arr.T # Transposes arr
arr.reshape(3,4) # Reshapes arr to 3 rows, 4 columns without changing data
arr.resize((5,6)) # Changes arr shape to 5x6 and fills new values with 0

# Adding/Removing Elements
np.append(arr,values) # Appends values to end of arr
np.insert(arr,2,values) # Inserts values into arr before index 2
np.delete(arr,3,axis=0) # Deletes row on index 3 of arr
np.delete(arr,4,axis=1) # Deletes column on index 4 of arr

# Combining/Splitting
np.concatenate((arr1,arr2),axis=0) # Adds arr2 as rows to the end of arr1
np.concatenate((arr1,arr2),axis=1) # Adds arr2 as columns to end of arr1
np.split(arr,3) # Splits arr into 3 sub-arrays
np.hsplit(arr,5) # Splits arr horizontally on the 5th index

# Indexing/Slicing/Subsetting
arr[5] # Returns the element at index 5
arr[2,5] # Returns the 2D array element on index [2][5]
arr[1]=4 # Assigns array element on index 1 the value 4
arr[1,3]=10 # Assigns array element on index [1][3] the value 10
arr[0:3] # Returns the elements at indices 0,1,2 (On a multidimensional array returns subarrays 0,1,2)
arr[0:3,4] # Returns the elements on rows 0,1,2 at column 4
arr[:2] # Returns the elements at indices 0,1 (On a 2D array: returns rows 0,1)
arr[:,1] # Returns the elements at index 1 on all rows
arr<5 # Returns an array with boolean values
(arr1<3) & (arr2>5) # Returns an array with boolean values
~arr # Inverts a boolean array
arr[arr<5] # Returns array elements smaller than 5

# Scalar Math
np.add(arr,1) # Add 1 to each array element
np.subtract(arr,2) # Subtract 2 from each array element
np.multiply(arr,3) # Multiply each array element by 3
np.divide(arr,4) # Divide each array element by 4 (returns np.nan for division by zero)
np.power(arr,5) # Raise each array element to the 5th power

# Vector Math
np.add(arr1,arr2) # Elementwise add arr2 to arr1
np.subtract(arr1,arr2) # Elementwise subtract arr2 from arr1
np.multiply(arr1,arr2) # Elementwise multiply arr1 by arr2
np.divide(arr1,arr2) # Elementwise divide arr1 by arr2
np.power(arr1,arr2) # Elementwise raise arr1 raised to the power of arr2
np.array_equal(arr1,arr2) # Returns True if the arrays have the same elements and shape
np.sqrt(arr) # Square root of each element in the array
np.sin(arr) # Sine of each element in the array
np.log(arr) # Natural log of each element in the array
np.abs(arr) # Absolute value of each element in the array
np.ceil(arr) # Rounds up to the nearest int
np.floor(arr) # Rounds down to the nearest int
np.round(arr) # Rounds to the nearest int

# Statistics
np.mean(arr,axis=0) # Returns mean along specific axis
arr.sum() # Returns sum of arr
arr.min() # Returns minimum value of arr
arr.max(axis=0) # Returns maximum value of specific axis
np.var(arr) # Returns the variance of array
np.std(arr,axis=1) # Returns the standard deviation of specific axis
arr.corrcoef() # Returns correlation coefficient of array

# Not totally clear to me that applying arbitraryish general maths functions to these numpy array structures is quite as easy as it might be in the R language where one can simply write out whatever function in vectorized format but I think here list comprehensions work relatively compactly say if I wanted to produce a vector which contained each element raised to the 1.273th power then I could simply even do like:

def afunction(a,power=1.237):
	return a**power
a=np.array([1,2,3,4,5])
avectorizedfunction=np.vectorize(afunction)
b=avectorizedfunction(a)
print(b)
b=avectorizedfunction(a,2.347)
print(b)

# OK actually that is false you can do the same stuff you can do in R so like:

a=np.array([1,2,3,4,5])
b=a**1.2375+a**2.5983
print(b)
c=a/b
print(c)

# Types, Lists, Dictionaries, Sets, Strings, Operators, Control Flow, Functions, Classes, Generators, Decorators, IPython, console, debugger, command line, NumPy, array initialization, indexing array properties and operations, boolean arrays, elementwise operations and math functions, inner/ outer products, linear algebra/ matrix math, reading/ writing files, interpolation, integration, optimization, fft, rounding, random variables, Matplotlib, figures and axes, figures and axes properties, plotting routines, Scipy, interpolation, linear algebra, integration, Pandas, data structures, DataFrame

# Types
a = 2           # integer
b = 5.0         # float
c = 8.3e5       # exponential
d = 1.5 + 0.5j  # complex
e = 4 > 5       # boolean
f = 'word'      # string

# Lists
a = ['red', 'blue', 'green']       # manually initialization
b = list(range(5))                 # initialize from iteratable
c = [nu**2 for nu in b]            # list comprehension
d = [nu**2 for nu in b if nu < 3]  # conditioned list comprehension
e = c[0]                           # access element
f = c[1:2]                         # access a slice of the list
g = c[-1]                          # access last element
h = ['re', 'bl'] + ['gr']          # list concatenation
i = ['re'] * 5                     # repeat a list
['re', 'bl'].index('re')           # returns index of 're'
a.append('yellow')                 # add new element to end of list
a.extend(b)                        # add elements from list `b` to end of list `a`
a.insert(1, 'yellow')              # insert element in specified position
're' in ['re', 'bl']               # true if 're' in list
'fi' not in ['re', 'bl']           # true if 'fi' not in list
sorted([3, 2, 1])                  # returns sorted list
a.pop(2)                           # remove and return item at index (default last)

# Dictionaries
a = {'red': 'rouge', 'blue': 'bleu'}         # dictionary
b = a['red']                                 # translate item
'red' in a                                   # true if dictionary a contains key 'red'
c = [value for key, value in a.items()]      # loop through contents
d = a.get('yellow', 'no translation found')  # return default
a.setdefault('extra', []).append('cyan')     # init key with default
a.update({'green': 'vert', 'brown': 'brun'}) # update dictionary by data from another one
a.keys()                                     # get list of keys
a.values()                                   # get list of values
a.items()                                    # get list of key-value pairs
del a['red']                                 # delete key and associated with it value
a.pop('blue')                                # remove specified key and return the corresponding value

# Sets
a = {1, 2, 3}                                # initialize manually
b = set(range(5))                            # initialize from iteratable
a.add(13)                                    # add new element to set
a.discard(13)                                # discard element from set
a.update([21, 22, 23])                       # update set with elements from iterable
a.pop()                                      # remove and return an arbitrary set element
2 in {1, 2, 3}                               # true if 2 in set
5 not in {1, 2, 3}                           # true if 5 not in set
a.issubset(b)                                # test whether every element in a is in b
a <= b                                       # issubset in operator form
a.issuperset(b)                              # test whether every element in b is in a
a >= b                                       # issuperset in operator form
a.intersection(b)                            # return the intersection of two sets as a new set
a.difference(b)                              # return the difference of two or more sets as a new set
a - b                                        # difference in operator form
a.symmetric_difference(b)                    # return the symmetric difference of two sets as a new set
a.union(b)                                   # return the union of sets as a new set
c = frozenset()                              # the same as set but immutable

# Strings
a = 'red'                      # assignment
char = a[2]                    # access individual characters
'red ' + 'blue'                # string concatenation
'1, 2, three'.split(',')       # split string into list
'.'.join(['1', '2', 'three'])  # concatenate list into string

# Operators
a = 2             # assignment
a += 1 (*=, /=)   # change and assign
3 + 2             # addition
3 / 2             # integer (python2) or float (python3) division
3 // 2            # integer division
3 * 2             # multiplication
3 ** 2            # exponent
3 % 2             # remainder
abs(a)            # absolute value
1 == 1            # equal
2 > 1             # larger
2 < 1             # smaller
1 != 2            # not equal
1 != 2 and 2 < 3  # logical AND
1 != 2 or 2 < 3   # logical OR
not 1 == 2        # logical NOT
'a' in b          # test if a is in b
a is b            # test if objects point to the same memory (id)

# Control Flow
# if/elif/else
a, b = 1, 2
if a + b == 3:
	print('True')
elif a + b == 1:
	print('False')
else:
	print('?')

# for
a = ['red', 'blue', 'green']
for color in a:
	print(color)

# while
number = 1
while number < 10:
	print(number)
	number += 1

# break
number = 1
while True:
	print(number)
	number += 1
	if number > 10:
		break

# continue
for i in range(20):
	if i % 2 == 0:
		continue
	print(i)

# Functions, Classes, Generators, Decorators
# Function groups code statements and possibly
# returns a derived value
def myfunc(a1, a2):
	return a1 + a2

x = myfunc(a1, a2)

# Class groups attributes (data)
# and associated methods (functions)
class Point(object):
	def __init__(self, x):
		self.x = x
	def __call__(self):
		print(self.x)

x = Point(3)

# Generator iterates without
# creating all values at once
def firstn(n):
	num = 0
	while num < n:
		yield num
		num += 1

x = [i for i in firstn(10)]

# Decorator can be used to modify
# the behaviour of a function
class myDecorator(object):
	def __init__(self, f):
		self.f = f
	def __call__(self):
		print("call")
	self.f()

@myDecorator
def my_funct():
	print('func')

my_funct()
IPython
console
<object>?                   # Information about the object
<object>.<TAB>              # tab completion

# run scripts / profile / debug
%run myscript.py

%timeit range(1000)         # measure runtime of statement
%run -t  myscript.py        # measure script execution time

%prun <statement>           # run statement with profiler
%prun -s <key> <statement>  # sort by key, e.g. "cumulative" or "calls"
%run -p  myfile.py          # profile script

%run -d myscript.py         # run script in debug mode
%debug                      # jumps to the debugger after an exception
%pdb                        # run debugger automatically on exception

# examine history
%history
%history ~1/1-5  # lines 1-5 of last session

# run shell commands
!make  # prefix command with "!"

# clean namespace
%reset

# run code from clipboard
%paste

# debugger
n               # execute next line
b 42            # set breakpoint in the main file at line 42
b myfile.py:42  # set breakpoint in 'myfile.py' at line 42
c               # continue execution
l               # show current position in the code
p data          # print the 'data' variable
pp data         # pretty print the 'data' variable
s               # step into subroutine
a               # print arguments that a function received
pp locals()     # show all variables in local scope
pp globals()    # show all variables in global scope

# command line
ipython --pdb -- myscript.py argument1 --option1  # debug after exception
ipython -i -- myscript.py argument1 --option1     # console after finish

# array initialization
np.array([2, 3, 4])             # direct initialization
np.empty(20, dtype=np.float32)  # single precision array of size 20
np.zeros(200)                   # initialize 200 zeros
np.ones((3,3), dtype=np.int32)  # 3 x 3 integer matrix with ones
np.eye(200)                     # ones on the diagonal
np.zeros_like(a)                # array with zeros and the shape of a
np.linspace(0., 10., 100)       # 100 points from 0 to 10
np.arange(0, 100, 2)            # points from 0 to <100 with step 2
np.logspace(-5, 2, 100)         # 100 log-spaced from 1e-5 -> 1e2
np.copy(a)                      # copy array to new memory

# indexing
a = np.arange(100)          # initialization with 0 - 99
a[:3] = 0                   # set the first three indices to zero
a[2:5] = 1                  # set indices 2-4 to 1
a[:-3] = 2                  # set all but last three elements to 2
a[start:stop:step]          # general form of indexing/slicing
a[None, :]                  # transform to column vector
a[[1, 1, 3, 8]]             # return array with values of the indices
a = a.reshape(10, 10)       # transform to 10 x 10 matrix
a.T                         # return transposed view
b = np.transpose(a, (1, 0)) # transpose array to new axis order
a[a < 2]                    # values with elementwise condition

# array properties and operations
a.shape                # a tuple with the lengths of each axis
len(a)                 # length of axis 0
a.ndim                 # number of dimensions (axes)
a.sort(axis=1)         # sort array along axis
a.flatten()            # collapse array to one dimension
a.conj()               # return complex conjugate
a.astype(np.int16)     # cast to integer
a.tolist()             # convert (possibly multidimensional) array to list
np.argmax(a, axis=1)   # return index of maximum along a given axis
np.cumsum(a)           # return cumulative sum
np.any(a)              # True if any element is True
np.all(a)              # True if all elements are True
np.argsort(a, axis=1)  # return sorted index array along axis
np.where(cond)         # return indices where cond is True
np.where(cond, x, y)   # return elements from x or y depending on cond

# boolean arrays
a < 2                         # returns array with boolean values
(a < 2) & (b > 10)            # elementwise logical and
(a < 2) | (b > 10)            # elementwise logical or
~a                            # invert boolean array

# elementwise operations and math functions
a * 5              # multiplication with scalar
a + 5              # addition with scalar
a + b              # addition with array b
a / b              # division with b (np.NaN for division by zero)
np.exp(a)          # exponential (complex and real)
np.power(a, b)     # a to the power b
np.sin(a)          # sine
np.cos(a)          # cosine
np.arctan2(a, b)   # arctan(a/b)
np.arcsin(a)       # arcsin
np.radians(a)      # degrees to radians
np.degrees(a)      # radians to degrees
np.var(a)          # variance of array
np.std(a, axis=1)  # standard deviation

# inner/ outer products
np.dot(a, b)                  # inner product: a_mi b_in
np.einsum('ij,kj->ik', a, b)  # einstein summation convention
np.sum(a, axis=1)             # sum over axis 1
np.abs(a)                     # return absolute values
a[None, :] + b[:, None]       # outer sum
a[None, :] * b[:, None]       # outer product
np.outer(a, b)                # outer product
np.sum(a * a.T)               # matrix norm

# linear algebra/ matrix math
evals, evecs = np.linalg.eig(a)      # Find eigenvalues and eigenvectors
evals, evecs = np.linalg.eigh(a)     # np.linalg.eig for hermitian matrix

# reading/ writing files

np.loadtxt(fname/fobject, skiprows=2, delimiter=',')   # ascii data from file
np.savetxt(fname/fobject, array, fmt='%.5f')           # write ascii data
np.fromfile(fname/fobject, dtype=np.float32, count=5)  # binary data from file
np.tofile(fname/fobject)                               # write (C) binary data
np.save(fname/fobject, array)                          # save as numpy binary (.npy)
np.load(fname/fobject, mmap_mode='c')                  # load .npy file (memory mapped)

# interpolation, integration, optimization
np.trapz(a, x=x, axis=1)  # integrate along axis 1
np.interp(x, xp, yp)      # interpolate function xp, yp at points x
np.linalg.lstsq(a, b)     # solve a x = b in least square sense

# fft
np.fft.fft(a)                # complex fourier transform of a
f = np.fft.fftfreq(len(a))   # fft frequencies
np.fft.fftshift(f)           # shifts zero frequency to the middle
np.fft.rfft(a)               # real fourier transform of a
np.fft.rfftfreq(len(a))      # real fft frequencies

# rounding
np.ceil(a)   # rounds to nearest upper int
np.floor(a)  # rounds to nearest lower int
np.round(a)  # rounds to neares int

# random variables
from np.random import normal, seed, rand, uniform, randint
normal(loc=0, scale=2, size=100)  # 100 normal distributed
seed(23032)                       # resets the seed value
rand(200)                         # 200 random numbers in [0, 1)
uniform(1, 30, 200)               # 200 random numbers in [1, 30)
randint(1, 16, 300)               # 300 random integers in [1, 16)
import matplotlib.pyplot as plt
figures and axes
fig = plt.figure(figsize=(5, 2))  # initialize figure
fig.savefig('out.png')            # save png image
fig, axes = plt.subplots(5, 2, figsize=(5, 5)) # fig and 5 x 2 nparray of axes
ax = fig.add_subplot(3, 2, 2)     # add second subplot in a 3 x 2 grid
ax = plt.subplot2grid((2, 2), (0, 0), colspan=2)  # multi column/row axis
ax = fig.add_axes([left, bottom, width, height])  # add custom axis

# figures and axes properties
fig.suptitle('title')            # big figure title
fig.subplots_adjust(bottom=0.1, right=0.8, top=0.9, wspace=0.2,
hspace=0.5)  # adjust subplot positions
fig.tight_layout(pad=0.1, h_pad=0.5, w_pad=0.5,
rect=None)      # adjust subplots to fit into fig
ax.set_xlabel('xbla')            # set xlabel
ax.set_ylabel('ybla')            # set ylabel
ax.set_xlim(1, 2)                # sets x limits
ax.set_ylim(3, 4)                # sets y limits
ax.set_title('blabla')           # sets the axis title
ax.set(xlabel='bla')             # set multiple parameters at once
ax.legend(loc='upper center')    # activate legend
ax.grid(True, which='both')      # activate grid
bbox = ax.get_position()         # returns the axes bounding box
bbox.x0 + bbox.width             # bounding box parameters

# plotting routines
ax.plot(x,y, '-o', c='red', lw=2, label='bla')  # plots a line
ax.scatter(x,y, s=20, c=color)                  # scatter plot
ax.pcolormesh(xx, yy, zz, shading='gouraud')    # fast colormesh
ax.colormesh(xx, yy, zz, norm=norm)             # slower colormesh
ax.contour(xx, yy, zz, cmap='jet')              # contour lines
ax.contourf(xx, yy, zz, vmin=2, vmax=4)         # filled contours
n, bins, patch = ax.hist(x, 50)                 # histogram
ax.imshow(matrix, origin='lower',
extent=(x1, x2, y1, y2))              # show image
ax.specgram(y, FS=0.1, noverlap=128, scale='linear')                     # plot a spectrogram
ax.text(x, y, string, fontsize=12, color='m')   # write text

# interpolation
# interpolate data at index positions:
from scipy.ndimage import map_coordinates
pts_new = map_coordinates(data, float_indices, order=3)

# simple 1d interpolator with axis argument:
from scipy.interpolate import interp1d
interpolator = interp1d(x, y, axis=2, fill_value=0., bounds_error=False)
y_new = interpolator(x_new)

# Integration
from scipy.integrate import quad     # definite integral of python
value = quad(func, low_lim, up_lim)  # function/method

# linear algebra
from scipy import linalg
evals, evecs = linalg.eig(a)      # Find eigenvalues and eigenvectors
evals, evecs = linalg.eigh(a)     # linalg.eig for hermitian matrix
b = linalg.expm(a)                # Matrix exponential
c = linalg.logm(a)                # Matrix logarithm

# Data structures
s = pd.Series(np.random.rand(1000), index=range(1000))  # series
index = pd.date_range("13/06/2016", periods=1000)       # time index
df = pd.DataFrame(np.zeros((1000, 3)), index=index, columns=["A", "B", "C"])            # DataFrame

# DataFrame
df = pd.read_csv("filename.csv")   # read and load CSV file in a DataFrame
raw = df.values                    # get raw data out of DataFrame object
cols = df.columns                  # get list of columns headers
df.dtypes                          # get data types of all columns
df.head(5)                         # get first 5 rows
df.describe()                      # get basic statisitics for all columns
df.index                           # get index column range

# column slicin
# (.loc[] and .ix[] are inclusive of the range of values selected)
df.col_name                         # select column values as a series by column name (not optimized)
df[['col_name']]                    # select column values as a dataframe by column name (not optimized)
df.loc[:, 'col_name']               # select column values as a series by column name
df.loc[:, ['col_name']]             # select column values as a dataframe by column name 
df.iloc[:, 0]                       # select by column index
df.iloc[:, [0]]                     # select by column index, but as a dataframe
df.ix[:, 'col_name']                # hybrid approach with column name
df.ix[:, 0]                         # hybrid approach with column index

# row slicin
print(df[:2])                      # print first 2 rows of the dataframe
df.iloc[0:2, :]                    # select first 2 rows of the dataframe
df.loc[0:2,'col_name']             # select first 3 rows of the dataframe
df.loc[0:2, ['col_name1', 'col_name3', 'col_name6']]    # select first 3 rows of the 3 different columns
df.iloc[0:2,0:2]                   # select fisrt 3 rows and first 3 columns
# Again, .loc[] and .ix[] are inclusive

# Dicin
df[ df.col_name < 7 ]                            # select all rows where col_name < 7
df[ (df.col_name1 < 7) & (df.col_name2 == 0) ]       # combine multiple boolean indexing conditionals using bit-wise logical operators.
# Regular Python boolean operators (and, or) cannot be used here. 
# Be sure to encapsulate each conditional in parenthesis to make this work.
df[df.recency < 7] = -100 # writing to slice

#SciKit-Learn is an open source Python library used for machine learning, preprocessing, cross-validation and visualization algorithms. It provides a range of supervised and unsupervised learning algorithms in Python.

#sklearn Naive Bayes Tutorial
#A Basic Example
#Let's create a basic example using scikit-learn library which will be used to
#Load the data  
#Divide the data into train and test,
#Train your data using the KNN Algorithm and,
#Predict the result
from sklearn import neighbors, datasets, preprocessing
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
iris = datasets.load_iris() 
X, y = iris.data[:, :2], iris.target
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=33)
scaler = preprocessing.StandardScaler().fit(X_train)
X_train = scaler.transform(X_train) 
X_test = scaler.transform(X_test)
knn = neighbors.KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, y_train)
y_pred = knn.predict(X_test)
accuracy_score(y_test, y_pred)
#Loading the data
#You need to have a numeric data stored in NumPy arrays or SciPy sparse matrices. You can also use other numeric arrays, such as Pandas DataFrame.

import numpy as np
X = np.random.random((10,5))
y = np.array(['M','M','F','F','M','F','M','M','F','F','F'])
X[X < 0.7] = 0
#Train and Test
#Once the data is loaded, your next task would be split your dataset into training data and testing data.

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)
#Data Preprocessing
#Standardization
#Data standardization is one of the data preprocessing step which is used for rescaling one or more attributes so that the attributes have a mean value of 0 and a standard deviation of 1. Standardization assumes that your data has a Gaussian (bell curve) distribution.

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler().fit(X_train)
standardized_X = scaler.transform(X_train)
standardized_X_test = scaler.transform(X_test)
#Binarization
#Binarization is a common operation performed on text count data. Using binarization the analyst can decide to consider the presence or absence of a feature rather than having a quantified number of occurrences for instance.

from sklearn.preprocessing import Binarizer
binarizer = Binarizer(threshold=0.0).fit(X)
binary_X = binarizer.transform(X)
#Normalization
#Normalization is a technique generally used for data preparation for machine learning. The main goal of normalization is to change the values of numeric columns in the dataset so that we can have a common scale, without losing the information or distorting the differences in the ranges of values.

from sklearn.preprocessing import Normalizer
scaler = Normalizer().fit(X_train)
normalized_X = scaler.transform(X_train)
normalized_X_test = scaler.transform(X_test)
#Encoding Categorical Features
#The LabelEncoder is another class used in data-preprocessing for encoding class levels. It can also be used to transform non-numerical labels into numerical labels.

from sklearn.preprocessing import LabelEncoder
enc = LabelEncoder()
y = enc.fit_transform(y)
#Imputing missing values
#The Imputer class in python will provide you with the basic strategies for imputing/filling missing values. It does this by using the mean, median values or the most frequent value of the row or column in which the missing values are located. This class also allows for encoding different missing values.

from sklearn.preprocessing import Imputer
imp = Imputer(missing_values=0, strategy='mean', axis=0)
imp.fit_transform(X_train)
#Generating Polynomial Features
#Polynomial Feature generates a new feature matrix which consists of all polynomial combinations of the features with degree less than or equal to the specified degree. For example, if an input sample is two dimensional and of the form [a, b], then the 2-degree polynomial features are [1, a, b, a^2, ab, b^2].

from sklearn.preprocessing import PolynomialFeatures
poly = PolynomialFeatures(5)
poly.fit_transform(X)
#Create Your Model
#Supervised Learning Estimator
#Supervised learning is a type of machine learning that enables the model to predict future outcomes after they are trained on labelled data.

#Unsupervised Learning Estimator
#Unsupervised learning is a type of machine learning that enables the model to predict future outcomes without being trained on the labelled data.

# Linear Regression Algorithm
from sklearn.linear_model import LinearRegression
lr = LinearRegression(normalize=True)
# Naive Bayes Algorithm
from sklearn.naive_bayes import GaussianNB
gnb = GaussianNB()
# KNN Algorithm
from sklearn import neighbors
knn = neighbors.KNeighborsClassifier(n_neighbors=5)
# Support Vector Machines (SVM)
from sklearn.svm import SVC
svc = SVC(kernel='linear')
# Principal Component Analysis (PCA)
from sklearn.decomposition import PCA
pca = PCA(n_components=0.95)
# K Means Clustering Algorithm
from sklearn.cluster import KMeans
k_means = KMeans(n_clusters=3, random_state=0)
#Model Fitting
#Fitting is a measure of how well a machine learning model generalizes to similar data to that on which it was trained

# For Supervised learning
lr.fit(X, y) #Fits data into the model
knn.fit(X_train, y_train)
svc.fit(X_train, y_train)
# For Unsupervised Learning
k_means.fit(X_train)#Fits data into the model
pca_model = pca.fit_transform(X_train) #Fit to data, then transform it
#Prediction
#Fitting is a measure of how well a machine learning model generalizes to similar data to that on which it was trained

# For Supervised learning
y_pred=svc.predict(np.random((2,5))) #predict label
y_pred=lr.predict(x_test) #predict label
y_pred=knn.predict_proba(x_test)#estimate probablity of a label
# For Unsupervised Learning
y_pred=k_means.predict(x_test) #predict labels in clustering algorithm
#Evaluating the model's performance
#Classification Metrics
#The sklearn.metrics module implements several loss, score, and utility functions to measure classification performance. 

# Mean Absolute Error
from sklearn.metrics import mean_absolute_error
y_true = [3, -0.5, 2]
mean_absolute_error(y_true, y_pred)
# Mean Squared Error
from sklearn.metrics import mean_squared_error
mean_squared_error(y_test, y_pred)
# R^2 Score
from sklearn.metrics import r2_score
r2_score(y_true, y_pred)
#Regression Metrics
#The sklearn.metrics module implements several loss, score, and utility functions to measure regression performance. 

# Accuracy Score
knn.score(X_test, y_test)
from sklearn.metrics import accuracy_score
accuracy_score(y_test, y_pred)
# Classification Report
from sklearn.metrics import classification_report
print(classification_report(y_test, y_pred))
# Confusion Matrix
from sklearn.metrics import confusion_matrix
print(confusion_matrix(y_test, y_pred))
#Clustering Metrics
# Adjusted Rand Index
from sklearn.metrics import adjusted_rand_score
adjusted_rand_score(y_true, y_pred)
# Homogeneity
from sklearn.metrics import homogeneity_score
homogeneity_score(y_true, y_pred)
# V-measure
from sklearn.metrics import v_measure_score
metrics.v_measure_score(y_true, y_pred)
#Cross Validation
from sklearn.cross_validation import cross_val_score 
print(cross_val_score(knn, X_train, y_train, cv=4)) 
print(cross_val_score(lr, X, y, cv=2))
#Tune your model
#Grid Search
#GridSearchCV implements a "fit" and a "score" method. It also implements "predict", "predict_proba", "decision_function", "transform" and "inverse_transform" if they are implemented in the estimator used.

from sklearn.grid_search import GridSearchCV
params = {"n_neighbors": np.arange(1,3), "metric": ["euclidean", "cityblock"]}
grid = GridSearchCV(estimator=knn, param_grid=params)
grid.fit(X_train, y_train)
print(grid.best_score_)
print(grid.best_estimator_.n_neighbors)
#Randomized Parameter Optimization
#RandomizedSearchCV performs the random search on hyper parameters. In contrast to GridSearchCV, not all parameter values are tried out, but rather a fixed number of parameter settings is sampled from the specified distributions. The number of parameter settings that are tried is given by n_iter.

from sklearn.grid_search import RandomizedSearchCV
params={"n_neighbours":range(1,5),"weights":["uniform","distance"]}
rserach = RandomizedSearchCV(estimator=knn,param_distribution=params, cv=4, n_iter=8, random_state=5)
rsearch.fit(X_train, Y_train)
print(rsearch.best_score)