# "You know what happens when good maths and Lazar get together, right? We get that money."

# Remember To Replace All "	" to "	"

# One assumes that at firms there may exist people, software engineers, machine learning engineers, who are very extremely performant at optimisations tasks and further tweaks, and one may become that dude, or primarily an ideator hypotheses and backtesting generator, who knows statistical arbitrage.

# Github
# learn-cuda
# https://github.com/kevinzakka/learn-cuda/blob/master/src/histogram.cu

# Kaggle
# Long Short Term Memory With PyTorch
# https://www.kaggle.com/kanncaa1/long-short-term-memory-with-pytorch

# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load in 

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt

# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list all files under the input directory

import os
for dirname, _, filenames in os.walk('/kaggle/input'):
	for filename in filenames:
		print(os.path.join(dirname, filename))

# Any results you write to the current directory are saved as output.

# Import Libraries
import torch
import torch.nn as nn
from torch.autograd import Variable
from sklearn.model_selection import train_test_split
from torch.utils.data import DataLoader, TensorDataset

# load data
train = pd.read_csv(r"/kaggle/input/digit-recognizer/train.csv",dtype = np.float32)

# split data into features(pixels) and labels(numbers from 0 to 9)
targets_numpy = train.label.values
features_numpy = train.loc[:,train.columns != "label"].values/255 # normalization

# train test split. Size of train data is 80% and size of test data is 20%. 
features_train, features_test, targets_train, targets_test = train_test_split(features_numpy,targets_numpy,test_size = 0.2,random_state = 42) 

# Create feature and targets tensor for train set. As you remember we need variable to accumulate gradients. Therefore first we create tensor, then we will create variable
featuresTrain = torch.from_numpy(features_train)
targetsTrain = torch.from_numpy(targets_train).type(torch.LongTensor) # data type is long

# create feature and targets tensor for test set.
featuresTest = torch.from_numpy(features_test)
targetsTest = torch.from_numpy(targets_test).type(torch.LongTensor) # data type is long

# batch_size, epoch and iteration
batch_size = 100
n_iters = 6000
num_epochs = n_iters / (len(features_train) / batch_size)
num_epochs = int(num_epochs)
print("Epoch Number: ",num_epochs)

# Pytorch train and test sets
train = TensorDataset(featuresTrain,targetsTrain)
test = TensorDataset(featuresTest,targetsTest)

# data loader
train_loader = DataLoader(train, batch_size = batch_size, shuffle = False)
test_loader = DataLoader(test, batch_size = batch_size, shuffle = False)

# visualize one of the images in data set
plt.imshow(features_numpy[10].reshape(28,28))
plt.axis("off")
plt.title(str(targets_numpy[10]))
plt.savefig('graph.png')
plt.show()

print(len(train_loader.dataset))
print(len(test_loader.dataset))

class LSTMModel(nn.Module): # Long Short Term Memory
	def __init__(self, input_dim, hidden_dim, layer_dim, output_dim):
		super(LSTMModel, self).__init__()
		
		# Hidden dimensions
		self.hidden_dim = hidden_dim

		# Number of hidden layers
		self.layer_dim = layer_dim

		# Long Short Term Memory
		self.lstm = nn.LSTM(input_dim, hidden_dim, layer_dim, batch_first=True) # batch_first=True (batch_dim, seq_dim, feature_dim)

		# Readout layer
		self.fc = nn.Linear(hidden_dim, output_dim)

	def forward(self, x):
		# Initialize hidden state with zeros
		h0 = torch.zeros(self.layer_dim, x.size(0), self.hidden_dim).requires_grad_()

		# Initialize cell state
		c0 = torch.zeros(self.layer_dim, x.size(0), self.hidden_dim).requires_grad_()

		# 28 time steps
		# We need to detach as we are doing truncated backpropagation through time (BPTT)
		# If we don't, we'll backprop all the way to the start even after going through another batch
		out, (hn, cn) = self.lstm(x, (h0.detach(), c0.detach()))

		# Index hidden state of last time step
		# out.size() --> 100, 28, 100
		# out[:, -1, :] --> 100, 100 --> just want last time step hidden states! 
		out = self.fc(out[:, -1, :]) 
		# out.size() --> 100, 10
		return out
	
input_dim = 28
hidden_dim = 100
layer_dim = 1
output_dim = 10
model = LSTMModel(input_dim, hidden_dim, layer_dim, output_dim)

error = nn.CrossEntropyLoss()

learning_rate = 0.1
optimizer = torch.optim.SGD(model.parameters(), lr=learning_rate)

# Number of steps to unroll
seq_dim = 28  
loss_list = []
iteration_list = []
accuracy_list = []
count = 0
for epoch in range(num_epochs):
	for i, (images, labels) in enumerate(train_loader):
		# Load images as a torch tensor with gradient accumulation abilities
		images = images.view(-1, seq_dim, input_dim).requires_grad_()

		# Clear gradients w.r.t. parameters
		optimizer.zero_grad()

		# Forward pass to get output/logits
		# outputs.size 100, 10
		outputs = model(images)

		# Calculate Loss: softmax --> cross entropy loss
		loss = error(outputs,labels)

		# Getting gradients
		loss.backward()

		# Updating parameters
		optimizer.step()

		count += 1

		if count % 500 == 0:
			# Calculate Accuracy
			correct = 0
			total = 0
			for images,labels in test_loader:
				
				images = images.view(-1, seq_dim, input_dim)
	
				# Forward pass only to get logits/output
				outputs = model(images)

				# Get predictions from the maximum value
				_, predicted = torch.max(outputs.data, 1)

				# Total number of labels
				total += labels.size(0)

				# Total correct predictions
				correct += (predicted == labels).sum()

			accuracy = 100 * correct / total
			
			loss_list.append(loss.data.item())
			iteration_list.append(count)
			accuracy_list.append(accuracy)
			
			# Print Loss
			print('Iteration: {}. Loss: {}. Accuracy: {}'.format(count, loss.data.item(), accuracy))

# Visualisation Loss 
plt.plot(iteration_list,loss_list)
plt.xlabel("Number Of Iteration")
plt.ylabel("Loss")
plt.title("Long Short Term Memory: Loss vs. Number Of Iteration")
plt.show()

# Visualization Accuracy 
plt.plot(iteration_list,accuracy_list,color = "red")
plt.xlabel("Number Of Iteration")
plt.ylabel("Accuracy")
plt.title("Long Short Term Memory: Accuracy vs. Number Of Iteration")
plt.savefig('graph.png')
plt.show()

# Kaggle
# Deep Learning Tutorial For Beginners
# https://www.kaggle.com/kanncaa1/deep-learning-tutorial-for-beginners

# This Python 3 environment comes with many helpful analytics libraries installed.
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here are several helpful packages to load in:

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory
# Import warnings.
import warnings
# Filter warnings.
warnings.filterwarnings('ignore')
from subprocess import check_output
print(check_output(["ls", "../input"]).decode("utf8"))
# Any results you write to the current directory are saved as output.

# Load dataset.
x_l = np.load('../input/Sign-language-digits-dataset/X.npy')
Y_l = np.load('../input/Sign-language-digits-dataset/Y.npy')
img_size = 64
plt.subplot(1,2,1)
plt.imshow(x_l[260].reshape(img_size,img_size))
plt.axis('off')
plt.subplot(1,2,2)
plt.imshow(x_l[900].reshape(img_size,img_size))
plt.axis('off')

# Join a sequence of arrays along an row axis.
X = np.concatenate((x_l[204:409], x_l[822:1027] ), axis=0) # from 0 to 204 is zero sign and from 205 to 410 is one sign 
z = np.zeros(205)
o = np.ones(205)
Y = np.concatenate((z,o),axis=0).reshape(X.shape[0],1)
print("X shape: ",X.shape)
print("Y shape: ",Y.shape)

# Then lets create x_train, y_train, x_test, y_test arrays
from sklearn.model_selection import train_test_split
X_train,X_test,Y_train,Y_test = train_test_split(X,Y,test_size=0.15,random_state=42)
number_of_train = X_train.shape[0]
number_of_test = X_test.shape[0]

X_train_flatten=X_train.reshape(number_of_train,X_train.shape[1]*X_train.shape[2])
X_test_flatten=X_test.reshape(number_of_test,X_test.shape[1]*X_test.shape[2])
print("X train flatten",X_train_flatten.shape)
print("X test flatten",X_test_flatten.shape)

x_train = X_train_flatten.T
x_test = X_test_flatten.T
y_train = Y_train.T
y_test = Y_test.T
print("x train: ",x_train.shape)
print("x test: ",x_test.shape)
print("y train: ",y_train.shape)
print("y test: ",y_test.shape)

# Short description and example of definition (def).
def dummy(parameter):
	dummy_parameter=parameter+5
	return dummy_parameter
result=dummy(3) # result=8

# Let us initialise parameters.
# So what we need is dimension 4096 that is number of pixels as a parameter for our initialize method(def)
def initialize_weights_and_bias(dimension):
	w = np.full((dimension,1),0.01)
	b = 0.0
	return w,b

# w,b = initialize_weights_and_bias(4096)

# calculation of z
# z = np.dot(w.T,x_train)+b
def sigmoid(z):
	y_head = 1/(1+np.exp(-z))
	return y_head

y_head = sigmoid(0)
y_head

# Forward propagation steps:
# Find z = w.T*x+b
# y_head = sigmoid(z)
# loss(error) = loss(y,y_head)
# cost = sum(loss)
def forward_propagation(w,b,x_train,y_train):
	z = np.dot(w.T,x_train) + b
	y_head = sigmoid(z) # probabilistic 0-1
	loss = -y_train*np.log(y_head)-(1-y_train)*np.log(1-y_head)
	cost = (np.sum(loss))/x_train.shape[1] # x_train.shape[1] is for scaling
	return cost 

# In backward propagation we will use y_head that found in forward propagation
# Therefore instead of writing backward propagation method, let us combine forward propagation and backward propagation
def forward_backward_propagation(w,b,x_train,y_train):
	# forward propagation
	z = np.dot(w.T,x_train) + b
	y_head = sigmoid(z)
	loss = -y_train*np.log(y_head)-(1-y_train)*np.log(1-y_head)
	cost = (np.sum(loss))/x_train.shape[1] # x_train.shape[1] is for scaling
	# backward propagation
	derivative_weight = (np.dot(x_train,((y_head-y_train).T)))/x_train.shape[1] # x_train.shape[1]  is for scaling
	derivative_bias = np.sum(y_head-y_train)/x_train.shape[1]				 # x_train.shape[1] is for scaling
	gradients = {"derivative_weight": derivative_weight,"derivative_bias": derivative_bias}
	return cost,gradients

# Updating(learning) parameters
def update(w,b,x_train,y_train,learning_rate,number_of_iterarion):
	cost_list=[]
	cost_list2=[]
	index=[]
	# updating(learning) parameters is number_of_iterarion times
	for i in range(number_of_iterarion):
		# make forward and backward propagation and find cost and gradients
		cost,gradients=forward_backward_propagation(w,b,x_train,y_train)
		cost_list.append(cost)
		# lets update
		w=w-learning_rate*gradients["derivative_weight"]
		b=b-learning_rate*gradients["derivative_bias"]
		if i%10==0:
			cost_list2.append(cost)
			index.append(i)
			print("Cost after iteration %i: %f" %(i,cost))
	# we update (learn) parameters weights and bias
	parameters={"weight":w,"bias":b}
	plt.plot(index,cost_list2)
	plt.xticks(index,rotation='vertical')
	plt.xlabel("Number of Iterarion")
	plt.ylabel("Cost")
	plt.show()
	return parameters,gradients,cost_list
# parameters, gradients, cost_list = update(w, b, x_train, y_train, learning_rate = 0.009,number_of_iterarion = 200)

# prediction
def predict(w,b,x_test):
	# x_test is a input for forward propagation
	z = sigmoid(np.dot(w.T,x_test)+b)
	Y_prediction = np.zeros((1,x_test.shape[1]))
	# if z is bigger than 0.5, our prediction is sign one (y_head=1),
	# if z is smaller than 0.5, our prediction is sign zero (y_head=0),
	for i in range(z.shape[1]):
		if z[0,i]<= 0.5:
			Y_prediction[0,i] = 0
		else:
			Y_prediction[0,i] = 1

	return Y_prediction
# predict(parameters["weight"],parameters["bias"],x_test)

def logistic_regression(x_train,y_train,x_test,y_test,learning_rate,num_iterations):
	# initialize
	dimension=x_train.shape[0]  # That is 4096
	w,b=initialize_weights_and_bias(dimension)

	# Do not change learning rate
	parameters, gradients, cost_list = update(w, b, x_train, y_train, learning_rate,num_iterations)  
	y_prediction_test = predict(parameters["weight"],parameters["bias"],x_test)
	y_prediction_train = predict(parameters["weight"],parameters["bias"],x_train)

	# Print train/test Errors
	print("train accuracy: {} %".format(100 - np.mean(np.abs(y_prediction_train - y_train)) * 100))
	print("test accuracy: {} %".format(100 - np.mean(np.abs(y_prediction_test - y_test)) * 100))
	
logistic_regression(x_train, y_train, x_test, y_test,learning_rate = 0.01, num_iterations = 150)

from sklearn import linear_model
logreg = linear_model.LogisticRegression(random_state=42,max_iter=150)
print("test accuracy: {} ".format(logreg.fit(x_train.T,y_train.T).score(x_test.T,y_test.T)))
print("train accuracy: {} ".format(logreg.fit(x_train.T,y_train.T).score(x_train.T,y_train.T)))

# Initialise parameters and layer sizes
def initialize_parameters_and_layer_sizes_NN(x_train, y_train):
	parameters = {"weight1": np.random.randn(3,x_train.shape[0]) * 0.1,
				  "bias1": np.zeros((3,1)),
				  "weight2": np.random.randn(y_train.shape[0],3) * 0.1,
				  "bias2": np.zeros((y_train.shape[0],1))}
	return parameters

def forward_propagation_NN(x_train,parameters):
	Z1 = np.dot(parameters["weight1"],x_train) + parameters["bias1"]
	A1 = np.tanh(Z1)
	Z2 = np.dot(parameters["weight2"],A1) + parameters["bias2"]
	A2 = sigmoid(Z2)
	cache = {"Z1":Z1,
			"A1":A1,
			"Z2":Z2,
			"A2":A2}
	return A2, cache

# Compute Cost
def compute_cost_NN(A2,Y,parameters):
	logprobs = np.multiply(np.log(A2),Y)
	cost = -np.sum(logprobs)/Y.shape[1]
	return cost

# Backward Propagation
def backward_propagation_NN(parameters,cache,X,Y):
	dZ2 = cache["A2"]-Y
	dW2 = np.dot(dZ2,cache["A1"].T)/X.shape[1]
	db2 = np.sum(dZ2,axis =1,keepdims=True)/X.shape[1]
	dZ1 = np.dot(parameters["weight2"].T,dZ2)*(1 - np.power(cache["A1"], 2))
	dW1 = np.dot(dZ1,X.T)/X.shape[1]
	db1 = np.sum(dZ1,axis =1,keepdims=True)/X.shape[1]
	grads = {"dweight1": dW1,
			 "dbias1": db1,
			 "dweight2": dW2,
			 "dbias2": db2}
	return grads

# Update Parameters
def update_parameters_NN(parameters, grads, learning_rate = 0.01):
	parameters = {"weight1": parameters["weight1"]-learning_rate*grads["dweight1"],"bias1": parameters["bias1"]-learning_rate*grads["dbias1"],"weight2": parameters["weight2"]-learning_rate*grads["dweight2"],"bias2": parameters["bias2"]-learning_rate*grads["dbias2"]}
	return parameters

# Prediction
def predict_NN(parameters,x_test):
	# x_test is a input for forward propagation
	A2, cache = forward_propagation_NN(x_test,parameters)
	Y_prediction = np.zeros((1,x_test.shape[1]))
	# If z is bigger than 0.5, our prediction is sign one (y_head=1).
	# If z is smaller than 0.5, our prediction is sign zero (y_head=0).
	for i in range(A2.shape[1]):
		if A2[0,i]<=0.5:
			Y_prediction[0,i]=0
		else:
			Y_prediction[0,i]=1
	return Y_prediction

# 2 - Layer neural network
def two_layer_neural_network(x_train, y_train,x_test,y_test,num_iterations):
	cost_list=[]
	index_list=[]
	# Initialise parameters and layer sizes.
	parameters = initialize_parameters_and_layer_sizes_NN(x_train, y_train)
	for i in range(0,num_iterations):
		 # Forward propagation.
		A2,cache=forward_propagation_NN(x_train,parameters)
		# Compute cost.
		cost=compute_cost_NN(A2,y_train,parameters)
		 # Backward propagation.
		grads=backward_propagation_NN(parameters,cache,x_train,y_train)
		 # Update parameters.
		parameters=update_parameters_NN(parameters, grads)
		if i%100==0:
			cost_list.append(cost)
			index_list.append(i)
			print ("Cost after iteration %i: %f" %(i, cost))
	plt.plot(index_list,cost_list)
	plt.xticks(index_list,rotation='vertical')
	plt.xlabel("Number of Iteration")
	plt.ylabel("Cost")
	plt.show()
	
	# predict
	y_prediction_test = predict_NN(parameters,x_test)
	y_prediction_train = predict_NN(parameters,x_train)

	# Print train/test Errors
	print("train accuracy:{}%".format(100-np.mean(np.abs(y_prediction_train-y_train))*100))
	print("test accuracy:{}%".format(100-np.mean(np.abs(y_prediction_test-y_test))*100))
	return parameters

parameters=two_layer_neural_network(x_train,y_train,x_test,y_test,num_iterations=2500)

# Reshaping
x_train, x_test, y_train, y_test = x_train.T, x_test.T, y_train.T, y_test.T

# Evaluating the Artificial Neural Network
from keras.wrappers.scikit_learn import KerasClassifier
from sklearn.model_selection import cross_val_score
from keras.models import Sequential # initialize neural network library
from keras.layers import Dense # build our layers library
def build_classifier():
	classifier = Sequential() # initialize neural network
	classifier.add(Dense(units = 8, kernel_initializer = 'uniform', activation = 'relu', input_dim = x_train.shape[1]))
	classifier.add(Dense(units = 4, kernel_initializer = 'uniform', activation = 'relu'))
	classifier.add(Dense(units = 1, kernel_initializer = 'uniform', activation = 'sigmoid'))
	classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])
	return classifier
classifier = KerasClassifier(build_fn = build_classifier, epochs = 100)
accuracies = cross_val_score(estimator = classifier, X = x_train, y = y_train, cv = 3)
mean = accuracies.mean()
variance = accuracies.std()
print("Accuracy mean: "+ str(mean))
print("Accuracy variance: "+ str(variance))

# Kaggle
# Pytorch Tutorial For Deep Learning Lovers
# https://www.kaggle.com/kanncaa1/pytorch-tutorial-for-deep-learning-lovers

# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load in 

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory

import os
print(os.listdir("../input"))

# Any results you write to the current directory are saved as output.

# import numpy library
import numpy as np

# numpy array
array = [[1,2,3],[4,5,6]]
first_array = np.array(array) # 2x3 array
print("Array Type: {}".format(type(first_array))) # type
print("Array Shape: {}".format(np.shape(first_array))) # shape
print(first_array)

# import pytorch library
import torch

# pytorch array
tensor = torch.Tensor(array)
print("Array Type: {}".format(tensor.type)) # type
print("Array Shape: {}".format(tensor.shape)) # shape
print(tensor)

# numpy ones
print("Numpy {}\n".format(np.ones((2,3))))

# pytorch ones
print(torch.ones((2,3)))

# numpy random
print("Numpy {}\n".format(np.random.rand(2,3)))

# pytorch random
print(torch.rand(2,3))

# random numpy array
array = np.random.rand(2,2)
print("{} {}\n".format(type(array),array))

# from numpy to tensor
from_numpy_to_tensor = torch.from_numpy(array)
print("{}\n".format(from_numpy_to_tensor))

# from tensor to numpy
tensor = from_numpy_to_tensor
from_tensor_to_numpy = tensor.numpy()
print("{} {}\n".format(type(from_tensor_to_numpy),from_tensor_to_numpy))

# create tensor 
tensor = torch.ones(3,3)
print("\n",tensor)

# Resize
print("{}{}\n".format(tensor.view(9).shape,tensor.view(9)))

# Addition
print("Addition: {}\n".format(torch.add(tensor,tensor)))

# Subtraction
print("Subtraction: {}\n".format(tensor.sub(tensor)))

# Element wise multiplication
print("Element wise multiplication: {}\n".format(torch.mul(tensor,tensor)))

# Element wise division
print("Element wise division: {}\n".format(torch.div(tensor,tensor)))

# Mean
tensor = torch.Tensor([1,2,3,4,5])
print("Mean: {}".format(tensor.mean()))

# Standard deviation (std)
print("std: {}".format(tensor.std()))

# import variable from pytorch library
from torch.autograd import Variable

# define variable
var = Variable(torch.ones(3), requires_grad = True)
var

# lets make basic backward propagation
# we have an equation that is y = x^2
array = [2,4]
tensor = torch.Tensor(array)
x = Variable(tensor, requires_grad = True)
y = x**2
print(" y =  ",y)

# recap o equation o = 1/2*sum(y)
o = (1/2)*sum(y)
print(" o =  ",o)

# backward
o.backward() # calculates gradients

# As I defined, variables accumulates gradients. In this part there is only one variable x.
# Therefore variable x should be have gradients
# Lets look at gradients with x.grad
print("gradients: ",x.grad)

# As a car company we collect this data from previous selling
# lets define car prices
car_prices_array = [3,4,5,6,7,8,9]
car_price_np = np.array(car_prices_array,dtype=np.float32)
car_price_np = car_price_np.reshape(-1,1)
car_price_tensor = Variable(torch.from_numpy(car_price_np))

# lets define number of car sell
number_of_car_sell_array = [7.5,7,6.5,6.0,5.5,5.0,4.5]
number_of_car_sell_np = np.array(number_of_car_sell_array,dtype=np.float32)
number_of_car_sell_np = number_of_car_sell_np.reshape(-1,1)
number_of_car_sell_tensor = Variable(torch.from_numpy(number_of_car_sell_np))

# lets visualize our data
import matplotlib.pyplot as plt
plt.scatter(car_prices_array,number_of_car_sell_array)
plt.xlabel("Car Price $")
plt.ylabel("Number of Car Sell")
plt.title("Car Price$ VS Number of Car Sell")
plt.show()

# Linear Regression With PyTorch

# Libraries
import torch	  
from torch.autograd import Variable	 
import torch.nn as nn 
import warnings
warnings.filterwarnings("ignore")

# Create Class
class LinearRegression(nn.Module):
	def __init__(self,input_size,output_size):
		# super function. It inherits from nn.Module and we can access everythink in nn.Module
		super(LinearRegression,self).__init__()
		# Linear function.
		self.linear = nn.Linear(input_dim,output_dim)

	def forward(self,x):
		return self.linear(x)
	
# define model
input_dim = 1
output_dim = 1
model = LinearRegression(input_dim,output_dim) # input and output size are 1

# Mean Squared Error
mse = nn.MSELoss()

# Optimisation [Find Parameters Which Minimise Error Function]
learning_rate = 0.02 # Sort of how fast one reaches a sufficiently tight approximation or true optimal parameters.
optimizer = torch.optim.SGD(model.parameters(),lr = learning_rate)

# Train Model
loss_list = []
iteration_number = 1001
for iteration in range(iteration_number):
		
	# Optimisation
	optimizer.zero_grad() 
	
	# Forward To Get Output
	results = model(car_price_tensor)
	
	# Calculate Loss
	loss = mse(results, number_of_car_sell_tensor)
	
	# Backward Propagation
	loss.backward()
	
	# Updating Parameters
	optimizer.step()
	
	# Store Loss
	loss_list.append(loss.data)
	
	# Print Loss
	if(iteration % 50 == 0):
		print('epoch {}, loss {}'.format(iteration, loss.data))

plt.plot(range(iteration_number),loss_list)
plt.xlabel("Number of Iterations")
plt.ylabel("Loss")
plt.show()

# Predict Our Car Price 
predicted = model(car_price_tensor).data.numpy()
plt.scatter(car_prices_array,number_of_car_sell_array,label = "original data",color ="red")
plt.scatter(car_prices_array,predicted,label = "predicted data",color ="blue")

# predict if car price is 10$, what will be the number of car sell
# predicted_10 = model(torch.from_numpy(np.array([10]))).data.numpy()
# plt.scatter(10,predicted_10.data,label = "car price 10$",color ="green")
plt.legend()
plt.xlabel("Car Price $")
plt.ylabel("Number Of Car Sell")
plt.title("Original vs. Predicted Values")
plt.show()

# Import Libraries
import torch
import torch.nn as nn
from torch.autograd import Variable
from torch.utils.data import DataLoader
import pandas as pd
from sklearn.model_selection import train_test_split

# Prepare Dataset
# load data
train = pd.read_csv(r"../input/train.csv",dtype = np.float32)

# split data into features(pixels) and labels(numbers from 0 to 9)
targets_numpy = train.label.values
features_numpy = train.loc[:,train.columns != "label"].values/255 # normalization

# train test split. Size of train data is 80% and size of test data is 20%. 
features_train, features_test, targets_train, targets_test = train_test_split(features_numpy,targets_numpy,test_size = 0.2,random_state = 42) 

# create feature and targets tensor for train set. As you remember we need variable to accumulate gradients. Therefore first we create tensor, then we will create variable
featuresTrain = torch.from_numpy(features_train)
targetsTrain = torch.from_numpy(targets_train).type(torch.LongTensor) # data type is long

# create feature and targets tensor for test set.
featuresTest = torch.from_numpy(features_test)
targetsTest = torch.from_numpy(targets_test).type(torch.LongTensor) # data type is long

# batch_size, epoch and iteration
batch_size = 100
n_iters = 10000
num_epochs = n_iters / (len(features_train) / batch_size)
num_epochs = int(num_epochs)

# Pytorch train and test sets
train = torch.utils.data.TensorDataset(featuresTrain,targetsTrain)
test = torch.utils.data.TensorDataset(featuresTest,targetsTest)

# data loader
train_loader = DataLoader(train, batch_size = batch_size, shuffle = False)
test_loader = DataLoader(test, batch_size = batch_size, shuffle = False)

# visualize one of the images in data set
plt.imshow(features_numpy[10].reshape(28,28))
plt.axis("off")
plt.title(str(targets_numpy[10]))
plt.savefig('graph.png')
plt.show()

# Create Logistic Regression Model
class LogisticRegressionModel(nn.Module):
	def __init__(self, input_dim, output_dim):
		super(LogisticRegressionModel, self).__init__()
		# Linear part
		self.linear = nn.Linear(input_dim, output_dim)
		# There should be logistic function right?
		# However logistic function in pytorch is in loss function
		# So actually we do not forget to put it, it is only at next parts
	
	def forward(self, x):
		out = self.linear(x)
		return out

# Instantiate Model Class
input_dim = 28*28 # size of image px*px
output_dim = 10  # labels 0,1,2,3,4,5,6,7,8,9

# create logistic regression model
model = LogisticRegressionModel(input_dim, output_dim)

# Cross Entropy Loss  
error = nn.CrossEntropyLoss()

# Stochastic Gradient Descent Optimizer 
learning_rate = 0.001
optimizer = torch.optim.SGD(model.parameters(), lr=learning_rate)

# Training The Model
count = 0
loss_list = []
iteration_list = []
for epoch in range(num_epochs):
	for i, (images, labels) in enumerate(train_loader):
		
		# Define variables
		train = Variable(images.view(-1, 28*28))
		labels = Variable(labels)
		
		# Clear gradients
		optimizer.zero_grad()
		
		# Forward propagation
		outputs = model(train)
		
		# Calculate softmax and cross entropy loss
		loss = error(outputs, labels)
		
		# Calculate gradients
		loss.backward()
		
		# Update parameters
		optimizer.step()
		
		count += 1
		
		# Prediction
		if count % 50 == 0:
			# Calculate Accuracy		 
			correct = 0
			total = 0
			# Predict test dataset
			for images, labels in test_loader: 
				test = Variable(images.view(-1, 28*28))
				
				# Forward propagation
				outputs = model(test)
				
				# Get predictions from the maximum value
				predicted = torch.max(outputs.data, 1)[1]
				
				# Total number of labels
				total += len(labels)
				
				# Total correct predictions
				correct += (predicted == labels).sum()
			
			accuracy = 100 * correct / float(total)
			
			# store loss and iteration
			loss_list.append(loss.data)
			iteration_list.append(count)
		if count % 500 == 0:
			# Print Loss
			print('Iteration:{}Loss:{}Accuracy:{}%'.format(count,loss.data,accuracy))

# Visualisation
plt.plot(iteration_list,loss_list)
plt.xlabel("Number of iteration")
plt.ylabel("Loss")
plt.title("Logistic Regression: Loss vs Number of iteration")
plt.show()

# Import Libraries
import torch
import torch.nn as nn
from torch.autograd import Variable

# Create Artifical Neural Network Model
class ANNModel(nn.Module):
	
	def __init__(self, input_dim, hidden_dim, output_dim):
		super(ANNModel, self).__init__()
		
		# Linear function 1: 784 --> 150
		self.fc1 = nn.Linear(input_dim, hidden_dim) 
		# Non-linearity 1
		self.relu1 = nn.ReLU()
		
		# Linear function 2: 150 --> 150
		self.fc2 = nn.Linear(hidden_dim, hidden_dim)
		# Non-linearity 2
		self.tanh2 = nn.Tanh()
		
		# Linear function 3: 150 --> 150
		self.fc3 = nn.Linear(hidden_dim, hidden_dim)
		# Non-linearity 3
		self.elu3 = nn.ELU()
		
		# Linear function 4 (readout): 150 --> 10
		self.fc4 = nn.Linear(hidden_dim, output_dim)  
	
	def forward(self,x):
		# Linear function 1
		out = self.fc1(x)
		# Non-linearity 1
		out = self.relu1(out)
		
		# Linear function 2
		out = self.fc2(out)
		# Non-linearity 2
		out = self.tanh2(out)
		
		# Linear function 2
		out = self.fc3(out)
		# Non-linearity 2
		out = self.elu3(out)
		
		# Linear function 4 (readout)
		out = self.fc4(out)
		return out

# Instantiate Artificial Neural Network
input_dim = 28*28
hidden_dim = 150 # Hidden layer dimension is one of the hyper parameters and it should be chosen and tuned. For now I only say 150 there is no reason.
output_dim = 10

# Create Artificial Neural Network
model = ANNModel(input_dim, hidden_dim, output_dim)

# Cross Entropy Loss 
error = nn.CrossEntropyLoss()

# Stochastic Gradient Descent Optimizer
learning_rate = 0.02
optimizer = torch.optim.SGD(model.parameters(), lr=learning_rate)

# Artificial Neural Network model training
count = 0
loss_list = []
iteration_list = []
accuracy_list = []
for epoch in range(num_epochs):
	for i,(images,labels) in enumerate(train_loader):

		train = Variable(images.view(-1,28*28))
		labels = Variable(labels)
		
		# Clear gradients.
		optimizer.zero_grad()
		
		# Forward propagation.
		outputs = model(train)
		
		# Calculate softmax and cross entropy loss.
		loss = error(outputs,labels)
		
		# Calculating gradients.
		loss.backward()
		
		# Update parameters.
		optimizer.step()
		
		count += 1
		
		if count % 50 == 0:
			# Calculate Accuracy		 
			correct = 0
			total = 0
			# Predict test dataset.
			for images,labels in test_loader:

				test = Variable(images.view(-1, 28*28))
				
				# Forward propagation
				outputs = model(test)
				
				# Get predictions from the maximum value
				predicted = torch.max(outputs.data, 1)[1]
				
				# Total number of labels
				total += len(labels)

				# Total correct predictions
				correct += (predicted == labels).sum()
			
			accuracy = 100 * correct / float(total)
			
			# store loss and iteration
			loss_list.append(loss.data)
			iteration_list.append(count)
			accuracy_list.append(accuracy)
		if count % 500 == 0:
			# Print Loss
			print('Iteration: {}  Loss: {}  Accuracy: {} %'.format(count, loss.data, accuracy))

# Visualisation Loss 
plt.plot(iteration_list,loss_list)
plt.xlabel("Number of iteration")
plt.ylabel("Loss")
plt.title("ANN: Loss vs Number of iteration")
plt.show()

# Visualisation Accuracy 
plt.plot(iteration_list,accuracy_list,color = "red")
plt.xlabel("Number of iteration")
plt.ylabel("Accuracy")
plt.title("ANN: Accuracy vs Number of iteration")
plt.show()

# Import Libraries
import torch
import torch.nn as nn
from torch.autograd import Variable

# Create Convolutional Neural Network Model
class CNNModel(nn.Module):
	def __init__(self):
		super(CNNModel, self).__init__()
		
		# Convolution 1
		self.cnn1 = nn.Conv2d(in_channels=1, out_channels=16, kernel_size=5, stride=1, padding=0)
		self.relu1 = nn.ReLU()
		
		# Max pool 1
		self.maxpool1 = nn.MaxPool2d(kernel_size=2)
	 
		# Convolution 2
		self.cnn2 = nn.Conv2d(in_channels=16, out_channels=32, kernel_size=5, stride=1, padding=0)
		self.relu2 = nn.ReLU()
		
		# Max pool 2
		self.maxpool2 = nn.MaxPool2d(kernel_size=2)
		
		# Fully connected 1
		self.fc1 = nn.Linear(32 * 4 * 4, 10) 
	
	def forward(self, x):
		# Convolution 1
		out = self.cnn1(x)
		out = self.relu1(out)
		
		# Max pool 1
		out = self.maxpool1(out)
		
		# Convolution 2 
		out = self.cnn2(out)
		out = self.relu2(out)
		
		# Max pool 2 
		out = self.maxpool2(out)
		
		# flatten
		out = out.view(out.size(0),-1)

		# Linear function (readout)
		out = self.fc1(out)
		
		return out

# batch_size, epoch and iteration
batch_size = 100
n_iters = 2500
num_epochs = n_iters / (len(features_train) / batch_size)
num_epochs = int(num_epochs)

# PyTorch Train And Test Sets
train = torch.utils.data.TensorDataset(featuresTrain,targetsTrain)
test = torch.utils.data.TensorDataset(featuresTest,targetsTest)

# Data Loader
train_loader = torch.utils.data.DataLoader(train, batch_size = batch_size, shuffle = False)
test_loader = torch.utils.data.DataLoader(test, batch_size = batch_size, shuffle = False)
	
# Create Convolutional Neural Network
model = CNNModel()

# Cross Entropy Loss 
error = nn.CrossEntropyLoss()

# Stochastic Gradient Descent Optimiser
learning_rate = 0.1
optimizer = torch.optim.SGD(model.parameters(), lr=learning_rate)

# Convolutional Neural Network Model Training
count = 0
loss_list = []
iteration_list = []
accuracy_list = []
for epoch in range(num_epochs):
	for i, (images, labels) in enumerate(train_loader):
		
		train = Variable(images.view(100,1,28,28))
		labels = Variable(labels)
		
		# Clear Gradients
		optimizer.zero_grad()
		
		# Forward Propagation
		outputs = model(train)
		
		# Calculate softmax And Cross Entropy Loss
		loss = error(outputs, labels)
		
		# Calculating Gradients
		loss.backward()
		
		# Update Parameters
		optimizer.step()
		
		count += 1
		
		if count % 50 == 0:
			# Calculate Accuracy		 
			correct = 0
			total = 0
			# Iterate through test dataset
			for images, labels in test_loader:
				
				test = Variable(images.view(100,1,28,28))
				
				# Forward propagation
				outputs = model(test)
				
				# Get predictions from the maximum value
				predicted = torch.max(outputs.data, 1)[1]
				
				# Total number of labels
				total += len(labels)
				
				correct += (predicted == labels).sum()
			
			accuracy = 100 * correct / float(total)
			
			# store loss and iteration
			loss_list.append(loss.data)
			iteration_list.append(count)
			accuracy_list.append(accuracy)
		if count % 500 == 0:
			# Print Loss
			print('Iteration: {}  Loss: {}  Accuracy: {} %'.format(count, loss.data, accuracy))

# visualization loss 
plt.plot(iteration_list,loss_list)
plt.xlabel("Number of iteration")
plt.ylabel("Loss")
plt.title("CNN: Loss vs Number of iteration")
plt.show()

# visualization accuracy 
plt.plot(iteration_list,accuracy_list,color = "red")
plt.xlabel("Number of iteration")
plt.ylabel("Accuracy")
plt.title("CNN: Accuracy vs Number of iteration")
plt.show()

# Kaggle
# Recurrent Neural Network With Pytorch
# https://www.kaggle.com/kanncaa1/recurrent-neural-network-with-pytorch

# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load in 

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt

# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory

import os
print(os.listdir("../input"))

# Any results you write to the current directory are saved as output.

# Import Libraries
import torch
import torch.nn as nn
from torch.autograd import Variable
from sklearn.model_selection import train_test_split
from torch.utils.data import DataLoader, TensorDataset

# Prepare Dataset
# load data
train = pd.read_csv(r"../input/train.csv",dtype = np.float32)

# split data into features(pixels) and labels(numbers from 0 to 9)
targets_numpy = train.label.values
features_numpy = train.loc[:,train.columns != "label"].values/255 # normalization

# train test split. Size of train data is 80% and size of test data is 20%. 
features_train, features_test, targets_train, targets_test = train_test_split(features_numpy,targets_numpy,test_size = 0.2,random_state = 42) 

# create feature and targets tensor for train set. As you remember we need variable to accumulate gradients. Therefore first we create tensor, then we will create variable
featuresTrain = torch.from_numpy(features_train)
targetsTrain = torch.from_numpy(targets_train).type(torch.LongTensor) # data type is long

# create feature and targets tensor for test set.
featuresTest = torch.from_numpy(features_test)
targetsTest = torch.from_numpy(targets_test).type(torch.LongTensor) # data type is long

# batch_size, epoch and iteration
batch_size = 100
n_iters = 10000
num_epochs = n_iters / (len(features_train) / batch_size)
num_epochs = int(num_epochs)

# Pytorch train and test sets
train = TensorDataset(featuresTrain,targetsTrain)
test = TensorDataset(featuresTest,targetsTest)

# data loader
train_loader = DataLoader(train, batch_size = batch_size, shuffle = False)
test_loader = DataLoader(test, batch_size = batch_size, shuffle = False)

# visualize one of the images in data set
plt.imshow(features_numpy[10].reshape(28,28))
plt.axis("off")
plt.title(str(targets_numpy[10]))
plt.savefig('graph.png')
plt.show()

# Create Recurrent Neural Network Model
class RNNModel(nn.Module):
	def __init__(self, input_dim, hidden_dim, layer_dim, output_dim):
		super(RNNModel, self).__init__()
		
		# Number of hidden dimensions
		self.hidden_dim = hidden_dim
		
		# Number of hidden layers
		self.layer_dim = layer_dim
		
		# Recurrent Neural Network
		self.rnn = nn.RNN(input_dim, hidden_dim, layer_dim, batch_first=True, nonlinearity='relu')
		
		# Readout layer
		self.fc = nn.Linear(hidden_dim, output_dim)
	
	def forward(self, x):
		
		# Initialize hidden state with zeros
		h0 = Variable(torch.zeros(self.layer_dim, x.size(0), self.hidden_dim))
			
		# One time step
		out, hn = self.rnn(x, h0)
		out = self.fc(out[:, -1, :]) 
		return out

# batch_size, epoch and iteration
batch_size = 100
n_iters = 8000
num_epochs = n_iters / (len(features_train) / batch_size)
num_epochs = int(num_epochs)

# PyTorch train and test sets
train = TensorDataset(featuresTrain,targetsTrain)
test = TensorDataset(featuresTest,targetsTest)

# data loader
train_loader = DataLoader(train, batch_size = batch_size, shuffle = False)
test_loader = DataLoader(test, batch_size = batch_size, shuffle = False)
	
# Create Recurrent Neural Network
input_dim = 28 # input dimension
hidden_dim = 100 # hidden layer dimension
layer_dim = 1 # number of hidden layers
output_dim = 10 # output dimension

model = RNNModel(input_dim, hidden_dim, layer_dim, output_dim)

# Cross Entropy Loss 
error = nn.CrossEntropyLoss()

# Stochastic Gradient Descent Optimizer
learning_rate = 0.05
optimizer = torch.optim.SGD(model.parameters(), lr=learning_rate)

seq_dim = 28  
loss_list = []
iteration_list = []
accuracy_list = []
count = 0
for epoch in range(num_epochs):
	for i, (images, labels) in enumerate(train_loader):

		train  = Variable(images.view(-1, seq_dim, input_dim))
		labels = Variable(labels )
			
		# Clear gradients
		optimizer.zero_grad()
		
		# Forward propagation
		outputs = model(train)
		
		# Calculate softmax and ross entropy loss
		loss = error(outputs, labels)
		
		# Calculating gradients
		loss.backward()
		
		# Update parameters
		optimizer.step()

		count += 1

		if count % 250 == 0:
			# Calculate Accuracy		 
			correct = 0
			total = 0
			# Iterate through test dataset
			for images, labels in test_loader:
				images = Variable(images.view(-1, seq_dim, input_dim))
				
				# Forward propagation
				outputs = model(images)
				
				# Get predictions from the maximum value
				predicted = torch.max(outputs.data, 1)[1]
				
				# Total number of labels
				total += labels.size(0)
				
				correct += (predicted == labels).sum()
			
			accuracy = 100 * correct / float(total)
			
			# store loss and iteration
			loss_list.append(loss.data)
			iteration_list.append(count)
			accuracy_list.append(accuracy)
			if count % 500 == 0:
				# Print Loss
				print('Iteration:{}Loss:{}Accuracy:{}%'.format(count,loss.data[0],accuracy))

# Visualisation loss.
plt.plot(iteration_list,loss_list)
plt.xlabel("Number Of Iteration")
plt.ylabel("Loss")
plt.title("Recurrent Neural Network: Loss vs. Number Of Iteration")
plt.show()

# Visualisation accuracy.
plt.plot(iteration_list,accuracy_list,color = "red")
plt.xlabel("Number Of Iteration")
plt.ylabel("Accuracy")
plt.title("Recurrent Neural Network: Accuracy vs. Number Of Iteration")
plt.savefig('graph.png')
plt.show()

# Kaggle
# Data Science Tutorial For Beginners
# https://www.kaggle.com/kanncaa1/data-sciencetutorial-for-beginners

# This Python 3 environment comes with many helpful analytics libraries installed.
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here are several helpful packages to load in.

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
import seaborn as sns  # visualization tool

# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory

from subprocess import check_output
print(check_output(["ls", "../input"]).decode("utf8"))

import os
for dirname, _, filenames in os.walk("/kaggle/input"):
	for filename in filenames:
		print(os.path.join(dirname, filename))
# Any results you write to the current directory are saved as output.

#data = pd.read_csv('/kaggle/input/pokemon.csv')
#data.head()

data = pd.read_csv('../input/pokemon.csv')
data.head()
data.info()
data.corr()

# Correlation Map
f,ax = plt.subplots(figsize=(18, 18))
sns.heatmap(data.corr(),annot=True,linewidths=.5,fmt='.1f',ax=ax)
plt.show()
data.head(10)
data.columns

# Line Plot
# color = color, label = label, linewidth = width of line, alpha = opacity, grid = grid, linestyle = sytle of line
data.Speed.plot(kind='line',color='g',label='Speed',linewidth=1,alpha=0.5,grid=True,linestyle=':')
data.Defense.plot(color='r',label='Defense',linewidth=1,alpha=0.5,grid=True,linestyle='-.')
plt.legend(loc='upper right') # legend = puts label into plot
plt.xlabel('x axis') # label = name of label
plt.ylabel('y axis')
plt.title('Line Plot') # title = title of plot
plt.show()

# Scatter Plot 
# x = attack, y = defense
data.plot(kind='scatter', x='Attack', y='Defense',alpha = 0.5,color = 'red')
plt.xlabel('Attack') # label = name of label
plt.ylabel('Defence')
plt.title('Attack Defense Scatter Plot') # title = title of plot

# Histogram
# bins = number of bar in figure
data.Speed.plot(kind='hist',bins=50,figsize=(12,12))
plt.show()

# clf() = cleans it up again you can start a fresh
data.Speed.plot(kind='hist',bins=50)
plt.clf()
# We cannot see plot due to clf()

# Create dictionary and look its keys and values.
dictionary={'spain':'madrid','usa':'vegas'}
print(dictionary.keys())
print(dictionary.values())

# Keys have to be immutable objects like string, boolean, float, integer or tubles.
# List is not immutable.
# Keys are unique.
dictionary['spain']="barcelona" # update existing entry
print(dictionary)
dictionary['france']="paris" # Add new entry
print(dictionary)
del dictionary['spain'] # remove entry with key 'spain'
print(dictionary)
print('france' in dictionary) # check include or not
dictionary.clear() # remove all entries in dict
print(dictionary)

# In order to run all code you need to take comment this line
# del dictionary # delete entire dictionary	 
print(dictionary) # it gives error because dictionary is deleted

data = pd.read_csv('../input/pokemon.csv')

series = data['Defense'] # data['Defense'] = series
print(type(series))
data_frame = data[['Defense']] # data[['Defense']] = data frame
print(type(data_frame))

# Comparison operator
print(3 > 2)
print(3!=2)
# Boolean operators
print(True and False)
print(True or False)

# 1 - Filtering Pandas data frame
x = data['Defense']>200	 # There are only 3 pokemons who have higher defense value than 200
data[x]

# 2 - Filtering pandas with logical_and
# There are only 2 pokemons who have higher defence value than 2oo and higher attack value than 100
data[np.logical_and(data['Defense']>200, data['Attack']>100)]

# This is also same with previous code line. Therefore we can also use '&' for filtering.
data[(data['Defense']>200) & (data['Attack']>100)]

# Stay in loop if condition (i is not equal 5) is true.
i = 0
while i != 5 :
	print('i is: ',i)
	i += 1
print(i,' is equal to 5')

# Stay in loop if condition (i is not equal 5) is true.
lis = [1,2,3,4,5]
for i in lis:
	print('i is: ',i)
print('')

# Enumerate index and value of list
# index : value = 0:1, 1:2, 2:3, 3:4, 4:5
for index,value in enumerate(lis):
	print(index," : ",value)
print('')   

# For dictionaries.
# We can use for loop to achive key and value of dictionary. We learnt key and value at dictionary part.
dictionary={'spain':'madrid','france':'paris'}
for key,value in dictionary.items():
	print(key," : ",value)
print('')

# For pandas we can achieve index and value.
for index,value in data[['Attack']][0:1].iterrows():
	print(index," : ",value)

# Example of what we learn above.
def tuple_ex():
	""" return defined t tuple"""
	t = (1,2,3)
	return t
a,b,c = tuple_ex()
print(a,b,c)

# guess prints what
x = 2
def f():
	x = 3
	return x
print(x) # x = 2 global scope
print(f()) # x = 3 local scope

# What if there is no local scope
x = 5
def f():
	y = 2*x # there is no local scope x
	return y
print(f()) # it uses global scope x  
# First local scope searched, then global scope searched, if two of them cannot be found lastly built in scope searched.

# How can we learn what is built in scope
import builtins
dir(builtins)

# Nested function
def square():
	""" return square of value """
	def add():
		""" add two local variable """
		x = 2
		y = 3
		z = x + y
		return z
	return add()**2
print(square())

# default arguments
def f(a, b = 1, c = 2):
	y = a + b + c
	return y
print(f(5))
# what if we want to change default arguments
print(f(5,4,3))

# flexible arguments *args
def f(*args):
	for i in args:
		print(i)
f(1)
print("")
f(1,2,3,4)
# flexible arguments **kwargs that is dictionary
def f(**kwargs):
	""" print key and value of dictionary"""
	for key, value in kwargs.items():			   # If you do not understand this part turn for loop part and look at dictionary in for loop
		print(key, " ", value)
f(country = 'spain', capital = 'madrid', population = 123456)

# lambda function
square = lambda x: x**2	 # where x is name of argument
print(square(4))
tot = lambda x,y,z: x+y+z   # where x,y,z are names of arguments
print(tot(1,2,3))

number_list = [1,2,3]
y = map(lambda x:x**2,number_list)
print(list(y))

# iteration example
name = "ronaldo"
it = iter(name)
print(next(it))	# print next iteration
print(*it)		 # print remaining iteration

# zip example
list1 = [1,2,3,4]
list2 = [5,6,7,8]
z = zip(list1,list2)
print(z)
z_list = list(z)
print(z_list)

un_zip = zip(*z_list)
un_list1,un_list2 = list(un_zip) # unzip returns tuple
print(un_list1)
print(un_list2)
print(type(un_list2))

# Example of list comprehension
num1 = [1,2,3]
num2 = [i + 1 for i in num1 ]
print(num2)

# Conditionals on iterable
num1 = [5,10,15]
num2 = [i**2 if i == 10 else i-5 if i < 7 else i+5 for i in num1]
print(num2)

# lets return pokemon csv and make one more list comprehension example
# lets classify pokemons whether they have high or low speed. Our threshold is average speed.
threshold = sum(data.Speed)/len(data.Speed)
data["speed_level"] = ["high" if i > threshold else "low" for i in data.Speed]
data.loc[:10,["speed_level","Speed"]] # we will learn loc more detailed later

data = pd.read_csv('../input/pokemon.csv')
data.head() # head shows first 5 rows

# tail shows last 5 rows
data.tail()

# columns gives column names of features
data.columns

# shape gives number of rows and columns in a tuble
data.shape

# info gives data type like dataframe, number of sample or row, number of feature or column, feature types and memory usage
data.info()

# For example lets look frequency of pokemom types
print(data['Type 1'].value_counts(dropna =False))  # if there are nan values that also be counted
# As it can be seen below there are 112 water pokemon or 70 grass pokemon

1,2,3,4,200

# For example max HP is 255 or min defense is 5
data.describe() #ignore null entries

# For example: compare attack of pokemons that are legendary  or not
# Black line at top is max
# Blue line at top is 75%
# Green line is median (50%)
# Blue line at bottom is 25%
# Black line at bottom is min
# There are no outliers
data.boxplot(column='Attack',by = 'Legendary')

# Firstly I create new data from pokemons data to explain melt nore easily.
data_new = data.head() # I only take 5 rows into new data
data_new

# lets melt
# id_vars = what we do not wish to melt
# value_vars = what we want to melt
melted = pd.melt(frame=data_new,id_vars = 'Name', value_vars= ['Attack','Defense'])
melted

# Index is name
# I want to make that columns are variable
# Finally values in columns are value
melted.pivot(index = 'Name', columns = 'variable',values='value')

# Firstly lets create 2 data frame
data1 = data.head()
data2= data.tail()
conc_data_row = pd.concat([data1,data2],axis =0,ignore_index =True) # axis = 0 : adds dataframes in row
conc_data_row

data1 = data['Attack'].head()
data2= data['Defense'].head()
conc_data_col = pd.concat([data1,data2],axis =1) # axis = 1 : adds dataframes in column
conc_data_col

data.dtypes

# lets convert object(str) to categorical and int to float.
data['Type 1'] = data['Type 1'].astype('category')
data['Speed'] = data['Speed'].astype('float')

# As you can see Type 1 is converted from object to categorical
# And Speed ,s converted from int to float
data.dtypes

# Lets look at does pokemon data have nan value
# As you can see there are 800 entries. However Type 2 has 414 non-null object so it has 386 null object.
data.info()

# Lets check Type 2
data["Type 2"].value_counts(dropna =False)
# As you can see, there are 386 NAN value

# Lets drop nan values
data1=data # also we will use data to fill missing value so I assign it to data1 variable
data1["Type 2"].dropna(inplace = True)  # inplace = True means we do not assign it to new variable. Changes automatically assigned to data
# So does it work ?

# Lets check with assert statement
# Assert statement:
assert 1==1 # return nothing because it is true

# In order to run all code, we need to make this line comment
# assert 1==2 # return error because it is false

assert data['Type 2'].notnull().all() # returns nothing because we drop nan values

data["Type 2"].fillna('empty',inplace=True)

assert data['Type 2'].notnull().all() # returns nothing because we do not have nan values

# # With assert statement we can check a lot of thing. For example
# assert data.columns[1] == 'Name'
# assert data.Speed.dtypes == np.int

# data frames from dictionary
country = ["Spain","France"]
population = ["11","12"]
list_label = ["country","population"]
list_col = [country,population]
zipped = list(zip(list_label,list_col))
data_dict = dict(zipped)
df = pd.DataFrame(data_dict)
df

# Add new columns
df["capital"] = ["madrid","paris"]
df

# Broadcasting
df["income"] = 0 # Broadcasting entire column
df

# Plotting all data.
data1 = data.loc[:,["Attack","Defense","Speed"]]
data1.plot()
# It is confusing.

# Subplots.
data1.plot(subplots=True)
plt.show()

# Scatter plot.
data1.plot(kind="scatter",x="Attack",y="Defense")
plt.show()

# Histogram plot.
data1.plot(kind="hist",y="Defense",bins=50,range=(0,250),normed=True)

# Histogram subplot with non cumulative and cumulative.
fig,axes=plt.subplots(nrows=2,ncols=1)
data1.plot(kind="hist",y="Defense",bins=50,range=(0,250),normed=True,ax=axes[0])
data1.plot(kind="hist",y="Defense",bins=50,range=(0,250),normed=True,ax=axes[1],cumulative=True)
plt.savefig('graph.png')
plt

data.describe()

time_list=["1992-03-08","1992-04-12"]
print(type(time_list[1])) # As you can see date is string
# however we want it to be datetime object
datetime_object = pd.to_datetime(time_list)
print(type(datetime_object))

# close warning
import warnings
warnings.filterwarnings("ignore")
# In order to practice lets take head of pokemon data and add it a time list
data2 = data.head()
date_list = ["1992-01-10","1992-02-10","1992-03-10","1993-03-15","1993-03-16"]
datetime_object = pd.to_datetime(date_list)
data2["date"] = datetime_object
# lets make date as index
data2 = data2.set_index("date")
data2

# Now we can select according to our date index
print(data2.loc["1993-03-16"])
print(data2.loc["1992-03-10":"1993-03-16"])

# We will use data2 that we create at previous part
data2.resample("A").mean()

# Lets resample with month
data2.resample("M").mean()
# As you can see there are a lot of nan because data2 does not include all months

# In real life (data is real. Not created from us like data2) we can solve this problem with interpolate
# We can interpolete from first value
data2.resample("M").first().interpolate("linear")

# Or we can interpolate with mean()
data2.resample("M").mean().interpolate("linear")

# read data
data = pd.read_csv('../input/pokemon.csv')
data = data.set_index("#")
data.head()

# indexing using square brackets
data["HP"][1]

# using column attribute and row label
data.HP[1]

# Using loc accessor.
data.loc[1,["HP"]]

# Selecting only some columns.
data[["HP","Attack"]]

# Difference between selecting columns: series and dataframes.
print(type(data["HP"])) # Series.
print(type(data[["HP"]])) # Data frames.

# Slicing and indexing series.
data.loc[1:10,"HP":"Defense"] # 10 and "Defense" are inclusive.

# Reverse slicing.
data.loc[10:1:-1,"HP":"Defense"] 

# From something to end.
data.loc[1:10,"Speed":] 

# Creating boolean series.
boolean=data.HP>200
data[boolean]

# Combining filters.
first_filter = data.HP > 150
second_filter = data.Speed > 35
data[first_filter & second_filter]

# Filtering column based others
data.HP[data.Speed<15]

# Plain python functions
def div(n):
	return n/2
data.HP.apply(div)

# Or we can use lambda function
data.HP.apply(lambda n : n/2)

# Defining column using other columns
data["total_power"] = data.Attack + data.Defense
data.head()

# our index name is this:
print(data.index.name)
# lets change it
data.index.name = "index_name"
data.head()

# Overwrite index
# if we want to modify index we need to change all of them.
data.head()
# first copy of our data to data3 then change index 
data3 = data.copy()
# lets make index start from 100. It is not remarkable change but it is just example
data3.index = range(100,900,1)
data3.head()

# We can make one of the column as index. I actually did it at the beginning of manipulating data frames with pandas section
# It was like this
# data= data.set_index("#")
# also you can use 
# data.index = data["#"]

# lets read data frame one more time to start from beginning
data = pd.read_csv('../input/pokemon.csv')
data.head()
# As you can see there is index. However we want to set one or more column to be index

# Setting index : type 1 is outer type 2 is inner index
data1 = data.set_index(["Type 1","Type 2"]) 
data1.head(100)
# data1.loc["Fire","Flying"] # howw to use indexes

dic = {"treatment":["A","A","B","B"],"gender":["F","M","F","M"],"response":[10,45,5,9],"age":[15,4,72,65]}
df = pd.DataFrame(dic)
df

# pivoting
df.pivot(index="treatment",columns = "gender",values="response")

df1 = df.set_index(["treatment","gender"])
df1
# lets unstack it

# level determines indexes
df1.unstack(level=0)

df1.unstack(level=1)

# change inner and outer level index position
df2 = df1.swaplevel(0,1)
df2

df

# df.pivot(index="treatment",columns = "gender",values="response")
pd.melt(df,id_vars="treatment",value_vars=["age","response"])

# We will use df
df

# according to treatment take means of other features
df.groupby("treatment").mean()   # mean is aggregation / reduction method
# there are other methods like sum, std,max or min

# we can only choose one of the feature
df.groupby("treatment").age.max() 

# Or we can choose multiple features
df.groupby("treatment")[["age","response"]].min() 

df.info()
# as you can see gender is object
# However if we use groupby, we can convert it categorical data. 
# Because categorical data uses less memory, speed up operations like groupby
#df["gender"] = df["gender"].astype("category")
#df["treatment"] = df["treatment"].astype("category")
#df.info()

# Kaggle
# Machine Learning Tutorial For Beginners
# https://www.kaggle.com/kanncaa1/machine-learning-tutorial-for-beginners

# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load in 

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
import seaborn as sns
# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory
# import warnings
import warnings
# ignore warnings
warnings.filterwarnings("ignore")
from subprocess import check_output
print(check_output(["ls", "../input"]).decode("utf8"))

# Any results you write to the current directory are saved as output.

# read csv (comma separated value) into data
data = pd.read_csv('../input/column_2C_weka.csv')
print(plt.style.available) # look at available plot styles

# ['seaborn-colorblind', 'seaborn-poster', 'ggplot', 'seaborn-pastel', 'seaborn-dark-palette', 'seaborn-notebook', 'seaborn-darkgrid', 'seaborn-paper', 'seaborn-ticks', 'seaborn', 'seaborn-dark', '_classic_test', 'classic', 'bmh', 'Solarize_Light2', 'fast', 'dark_background', 'seaborn-talk', 'fivethirtyeight', 'seaborn-white', 'seaborn-bright', 'grayscale', 'seaborn-muted', 'seaborn-whitegrid', 'seaborn-deep']

plt.style.use('ggplot')

# to see features and target variable
data.head()

# Well know question is is there any NaN value and length of this data so lets look at info
data.info()

data.describe()

color_list = ['red' if i=='Abnormal' else 'green' for i in data.loc[:,'class']]
pd.plotting.scatter_matrix(data.loc[:, data.columns != 'class'],
									   c=color_list,
									   figsize= [15,15],
									   diagonal='hist',
									   alpha=0.5,
									   s = 200,
									   marker = '*',
									   edgecolor= "black")
plt.show()

sns.countplot(x="class", data=data)
data.loc[:,'class'].value_counts()

# K Nearest Neighbours
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors = 3)
x,y = data.loc[:,data.columns != 'class'], data.loc[:,'class']
knn.fit(x,y)
prediction = knn.predict(x)
print('Prediction: {}'.format(prediction))

# train test split
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size = 0.3,random_state = 1)
knn = KNeighborsClassifier(n_neighbors = 3)
x,y = data.loc[:,data.columns != 'class'], data.loc[:,'class']
knn.fit(x_train,y_train)
prediction = knn.predict(x_test)
#print('Prediction: {}'.format(prediction))
print('With KNN (K=3) accuracy is: ',knn.score(x_test,y_test)) # accuracy

# Model complexity
neig = np.arange(1, 25)
train_accuracy = []
test_accuracy = []
# Loop over different values of k
for i, k in enumerate(neig):
	# k from 1 to 25(exclude)
	knn = KNeighborsClassifier(n_neighbors=k)
	# Fit with knn
	knn.fit(x_train,y_train)
	# train accuracy
	train_accuracy.append(knn.score(x_train, y_train))
	# test accuracy
	test_accuracy.append(knn.score(x_test, y_test))

# Plot
plt.figure(figsize=[13,8])
plt.plot(neig, test_accuracy, label = 'Testing Accuracy')
plt.plot(neig, train_accuracy, label = 'Training Accuracy')
plt.legend()
plt.title('-value VS Accuracy')
plt.xlabel('Number of Neighbors')
plt.ylabel('Accuracy')
plt.xticks(neig)
plt.savefig('graph.png')
plt.show()
print("Best accuracy is {} with K = {}".format(np.max(test_accuracy),1+test_accuracy.index(np.max(test_accuracy))))

# create data1 that includes pelvic_incidence that is feature and sacral_slope that is target variable
data1 = data[data['class'] =='Abnormal']
x = np.array(data1.loc[:,'pelvic_incidence']).reshape(-1,1)
y = np.array(data1.loc[:,'sacral_slope']).reshape(-1,1)
# Scatter
plt.figure(figsize=[10,10])
plt.scatter(x=x,y=y)
plt.xlabel('pelvic_incidence')
plt.ylabel('sacral_slope')
plt.show()

# Linear Regression
from sklearn.linear_model import LinearRegression
reg = LinearRegression()
# Predict space.
predict_space = np.linspace(min(x), max(x)).reshape(-1,1)
# Fit
reg.fit(x,y)
# Predict
predicted = reg.predict(predict_space)
# R^2 
print('R^2 score: ',reg.score(x, y))
# Plot regression line and scatter.
plt.plot(predict_space, predicted, color='black', linewidth=3)
plt.scatter(x=x,y=y)
plt.xlabel('pelvic_incidence')
plt.ylabel('sacral_slope')
plt.show()

# Cross Validation
from sklearn.model_selection import cross_val_score
reg = LinearRegression()
k = 5
cv_result = cross_val_score(reg,x,y,cv=k) # Uses R^2 as score.
print('CV Scores: ',cv_result)
print('CV scores average: ',np.sum(cv_result)/k)

# L2 Ridge
from sklearn.linear_model import Ridge
x_train,x_test,y_train,y_test = train_test_split(x,y,random_state = 2, test_size = 0.3)
ridge = Ridge(alpha = 0.1, normalize = True)
ridge.fit(x_train,y_train)
ridge_predict = ridge.predict(x_test)
print('Ridge score: ',ridge.score(x_test,y_test))

# L1 Lasso
from sklearn.linear_model import Lasso
x = np.array(data1.loc[:,['pelvic_incidence','pelvic_tilt numeric','lumbar_lordosis_angle','pelvic_radius']])
x_train,x_test,y_train,y_test = train_test_split(x,y,random_state = 3, test_size = 0.3)
lasso = Lasso(alpha = 0.1, normalize = True)
lasso.fit(x_train,y_train)
ridge_predict = lasso.predict(x_test)
print('Lasso score: ',lasso.score(x_test,y_test))
print('Lasso coefficients: ',lasso.coef_)

# Confusion matrix with random forest.
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.ensemble import RandomForestClassifier
x,y = data.loc[:,data.columns != 'class'], data.loc[:,'class']
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size = 0.3,random_state = 1)
rf = RandomForestClassifier(random_state = 4)
rf.fit(x_train,y_train)
y_pred = rf.predict(x_test)
cm = confusion_matrix(y_test,y_pred)
print('Confusion matrix: \n',cm)
print('Classification report: \n',classification_report(y_test,y_pred))

# Visualise with seaborn library.
sns.heatmap(cm,annot=True,fmt="d") 
plt.show()

# Receiver Operating Characteristic Curve with logistic regression.
from sklearn.metrics import roc_curve
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix,classification_report
# abnormal=1 and normal=0
data['class_binary'] = [1 if i == 'Abnormal' else 0 for i in data.loc[:,'class']]
x,y = data.loc[:,(data.columns != 'class') & (data.columns != 'class_binary')], data.loc[:,'class_binary']
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.3, random_state=42)
logreg = LogisticRegression()
logreg.fit(x_train,y_train)
y_pred_prob = logreg.predict_proba(x_test)[:,1]
fpr, tpr, thresholds = roc_curve(y_test, y_pred_prob)
# Plot Receiver Operating Characteristic Curve.
plt.plot([0, 1], [0, 1], 'k--')
plt.plot(fpr, tpr)
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('ROC')
plt.show()

# Grid search cross validation with 1 hyperparameter.
from sklearn.model_selection import GridSearchCV
grid = {'n_neighbors': np.arange(1,50)}
knn = KNeighborsClassifier()
knn_cv = GridSearchCV(knn, grid, cv=3) # Grid Search Cross Validation
knn_cv.fit(x,y)# Fit

# Print hyperparameter
print("Tuned hyperparameter k: {}".format(knn_cv.best_params_)) 
print("Best score: {}".format(knn_cv.best_score_))

# grid search cross validation with 2 hyperparameter
# 1. hyperparameter is C:logistic regression regularization parameter
# 2. penalty l1 or l2
# Hyperparameter grid
param_grid = {'C': np.logspace(-3, 3, 7), 'penalty': ['l1', 'l2']}
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size = 0.3,random_state = 12)
logreg = LogisticRegression()
logreg_cv = GridSearchCV(logreg,param_grid,cv=3)
logreg_cv.fit(x_train,y_train)

# Print the optimal parameters and best score
print("Tuned hyperparameters : {}".format(logreg_cv.best_params_))
print("Best Accuracy: {}".format(logreg_cv.best_score_))

# Load data
data = pd.read_csv('../input/column_2C_weka.csv')
# get_dummies
df = pd.get_dummies(data)
df.head(10)

# drop one of the feature
df.drop("class_Normal",axis = 1, inplace = True) 
df.head(10)
# instead of two steps we can make it with one step pd.get_dummies(data,drop_first = True)

# Support Vector Machines, pre-process and pipeline
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline
steps = [('scalar', StandardScaler()),
		 ('SVM', SVC())]
pipeline = Pipeline(steps)
parameters = {'SVM__C':[1, 10, 100],
			  'SVM__gamma':[0.1, 0.01]}
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2,random_state = 1)
cv = GridSearchCV(pipeline,param_grid=parameters,cv=3)
cv.fit(x_train,y_train)

y_pred = cv.predict(x_test)

print("Accuracy: {}".format(cv.score(x_test, y_test)))
print("Tuned Model Parameters: {}".format(cv.best_params_))

# As you can see there is no labels in data
data = pd.read_csv('../input/column_2C_weka.csv')
plt.scatter(data['pelvic_radius'],data['degree_spondylolisthesis'])
plt.xlabel('pelvic_radius')
plt.ylabel('degree_spondylolisthesis')
plt.show()

# K Means Clustering: The algorithm works iteratively to assign each data point to one of K groups based on the features that are provided. Data points are clustered based on feature similarity
data2 = data.loc[:,['degree_spondylolisthesis','pelvic_radius']]
from sklearn.cluster import KMeans
kmeans = KMeans(n_clusters = 2)
kmeans.fit(data2)
labels = kmeans.predict(data2)
plt.scatter(data['pelvic_radius'],data['degree_spondylolisthesis'],c = labels)
plt.xlabel('pelvic_radius')
plt.xlabel('degree_spondylolisthesis')
plt.show()

# cross tabulation table
df = pd.DataFrame({'labels':labels,"class":data['class']})
ct = pd.crosstab(df['labels'],df['class'])
print(ct)

# inertia
inertia_list = np.empty(8)
for i in range(1,8):
	kmeans = KMeans(n_clusters=i)
	kmeans.fit(data2)
	inertia_list[i] = kmeans.inertia_
plt.plot(range(0,8),inertia_list,'-o')
plt.xlabel('Number of cluster')
plt.ylabel('Inertia')
plt.show()

data = pd.read_csv('../input/column_2C_weka.csv')
data3 = data.drop('class',axis = 1)

from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline
scalar = StandardScaler()
kmeans = KMeans(n_clusters = 2)
pipe = make_pipeline(scalar,kmeans)
pipe.fit(data3)
labels = pipe.predict(data3)
df = pd.DataFrame({'labels':labels,"class":data['class']})
ct = pd.crosstab(df['labels'],df['class'])
print(ct)

from scipy.cluster.hierarchy import linkage,dendrogram

merg = linkage(data3.iloc[200:220,:],method = 'single')
dendrogram(merg, leaf_rotation = 90, leaf_font_size = 6)
plt.show()

from sklearn.manifold import TSNE
model = TSNE(learning_rate=100)
transformed = model.fit_transform(data2)
x = transformed[:,0]
y = transformed[:,1]
plt.scatter(x,y,c = color_list )
plt.xlabel('pelvic_radius')
plt.xlabel('degree_spondylolisthesis')
plt.show()

# Principal Component Analysis
from sklearn.decomposition import PCA
model = PCA()
model.fit(data3)
transformed = model.transform(data3)
print('Principle components: ',model.components_)

# Principal Component Analysis Variance
scaler = StandardScaler()
pca = PCA()
pipeline = make_pipeline(scaler,pca)
pipeline.fit(data3)

plt.bar(range(pca.n_components_), pca.explained_variance_)
plt.xlabel('PCA feature')
plt.ylabel('variance')
plt.show()

# Apply Principal Component Analysis
pca = PCA(n_components = 2)
pca.fit(data3)
transformed = pca.transform(data3)
x = transformed[:,0]
y = transformed[:,1]
plt.scatter(x,y,c = color_list)
plt.show()

# Towards Data Science
# How To Use A Pre Trained Model Visual Geometry Group For Image Classification
# https://towardsdatascience.com/how-to-use-a-pre-trained-model-vgg-for-image-classification-8dd7c4a4a517

from keras.applications.vgg16 import VGG16 # Visual Geometry Group
model=VGG16(weights='imagenet')
print(model.summary())

from tensorflow.keras.preprocessing import image
from tensorflow.keras.applications.vgg16 import preprocess_input,decode_predictions
import numpy as np

img_path = '/kaggle/input/images/dog.jpg'
# Interpolation method to match the source size with the target size.
# Image loaded in PIL [Python Imaging Library]
img = image.load_img(img_path,color_mode='rgb', target_size=(224, 224))
display(img)

# Converts a PIL [Python Imaging Library] Image to 3D NumPy Array
x = image.img_to_array(img)
x.shape
# Adding the 4th dimension, for number of images.
x = np.expand_dims(x, axis=0)

# mean centering with respect to Image
x = preprocess_input(x)
features = model.predict(x)
p = decode_predictions(features)

# Analytics Vidhya
# Which Algorithm Takes The Crown: Light Gradient Boosting Machines Versus Extreme Gradient Boosting?
# https://www.analyticsvidhya.com/blog/2017/06/which-algorithm-takes-the-crown-light-gbm-vs-xgboost/

# Loading our training dataset 'adult.csv' with name 'data' using pandas.
data=pd.read_csv('adult.csv',header=None) 

# Assigning names to the columns.
data.columns=['age','workclass','fnlwgt','education','education-num','marital_Status','occupation','relationship','race','sex','capital_gain','capital_loss','hours_per_week','native_country','Income'] 

# Glimpse of the dataset.
data.head()

# Label Encoding our target variable.
from sklearn.preprocessing import LabelEncoder,OneHotEncoder
l=LabelEncoder() 
l.fit(data.Income) 

l.classes_ 
data.Income=Series(l.transform(data.Income)) # Label encoding our target variable.
data.Income.value_counts() 

# One Hot Encoding of the Categorical features.
one_hot_workclass=pd.get_dummies(data.workclass) 
one_hot_education=pd.get_dummies(data.education) 
one_hot_marital_Status=pd.get_dummies(data.marital_Status) 
one_hot_occupation=pd.get_dummies(data.occupation)
one_hot_relationship=pd.get_dummies(data.relationship) 
one_hot_race=pd.get_dummies(data.race) 
one_hot_sex=pd.get_dummies(data.sex) 
one_hot_native_country=pd.get_dummies(data.native_country) 

# Removing categorical features.
data.drop(['workclass','education','marital_Status','occupation','relationship','race','sex','native_country'],axis=1,inplace=True)

# Merging one hot encoded features with our dataset 'data'.
data=pd.concat([data,one_hot_workclass,one_hot_education,one_hot_marital_Status,one_hot_occupation,one_hot_relationship,one_hot_race,one_hot_sex,one_hot_native_country],axis=1) 

# Removing duplicate columns.
_,i=np.unique(data.columns, return_index=True) 
data=data.iloc[:, i] 

# Here our target variable is 'Income' with values as 1 or 0.  
# Separating our data into features dataset x and our target dataset y.
x=data.drop('Income',axis=1) 
y=data.Income

# Imputing missing values in our target variable.
y.fillna(y.mode()[0],inplace=True) 

# Now splitting our dataset into test and train.
from sklearn.model_selection import train_test_split 
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=.3)

# Applying Extreme Gradient Boosting

# The data is stored in a DMatrix object.
# Label is used to define our outcome variable.
dtrain=xgb.DMatrix(x_train,label=y_train)
dtest=xgb.DMatrix(x_test)

# Setting parameters for Extreme Gradient Boosting.
parameters={'max_depth':7, 'eta':1, 'silent':1,'objective':'binary:logistic','eval_metric':'auc','learning_rate':.05}

# Maximum Depth Of Tree
# Maximum depth of a tree. Increasing this value will make the model more complex and more likely to overfit. 0 is only accepted in lossguide growing policy when tree_method is set as hist or gpu_hist and it indicates no limit on depth. Beware that XGBoost aggressively consumes memory when training a deep tree.
# Area Under Curve Receive Operating Characteristics Curve
# Performance Measurement For Classification Problems At Various Threshold Settings
# eta: Step size shrinkage used in update to prevents overfitting. After each boosting step, we can directly get the weights of new features, and eta shrinks the feature weights to make the boosting process more conservative.
# verbosity: Verbosity of printing messages. Valid values of 0 (silent), 1 (warning), 2 (info), and 3 (debug).
# Can Read Technical Documentation
# https://xgboost.readthedocs.io/en/stable/parameter.html
# Or elsewhere contains all this stuff and much more.

# Training our model.
num_round=50
from datetime import datetime 
start = datetime.now() 
xg=xgb.train(parameters,dtrain,num_round) 
stop = datetime.now()

# Execution time of the model.
execution_time_xgb = stop-start 
execution_time_xgb

# datetime.timedelta(,,) representation => (days,seconds,microseconds) 
# Now predicting our model on test set.
ypred=xg.predict(dtest) 
ypred

# Converting probabilities into 1 or 0  
for i in range(0,9769):
	if ypred[i]>=.5: # Setting threshold to .5 
	   ypred[i]=1
	else:
	   ypred[i]=0

# Calculating accuracy of our model.
from sklearn.metrics import accuracy_score 
accuracy_xgb=accuracy_score(y_test,ypred) 
accuracy_xgb

# Light Gradient Boosting Machines

train_data=lgb.Dataset(x_train,label=y_train)

# Setting parameters for Light Gradient Boosting Machines.
param = {'num_leaves':150, 'objective':'binary','max_depth':7,'learning_rate':.05,'max_bin':200}
param['metric']=['auc','binary_logloss']

# Here we have set max_depth in Extreme Gradient Boost and Light Gradient Boosting Machines to 7 to have a "fair" comparison between the two.

# Training our model using Light Gradient Boosting Machines.
num_round=50
start=datetime.now()
lgbm=lgb.train(param,train_data,num_round)
stop=datetime.now()

# Execution time of the model.
execution_time_lgbm=stop-start
execution_time_lgbm

# Predicting on test set.
ypred2=lgbm.predict(x_test)
ypred2[0:5] # Showing first 5 predictions.

# Converting probabilities into 0 or 1.
for i in range(0,9769):
	if ypred2[i]>=.5: # Setting threshold to .5
	   ypred2[i]=1
	else:
	   ypred2[i]=0

# Calculating accuracy.
accuracy_lgbm=accuracy_score(ypred2,y_test)
accuracy_lgbm
y_test.value_counts()

from sklearn.metrics import roc_auc_score

# Calculating roc_auc_score for Extreme Gradient Boosting.
auc_xgb=roc_auc_score(y_test,ypred)
auc_xgb

# Calculating roc_auc_score for Light Gradient Boosting Machines.
auc_lgbm=roc_auc_score(y_test,ypred2)
auc_lgbm comparison_dict={'accuracy score':(accuracy_lgbm,accuracy_xgb),'auc score':(auc_lgbm,auc_xgb),'execution time':(execution_time_lgbm,execution_time_xgb)}

# Creating a dataframe ‘comparison_df’ for comparing the performance of Light Gradient Boosting Machines and Extreme Gradient Boosting. 
comparison_df=DataFrame(comparison_dict) 
comparison_df.index=['LightGBM','xgboost'] 
comparison_df

# K Means Clustering Algorithm Implementation
# https://towardsdatascience.com/k-means-clustering-algorithm-implementation-da0f735ab0f9

import pandas as pd
import numpy as np
import plotly.offline as plt
import plotly.graph_objs as go

k_means = (data.sample(k, replace=False))	# store current means
k_means2 = pd.DataFrame()					# store previous means
clusters = pd.DataFrame()					# store distances

while not k_means2.equals(k_means):
	# distance matrix (euclidean distance)
	cluster_count=0
	for idx, k_mean in k_means.iterrows():
		clusters[cluster_count]=(data[k_means.columns]-np.array(k_mean)).pow(2).sum(1).pow(0.5)
		cluster_count+=1

	# update cluster
	data['MDCluster'] = clusters.idxmin(axis=1)

	# store previous cluster
	k_means2 = k_means
	k_means = pd.DataFrame()
	k_means_frame = data.groupby('MDCluster').agg(np.mean)

	k_means[k_means_frame.columns]=k_means_frame[k_means_frame.columns]

# plotting
data_graph = [go.Scatter(
			  x=data['V1'],
			  y=data['V2'].where(data['MDCluster'] == c),
			  mode='markers',
			  name='Cluster: ' + str(c)
			  ) for c in range(k)]

data_graph.append(
	go.Scatter(
		x=k_means['V1'],
		y=k_means['V2'],
		mode='markers',
		marker=dict(
			size=10,
			color='#000000',
		),
		name='Centroids of Clusters'
	)
)

plt.plot(data_graph, filename='../output_files/cluster.html')

# Stock Market Analysis + Prediction Using Long Short Term Memory
# Kaggle
# https://www.kaggle.com/faressayah/stock-market-analysis-prediction-using-lstm

import pandas as pd
import numpy as np

import matplotlib.pyplot as plt
import seaborn as sns
sns.set_style('whitegrid')
plt.style.use("fivethirtyeight")
%matplotlib inline

# For reading stock data from yahoo
from pandas_datareader.data import DataReader
import yfinance as yf

# For time stamps
from datetime import datetime

# The tech stocks we'll use for this analysis
tech_list = ['AAPL', 'GOOG', 'MSFT', 'AMZN']

# Set up End and Start times for data grab
tech_list = ['AAPL', 'GOOG', 'MSFT', 'AMZN']

end = datetime.now()
start = datetime(end.year - 1, end.month, end.day)

for stock in tech_list:
	globals()[stock] = yf.download(stock, start, end)

# for company, company_name in zip(company_list, tech_list):
#	 company["company_name"] = company_name

company_list = [AAPL, GOOG, MSFT, AMZN]
company_name = ["APPLE", "GOOGLE", "MICROSOFT", "AMAZON"]

for company, com_name in zip(company_list, company_name):
	company["company_name"] = com_name
	
df = pd.concat(company_list, axis=0)
df.tail(10)

# Summary Stats
AAPL.describe()

# General info
AAPL.info()

# Let's see a historical view of the closing price

plt.figure(figsize=(15, 6))
plt.subplots_adjust(top=1.25, bottom=1.2)

for i, company in enumerate(company_list, 1):
	plt.subplot(2, 2, i)
	company['Adj Close'].plot()
	plt.ylabel('Adj Close')
	plt.xlabel(None)
	plt.title(f"Closing Price of {tech_list[i - 1]}")
	
plt.tight_layout()

# Now let's plot the total volume of stock being traded each day
plt.figure(figsize=(15, 7))
plt.subplots_adjust(top=1.25, bottom=1.2)

for i, company in enumerate(company_list, 1):
	plt.subplot(2, 2, i)
	company['Volume'].plot()
	plt.ylabel('Volume')
	plt.xlabel(None)
	plt.title(f"Sales Volume for {tech_list[i - 1]}")
	
plt.tight_layout()

ma_day = [10, 20, 50]

for ma in ma_day:
	for company in company_list:
		column_name = f"MA for {ma} days"
		company[column_name] = company['Adj Close'].rolling(ma).mean()

# print(GOOG.columns)

# df.groupby("company_name").hist(figsize=(12, 12));

fig, axes = plt.subplots(nrows=2, ncols=2)
fig.set_figheight(8)
fig.set_figwidth(15)

AAPL[['Adj Close', 'MA for 10 days', 'MA for 20 days', 'MA for 50 days']].plot(ax=axes[0,0])
axes[0,0].set_title('APPLE')

GOOG[['Adj Close', 'MA for 10 days', 'MA for 20 days', 'MA for 50 days']].plot(ax=axes[0,1])
axes[0,1].set_title('GOOGLE')

MSFT[['Adj Close', 'MA for 10 days', 'MA for 20 days', 'MA for 50 days']].plot(ax=axes[1,0])
axes[1,0].set_title('MICROSOFT')

AMZN[['Adj Close', 'MA for 10 days', 'MA for 20 days', 'MA for 50 days']].plot(ax=axes[1,1])
axes[1,1].set_title('AMAZON')

fig.tight_layout()

# We'll use pct_change to find the percent change for each day
for company in company_list:
	company['Daily Return'] = company['Adj Close'].pct_change()

# Then we'll plot the daily return percentage
fig, axes = plt.subplots(nrows=2, ncols=2)
fig.set_figheight(8)
fig.set_figwidth(15)

AAPL['Daily Return'].plot(ax=axes[0,0], legend=True, linestyle='--', marker='o')
axes[0,0].set_title('APPLE')

GOOG['Daily Return'].plot(ax=axes[0,1], legend=True, linestyle='--', marker='o')
axes[0,1].set_title('GOOGLE')

MSFT['Daily Return'].plot(ax=axes[1,0], legend=True, linestyle='--', marker='o')
axes[1,0].set_title('MICROSOFT')

AMZN['Daily Return'].plot(ax=axes[1,1], legend=True, linestyle='--', marker='o')
axes[1,1].set_title('AMAZON')

fig.tight_layout()

plt.figure(figsize=(12, 7))

for i, company in enumerate(company_list, 1):
	plt.subplot(2, 2, i)
	company['Daily Return'].hist(bins=50)
	plt.ylabel('Daily Return')
	plt.title(f'{company_name[i - 1]}')
	
plt.tight_layout()

# Grab all the closing prices for the tech stock list into one DataFrame
closing_df = DataReader(tech_list, 'yahoo', start, end)['Adj Close']

# Let's take a quick look
closing_df.head()

# Make a new tech returns DataFrame
tech_rets = closing_df.pct_change()
tech_rets.head()

# Comparing Google to itself should show a perfectly linear relationship
sns.jointplot(x='GOOG', y='GOOG', data=tech_rets, kind='scatter', color='seagreen')

# We'll use joinplot to compare the daily returns of Google and Microsoft
sns.jointplot(x='GOOG', y='MSFT', data=tech_rets, kind='scatter')

# We can simply call pairplot on our DataFrame for an automatic visual analysis 
# of all the comparisons

sns.pairplot(tech_rets, kind='reg')

# Set up our figure by naming it returns_fig, call PairPLot on the DataFrame
return_fig = sns.PairGrid(tech_rets.dropna())

# Using map_upper we can specify what the upper triangle will look like.
return_fig.map_upper(plt.scatter, color='purple')

# We can also define the lower triangle in the figure, inclufing the plot type (kde) 
# or the color map (BluePurple)
return_fig.map_lower(sns.kdeplot, cmap='cool_d')

# Finally we'll define the diagonal as a series of histogram plots of the daily return
return_fig.map_diag(plt.hist, bins=30)

# Set up our figure by naming it returns_fig, call PairPLot on the DataFrame
returns_fig = sns.PairGrid(closing_df)

# Using map_upper we can specify what the upper triangle will look like.
returns_fig.map_upper(plt.scatter,color='purple')

# We can also define the lower triangle in the figure, inclufing the plot type (kde) or the color map (BluePurple)
returns_fig.map_lower(sns.kdeplot,cmap='cool_d')

# Finally we'll define the diagonal as a series of histogram plots of the daily return
returns_fig.map_diag(plt.hist,bins=30)

# Let's go ahead and use sebron for a quick correlation plot for the daily returns
sns.heatmap(tech_rets.corr(), annot=True, cmap='summer')

sns.heatmap(closing_df.corr(), annot=True, cmap='summer')

# Let's start by defining a new DataFrame as a clenaed version of the oriignal tech_rets DataFrame
rets = tech_rets.dropna()

area = np.pi * 20

plt.figure(figsize=(10, 7))
plt.scatter(rets.mean(), rets.std(), s=area)
plt.xlabel('Expected return')
plt.ylabel('Risk')

for label, x, y in zip(rets.columns, rets.mean(), rets.std()):
	plt.annotate(label, xy=(x, y), xytext=(50, 50), textcoords='offset points', ha='right', va='bottom', 
				 arrowprops=dict(arrowstyle='-', color='blue', connectionstyle='arc3,rad=-0.3'))

# Get the stock quote
df = DataReader('AAPL', data_source='yahoo', start='2012-01-01', end=datetime.now())
# Show teh data
df

plt.figure(figsize=(16,6))
plt.title('Close Price History')
plt.plot(df['Close'])
plt.xlabel('Date', fontsize=18)
plt.ylabel('Close Price USD ($)', fontsize=18)
plt.show()

# Create a new dataframe with only the 'Close column 
data = df.filter(['Close'])
# Convert the dataframe to a numpy array
dataset = data.values
# Get the number of rows to train the model on
training_data_len = int(np.ceil( len(dataset) * .95 ))

training_data_len

# Scale the data
from sklearn.preprocessing import MinMaxScaler

scaler = MinMaxScaler(feature_range=(0,1))
scaled_data = scaler.fit_transform(dataset)

scaled_data

# Create the training data set 
# Create the scaled training data set
train_data = scaled_data[0:int(training_data_len), :]
# Split the data into x_train and y_train data sets
x_train = []
y_train = []

for i in range(60, len(train_data)):
	x_train.append(train_data[i-60:i,0])
	y_train.append(train_data[i,0])
	if i<=61:
		print(x_train)
		print(y_train)
		print()

# Convert the x_train and y_train to numpy arrays 
x_train, y_train = np.array(x_train), np.array(y_train)

# Reshape the data
x_train = np.reshape(x_train, (x_train.shape[0], x_train.shape[1], 1))
# x_train.shape

from keras.models import Sequential
from keras.layers import Dense, LSTM

# Build the Long Short Term Memory model
model = Sequential()
model.add(LSTM(128, return_sequences=True, input_shape= (x_train.shape[1], 1)))
model.add(LSTM(64, return_sequences=False))
model.add(Dense(25))
model.add(Dense(1))

# Compile the model
model.compile(optimizer='adam', loss='mean_squared_error')

# Train the model
model.fit(x_train, y_train, batch_size=1, epochs=1)

# Create the testing data set
# Create a new array containing scaled values from index 1543 to 2002 
test_data = scaled_data[training_data_len - 60: , :]
# Create the data sets x_test and y_test
x_test = []
y_test = dataset[training_data_len:, :]
for i in range(60, len(test_data)):
	x_test.append(test_data[i-60:i, 0])
	
# Convert the data to a numpy array
x_test = np.array(x_test)

# Reshape the data
x_test = np.reshape(x_test, (x_test.shape[0], x_test.shape[1], 1 ))

# Get the models predicted price values 
predictions = model.predict(x_test)
predictions = scaler.inverse_transform(predictions)

# Get the Root Mean Squared Error
rmse = np.sqrt(np.mean(((predictions - y_test) ** 2)))
rmse

# Plot the data
train = data[:training_data_len]
valid = data[training_data_len:]
valid['Predictions'] = predictions
# Visualize the data
plt.figure(figsize=(16,6))
plt.title('Model')
plt.xlabel('Date', fontsize=18)
plt.ylabel('Close Price USD ($)', fontsize=18)
plt.plot(train['Close'])
plt.plot(valid[['Close', 'Predictions']])
plt.legend(['Train', 'Val', 'Predictions'], loc='lower right')
plt.show()

# Show the valid and predicted prices
valid

# Ubiquant Light Gradient Boosting Machines Baseline
# https://www.kaggle.com/valleyzw/ubiquant-lgbm-baseline

args = Namespace(
	debug=False,
	seed=21,
	folds=5,
	workers=4,
	min_time_id=None, 
	holdout=False,
	cv_method="group",
	num_bins=16,
	holdout_size=100,
	outlier_threshold=0.001,
	trading_days_per_year=250,   # chinese stock market trading days per year (roughly)
	add_investment_id_model=False,
	data_path=Path("../input/ubiquant-parquet/"),
)
seed_everything(args.seed)

if args.debug:
	setattr(args, 'min_time_id', 1150)

assert args.cv_method in {"kfold", "group", "stratified", "time", "group_time", "time_range"}, "unknown cv method"
assert args.data_path.exists(), "data_path not exists"

%%time
train = pd.read_parquet(args.data_path.joinpath("train_low_mem.parquet"))
assert train.isnull().any().sum() == 0, "null exists."
assert train.row_id.str.extract(r"(?P<time_id>\d+)_(?P<investment_id>\d+)").astype(train.time_id.dtype).equals(train[["time_id", "investment_id"]]), "row_id!=time_id_investment_id"
assert train.time_id.is_monotonic_increasing, "time_id not monotonic increasing"

f, (ax0, ax1, ax2) = plt.subplots(3, 1, gridspec_kw={'height_ratios': [1,1,6]}, figsize=(10,10), sharex=True, dpi=128)
_df = train[['time_id', 'investment_id']].groupby("time_id").count().reindex(range(train.time_id.min(), train.time_id.max()+1))
peeks, _ = find_peaks(-_df.values.squeeze(), threshold=200)
_df.plot(ax=ax0)
ax0.set_xticks(ticks=peeks, minor=True)
ax0.set_ylabel("count")
ax0.legend(loc='upper left')

train[['time_id', 'target']].groupby("time_id").mean().reindex(range(train.time_id.min(), train.time_id.max()+1)).plot(ax=ax1)
ax1.set_ylabel("mean")
ax1.legend(loc='upper left')

_df = (
	train[['investment_id', 'time_id', "target"]]
	.pivot_table(index="time_id", columns="investment_id", values="target", aggfunc="count")
	.reindex(range(train.time_id.min(), train.time_id.max()+1))
)
ax2.imshow(_df.T, cmap='winter', interpolation='nearest', aspect="auto", origin="lower", alpha=0.6)
ax2.set_xlabel("time_id")
ax2.set_ylabel("investment_id")
plt.tight_layout()
plt.show()

df = train[["investment_id", "target"]].groupby("investment_id").target.mean()
upper_bound, lower_bound = df.quantile([1-args.outlier_threshold, args.outlier_threshold])
ax = df.plot(figsize=(16, 8))
ax.axhspan(lower_bound, upper_bound, fill=False, linestyle="--", color="k")
plt.show()

outlier_investments = df.loc[(df>upper_bound)|(df<lower_bound)|(df==0)].index
_=pd.pivot(
	train.loc[train.investment_id.isin(outlier_investments), ["investment_id", "time_id", "target"]],
	index='time_id', columns='investment_id', values='target'
).plot(figsize=(16,12), subplots=True, sharex=True)

outlier_list = []
outlier_col = []

for col in (f"f_{i}" for i in range(300)):
	_mean, _std = train[col].mean(), train[col].std()
	
	temp_df = train.loc[(train[col] > _mean + _std * 70) | (train[col] < _mean - _std * 70)]
	temp2_df = train.loc[(train[col] > _mean + _std * 35) | (train[col] < _mean - _std * 35)]
	if len(temp_df) >0 : 
		outliers = temp_df.index.to_list()
		outlier_list.extend(outliers)
		outlier_col.append(col)
		print(col, len(temp_df))
	elif len(temp2_df)>0 and len(temp2_df) <6 :
		outliers = temp2_df.index.to_list()
		outlier_list.extend(outliers)
		outlier_col.append(col)
		print(col, len(temp2_df))

outlier_list = list(set(outlier_list))
train.drop(train.index[outlier_list], inplace = True)
print(len(outlier_col), len(outlier_list), train.shape)

_=pd.pivot(
	train.loc[train.investment_id.isin([1,17,19,3011,3151]), ["investment_id", "time_id", "target"]],
	index='time_id', columns='investment_id', values='target'
).plot(figsize=(16,12), subplots=True, sharex=True)

_features = ["f_74", "f_153", "f_183", "f_145"]
df=train[["time_id", "target"]+_features].groupby("time_id").mean()
time_to_cheer_up, time_to_calm_down = df.target.idxmax(), df.target.idxmin()
ax, *_ = df.plot(figsize=(16,12), subplots=True, sharex=True)
ax.axhline(0, linestyle="--", color="k", linewidth=1)
ax.scatter(time_to_cheer_up, df.loc[time_to_cheer_up, "target"], marker="^", color="k")
ax.scatter(time_to_calm_down, df.loc[time_to_calm_down, "target"], marker="v", color="k")
plt.show()

ax, *_ = train.loc[train.time_id==time_to_cheer_up, ["investment_id", "target"]+_features].plot(x="investment_id", figsize=(16,12), subplots=True, sharex=True)
ax.axhline(0, linestyle="--", color="k")
ax, *_ = train.loc[train.time_id==time_to_calm_down, ["investment_id", "target"]+_features].plot(x="investment_id", figsize=(16,12), subplots=True, sharex=True)
ax.axhline(0, linestyle="--", color="k")
plt.show()

if args.min_time_id is not None:
	train = train.query("time_id>=@args.min_time_id").reset_index(drop=True)
	gc.collect()
	
train=train.loc[~train.investment_id.isin(outlier_investments)].reset_index(drop=True)
train.shape

_=train[["time_id", "target"]+_features].groupby("time_id").mean().plot(figsize=(16,12), subplots=True, sharex=True)

time_id_df = (
	train[["investment_id", "time_id"]]
	.groupby("investment_id")
	.agg(["min", "max", "count", np.ptp])
	.assign(time_span=lambda x: x.time_id.ptp)
	.drop(columns="ptp", level=1)
	.reset_index()
)
time_id_df.head(6)

train = train.merge(time_id_df.drop(columns="time_id", level=0).droplevel(level=1, axis=1), on="investment_id", how='left')
train.time_span.hist(bins=args.num_bins, figsize=(16,8))
max_time_span=time_id_df.time_id["max"].max()
del time_id_df
gc.collect()

if args.holdout:
	_target = pd.cut(train.time_span, args.num_bins, labels=False)
	_train, _valid = train_test_split(_target, stratify=_target, random_state=args.seed)
	print(f"train length: {len(_train)}", f"holdout length: {len(_valid)}")
	valid = train.iloc[_valid.index].sort_values(by=["time_id", "investment_id"]).reset_index(drop=True)
	train = train.iloc[_train.index].sort_values(by=["time_id", "investment_id"]).reset_index(drop=True)
	train.time_span.hist(bins=args.num_bins, figsize=(16,8), alpha=0.8)
	valid.time_span.hist(bins=args.num_bins, figsize=(16,8), alpha=0.8)
	valid.drop(columns="time_span").to_parquet("valid.parquet")
	del valid, _train, _valid, _target
	gc.collect()
assert train.time_id.is_monotonic_increasing, "time_id not monotonic increasing"

if args.cv_method=="stratified":
	train["fold"] = -1
	_target = pd.cut(train.time_span, args.num_bins, labels=False)
	skf = StratifiedKFold(n_splits=args.folds)
	for fold, (train_index, valid_index) in enumerate(skf.split(_target, _target)):
		train.loc[valid_index, 'fold'] = fold

	fig, axs = plt.subplots(nrows=args.folds, ncols=1, sharex=True, figsize=(16,8), tight_layout=True)
	for ax, (fold, df) in zip(axs, train[["fold", "time_span"]].groupby("fold")):
		ax.hist(df.time_span, bins=args.num_bins)
		ax.text(0, 40000, f"fold: {fold}, count: {len(df)}", fontsize=16)
	plt.show()
	del _target, train_index, valid_index
	_=gc.collect()

cat_features = []
num_features = list(train.filter(like="f_").columns)
features = num_features + cat_features

combination_features = ["f_231-f_250", "f_118-f_280", "f_155-f_297", "f_25-f_237", "f_179-f_265", "f_119-f_270", "f_71-f_197", "f_21-f_65"]
for f in combination_features:
	f1, f2 = f.split("-")
	train[f] = train[f1] + train[f2]
features += combination_features

to_drop = ["f_148", "f_72", "f_49", "f_205", "f_228", "f_97", "f_262", "f_258"]
features = list(sorted(set(features).difference(set(to_drop))))

train = reduce_mem_usage(train.drop(columns="time_span"))
train[["investment_id", "time_id"]] = train[["investment_id", "time_id"]].astype(np.uint16)
train=train.drop(columns=["row_id"]+to_drop)

if args.cv_method=="stratified":
	train["fold"] = train["fold"].astype(np.uint8)
gc.collect()
# features += ["time_id"] # https://www.kaggle.com/c/ubiquant-market-prediction/discussion/302429
features_backup = features.copy()
len(features)

if args.cv_method=="time_range":
	train["time_range"] = pd.cut(train.time_id, bins=int(np.ceil(max_time_span/args.trading_days_per_year)))
	_ = train.time_range.value_counts(sort=False).plot(kind="barh", figsize=(16,8))

# corr_matrix = train.filter(like="f_").corr().abs()
# upper = corr_matrix.where(np.triu(np.ones(corr_matrix.shape), k=1).astype(np.bool))
# # Find features with correlation greater than 0.97
# to_drop = [column for column in upper.columns if any(upper[column] >= 0.97)]
# sorted(to_drop)

def rmse(y_true, y_pred):
	return np.sqrt(mean_squared_error(y_true, y_pred))

# TODO: replace with feval_pearsonr
def feval_rmse(y_pred, lgb_train):
	y_true = lgb_train.get_label()
	return 'rmse', rmse(y_true, y_pred), False

# https://www.kaggle.com/c/ubiquant-market-prediction/discussion/302480
def feval_pearsonr(y_pred, lgb_train):
	y_true = lgb_train.get_label()
	return 'pearsonr', pearsonr(y_true, y_pred)[0], True

# https://www.kaggle.com/gogo827jz/jane-street-supervised-autoencoder-mlp?scriptVersionId=73762661
# weighted average as per Donate et al.'s formula
# https://doi.org/10.1016/j.neucom.2012.02.053
# [0.0625, 0.0625, 0.125, 0.25, 0.5] for 5 fold
def weighted_average(a):
	w = []
	n = len(a)
	for j in range(1, n + 1):
		j = 2 if j == 1 else j
		w.append(1 / (2**(n + 1 - j)))
	return np.average(a, weights = w)

def run(info):	
	# hyperparams from: https://www.kaggle.com/valleyzw/ubiquant-lgbm-optimization
	params = {
		'learning_rate':0.05,
		"objective": "regression",
		"metric": "rmse",
		'boosting_type': "gbdt",
		'verbosity': -1,
		'n_jobs': -1, 
		'seed': args.seed,
		'lambda_l1': 0.017886589369575545, 
		'lambda_l2': 0.00010502197797107082, 
		'num_leaves': 114, 
		'feature_fraction': 0.877437769489544, 
		'bagging_fraction': 0.8756371955011882, 
		'bagging_freq': 2, 
		'max_depth': 23, 
		'max_bin': 512, 
		'min_data_in_leaf': 416,
		'n_estimators': 1000, 
	}
	
	y = train['target']
	train['preds'] = -1000
	scores = defaultdict(list)
	features_importance= []
	
	def run_single_fold(fold, trn_ind, val_ind):
		train_dataset = lgb.Dataset(train.loc[trn_ind, features], y.loc[trn_ind], categorical_feature=cat_features)
		valid_dataset = lgb.Dataset(train.loc[val_ind, features], y.loc[val_ind], categorical_feature=cat_features)
		model = lgb.train(
			params,
			train_set = train_dataset, 
			valid_sets = [train_dataset, valid_dataset], 
			verbose_eval=100,
			early_stopping_rounds=50,
			feval = feval_pearsonr
		)
		joblib.dump(model, f'lgbm_seed{args.seed}_{fold}_{info}.pkl')
		preds = model.predict(train.loc[val_ind, features])
		train.loc[val_ind, "preds"] = preds
		scores["rmse"].append(rmse(y.loc[val_ind], preds))
		scores["pearsonr"].append(pearsonr(y.loc[val_ind], preds)[0])
		fold_importance_df= pd.DataFrame({'feature': features, 'importance': model.feature_importance(), 'fold': fold})
		features_importance.append(fold_importance_df)
		del train_dataset, valid_dataset, model
		gc.collect()
		
	if args.cv_method=="stratified":
		for fold in range(args.folds):
			print(f"=====================fold: {fold}=====================")
			trn_ind, val_ind = train.fold!=fold, train.fold==fold
			print(f"train length: {trn_ind.sum()}, valid length: {val_ind.sum()}")
			run_single_fold(fold, trn_ind, val_ind)
	elif args.cv_method=="time":
		tscv = TimeSeriesSplit(args.folds)
		for fold, (trn_ind, val_ind) in enumerate(tscv.split(train[features])):
			print(f"=====================fold: {fold}=====================")
			print(f"train length: {len(trn_ind)}, valid length: {len(val_ind)}")
			run_single_fold(fold, trn_ind, val_ind)
	elif args.cv_method=="group":
		# https://www.kaggle.com/lucamassaron/eda-target-analysis/notebook
		kfold = GroupKFold(args.folds)
		for fold, (trn_ind, val_ind) in enumerate(kfold.split(train[features], y, train.time_id)):
			print(f"=====================fold: {fold}=====================")
			print(f"train length: {len(trn_ind)}, valid length: {len(val_ind)}")
			run_single_fold(fold, trn_ind, val_ind)
	elif args.cv_method=="group_time":
		# https://www.kaggle.com/joelqv/grouptimeseriescv-catboost-gpu
		# kfold = GroupTimeSeriesSplit(n_splits=args.folds)
		# for fold, (trn_ind, val_ind) in enumerate(kfold.split(train[features], y, train.time_id)):
		# https://www.kaggle.com/c/ubiquant-market-prediction/discussion/304036
		kfold = GroupTimeSeriesSplit(n_folds=args.folds, holdout_size=args.holdout_size, groups=train.time_id)
		for fold, (trn_ind, val_ind) in enumerate(kfold.split(train)):
			print(f"=====================fold: {fold}=====================")
			print(f"train length: {len(trn_ind)}, valid length: {len(val_ind)}")
			run_single_fold(fold, trn_ind, val_ind)
	elif args.cv_method=="kfold":
		kfold = KFold(args.folds)
		for fold, (trn_ind, val_ind) in enumerate(kfold.split(train[features], train.investment_id)):
			print(f"=====================fold: {fold}=====================")
			print(f"train length: {len(trn_ind)}, valid length: {len(val_ind)}")
			run_single_fold(fold, trn_ind, val_ind)
	# TODO: add another fold to train with the whole training dataset with a tiny learning rate
	elif args.cv_method=="time_range":
		ranges = train.time_range.unique()
		kfold = TimeSeriesSplit(n_splits=args.folds-1)
		for fold, (trn_ind, val_ind) in enumerate(kfold.split(ranges)):
			trn_ind, val_ind = train.time_range.isin(ranges[trn_ind]), train.time_range.isin(ranges[val_ind])
			assert trn_ind.idxmin()-1 < val_ind.idxmax()
			print(f"train length: {trn_ind.sum()}, valid length: {val_ind.sum()}")
			run_single_fold(fold, trn_ind, val_ind)
		
	print(f"lgbm {info} {args.folds} folds mean rmse: {np.mean(scores['rmse'])}, mean pearsonr: {np.mean(scores['pearsonr'])}")
	if "time" in args.cv_method:
		print(f"lgbm {info} {args.folds} folds weighted mean rmse: {weighted_average(scores['rmse'])}, weighted mean pearsonr: {weighted_average(scores['pearsonr'])}")
	train.filter(regex=r"^(?!f_).*").to_csv(f"preds_{info}.csv", index=False)
	return pd.concat(features_importance, axis=0)

investment_ids = train.investment_id.unique()
info = "without_investment_id"
features_importance = run(info=info)
df = train[["target", "preds", "time_id"]].query("preds!=-1000")
score = df.groupby("time_id").apply(lambda x: pearsonr(x.target, x.preds)[0]).mean()
print(f"lgbm {info} {args.cv_method} {args.folds} folds mean rmse: {rmse(df.target, df.preds):.4f}, mean pearsonr: {pearsonr(df.target, df.preds)[0]:.4f}, mean pearsonr by time_id: {score:.4f}")

folds_mean_importance = (
	features_importance.groupby("feature", as_index=False)
	.importance.mean()
	.sort_values(by="importance", ascending=False)
)
features_importance.to_csv(f"features_importance_{info}.csv", index=False)
folds_mean_importance.to_csv(f"folds_mean_feature_importance_{info}.csv", index=False)

plt.figure(figsize=(16, 10))
plt.subplot(1,2,1)
sns.barplot(x="importance", y="feature", data=folds_mean_importance.head(50))
plt.title(f'Head LightGBM Features {info} (avg over {args.folds} folds)')
plt.subplot(1,2,2)
sns.barplot(x="importance", y="feature", data=folds_mean_importance.tail(50))
plt.title(f'Tail LightGBM Features {info} (avg over {args.folds} folds)')
plt.tight_layout()
plt.show()

del df
gc.collect()

# Ubiquant Exploratory Data Analysis And Baseline
# https://www.kaggle.com/ilialar/ubiquant-eda-and-baseline

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

# Input data files are available in the read-only "../input/" directory
# For example, running this (by clicking run or pressing Shift+Enter) will list all files under the input directory

import os
for dirname, _, filenames in os.walk('/kaggle/input'):
	for filename in filenames:
		print(os.path.join(dirname, filename))
		
import seaborn as sns
import matplotlib.pyplot as plt

data_types_dict = {
	'time_id': 'int32',
	'investment_id': 'int16',
	"target": 'float16',
}

features = [f'f_{i}' for i in range(300)]

for f in features:
	data_types_dict[f] = 'float16'
	
target = 'target'

train_df = pd.read_csv('/kaggle/input/ubiquant-market-prediction/train.csv', 
#						nrows=5 * 10**4,
					   usecols = data_types_dict.keys(),
					   dtype=data_types_dict, 
					   index_col = 0)
/opt/conda/lib/python3.7/site-packages/numpy/lib/arraysetops.py:580: FutureWarning: elementwise comparison failed; returning scalar instead, but in the future will perform elementwise comparison
  mask |= (ar1 == a)

train_df

train_df['target'].hist(bins = 100, figsize = (20,10))

for f in np.random.choice(train_df['investment_id'].unique(), 10):
	train_df[train_df['investment_id'] == f]['target'].hist(bins = 100, alpha = 0.2, figsize = (20,10))

train_df['investment_id'].nunique()

train_df['investment_id'].value_counts().plot(kind = 'bar',figsize = (20,10))

f = 'f_67'
train_df[f].hist(bins = 100, figsize = (20,10))

f = 'f_109'
train_df[f].hist(bins = 100, figsize = (20,10))

f = 'f_62'
train_df[f].hist(bins = 100, figsize = (20,10))

f = 'f_234'
train_df[f].hist(bins = 100, figsize = (20,10))

f = 'f_164'
train_df[f].hist(bins = 100, figsize = (20,10))

train_df[features].nunique().hist()

sample_df = train_df.sample(frac = 0.01)
sample_df

correlation = sample_df[[target] + features].corr()

correlation['target'].iloc[1:].hist(bins = 20, figsize = (20,10))

import seaborn as sns
sns.clustermap(correlation, figsize=(20, 20))
/opt/conda/lib/python3.7/site-packages/seaborn/matrix.py:654: UserWarning: Clustering large matrix with scipy. Installing `fastcluster` may give better performance.
  warnings.warn(msg)

from lightgbm import LGBMRegressor

# features += ['investment_id']

from sklearn.model_selection import StratifiedKFold 
seed = 0
folds = 10
models = []

skf = StratifiedKFold(folds, shuffle = True, random_state = seed)

for train_index, test_index in skf.split(train_df, train_df['investment_id']):
	train = train_df.iloc[train_index]
	valid = train_df.iloc[test_index]
	
	lgbm = LGBMRegressor(
		num_leaves=2 ** np.random.randint(3, 8),
		learning_rate = 10 ** (-np.random.uniform(0.1,2)),
		n_estimators = 1000,
		min_child_samples = 1000, 
		subsample=np.random.uniform(0.5,1.0), 
		subsample_freq=1,
		n_jobs= -1
	)

	lgbm.fit(train[features], train[target], eval_set = (valid[features], valid[target]), early_stopping_rounds = 10)
	models.append(lgbm)

import lightgbm
lightgbm.plot_importance(lgbm, figsize = (20, 60))

import ubiquant
env = ubiquant.make_env()   # initialize the environment
iter_test = env.iter_test()	# an iterator which loops over the test set and sample submission
for (test_df, sample_prediction_df) in iter_test:
	
	test_df['target']  = 0
	
	for lgbm in models:
		test_df['target'] += lgbm.predict(test_df[features])
	test_df['target'] /= len(models)
	env.predict(test_df[['row_id','target']])

# Ubiquant Exploratory Data Analysis Target Analysis
# https://www.kaggle.com/lucamassaron/eda-target-analysis

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

train = pd.read_feather('../input/training-data-to-feather-python-r-low-mem/train.feather')

obs = train.shape[0]
print(f"number of observations: {obs}")

time_steps, assets = train.time_id.nunique(), train.investment_id.nunique()
print(f"number of assets: {assets} \t time steps: {time_steps}")

print(f"number of assets: {assets} (range from {train.investment_id.min()} to {train.investment_id.max()})")

obs_by_asset = train.groupby(['investment_id'])['target'].count()

fig, ax = plt.subplots(1, 1, figsize=(12, 6))
obs_by_asset.plot.hist(bins=60)
plt.title("target by asset distribution")
plt.show()

train[['investment_id', 'time_id']].plot.scatter('time_id', 'investment_id', figsize=(20, 30), s=0.5)
plt.show()

mean_target = train.groupby(['investment_id'])['target'].mean()
mean_mean_target = np.mean(mean_target)

fig, ax = plt.subplots(1, 1, figsize=(12, 6))
mean_target.plot.hist(bins=60)
plt.title("mean target distribution")
plt.show()

print(f"Mean of mean target: {mean_mean_target: 0.5f}")

sts_target = train.groupby(['investment_id'])['target'].std()
mean_std_target = np.mean(sts_target)

fig, ax = plt.subplots(1, 1, figsize=(12, 6))
sts_target.plot.hist(bins=60)
plt.title("standard deviation of target distribution")
plt.show()

print(f"Mean of std target: {mean_std_target: 0.5f}")

ax = sns.jointplot(x=obs_by_asset, y=mean_target, kind="reg", 
				   height=8, joint_kws={'line_kws':{'color':'red'}})
ax.ax_joint.set_xlabel('observations')
ax.ax_joint.set_ylabel('mean target')
plt.show()

qx = sns.jointplot(x=obs_by_asset.values, y=sts_target, kind="reg", 
				   height=8, joint_kws={'line_kws':{'color':'red'}})
ax.ax_joint.set_xlabel('observations')
ax.ax_joint.set_ylabel('std target')
plt.show()

fig, ax = plt.subplots(1, 1, figsize=(12, 6))
train.groupby('time_id')['investment_id'].nunique().plot()
plt.title("number of unique assets by time")
plt.show()

plt.figure(figsize=(12, 6))

plt.subplot(3, 1, 1,)
(train.groupby('time_id')['investment_id'].nunique()).plot()
plt.title("number of unique assets by time")

plt.subplot(3, 1, 2)
train.groupby('time_id')['target'].mean().plot()
plt.title("average target by time")
plt.axhline(y=mean_mean_target, color='r', linestyle='--', label="mean")
plt.legend(loc='lower left')

plt.subplot(3, 1, 3)
train.groupby('time_id')['target'].std().plot()
plt.title("std of target by time")
plt.axhline(y=mean_std_target, color='r', linestyle='--', label="mean")
plt.legend(loc='lower left')

plt.subplots_adjust(left=0.1,bottom=0.1,right=0.9,top=1.3,wspace=0.4,hspace=0.4)

plt.show()

r = np.corrcoef(train.groupby('time_id')['investment_id'].nunique(), train.groupby('time_id')['target'].mean())[0][1]
print(f"Correlation of number of assets by target: {r:0.3f}")

time2target_mean = train.groupby(['time_id'])['target'].mean()
time2target_std = train.groupby(['time_id'])['target'].std()

_,axes = plt.subplots(1,1,figsize=(24,12))
plt.fill_between(
		time2target_mean.index,
		time2target_mean - time2target_std,
		time2target_mean + time2target_std,
		alpha=0.1,
		color="b",
)
plt.plot(
		time2target_mean.index, time2target_mean, "o-", color="b", label="Training score"
)
plt.axhline(y=mean_mean_target, color='r', linestyle='--', label="mean")
axes.set_ylabel("target")
axes.set_xlabel("time")
plt.show()

time2target_mean = train.groupby(['time_id'])['target'].mean()
time2target_std = train.groupby(['time_id'])['target'].std()

_,axes = plt.subplots(1,1,figsize=(24,12))
plt.fill_between(
		time2target_mean.index,
		time2target_mean - time2target_std,
		time2target_mean + time2target_std,
		alpha=0.1,
		color="b",
)
plt.plot(
		time2target_mean.index, time2target_mean, "o-", color="b", label="Training score"
)
plt.axhline(y=mean_mean_target, color='r', linestyle='--', label="mean")

asset = 70
plt.plot(train[train.investment_id==asset].time_id,
			   train[train.investment_id==asset].target, '.')

axes.set_ylabel("target")
axes.set_xlabel("time")
plt.show()

obs_by_asset = train.groupby(['investment_id'])['target'].count().to_dict()
target = train.investment_id.copy().replace(obs_by_asset).astype(np.int16)
features = train.columns[4:]

del(obs_by_asset)

corrs = list()
for col in features:
	corr = np.corrcoef(target, train[col])[0][1]
	corrs.append(corr)
	
del(target)

feat_importances = pd.Series(corrs, index=features)
feat_importances.nlargest(20).plot(kind='barh', figsize=(12, 6)).invert_yaxis()
plt.show()

# Google Landmark Retrieval Challenge

# Large Scale Hierarchical Text Classification

# Right Whale Recognition

# Dogs Versus Cats

# Chest X Ray Images

# Cats And Dogs Sentdex Tutorial

# Saturn Ring Image Set/NASA/Cassini Mission

# Metal Artifact Reduction Convolutional Neural Network Deep-Generative Adversarial Network

# Image Depth Estimation

# Deep Learning Tutorial For Beginners

# Pytorch Tutorial For Deep Learning Lovers

# Deep Learning From Scratch

# Deep Learning Starter: Simple Long Short Term Memory

# Deep Reinforcement Learning On Stock Data

# Deep Learning For Time Series Forecasting

# Deep Learning For Natural Language Processing: Zero To Transformers And Bidirectional Encoder Representations From Transformers

# Welcome To Deep Learning Convolutional Neural Networks 0.99

# Deep Learning Support 0.9663

# Deep Reinforcement Learning

# Visualisation Machine Learning Deep Learning

# Salt Identification Challenge

# Learning Pytorch Long Short Term Memory Deep Learning With M5 Data

# Greg Brockman's Github

# Greg Brockman's Github On Kaggle

# Making more observations of the Ubiquant Market Prediction task and thinking about simply incorporating monthly Kaggle review sessions as part of the Puzzles feed review sessions since it seems very deeply wise to review a little bit over literally all of the public Kaggle competitions as well as some of the most relevant topical notebooks in time series analysis, finance, and perhaps other domains depending on what I am doing and where.

# Wojciech Zaremba Github is great too and all linked Open Artificial Intelligence Githubs are must skims or must reads status. The Long Short Term Memory Units package... Learning To Execute.