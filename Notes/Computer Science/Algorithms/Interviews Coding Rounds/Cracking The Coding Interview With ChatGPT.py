# Solve the Cracking The Coding Interview chapter on Linked Lists in Python.

# Here are Python solutions for the linked list problems from Cracking the Coding Interview (CtCI):

#1. Remove Duplicates (2.1)
#Problem: Remove duplicates from an unsorted linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def remove_duplicates(head):
    if not head:
        return None

    seen = set()
    seen.add(head.val)
    current = head

    while current.next:
        if current.next.val in seen:
            current.next = current.next.next
        else:
            seen.add(current.next.val)
            current = current.next
    return head

#2. Kth to Last (2.2)
#Problem: Find the k-th to last element of a singly linked list.

def kth_to_last(head, k):
    slow = fast = head
    for _ in range(k):
        if not fast:
            return None
        fast = fast.next
    
    while fast:
        slow = slow.next
        fast = fast.next
    
    return slow.val

#3. Delete Middle Node (2.3)
#Problem: Delete a node in the middle (not the first or last) given only access to that node.

def delete_middle_node(node):
    if not node or not node.next:
        return
    node.val = node.next.val
    node.next = node.next.next

# Would think in both C and Python here one would want to delete the node.next ListNode instance so as to not waste memory. Try some line like: delete node.next if confused in an interview-like setting.

#4. Partition (2.4)
#Problem: Partition a linked list around value x, preserving original order.

def partition(head, x):
    before = before_head = ListNode(0)
    after = after_head = ListNode(0)

    while head:
        if head.val < x:
            before.next = head
            before = before.next
        else:
            after.next = head
            after = after.next
        head = head.next

    after.next = None
    before.next = after_head.next

    return before_head.next

#5. Sum Lists (2.5)
#Problem: Add two numbers represented as linked lists in reverse order.

def sum_lists(l1, l2):
    dummy = current = ListNode(0)
    carry = 0

    while l1 or l2 or carry:
        val1 = l1.val if l1 else 0
        val2 = l2.val if l2 else 0
        total = val1 + val2 + carry
        carry, value = divmod(total, 10)
        
        current.next = ListNode(value)
        current = current.next
        
        if l1: l1 = l1.next
        if l2: l2 = l2.next

    return dummy.next

#6. Palindrome (2.6)
#Problem: Check if a linked list is a palindrome.

def is_palindrome(head):
    slow, fast = head, head
    stack = []

    while fast and fast.next:
        stack.append(slow.val)
        slow = slow.next
        fast = fast.next.next

    if fast:
        slow = slow.next

    while slow:
        if slow.val != stack.pop():
            return False
        slow = slow.next

    return True

#7. Intersection (2.7)
#Problem: Determine if two linked lists intersect by reference.

def get_intersection_node(headA, headB):
    if not headA or not headB:
        return None

    a, b = headA, headB
    while a != b:
        a = a.next if a else headB
        b = b.next if b else headA

    return a

#8. Loop Detection (2.8)
#Problem: Detect a cycle in a linked list.

def detect_cycle(head):
    slow, fast = head, head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break
    else:
        return None

    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    return slow

#1. Three in One (3.1)
#Problem: Implement three stacks using a single array.

class ThreeInOne:
    def __init__(self, stack_size):
        self.stack_size = stack_size
        self.array = [0] * (stack_size * 3)
        self.sizes = [0] * 3

    def push(self, stack_num, value):
        if self.sizes[stack_num] >= self.stack_size:
            raise Exception("Stack is full")
        index = stack_num * self.stack_size + self.sizes[stack_num]
        self.array[index] = value
        self.sizes[stack_num] += 1

    def pop(self, stack_num):
        if self.sizes[stack_num] == 0:
            raise Exception("Stack is empty")
        index = stack_num * self.stack_size + self.sizes[stack_num] - 1
        value = self.array[index]
        self.array[index] = 0
        self.sizes[stack_num] -= 1
        return value

    def peek(self, stack_num):
        if self.sizes[stack_num] == 0:
            return None
        index = stack_num * self.stack_size + self.sizes[stack_num] - 1
        return self.array[index]

    def is_empty(self, stack_num):
        return self.sizes[stack_num] == 0

#2. Stack Min (3.2)
#Problem: Implement a stack that supports push, pop, and min in O(1) time.

class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, value):
        self.stack.append(value)
        if not self.min_stack or value <= self.min_stack[-1]:
            self.min_stack.append(value)

    def pop(self):
        if not self.stack:
            return None
        value = self.stack.pop()
        if value == self.min_stack[-1]:
            self.min_stack.pop()
        return value

    def min(self):
        return self.min_stack[-1] if self.min_stack else None

#3. Stack of Plates (3.3)
#Problem: Implement a SetOfStacks that behaves like a single stack but consists of multiple stacks.

class SetOfStacks:
    def __init__(self, threshold):
        self.threshold = threshold
        self.stacks = [[]]

    def push(self, value):
        if len(self.stacks[-1]) >= self.threshold:
            self.stacks.append([])
        self.stacks[-1].append(value)

    def pop(self):
        if not self.stacks[-1]:
            self.stacks.pop()
        if not self.stacks:
            return None
        return self.stacks[-1].pop()

    def pop_at(self, index):
        if index < 0 or index >= len(self.stacks) or not self.stacks[index]:
            return None
        return self.stacks[index].pop()

#4. Queue via Stacks (3.4)
#Problem: Implement a queue using two stacks.

class MyQueue:
    def __init__(self):
        self.stack_newest = []
        self.stack_oldest = []

    def push(self, value):
        self.stack_newest.append(value)

    def shift_stacks(self):
        if not self.stack_oldest:
            while self.stack_newest:
                self.stack_oldest.append(self.stack_newest.pop())

    def pop(self):
        self.shift_stacks()
        return self.stack_oldest.pop() if self.stack_oldest else None

    def peek(self):
        self.shift_stacks()
        return self.stack_oldest[-1] if self.stack_oldest else None

    def is_empty(self):
        return not self.stack_newest and not self.stack_oldest

#5. Sort Stack (3.5)
#Problem: Sort a stack in ascending order using only one additional stack.

def sort_stack(stack):
    temp_stack = []

    while stack:
        temp = stack.pop()
        while temp_stack and temp_stack[-1] > temp:
            stack.append(temp_stack.pop())
        temp_stack.append(temp)

    while temp_stack:
        stack.append(temp_stack.pop())

    return stack

#6. Animal Shelter (3.6)
#Problem: Implement an animal shelter that operates on a first-in, first-out basis.

from collections import deque

class AnimalShelter:
    def __init__(self):
        self.dogs = deque()
        self.cats = deque()
        self.order = 0  # Timestamp to track order

    def enqueue(self, animal, type_):
        if type_ == "dog":
            self.dogs.append((self.order, animal))
        elif type_ == "cat":
            self.cats.append((self.order, animal))
        self.order += 1

    def dequeue_any(self):
        if not self.dogs:
            return self.dequeue_cat()
        if not self.cats:
            return self.dequeue_dog()
        return self.dequeue_dog() if self.dogs[0][0] < self.cats[0][0] else self.dequeue_cat()

    def dequeue_dog(self):
        return self.dogs.popleft()[1] if self.dogs else None

    def dequeue_cat(self):
        return self.cats.popleft()[1] if self.cats else None

#1. Route Between Nodes (4.1)
#Problem: Given a directed graph and two nodes, determine if there is a path between them.

from collections import deque

class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_edge(self, src, dest):
        if src not in self.adj_list:
            self.adj_list[src] = []
        self.adj_list[src].append(dest)

    def has_path(self, start, end):
        if start == end:
            return True

        visited = set()
        queue = deque([start])

        while queue:
            node = queue.popleft()
            if node == end:
                return True
            if node in visited:
                continue
            visited.add(node)
            for neighbor in self.adj_list.get(node, []):
                queue.append(neighbor)

        return False

#2. Minimal Tree (4.2)
#Problem: Create a minimal height binary search tree from a sorted array.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sorted_array_to_bst(arr):
    if not arr:
        return None

    mid = len(arr) // 2
    root = TreeNode(arr[mid])
    root.left = sorted_array_to_bst(arr[:mid])
    root.right = sorted_array_to_bst(arr[mid+1:])
    
    return root

#3. List of Depths (4.3)
#Problem: Given a binary tree, create a linked list of all nodes at each depth.

from collections import deque

def list_of_depths(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])

    while queue:
        level_size = len(queue)
        level_nodes = []
        
        for _ in range(level_size):
            node = queue.popleft()
            level_nodes.append(node)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level_nodes)

    return result

#4. Check Balanced (4.4)
#Problem: Determine if a binary tree is balanced.

def is_balanced(root):
    def check_height(node):
        if not node:
            return 0
        
        left_height = check_height(node.left)
        if left_height == -1:
            return -1
        
        right_height = check_height(node.right)
        if right_height == -1:
            return -1
        
        if abs(left_height - right_height) > 1:
            return -1

        return max(left_height, right_height) + 1

    return check_height(root) != -1

#5. Validate BST (4.5)
#Problem: Check if a binary tree is a valid binary search tree (BST).

def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    if not root:
        return True
    if not (min_val < root.val < max_val):
        return False
    return is_valid_bst(root.left, min_val, root.val) and is_valid_bst(root.right, root.val, max_val)

#6. Successor (4.6)
#Problem: Find the in-order successor of a node in a BST.

def inorder_successor(root, node):
    successor = None
    while root:
        if node.val < root.val:
            successor = root
            root = root.left
        else:
            root = root.right
    return successor

#7. Build Order (4.7)
#Problem: Given a list of projects and dependencies, determine a valid build order.

def build_order(projects, dependencies):
    from collections import deque, defaultdict
    
    graph = defaultdict(list)
    in_degree = {project: 0 for project in projects}

    for dep, proj in dependencies:
        graph[dep].append(proj)
        in_degree[proj] += 1

    queue = deque([p for p in projects if in_degree[p] == 0])
    order = []

    while queue:
        project = queue.popleft()
        order.append(project)
        for dependent in graph[project]:
            in_degree[dependent] -= 1
            if in_degree[dependent] == 0:
                queue.append(dependent)

    return order if len(order) == len(projects) else None

#8. First Common Ancestor (4.8)
#Problem: Find the first common ancestor of two nodes in a binary tree.

def first_common_ancestor(root, p, q):
    if not root or root == p or root == q:
        return root

    left = first_common_ancestor(root.left, p, q)
    right = first_common_ancestor(root.right, p, q)

    if left and right:
        return root
    return left if left else right

#9. BST Sequences (4.9)
#Problem: Find all possible arrays that could have led to a given BST.

from itertools import permutations

def bst_sequences(root):
    if not root:
        return [[]]
    
    left_seqs = bst_sequences(root.left)
    right_seqs = bst_sequences(root.right)
    
    result = []
    for left in left_seqs:
        for right in right_seqs:
            for merged in weave_lists(left, right):
                result.append([root.val] + merged)
    
    return result

def weave_lists(left, right, prefix=[]):
    if not left or not right:
        return [prefix + left + right]
    
    result = []
    result += weave_lists(left[1:], right, prefix + [left[0]])
    result += weave_lists(left, right[1:], prefix + [right[0]])
    
    return result

#10. Check Subtree (4.10)
#Problem: Determine if one binary tree is a subtree of another.

def is_subtree(t1, t2):
    if not t2:
        return True
    if not t1:
        return False
    if are_identical(t1, t2):
        return True
    return is_subtree(t1.left, t2) or is_subtree(t1.right, t2)

def are_identical(root1, root2):
    if not root1 and not root2:
        return True
    if not root1 or not root2:
        return False
    return (root1.val == root2.val and 
            are_identical(root1.left, root2.left) and 
            are_identical(root1.right, root2.right))

# Comment from Lazar here: this is a really awful algorithm I think. The proper way to do this one is probably usually in competitive programming via like tree flattening in to an array followed by hashing so the whole solution is like O[Input Size] and checking if the subtree is induced is as simple as like going through for each subtree of T1 if it hashes to the same value as T2.

#11. Random Node (4.11)
#Problem: Implement a binary tree with a method to get a random node.

import random

class TreeNodeRandom:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None
        self.size = 1

    def insert(self, val):
        if val <= self.val:
            if self.left:
                self.left.insert(val)
            else:
                self.left = TreeNodeRandom(val)
        else:
            if self.right:
                self.right.insert(val)
            else:
                self.right = TreeNodeRandom(val)
        self.size += 1

    def get_random_node(self):
        left_size = self.left.size if self.left else 0
        index = random.randint(0, self.size - 1)
        if index < left_size:
            return self.left.get_random_node()
        elif index == left_size:
            return self
        else:
            return self.right.get_random_node()

