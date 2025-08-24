# LeetCode And Perhaps Other Codes Copied And Pasted From Internet

# Python3 implementation of Min Heap
  
import sys
  
class MinHeap:
	def __init__(self, maxsize):
		self.maxsize = maxsize
		self.size = 0
		self.Heap = [0]*(self.maxsize + 1)
		self.Heap[0] = -1 * sys.maxsize
		self.FRONT = 1

	def parent(self, pos):
		return pos // 2

	def leftChild(self, pos):
		return 2 * pos

	def rightChild(self, pos):
		return (2 * pos) + 1

	def isLeaf(self, pos):
		return pos * 2 > self.size

	def swap(self, fpos, spos):
		self.Heap[fpos], self.Heap[spos] = self.Heap[spos], self.Heap[fpos]

	def minHeapify(self, pos):
		if not self.isLeaf(pos):
			if (self.Heap[pos] > self.Heap[self.leftChild(pos)] or 
			   self.Heap[pos] > self.Heap[self.rightChild(pos)]):
				if self.Heap[self.leftChild(pos)] < self.Heap[self.rightChild(pos)]:
					self.swap(pos, self.leftChild(pos))
					self.minHeapify(self.leftChild(pos))
				else:
					self.swap(pos, self.rightChild(pos))
					self.minHeapify(self.rightChild(pos))

	def insert(self, element):
		if self.size >= self.maxsize:
			return
		self.size += 1
		self.Heap[self.size] = element
		current = self.size
		while self.Heap[current] < self.Heap[self.parent(current)]:
			self.swap(current, self.parent(current))
			current = self.parent(current)

	def Print(self):
		for i in range(1, (self.size // 2) + 1):
			print(" PARENT : " + str(self.Heap[i]) + " LEFT CHILD : " + str(self.Heap[2 * i]) + " RIGHT CHILD : " + str(self.Heap[2 * i + 1]))
	
	def minHeap(self):
		for pos in range(self.size // 2, 0, -1):
			self.minHeapify(pos)

	def remove(self):
		popped = self.Heap[self.FRONT]
		self.Heap[self.FRONT] = self.Heap[self.size]
		self.size -= 1
		self.minHeapify(self.FRONT)
		return popped

if __name__ == "__main__":
	print('The minHeap is ')
	minHeap = MinHeap(15)
	minHeap.insert(5)
	minHeap.insert(3)
	minHeap.insert(17)
	minHeap.insert(10)
	minHeap.insert(84)
	minHeap.insert(19)
	minHeap.insert(6)
	minHeap.insert(22)
	minHeap.insert(9)
	minHeap.minHeap()
	minHeap.Print()
	print("The Min val is " + str(minHeap.remove()))

# Some Random Linear Programming Example

>>> obj = [-1, -2]
>>> #      ─┬  ─┬
>>> #       │   └┤ Coefficient for y
>>> #       └────┤ Coefficient for x

>>> lhs_ineq = [[ 2,  1],  # Red constraint left side
...             [-4,  5],  # Blue constraint left side
...             [ 1, -2]]  # Yellow constraint left side

>>> rhs_ineq = [20,  # Red constraint right side
...             10,  # Blue constraint right side
...              2]  # Yellow constraint right side

>>> lhs_eq = [[-1, 5]]  # Green constraint left side
>>> rhs_eq = [15]       # Green constraint right side

>>> bnd = [(0, float("inf")),  # Bounds of x
...        (0, float("inf"))]  # Bounds of y

>>> opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq,
...               A_eq=lhs_eq, b_eq=rhs_eq, bounds=bnd,
...               method="revised simplex")
>>> opt
     con: array([0.])
     fun: -16.818181818181817
 message: 'Optimization terminated successfully.'
     nit: 3
   slack: array([ 0.        , 18.18181818,  3.36363636])
  status: 0
 success: True
       x: array([7.72727273, 4.54545455])

>>> opt.fun
-16.818181818181817

>>> opt.success
True

>>> opt.x
array([7.72727273, 4.54545455])

>>> opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq, bounds=bnd,
...               method="revised simplex")
>>> opt
     con: array([], dtype=float64)
     fun: -20.714285714285715
 message: 'Optimization terminated successfully.'
     nit: 2
   slack: array([0.        , 0.        , 9.85714286])
  status: 0
 success: True
       x: array([6.42857143, 7.14285714]))

>>> obj = [-20, -12, -40, -25]

>>> lhs_ineq = [[1, 1, 1, 1],  # Manpower
...             [3, 2, 1, 0],  # Material A
...             [0, 1, 2, 3]]  # Material B

>>> rhs_ineq = [ 50,  # Manpower
...             100,  # Material A
...              90]  # Material B

>>> opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq,
...               method="revised simplex")
>>> opt
     con: array([], dtype=float64)
     fun: -1900.0
 message: 'Optimization terminated successfully.'
     nit: 2
   slack: array([ 0., 40.,  0.])
  status: 0
 success: True
       x: array([ 5.,  0., 45.,  0.])

from pulp import LpMaximize, LpProblem, LpStatus, lpSum, LpVariable

# Create the model
model = LpProblem(name="small-problem", sense = LpMaximize)

# Initialize the decision variables
x = LpVariable(name="x", lowBound = 0)
y = LpVariable(name="y", lowBound = 0)

>>> expression = 2 * x + 4 * y
>>> type(expression)
<class 'pulp.pulp.LpAffineExpression'>

>>> constraint = 2 * x + 4 * y >= 8
>>> type(constraint)
<class 'pulp.pulp.LpConstraint'>

# Add the constraints to the model
model += (2 * x + y <= 20, "red_constraint")
model += (4 * x - 5 * y >= -10, "blue_constraint")
model += (-x + 2 * y >= -2, "yellow_constraint")
model += (-x + 5 * y == 15, "green_constraint")

# Add the objective function to the model
obj_func = x + 2 * y
model += obj_func

# Add the objective function to the model
model += x + 2 * y

# Add the objective function to the model
model += lpSum([x, 2 * y])

>>> model
small-problem:
MAXIMIZE
1*x + 2*y + 0
SUBJECT TO
red_constraint: 2 x + y <= 20

blue_constraint: 4 x - 5 y >= -10

yellow_constraint: - x + 2 y >= -2

green_constraint: - x + 5 y = 15

# Solve the problem
status = model.solve()

>>> print(f"status: {model.status}, {LpStatus[model.status]}")
status: 1, Optimal

>>> print(f"objective: {model.objective.value()}")
objective: 16.8181817

>>> for var in model.variables():
...     print(f"{var.name}: {var.value()}")
...
x: 7.7272727
y: 4.5454545

>>> for name, constraint in model.constraints.items():
...     print(f"{name}: {constraint.value()}")
...
red_constraint: -9.99999993922529e-08
blue_constraint: 18.181818300000003
yellow_constraint: 3.3636362999999996
green_constraint: -2.0000000233721948e-07)

>>> model.variables()
[x, y]
>>> model.variables()[0] is x
True
>>> model.variables()[1] is y
True

>>> model.solver
<pulp.apis.coin_api.PULP_CBC_CMD object at 0x7f60aea19e50>

from pulp import GLPK

# Create the model
model = LpProblem(name = "small-problem", sense = LpMaximize)

# Initialize the decision variables
x = LpVariable(name = "x", lowBound = 0)
y = LpVariable(name = "y", lowBound = 0)

# Add the constraints to the model
model += (2 * x + y <= 20, "red_constraint")
model += (4 * x - 5 * y >= -10, "blue_constraint")
model += (-x + 2 * y >= -2, "yellow_constraint")
model += (-x + 5 * y == 15, "green_constraint")

# Add the objective function to the model
model += lpSum([x, 2 * y])

# Solve the problem
status = model.solve(solver = GLPK(msg = False))

>>> print(f"status: {model.status}, {LpStatus[model.status]}")
status: 1, Optimal

>>> print(f"objective: {model.objective.value()}")
objective: 16.81817

>>> for var in model.variables():
...     print(f"{var.name}: {var.value()}")
...
x: 7.72727
y: 4.54545

>>> for name, constraint in model.constraints.items():
...     print(f"{name}: {constraint.value()}")
...
red_constraint: -1.0000000000509601e-05
blue_constraint: 18.181830000000005
yellow_constraint: 3.3636299999999997
green_constraint: -2.000000000279556e-05

>>> model.solver
<pulp.apis.glpk_api.GLPK_CMD object at 0x7f60aeb04d50>

# Create the model
model = LpProblem(name = "small-problem", sense = LpMaximize)

# Initialize the decision variables: x is integer, y is continuous
x = LpVariable(name = "x", lowBound = 0, cat = "Integer")
y = LpVariable(name = "y", lowBound = 0)

# Add the constraints to the model
model += (2 * x + y <= 20, "red_constraint")
model += (4 * x - 5 * y >= -10, "blue_constraint")
model += (-x + 2 * y >= -2, "yellow_constraint")
model += (-x + 5 * y == 15, "green_constraint")

# Add the objective function to the model
model += lpSum([x, 2 * y])

# Solve the problem
status = model.solve()

>>> print(f"status: {model.status}, {LpStatus[model.status]}")
status: 1, Optimal

>>> print(f"objective: {model.objective.value()}")
objective: 15.8

>>> for var in model.variables():
...     print(f"{var.name}: {var.value()}")
...
x: 7.0
y: 4.4

>>> for name, constraint in model.constraints.items():
...     print(f"{name}: {constraint.value()}")
...
red_constraint: -1.5999999999999996
blue_constraint: 16.0
yellow_constraint: 3.8000000000000007
green_constraint: 0.0)

>>> model.solver
<pulp.apis.coin_api.PULP_CBC_CMD at 0x7f0f005c6210>

# Define the model
model = LpProblem(name = "resource-allocation", sense = LpMaximize)

# Define the decision variables
x = {i: LpVariable(name = f"x{i}", lowBound = 0) for i in range(1, 5)}

# Add constraints
model += (lpSum(x.values()) <= 50, "manpower")
model += (3 * x[1] + 2 * x[2] + x[3] <= 100, "material_a")
model += (x[2] + 2 * x[3] + 3 * x[4] <= 90, "material_b")

# Set the objective
model += 20 * x[1] + 12 * x[2] + 40 * x[3] + 25 * x[4]

# Solve the optimization problem
status = model.solve()

# Get the results
print(f"status: {model.status}, {LpStatus[model.status]}")
print(f"objective: {model.objective.value()}")

for var in x.values():
    print(f"{var.name}: {var.value()}")

for name, constraint in model.constraints.items():
    print(f"{name}: {constraint.value()}")

model = LpProblem(name = "resource-allocation", sense = LpMaximize)

# Define the decision variables
x = {i: LpVariable(name = f"x{i}", lowBound = 0) for i in range(1, 5)}
y = {i: LpVariable(name = f"y{i}", cat = "Binary") for i in (1, 3)}

# Add constraints
model += (lpSum(x.values()) <= 50, "manpower")
model += (3 * x[1] + 2 * x[2] + x[3] <= 100, "material_a")
model += (x[2] + 2 * x[3] + 3 * x[4] <= 90, "material_b")

M = 100
model += (x[1] <= y[1] * M, "x1_constraint")
model += (x[3] <= y[3] * M, "x3_constraint")
model += (y[1] + y[3] <= 1, "y_constraint")

# Set Objective
model += 20 * x[1] + 12 * x[2] + 40 * x[3] + 25 * x[4]

# Solve The Optimisation Problem
status = model.solve()

print(f"status: {model.status}, {LpStatus[model.status]}")
print(f"objective: {model.objective.value()}")

for var in model.variables():
    print(f"{var.name}: {var.value()}")

for name, constraint in model.constraints.items():
    print(f"{name}: {constraint.value()}")