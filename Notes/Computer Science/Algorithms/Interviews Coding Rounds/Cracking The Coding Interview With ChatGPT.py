# Worth thinking about this book and also reading the intended solutions from the authors in Java.
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
    root.left = sorted_array_to_bst(arr[:mid]) # Comment from Lazar: looks bad.
    root.right = sorted_array_to_bst(arr[mid+1:]) # Comment from Lazar: looks bad.
    return root
# Comment from Lazar: think this is awful. Really bad programme design here. You do not want to be uh I think the way Python executes this is like uh... still somehow probably sharper rather than calling this on arr[:mid] you want to be having a sub function which reads in 2 integers representing the left and right bound or something in case this actual array is getting moved around a bunch so like the run time might still be O[n * log[n]] or something but these calls go faster.
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
# Lazar: from now on I will comment with "Lazar:". Seems to me like my canonical dag function from competitive programming library works OK here.
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
# Lazar: again, see my competitive programming notebook.
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
# Comment from Lazar here: this is a really awful algorithm I think. The proper way to do this one is probably usually in competitive programming via like tree flattening in to an array followed by hashing so the whole solution is like O[Input Size] and checking if the subtree is induced is as simple as like going through for each subtree of T1 if it hashes to the same value as T2. And it is also quite simple to also check it the tree has the same the subtree has the same size as a precondition.
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
# Lazar: Ummm seems obviously wrong to me. A much better way would be to simply track like say we are doing a binary tree uh kind of depends on the operations supported but if the tree has decent density on its underlying array of support what we just do is keep track of the maximum or the uh length of the array of support and then pseudorandomly see if there is a tree element at an index basically so as long as the density is reasonably high this randomised algorithm will eventually just hit a random uniform node in the entire tree. And this way we do not have to keep track of subtree sizes or update up the tree in O[log[n]] or worse O[n] for each insertion. Depending on desired insertion time tradeoff with get random node tradeoff and expected density behaviours.
#Chapter 5: Bit Manipulation - Python Solutions
#5.1 Insertion
#Problem: Insert M into N from bit i to bit j.
def insert_bits(n, m, i, j):
    all_ones = ~0  # Sequence of all 1s
    left = all_ones << (j + 1)  # 1s before position j, then 0s
    right = (1 << i) - 1  # 1s after position i
    mask = left | right  # All 1s, except for 0s between i and j
    n_cleared = n & mask  # Clear bits j through i
    m_shifted = m << i  # Shift M into the correct position
    return n_cleared | m_shifted  # Merge M into N
# Example usage:
print(bin(insert_bits(0b10000000000, 0b10011, 2, 6)))  # Expected: 0b10001001100
#5.2 Binary to String
#Problem: Convert decimal fraction between 0 and 1 into binary.
def binary_to_string(num):
    if num >= 1 or num <= 0:
        return "ERROR"
    binary = ["0."]
    while num > 0:
        if len(binary) >= 34:  # Account for '0.' prefix
            return "ERROR"
        num *= 2
        if num >= 1:
            binary.append("1")
            num -= 1
        else:
            binary.append("0")
    return "".join(binary)
# Example usage:
print(binary_to_string(0.625))  # Expected: "0.101"
#5.3 Flip Bit to Win
#Problem: Find longest sequence of 1s possible by flipping one bit.
def flip_bit_to_win(n):
    if n == -1:
        return 32  # All bits are 1
    max_len = 1
    curr_len = 0
    prev_len = 0
    while n != 0:
        if n & 1:
            curr_len += 1
        else:
            prev_len = 0 if (n & 2) == 0 else curr_len
            curr_len = 0
        max_len = max(max_len, prev_len + curr_len + 1)
        n >>= 1
    return max_len
# Example usage:
print(flip_bit_to_win(0b11011101111))  # Expected: 8
#5.4 Next Number
#Problem: Find next smallest and next largest number with the same number of 1s.
def get_next(n):
    c = n
    c0 = c1 = 0
    while ((c & 1) == 0) and (c != 0):
        c0 += 1
        c >>= 1
    while (c & 1) == 1:
        c1 += 1
        c >>= 1
    if c0 + c1 == 31 or c0 + c1 == 0:
        return -1  # No larger number possible
    pos = c0 + c1
    n |= (1 << pos)
    n &= ~((1 << pos) - 1)
    n |= (1 << (c1 - 1)) - 1
    return n
def get_prev(n):
    c = n
    c0 = c1 = 0
    while (c & 1) == 1:
        c1 += 1
        c >>= 1
    if c == 0:
        return -1  # No smaller number possible
    while ((c & 1) == 0) and (c != 0):
        c0 += 1
        c >>= 1
    pos = c0 + c1
    n &= ((~0) << (pos + 1))
    mask = (1 << (c1 + 1)) - 1
    n |= mask << (c0 - 1)
    return n
# Example usage:
num = 0b10110
print(bin(get_next(num)))  # Expected: Next larger number
print(bin(get_prev(num)))  # Expected: Next smaller number
#5.5 Debugger
#Problem: Explain why (n & (n - 1)) == 0 checks if n is a power of 2.
#Solution:
#n & (n - 1) removes the lowest set bit in n. If the result is 0, n had only one bit set, meaning it's a power of 2.
def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0
# Example usage:
print(is_power_of_two(16))  # Expected: True
print(is_power_of_two(18))  # Expected: False
#5.6 Conversion
#Problem: Find the number of bits to flip to convert A to B.
def bit_swap_required(a, b):
    count = 0
    c = a ^ b
    while c:
        count += c & 1
        c >>= 1
    return count
# Example usage:
print(bit_swap_required(29, 15))  # Expected: 2
#5.7 Pairwise Swap
#Problem: Swap odd and even bits.
def swap_odd_even_bits(n):
    even_mask = 0xAAAAAAAA  # 10101010...
    odd_mask = 0x55555555   # 01010101...
    even_bits = (n & even_mask) >> 1
    odd_bits = (n & odd_mask) << 1
    return even_bits | odd_bits
# Example usage:
print(bin(swap_odd_even_bits(0b101010)))  # Expected: Swapped version
#5.8 Draw Line
#Problem: Draw a horizontal line on a monochrome screen.
def draw_line(screen, width, x1, x2, y):
    start_offset = x1 % 8
    first_full_byte = x1 // 8 if start_offset == 0 else (x1 // 8) + 1
    end_offset = x2 % 8
    last_full_byte = x2 // 8 if end_offset == 7 else (x2 // 8) - 1
    for b in range(first_full_byte, last_full_byte + 1):
        screen[(width // 8) * y + b] = 0xFF
    start_mask = 0xFF >> start_offset
    end_mask = ~(0xFF >> (end_offset + 1))
    if (x1 // 8) == (x2 // 8):
        mask = start_mask & end_mask
        screen[(width // 8) * y + (x1 // 8)] |= mask
    else:
        if start_offset != 0:
            screen[(width // 8) * y + (x1 // 8)] |= start_mask
        if end_offset != 7:
            screen[(width // 8) * y + (x2 // 8)] |= end_mask
# Example usage:
screen = [0] * 10
draw_line(screen, 32, 5, 25, 2)
print(screen)
# 6.1 The Heavy Pill
def find_heavy_bottle(weight):
    expected_weight = sum(range(1, 21))  # Sum of first 20 natural numbers
    extra_weight = weight - expected_weight
    return int(extra_weight / 0.1)  # This gives the heavy bottle number
# Example usage:
# If the total weight measured is 211.5g, the heavy bottle is:
print(find_heavy_bottle(211.5))  # Output: 15
# 6.2 Basketball
def count_ways_to_score(n):
    dp = [0] * (n + 1)
    dp[0] = 1  # One way to score 0 points (doing nothing)
    for score in [1, 2, 3]:  
        for i in range(score, n + 1):
            dp[i] += dp[i - score]
    return dp[n]
# Example usage:
print(count_ways_to_score(4))  # Output: 7
# 6.3 Dominos on a Chessboard
# 6.4 Ants on a Triangle
# 6.5 Jugs of Water
def water_jug():
    x, y = 0, 0  # (5L jug, 3L jug)
    steps = []
    # Fill 3L jug and transfer to 5L jug
    while x != 4:
        if y == 0:
            y = 3  # Fill 3L
            steps.append("Fill 3L jug")
        elif x < 5:
            transfer = min(5 - x, y)
            x += transfer
            y -= transfer
            steps.append(f"Pour {transfer}L from 3L jug to 5L jug")
        else:
            x = 0  # Empty 5L jug
            steps.append("Empty 5L jug")
    return steps
print(water_jug())
# 6.6 Blue-Eyed Island
# 6.7 The Apocalypse
import random
def simulate_apocalypse(families=10000):
    boys = girls = 0
    for _ in range(families):
        while True:
            if random.choice([True, False]):  # Boy
                boys += 1
                break
            else:  # Girl
                girls += 1
    return boys, girls, boys / girls
print(simulate_apocalypse())  # Output: (≈1:1 ratio)
# 6.8 The Egg Drop Problem
def egg_drop():
    floors, step, current = 100, 14, 14
    while current < 100:
        print(f"Drop at {current}")
        step -= 1
        current += step
egg_drop()
# 7.1 Deck of Cards
import random
from enum import Enu
class Suit(Enum):
    HEARTS = "Hearts"
    DIAMONDS = "Diamonds"
    CLUBS = "Clubs"
    SPADES = "Spades"
class Card:
    def __init__(self, rank, suit):
        self.rank = rank
        self.suit = suit
    def __repr__(self):
        return f"{self.rank} of {self.suit.value}"
class Deck:
    def __init__(self):
        self.cards = [Card(rank, suit) for suit in Suit for rank in range(1, 14)]
        self.shuffle()
    def shuffle(self):
        random.shuffle(self.cards)
    def deal_card(self):
        return self.cards.pop() if self.cards else None
# Example Usage
deck = Deck()
print(deck.deal_card())  # Example: "10 of Hearts"
# 7.2 Call Center
from collections import deque
class Employee:
    def __init__(self, name, level):
        self.name = name
        self.level = level  # 0: Respondent, 1: Manager, 2: Director
        self.available = True
    def handle_call(self):
        self.available = False
    def end_call(self):
        self.available = True
class CallCenter:
    def __init__(self):
        self.employees = {0: deque(), 1: deque(), 2: deque()}
    def add_employee(self, employee):
        self.employees[employee.level].append(employee)
    def dispatch_call(self):
        for level in range(3):
            if self.employees[level]:
                emp = self.employees[level].popleft()
                emp.handle_call()
                print(f"Call assigned to {emp.name} ({'Respondent' if level == 0 else 'Manager' if level == 1 else 'Director'})")
                return emp
        print("No available employees to take the call")
        return None
# Example Usage
cc = CallCenter()
cc.add_employee(Employee("Alice", 0))
cc.add_employee(Employee("Bob", 1))
call = cc.dispatch_call()  # Assigns call to Alice (Respondent)
# 7.3 Jukebox
class Song:
    def __init__(self, title, artist):
        self.title = title
        self.artist = artist
    def __repr__(self):
        return f"{self.title} by {self.artist}"
class Playlist:
    def __init__(self):
        self.songs = []
    def add_song(self, song):
        self.songs.append(song)
    def play(self):
        if self.songs:
            print(f"Playing: {self.songs.pop(0)}")
        else:
            print("Playlist is empty!")
# Example Usage
jukebox = Playlist()
jukebox.add_song(Song("Bohemian Rhapsody", "Queen"))
jukebox.play()  # Playing: Bohemian Rhapsody by Queen
# 7.4 Parking Lot
class Vehicle:
    def __init__(self, size):
        self.size = size # 1 = Motorcycle, 2 = Car, 3 = Bus
class ParkingLot:
    def __init__(self, spots):
        self.spots = [None] * spots  # Empty spots list
    def park_vehicle(self, vehicle):
        for i in range(len(self.spots)):
            if self.spots[i] is None:
                self.spots[i] = vehicle
                print(f"Vehicle of size {vehicle.size} parked at spot {i}")
                return True
        print("No available parking spot")
        return False
# Example Usage
lot = ParkingLot(5)
lot.park_vehicle(Vehicle(2))  # Park a car
# 7.5 Online Book Reader
class Book:
    def __init__(self, title, author, content):
        self.title = title
        self.author = author
        self.content = content.split("\n")
    def read_page(self, page):
        return self.content[page] if 0 <= page < len(self.content) else "End of book"
class User:
    def __init__(self, name):
        self.name = name
        self.current_book = None
        self.current_page = 0
    def start_reading(self, book):
        self.current_book = book
        self.current_page = 0
    def turn_page(self):
        if self.current_book:
            print(self.current_book.read_page(self.current_page))
            self.current_page += 1
# Example Usage
book = Book("Sample Book", "Author", "Page 1\nPage 2\nPage 3")
user = User("Alice")
user.start_reading(book)
user.turn_page()  # Page 1
user.turn_page()  # Page 2
# 7.6 Chess Game
class Piece:
    def __init__(self, color):
        self.color = color  # "White" or "Black"
    def valid_moves(self, position):
        raise NotImplementedError
class Pawn(Piece):
    def valid_moves(self, position):
        return [position + 1]  # Simplified
class ChessBoard:
    def __init__(self):
        self.board = {}
    def place_piece(self, piece, position):
        self.board[position] = piece
# Example Usage
board = ChessBoard()
board.place_piece(Pawn("White"), (1, 1))
print(board.board)  # {(1,1): <Pawn object>}
# 8.1 Triple Step
def count_ways(n, memo={}):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n in memo:
        return memo[n]
    memo[n] = count_ways(n - 1, memo) + count_ways(n - 2, memo) + count_ways(n - 3, memo)
    return memo[n]
# Example Usage:
print(count_ways(5))  # Output: 13
# 8.2 Robot in a Grid
def find_path(grid):
    if not grid or not grid[0]:
        return None
    rows, cols = len(grid), len(grid[0])
    path = []
    memo = {}
    def backtrack(r, c):
        if r < 0 or c < 0 or grid[r][c] == 1:
            return False
        if (r, c) in memo:
            return memo[(r, c)]
        at_origin = (r == 0 and c == 0)
        if at_origin or backtrack(r - 1, c) or backtrack(r, c - 1):
            path.append((r, c))
            memo[(r, c)] = True
            return True
# 8.3 Magic Index
def magic_index(arr, left=0, right=None):
    if right is None:
        right = len(arr) - 1
    if left > right:
        return -1
    mid = (left + right) // 2
    if arr[mid] == mid:
        return mid
    elif arr[mid] > mid:
        return magic_index(arr, left, mid - 1)
    else:
        return magic_index(arr, mid + 1, right)
# Example Usage:
print(magic_index([-1, 0, 2, 3, 5]))  # Output: 2
# 8.4 Power Set
def subsets(arr):
    result = []
    def backtrack(index, path):
        if index == len(arr):
            result.append(path[:])
            return
        backtrack(index + 1, path)
        path.append(arr[index])
        backtrack(index + 1, path)
        path.pop()
    backtrack(0, [])
    return result
# Example Usage:
print(subsets(["a", "b", "c"]))  
# Output: [[], ['c'], ['b'], ['b', 'c'], ['a'], ['a', 'c'], ['a', 'b'], ['a', 'b', 'c']]
# 8.5 Recursive Multiply
def multiply(a, b):
    if b == 0:
        return 0
    if b > 0:
        return a + multiply(a, b - 1)
    return -multiply(a, -b)
# Example Usage:
print(multiply(3, 5))  # Output: 15
# 8.6 Towers of Hanoi
def hanoi(n, source, target, auxiliary):
    if n == 1:
        print(f"Move disk 1 from {source} to {target}")
        return
    hanoi(n - 1, source, auxiliary, target)
    print(f"Move disk {n} from {source} to {target}")
    hanoi(n - 1, auxiliary, target, source)
# Example Usage:
hanoi(3, 'A', 'C', 'B')
# 8.7 Permutations Without Duplicates
def permute(s, path=""):
    if not s:
        print(path)
        return
    for i in range(len(s)):
        permute(s[:i] + s[i+1:], path + s[i])
# Example Usage:
permute("abc")
# 8.8 Permutations With Duplicates
from collections import Counter
def permute_unique(s, path="", counter=None):
    if counter is None:
        counter = Counter(s)
    if len(path) == len(s):
        print(path)
        return
    for char in counter:
        if counter[char] > 0:
            counter[char] -= 1
            permute_unique(s, path + char, counter)
            counter[char] += 1
# Example Usage:
permute_unique("aabc")
# 8.9 Parentheses
def generate_parentheses(n, left=0, right=0, path=""):
    if left == n and right == n:
        print(path)
        return
    if left < n:
        generate_parentheses(n, left + 1, right, path + "(")
    if right < left:
        generate_parentheses(n, left, right + 1, path + ")")
# Example Usage:
generate_parentheses(3)
# 8.10 Paint Fill
def paint_fill(screen, r, c, new_color, original=None):
    if original is None:
        original = screen[r][c]
    if r < 0 or r >= len(screen) or c < 0 or c >= len(screen[0]) or screen[r][c] != original:
        return
    screen[r][c] = new_color
    directions = [(0,1), (1,0), (0,-1), (-1,0)]
    for dr, dc in directions:
        paint_fill(screen, r + dr, c + dc, new_color, original)
# Example Usage:
screen = [[0,0,0], [0,1,0], [0,0,0]]
paint_fill(screen, 1, 1, 2)
print(screen)  # Filled area changed to 2
# Lazar: I am not the domain expert really to verify if this is great style according to an elite top level MAGMA boss kind of a SWE dude.
# 9.1 Stock Data Service
from flask import Flask, jsonify
app = Flask(__name__)
# Simulated stock database
stock_prices = {
    "AAPL": 175.50,
    "GOOGL": 2800.10,
    "AMZN": 3450.00,
}
@app.route('/stock/<symbol>', methods=['GET'])
def get_stock_price(symbol):
    price = stock_prices.get(symbol.upper())
    if price is None:
        return jsonify({"error": "Stock not found"}), 404
    return jsonify({"symbol": symbol.upper(), "price": price})
if __name__ == '__main__':
    app.run(debug=True)
# 9.2 Social Network: Finding a Mutual Friend
from collections import deque
class SocialNetwork:
    def __init__(self):
        self.graph = {}
    def add_friendship(self, user1, user2):
        self.graph.setdefault(user1, []).append(user2)
        self.graph.setdefault(user2, []).append(user1)
    def shortest_path(self, start, end):
        if start not in self.graph or end not in self.graph:
            return None
        queue = deque([(start, [start])])
        visited = set()
        while queue:
            user, path = queue.popleft()
            if user == end:
                return path
            for friend in self.graph.get(user, []):
                if friend not in visited:
                    visited.add(friend)
                    queue.append((friend, path + [friend]))
        return None  # No path found
# Example Usage:
network = SocialNetwork()
network.add_friendship("Alice", "Bob")
network.add_friendship("Bob", "Charlie")
network.add_friendship("Charlie", "David")
print(network.shortest_path("Alice", "David"))  
# Output: ['Alice', 'Bob', 'Charlie', 'David']
# Lazar: Hmmm this is kind of an interesting task. Think the uh usual approach here would be to like have for each person just have a hash set of their friends or something.
# 9.3 Web Crawler
import threading
import requests
from bs4 import BeautifulSoup
from collections import deque
class WebCrawler:
    def __init__(self, base_url, max_depth=2):
        self.base_url = base_url
        self.max_depth = max_depth
        self.visited = set()
        self.lock = threading.Lock()
    def crawl(self, url, depth=0):
        if depth > self.max_depth or url in self.visited:
            return
        with self.lock:
            self.visited.add(url)
        try:
            response = requests.get(url, timeout=5)
            if response.status_code != 200:
                return
            print(f"Crawled: {url}")
            soup = BeautifulSoup(response.text, 'html.parser')
            links = [a['href'] for a in soup.find_all('a', href=True) if a['href'].startswith('http')]
            threads = []
            for link in links:
                thread = threading.Thread(target=self.crawl, args=(link, depth + 1))
                threads.append(thread)
                thread.start()
            for thread in threads:
                thread.join()
        except Exception as e:
            print(f"Error crawling {url}: {e}")
# Example Usage:
crawler = WebCrawler("https://example.com")
crawler.crawl("https://example.com")
# 9.4 Search Engine Index
class SearchEngine:
    def __init__(self):
        self.index = {}
    def add_document(self, url, content):
        words = content.lower().split()
        for word in words:
            self.index.setdefault(word, set()).add(url)
    def search(self, query):
        return self.index.get(query.lower(), set())
# Example Usage:
search_engine = SearchEngine()
search_engine.add_document("https://example.com", "Hello world")
search_engine.add_document("https://test.com", "Hello Python")
print(search_engine.search("Hello"))  
# Output: {'https://example.com', 'https://test.com'}
# 9.5 Cache System (LRU Cache)
from collections import OrderedDict
class LRUCache:
    def __init__(self, capacity=3):
        self.cache = OrderedDict()
        self.capacity = capacity
    def get(self, key):
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)  # Mark as recently used
        return self.cache[key]
    def put(self, key, value):
        if key in self.cache:
            self.cache.move_to_end(key)
        elif len(self.cache) >= self.capacity:
            self.cache.popitem(last=False)  # Remove least recently used item
        self.cache[key] = value
# Example Usage:
cache = LRUCache(2)
cache.put(1, 100)
cache.put(2, 200)
print(cache.get(1))  # Output: 100
cache.put(3, 300)    # Removes key 2 (least recently used)
print(cache.get(2))  # Output: -1 (not found)
# 9.6 URL Shortener (TinyURL)
import hashlib
class URLShortener:
    def __init__(self):
        self.url_map = {}
    def shorten(self, original_url):
        short_hash = hashlib.md5(original_url.encode()).hexdigest()[:6]
        self.url_map[short_hash] = original_url
        return f"https://tinyurl.com/{short_hash}"
    def expand(self, short_url):
        short_hash = short_url.split("/")[-1]
        return self.url_map.get(short_hash, "URL not found")
# Example Usage:
shortener = URLShortener()
short_url = shortener.shorten("https://example.com")
print(short_url)  # Example: https://tinyurl.com/1a2b3c
print(shortener.expand(short_url))  # Output: https://example.com
# 9.7 Distributed Key-Value Store
import hashlib
class ConsistentHashing:
    def __init__(self, servers):
        self.servers = {self.hash(server): server for server in servers}
    def hash(self, key):
        return int(hashlib.md5(key.encode()).hexdigest(), 16) % 100
    def get_server(self, key):
        key_hash = self.hash(key)
        closest_server = min(self.servers.keys(), key=lambda x: abs(x - key_hash))
        return self.servers[closest_server]
# Example Usage:
ch = ConsistentHashing(["Server1", "Server2", "Server3"])
print(ch.get_server("my_key"))  # Returns the server storing "my_key"
# 10.1 Sorted Merge
def sorted_merge(A, B, lastA, lastB):
    indexA, indexB, indexMerged = lastA - 1, lastB - 1, lastA + lastB - 1
    while indexB >= 0:
        if indexA >= 0 and A[indexA] > B[indexB]:
            A[indexMerged] = A[indexA]
            indexA -= 1
        else:
            A[indexMerged] = B[indexB]
            indexB -= 1
        indexMerged -= 1
# Example Usage:
A = [1, 3, 5, 0, 0, 0]
B = [2, 4, 6]
sorted_merge(A, B, 3, 3)
print(A)  # Output: [1, 2, 3, 4, 5, 6]
# 10.2 Group Anagrams
from collections import defaultdict
def group_anagrams(words):
    anagrams = defaultdict(list)
    for word in words:
        key = ''.join(sorted(word))
        anagrams[key].append(word)
    return [group for group in anagrams.values()]
# Example Usage:
words = ["bat", "tab", "eat", "tea", "tan", "nat"]
print(group_anagrams(words))
# Output: [['bat', 'tab'], ['eat', 'tea'], ['tan', 'nat']]
# 10.3 Search in Rotated Array
def search_rotated(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        if arr[left] <= arr[mid]:  # Left half is sorted
            if arr[left] <= target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:  # Right half is sorted
            if arr[mid] < target <= arr[right]:
                left = mid + 1
            else:
                right = mid - 1
    return -1
# Example Usage:
arr = [4, 5, 6, 7, 0, 1, 2]
print(search_rotated(arr, 0))  # Output: 4
# Lazar: Think this task is super canonical. Would want to Google around more to ensure good memory lookups and dropping constant factors as possible here.
# 10.4 Sorted Search, No Size
def search_listy(listy, target):
    index = 1
    while listy.elementAt(index) != -1 and listy.elementAt(index) < target:
        index *= 2
    left, right = index // 2, index
    while left <= right:
        mid = (left + right) // 2
        val = listy.elementAt(mid)
        if val == target:
            return mid
        elif val == -1 or val > target:
            right = mid - 1
        else:
            left = mid + 1
    return -1
# 10.5 Sparse Search
def sparse_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == "":
            left_idx, right_idx = mid - 1, mid + 1
            while left_idx >= left and arr[left_idx] == "":
                left_idx -= 1
            while right_idx <= right and arr[right_idx] == "":
                right_idx += 1
            if left_idx < left and right_idx > right:
                return -1
            mid = left_idx if left_idx >= left else right_idx
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
# Example Usage:
words = ["at", "", "", "ball", "", "", "car", "", "", "dad", "", ""]
print(sparse_search(words, "ball"))  # Output: 3
# Lazar: Eh. Does not look great to me.
# 10.8 Find Duplicates
class BitVector:
    def __init__(self, size):
        self.vector = [0] * ((size // 32) + 1)
    def set_bit(self, num):
        self.vector[num // 32] |= (1 << (num % 32))
    def get_bit(self, num):
        return (self.vector[num // 32] & (1 << (num % 32))) != 0
def find_duplicates(arr, max_value):
    bit_vector = BitVector(max_value)
    duplicates = []
    for num in arr:
        if bit_vector.get_bit(num):
            duplicates.append(num)
        else:
            bit_vector.set_bit(num)
    return duplicates
# Example Usage:
arr = [1, 5, 7, 5, 9, 1, 10]
print(find_duplicates(arr, 100))  # Output: [5, 1]
# 10.9 Sorted Matrix Search
def search_matrix(matrix, target):
    if not matrix or not matrix[0]:
        return None
    row, col = 0, len(matrix[0]) - 1
    while row < len(matrix) and col >= 0:
        if matrix[row][col] == target:
            return (row, col)
        elif matrix[row][col] > target:
            col -= 1
        else:
            row += 1
    return None
# Example Usage:
matrix = [
    [1,  4,  7,  10],
    [2,  5,  8,  11],
    [3,  6,  9,  12]
]
print(search_matrix(matrix, 8))  # Output: (1, 2)
# 10.10 Rank from Stream
class RankNode:
    def __init__(self, data):
        self.data = data
        self.left_size = 0
        self.left = None
        self.right = None
class StreamRank:
    def __init__(self):
        self.root = None
    def track(self, x):
        if not self.root:
            self.root = RankNode(x)
        else:
            self.insert(self.root, x)
    def insert(self, node, x):
        if x <= node.data:
            node.left_size += 1
            if node.left:
                self.insert(node.left, x)
            else:
                node.left = RankNode(x)
        else:
            if node.right:
                self.insert(node.right, x)
            else:
                node.right = RankNode(x)
    def get_rank(self, x):
        return self.get_rank_helper(self.root, x)
    def get_rank_helper(self, node, x):
        if not node:
            return -1
        if x == node.data:
            return node.left_size
        elif x < node.data:
            return self.get_rank_helper(node.left, x)
        else:
            right_rank = self.get_rank_helper(node.right, x)
            return -1 if right_rank == -1 else node.left_size + 1 + right_rank
# OK
# 11.1
# Think ChatGPT is somehow garbling some garbage here and not looking at the actual underlying source textbook which I ought to get around to eventually anyways.
# The mistake here is probably that the unsigned int i will go from 0 to some positive value at --i or whatever and this loop will be infinite maybe it will go to 2^32-1 or something.
# 11.2 Oh I dunno maybe print statements will help. Single threaded C is interesting.
# 11.3 Probably just read the code and check out if it looks logical is a good first step uh. One way to check if it never returns false when the value should be true would be to run it through real historical games. And checking the other direction mid-key one could get an informal look by pinging in clearly wrong values and checking it does return false as desired.
# 11.4 Just open it up in browser or something? Check out if it is working OK.
# 11.5 Testing a pen ugh you would want to examine it maybe think about inkwell design. Maybe open and close it 100 times click click click to check the opening mechanism is working OK. And write with it. On paper at the very least as intended. See how it feels. OKOKOK according to my father the right move here would be to read the solutions but if one wants to digress on the topic of testing the opening and closing mechanism well one can semi-verify the design notes look good but also when one does an initial production could take out like 1000 pens and use an automated robot to click them with different click strengths say like 10000 times each to verify that all 1000 pass all 10000 clicks or something at which point we would then know maybe discern that our design is OK and furthermore the production process is OK too or something. And do all the other tests a solid number of times so that our firm will win the reputation for being a competitive firm which produces solid quality products and so on and so on.
# 11.6 Oh I dunno monitour the system when it is used properly and improperly. See how it manages the amount of paper left in the machine etc. to ping in that it needs a refill etc. to the relevant parties.
# 11.1 Merge Two Sorted Arrays
def merge_sorted_arrays(A, B, lastA, lastB):
    indexA, indexB, indexMerged = lastA - 1, lastB - 1, lastA + lastB - 1
    while indexB >= 0:
        if indexA >= 0 and A[indexA] > B[indexB]:
            A[indexMerged] = A[indexA]
            indexA -= 1
        else:
            A[indexMerged] = B[indexB]
            indexB -= 1
        indexMerged -= 1
# Example Usage:
A = [1, 3, 5, 0, 0, 0]
B = [2, 4, 6]
merge_sorted_arrays(A, B, 3, 3)
print(A)  # Output: [1, 2, 3, 4, 5, 6]
# Lazar: Interesting enough I think I recently used ChatGPT to generate such a C++ function for me in a round.
# 11.2 Sort Strings Anagramically
from collections import defaultdict
def group_anagrams(words):
    anagram_map = defaultdict(list)
    for word in words:
        sorted_word = ''.join(sorted(word))
        anagram_map[sorted_word].append(word)
    return [group for group in anagram_map.values()]
# Example Usage:
words = ["bat", "tab", "eat", "tea", "tan", "nat"]
print(group_anagrams(words))
# Output: [['bat', 'tab'], ['eat', 'tea'], ['tan', 'nat']]
# 11.3 Find an Element in a Rotated Sorted Array
def search_rotated(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        if arr[left] <= arr[mid]:  # Left half is sorted
            if arr[left] <= target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:  # Right half is sorted
            if arr[mid] < target <= arr[right]:
                left = mid + 1
            else:
                right = mid - 1
    return -1
# Example Usage:
arr = [4, 5, 6, 7, 0, 1, 2]
print(search_rotated(arr, 0))  # Output: 4
# 11.4 Find an Element with No Size
def search_listy(listy, target):
    index = 1
    while listy.elementAt(index) != -1 and listy.elementAt(index) < target:
        index *= 2
    left, right = index // 2, index
    while left <= right:
        mid = (left + right) // 2
        val = listy.elementAt(mid)
        if val == target:
            return mid
        elif val == -1 or val > target:
            right = mid - 1
        else:
            left = mid + 1
    return -1
# 11.5 Sparse Search
def sparse_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == "":
            left_idx, right_idx = mid - 1, mid + 1
            while left_idx >= left and arr[left_idx] == "":
                left_idx -= 1
            while right_idx <= right and arr[right_idx] == "":
                right_idx += 1
            if left_idx < left and right_idx > right:
                return -1
            mid = left_idx if left_idx >= left else right_idx
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
# Example Usage:
words = ["at", "", "", "ball", "", "", "car", "", "", "dad", "", ""]
print(sparse_search(words, "ball"))  # Output: 3
# 11.6 Find Duplicate in 4 Billion Integers
class BitVector:
    def __init__(self, size):
        self.vector = [0] * ((size // 32) + 1)
    def set_bit(self, num):
        self.vector[num // 32] |= (1 << (num % 32))
    def get_bit(self, num):
        return (self.vector[num // 32] & (1 << (num % 32))) != 0
def find_duplicates(arr, max_value):
    bit_vector = BitVector(max_value)
    duplicates = []
    for num in arr:
        if bit_vector.get_bit(num):
            duplicates.append(num)
        else:
            bit_vector.set_bit(num)
    return duplicates
# Example Usage:
arr = [1, 5, 7, 5, 9, 1, 10]
print(find_duplicates(arr, 100))  # Output: [5, 1]
# 11.7 Missing Integer
def find_missing_number(arr, max_value):
    bit_vector = [False] * (max_value + 1)
    for num in arr:
        bit_vector[num] = True
    for i in range(max_value + 1):
        if not bit_vector[i]:
            return i
    return None  # No missing number
# Example Usage:
arr = [0, 1, 2, 3, 5]
print(find_missing_number(arr, 5))  # Output: 4
# OK.
# 11.8 Rank from Stream
class RankNode:
    def __init__(self, data):
        self.data = data
        self.left_size = 0
        self.left = None
        self.right = None
class StreamRank:
    def __init__(self):
        self.root = None
    def track(self, x):
        if not self.root:
            self.root = RankNode(x)
        else:
            self.insert(self.root, x)
    def insert(self, node, x):
        if x <= node.data:
            node.left_size += 1
            if node.left:
                self.insert(node.left, x)
            else:
                node.left = RankNode(x)
        else:
            if node.right:
                self.insert(node.right, x)
            else:
                node.right = RankNode(x)
    def get_rank(self, x):
        return self.get_rank_helper(self.root, x)
    def get_rank_helper(self, node, x):
        if not node:
            return -1
        if x == node.data:
            return node.left_size
        elif x < node.data:
            return self.get_rank_helper(node.left, x)
        else:
            right_rank = self.get_rank_helper(node.right, x)
            return -1 if right_rank == -1 else node.left_size + 1 + right_rank
# OK Now it thinks Chapter 12 is this chapter so clearly the chapters are now misaligned or whatever and probably some of these tasks were wrong.
def find_max(arr):
    if not arr:
        return None  # Handle empty array case
    max_val = arr[0]
    for num in arr:
        if num > max_val:
            max_val = num
    return max_val
# Test Cases:
print(find_max([-10, -5, -1]))  # Output: -1
print(find_max([]))  # Output: None
# Lazar: OK think I would drill this in a round maybe.
# 12.2 Test a Random Number Generator
import random
def test_random_number_generator(rng_function, lower, upper, trials=10000):
    counts = {i: 0 for i in range(lower, upper + 1)}
    for _ in range(trials):
        num = rng_function()
        if lower <= num <= upper:
            counts[num] += 1
        else:
            print(f"Out-of-bounds value: {num}")
    print("Distribution:", counts)
# Example test:
random.seed(42)
test_random_number_generator(lambda: random.randint(1, 6), 1, 6)
# Lazar: Eh looks really bad to me think the verification or benchmarking of pseudo random number generation is itself a somewhat serious academic topic which more people would know more about. This looks very casual and weak to me. Maybe I should come back later and ask it to explain that to me.
# 12.3 Debugging Code that Crashes on Large Inputs
import sys
def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)
# Fix: Use iterative approach to avoid stack overflow
def factorial_iterative(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result
# Large Input Test:
sys.setrecursionlimit(1000)
# print(factorial(1000))  # Causes RecursionError
print(factorial_iterative(1000))  # Works fine
# 12.4 Testing a Function that Shuffles an Array
import random
def shuffle_array(arr):
    random.shuffle(arr)
# Test Shuffle
def test_shuffle():
    arr = [1, 2, 3, 4, 5]
    results = set()
    for _ in range(1000):
        shuffled = arr[:]
        shuffle_array(shuffled)
        results.add(tuple(shuffled))
    print(f"Unique permutations found: {len(results)}")
test_shuffle()
# Lazar: Seems like we could do better here for sure by referencing the canon.
# 12.5 Find a Broken Method in a Large System
import logging
logging.basicConfig(level=logging.DEBUG)
def buggy_function(n):
    logging.debug(f"Processing {n}")
    return 10 / n  # Bug: division by zero for n = 0
# Debugging:
try:
    print(buggy_function(0))  # Error case
except ZeroDivisionError:
    logging.error("Division by zero occurred!")
# 12.6 Edge Cases for a String Reversal Function
def reverse_string(s):
    return s[::-1]
# Test Cases:
assert reverse_string("hello") == "olleh"
assert reverse_string("") == ""
assert reverse_string("a") == "a"
assert reverse_string("abcd") == "dcba"
assert reverse_string("h@llo!") == "!oll@h"
assert reverse_string("你好") == "好你"
print("All test cases passed!")
# Lazar: Uh huh interesting like uh... could check out also very large word size inputs. For the Meta Hacker Cup I am intending to throw in maximum sized inputs next year of average and worst case expected runtime complexity.
# 12.7 Testing a Multiplication Function
def multiply(a, b):
    return a * b
# Test Cases:
assert multiply(3, 5) == 15
assert multiply(0, 100) == 0
assert multiply(-3, 5) == -15
assert multiply(10**6, 10**6) == 10**12
assert abs(multiply(0.1, 0.2) - 0.02) < 1e-9  # Handling floating-point precision
print("All test cases passed!")
# Lazar: I think I have had issues with precision here in Python before in fact int/int settings which had pretty mediocre precision for large int values.
# 13.1 Private vs. Public vs. Protected
class Example:
    def __init__(self):
        self.public_var = "Public"
        self._protected_var = "Protected"
        self.__private_var = "Private"
    def public_method(self):
        return "Public Method"
    def _protected_method(self):
        return "Protected Method"
    def __private_method(self):
        return "Private Method"
obj = Example()
print(obj.public_var)  # Accessible
print(obj._protected_var)  # Accessible but should be used internally
# print(obj.__private_var)  # AttributeError: Private variable
print(obj._Example__private_var)  # Accessing private via name mangling (not recommended)
# 13.2 Deep Copy vs. Shallow Copy
import copy
list1 = [[1, 2, 3], 4, 5]
shallow = copy.copy(list1)
deep = copy.deepcopy(list1)
shallow[0][0] = 99  # Modifies both list1 and shallow copy
deep[0][0] = 77  # Only modifies deep copy
print(list1)  # [[99, 2, 3], 4, 5]
print(shallow)  # [[99, 2, 3], 4, 5]
print(deep)  # [[77, 2, 3], 4, 5]
# 13.3 Volatile Keyword Equivalent in Python
import threading
class SharedResource:
    def __init__(self):
        self.value = 0
        self.lock = threading.Lock()
    def increment(self):
        with self.lock:  # Ensures thread safety
            self.value += 1
shared = SharedResource()
threads = [threading.Thread(target=shared.increment) for _ in range(1000)]
for t in threads: t.start()
for t in threads: t.join()
print(shared.value)  # Should be 1000
# 13.4 Synchronization in Python
import threading
class Counter:
    def __init__(self):
        self.value = 0
        self.lock = threading.Lock()
    def increment(self):
        with self.lock:
            self.value += 1
counter = Counter()
threads = [threading.Thread(target=counter.increment) for _ in range(1000)]
for t in threads: t.start()
for t in threads: t.join()
print(counter.value)  # Expected: 1000
# 13.5 Deadlocks and Avoidance
import threading
lock1 = threading.Lock()
lock2 = threading.Lock()
def task1():
    with lock1:
        print("Task 1 acquired Lock 1")
        with lock2:
            print("Task 1 acquired Lock 2")
def task2():
    with lock2:
        print("Task 2 acquired Lock 2")
        with lock1:
            print("Task 2 acquired Lock 1")
thread1 = threading.Thread(target=task1)
thread2 = threading.Thread(target=task2)
thread1.start()
thread2.start()
thread1.join()
thread2.join()
def task1():
    with lock1:
        print("Task 1 acquired Lock 1")
        if lock2.acquire(timeout=1):
            print("Task 1 acquired Lock 2")
            lock2.release()
def task2():
    with lock2:
        print("Task 2 acquired Lock 2")
        if lock1.acquire(timeout=1):
            print("Task 2 acquired Lock 1")
            lock1.release()
# 13.6 Thread Safety in Singleton Pattern
import threading
class Singleton:
    _instance = None
    _lock = threading.Lock()
    def __new__(cls):
        with cls._lock:
            if cls._instance is None:
                cls._instance = super(Singleton, cls).__new__(cls)
        return cls._instance
singleton1 = Singleton()
singleton2 = Singleton()
print(singleton1 is singleton2)  # True
# Lazar: Eh. Should read more on threading in a different book on Python ugh.
# 13.7 Garbage Collection in Python
import gc
class A:
    def __del__(self):
        print("Object deleted")
a = A()
del a  # Immediately deleted if no references
gc.collect()  # Forces garbage collection
# Lazar: Egh and also garbage collection and more generally operating systems.
# 13.8 Immutable vs. Mutable Objects
a = "hello"
b = a
a = "world"
print(b)  # "hello" (unchanged due to immutability)
lst1 = [1, 2, 3]
lst2 = lst1
lst1.append(4)
print(lst2)  # [1, 2, 3, 4] (same object)
# 14.1 Differences Between Primary Key and Foreign Key
CREATE TABLE Users (
    user_id INT PRIMARY KEY,
    name VARCHAR(100)
);
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    user_id INT,
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);
# Lazar: Eh. OK.
# 14.2 SQL Query for a Common Interview Task
SELECT MAX(salary) AS second_highest_salary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);
SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 1;
# 14.3 Normalization and Denormalization
CREATE TABLE Customers (
    customer_id INT PRIMARY KEY,
    name VARCHAR(100)
);
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)
);
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_name VARCHAR(100) -- Duplicating customer data
);
# 14.4 SQL Query for Joining Two Tables
SELECT s.student_name, c.course_name
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
JOIN Courses c ON e.course_id = c.course_id;
# 14.5 Indexing and When to Use It
CREATE INDEX idx_name ON Users(name);
# 14.6 NoSQL vs. SQL Databases
{
    "user_id": 1,
    "name": "Alice",
    "orders": [
        {"order_id": 101, "item": "Laptop"},
        {"order_id": 102, "item": "Phone"}
    ]
}
# 14.7 Designing a Scalable System
Client -> Load Balancer -> App Servers -> DB + Cache -> Storage (S3)
# 14.8 Handling High Read vs. High Write Load
import redis
cache = redis.Redis(host='localhost', port=6379, db=0)
def get_user(user_id):
    cached_user = cache.get(f"user:{user_id}")
    if cached_user:
        return cached_user  # Fast retrieval
    else:
        user = db_query(user_id)  # Expensive DB call
        cache.setex(f"user:{user_id}", 3600, user)  # Cache for 1 hour
        return user
# 14.9 ACID vs. BASE
#Summary of Database Concepts
#Concept						Explanation
#Primary Key vs. Foreign Key	PK uniquely identifies records, FK creates relationships
#Normalization					Reduces redundancy, improves consistency
#Joins in SQL					Combines tables for relational queries
#Indexing						Improves read performance, slows writes
#NoSQL vs. SQL					NoSQL scales horizontally, SQL enforces consistency
#Scalability					Uses caching, sharding, load balancing
#Read vs. Write Optimization	Caching, replication, batching inserts
#ACID vs. BASE					ACID ensures strong consistency, BASE favors availability
# 15.1 Difference Between Process and Thread
import os
import threading
import multiprocessing
def process_task():
    print(f"Process ID: {os.getpid()}")
def thread_task():
    print(f"Thread Name: {threading.current_thread().name}")
# Creating a new process
process = multiprocessing.Process(target=process_task)
process.start()
process.join()
# Creating a new thread
thread = threading.Thread(target=thread_task)
thread.start()
thread.join()
# 15.2 Race Condition and How to Prevent It
import threading
counter = 0
def increment():
    global counter
    for _ in range(100000):
        counter += 1  # Not thread-safe
threads = [threading.Thread(target=increment) for _ in range(2)]
for t in threads: t.start()
for t in threads: t.join()
print(counter)  # Expected: 200000, but output varies due to race condition
lock = threading.Lock()
counter = 0
def increment_safe():
    global counter
    for _ in range(100000):
        with lock:  # Ensures only one thread modifies counter at a time
            counter += 1
threads = [threading.Thread(target=increment_safe) for _ in range(2)]
for t in threads: t.start()
for t in threads: t.join()
print(counter)  # Always 200000
# 15.3 Deadlock and Avoidance
import threading
lock1 = threading.Lock()
lock2 = threading.Lock()
def task1():
    with lock1:
        print("Task 1 acquired Lock 1")
        with lock2:
            print("Task 1 acquired Lock 2")
def task2():
    with lock2:
        print("Task 2 acquired Lock 2")
        with lock1:
            print("Task 2 acquired Lock 1")  # Deadlock occurs here
thread1 = threading.Thread(target=task1)
thread2 = threading.Thread(target=task2)
thread1.start()
thread2.start()
thread1.join()
thread2.join()
def task1():
    with lock1:
        print("Task 1 acquired Lock 1")
        with lock2:
            print("Task 1 acquired Lock 2")
def task2():
    with lock1:  # Always acquire locks in the same order
        print("Task 2 acquired Lock 1")
        with lock2:
            print("Task 2 acquired Lock 2")
# 15.4 Thread-safe Singleton
import threading
class Singleton:
    _instance = None
    _lock = threading.Lock()
    def __new__(cls):
        with cls._lock:  # Ensures thread safety
            if cls._instance is None:
                cls._instance = super(Singleton, cls).__new__(cls)
        return cls._instance
singleton1 = Singleton()
singleton2 = Singleton()
print(singleton1 is singleton2)  # True
# 15.5 Producer-Consumer Problem
import threading
import queue
import time
buffer = queue.Queue(maxsize=5)
def producer():
    for i in range(10):
        buffer.put(i)  # Adds item to the queue
        print(f"Produced: {i}")
        time.sleep(0.5)
def consumer():
    for i in range(10):
        item = buffer.get()  # Removes item from the queue
        print(f"Consumed: {item}")
        buffer.task_done()
# Create threads
producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)
producer_thread.start()
consumer_thread.start()
producer_thread.join()
consumer_thread.join()
# 15.6 Read-Write Locks
import threading
class ReadWriteLock:
    def __init__(self):
        self.lock = threading.RLock()
        self.readers = 0
    def acquire_read(self):
        with self.lock:
            self.readers += 1
    def release_read(self):
        with self.lock:
            self.readers -= 1
    def acquire_write(self):
        self.lock.acquire()
    def release_write(self):
        self.lock.release()
rw_lock = ReadWriteLock()
def reader():
    rw_lock.acquire_read()
    print("Reading...")
    time.sleep(1)
    rw_lock.release_read()
def writer():
    rw_lock.acquire_write()
    print("Writing...")
    time.sleep(2)
    rw_lock.release_write()
read_threads = [threading.Thread(target=reader) for _ in range(3)]
write_thread = threading.Thread(target=writer)
for t in read_threads: t.start()
write_thread.start()
for t in read_threads: t.join()
write_thread.join()
# Summary of Key Concepts
# Concept				Solution in Python
# Processes vs Threads	Use multiprocessing.Process vs. threading.Thread
# Race Conditions		Use threading.Lock()
# Deadlocks				Use ordered locking or try_lock()
# Singleton Pattern		Use __new__ with threading.Lock()
# Producer-Consumer		Use queue.Queue()
# Read-Write Locks		Use threading.RLock()
# 16.1 Number Swapper
def swap(a, b):
    a = a + b
    b = a - b
    a = a - b
    return a, b
x, y = 5, 10
x, y = swap(x, y)
print(x, y)  # Output: 10, 5
def swap_xor(a, b):
    a ^= b
    b ^= a
    a ^= b
    return a, b
# 16.2 Word Frequencies
from collections import Counter
def word_frequencies(book):
    return Counter(book)
book = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
freq_map = word_frequencies(book)
print(freq_map["the"])  # Output: 2
# 16.3 Intersection
def is_intersecting(p1, p2, p3, p4):
    def ccw(a, b, c):
        return (c[1] - a[1]) * (b[0] - a[0]) > (b[1] - a[1]) * (c[0] - a[0])
    return ccw(p1, p3, p4) != ccw(p2, p3, p4) and ccw(p1, p2, p3) != ccw(p1, p2, p4)
print(is_intersecting((0, 0), (3, 3), (0, 3), (3, 0)))  # Output: True
# 16.4 Tic-Tac-Toe Winner
def check_winner(board):
    n = len(board)
    def check_line(line):
        return line[0] if all(x == line[0] and x != ' ' for x in line) else None
    for row in board:
        winner = check_line(row)
        if winner: return winner
    for col in range(n):
        winner = check_line([board[row][col] for row in range(n)])
        if winner: return winner
    winner = check_line([board[i][i] for i in range(n)]) or check_line([board[i][n-1-i] for i in range(n)])
    return winner
board = [['X', 'O', 'X'], ['O', 'X', 'O'], ['O', ' ', 'X']]
print(check_winner(board))  # Output: 'X'
# 16.5 Factorial Zeros
def count_trailing_zeros(n):
    count = 0
    while n >= 5:
        n //= 5
        count += n
    return count
print(count_trailing_zeros(100))  # Output: 24
# 16.6 Smallest Difference
def smallest_difference(A, B):
    A.sort()
    B.sort()
    i = j = 0
    min_diff = float('inf')
    while i < len(A) and j < len(B):
        min_diff = min(min_diff, abs(A[i] - B[j]))
        if A[i] < B[j]: i += 1
        else: j += 1
    return min_diff
print(smallest_difference([1, 3, 15, 11, 2], [23, 127, 235, 19, 8]))  # Output: 3
# Lazar: This is like very computationally interesting I wanted to ping it in on OEIS at least see if someone had sharper code here based around slightly modifying the n/4 bound or whatever https://oeis.org/A027868
# 16.7 Number Max
def max_no_if(a, b):
    return a * (a > b) + b * (b >= a)
print(max_no_if(5, 10))  # Output: 10
def max_bitwise(a, b):
    return a ^ ((a ^ b) & -(a < b))
print(max_bitwise(5, 10))  # Output: 10
# 16.8 English Int
def numberToWords(num):
    below_20 = "One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen".split()
    tens = "Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety".split()
    thousands = ["", "Thousand", "Million", "Billion"]
    def helper(n):
        if not n:
            return ""
        elif n < 20:
            return below_20[n - 1] + " "
        elif n < 100:
            return tens[n // 10 - 2] + " " + helper(n % 10)
        else:
            return below_20[n // 100 - 1] + " Hundred " + helper(n % 100)
    if num == 0:
        return "Zero"
    res, i = "", 0
    while num:
        if num % 1000:
            res = helper(num % 1000) + thousands[i] + " " + res
        num //= 1000
        i += 1
    return res.strip()
print(numberToWords(1234567))  # Output: 'One Million Two Hundred Thirty-Four Thousand Five Hundred Sixty-Seven'
#Summary of Problems and Solutions
#Problem					Solution					Time Complexity
#Swap Numbers				XOR or arithmetic			O(1)
#Word Frequencies			HashMap (Counter)			O(n)
#Line Intersection			Cross-product method		O(1)
#Tic-Tac-Toe Winner			Check rows, cols, diagonals	O(1)
#Factorial Zeros			Count 5s in n!				O(log n)
#Smallest Difference		Sort + Two Pointers			O(n log n)
#Find Max Without if		Bitwise OR multiplication	O(1)
#Integer to English Words	Recursive division by 1000	O(log n)
# 17.1 Add Without Plus
def add(a, b):
    while b != 0:
        carry = a & b
        a = a ^ b
        b = carry << 1
    return a
print(add(5, 7))  # Output: 12
# 17.2 Shuffle
import random
def shuffle_array(arr):
    for i in range(len(arr) - 1, 0, -1):
        j = random.randint(0, i)
        arr[i], arr[j] = arr[j], arr[i]
    return arr
print(shuffle_array([1, 2, 3, 4, 5]))  # Random order
# 17.3 Random Set
import random
class RandomSet:
    def __init__(self):
        self.data = []
        self.index_map = {}
    def insert(self, val):
        if val in self.index_map:
            return False
        self.index_map[val] = len(self.data)
        self.data.append(val)
        return True
    def remove(self, val):
        if val not in self.index_map:
            return False
        last_elem = self.data[-1]
        idx = self.index_map[val]
        self.data[idx] = last_elem
        self.index_map[last_elem] = idx
        self.data.pop()
        del self.index_map[val]
        return True
    def get_random(self):
        return random.choice(self.data)
rs = RandomSet()
rs.insert(5)
rs.insert(10)
print(rs.get_random())  # Random 5 or 10
# 17.4 Missing Number
def find_missing(arr):
    n = len(arr) + 1
    xor_all = 0
    for i in range(1, n + 1):
        xor_all ^= i
    for num in arr:
        xor_all ^= num
    return xor_all
print(find_missing([1, 2, 4, 5, 6]))  # Output: 3
# Lazar: Uh this is pretty bad uh... depending on the runtime of the ^= operation I guess like uh.
# 17.5 Letters and Numbers
def longest_equal_subarray(arr):
    diff_map = {0: -1}
    diff = 0
    max_len = 0
    start, end = 0, 0
    for i, char in enumerate(arr):
        diff += 1 if char.isalpha() else -1
        if diff in diff_map:
            if i - diff_map[diff] > max_len:
                max_len = i - diff_map[diff]
                start, end = diff_map[diff] + 1, i
        else:
            diff_map[diff] = i
    return arr[start:end + 1]
print(longest_equal_subarray(['a', '1', 'b', 'c', '2', '3'])) # Output: ['1', 'b', 'c', '2']
# Lazar: OK
# 17.6 Count of 2s
def count_2s(n):
    count = 0
    factor = 1
    while factor <= n:
        lower = n - (n // factor) * factor
        curr_digit = (n // factor) % 10
        higher = n // (factor * 10)
        if curr_digit < 2:
            count += higher * factor
        elif curr_digit == 2:
            count += higher * factor + lower + 1
        else:
            count += (higher + 1) * factor
        factor *= 10
    return count
print(count_2s(25)) # Output: 9
# Lazar: OKOKOK
# 17.7 Baby Names
from collections import defaultdict
class UnionFind:
    def __init__(self):
        self.parent = {}
    def find(self, name):
        if self.parent[name] != name:
            self.parent[name] = self.find(self.parent[name])
        return self.parent[name]
    def union(self, name1, name2):
        root1, root2 = self.find(name1), self.find(name2)
        if root1 != root2:
            self.parent[root2] = root1
def baby_names(names, synonyms):
    uf = UnionFind()
    freq_map = defaultdict(int)
    for name, count in names.items():
        uf.parent[name] = name
        freq_map[name] = count
    for name1, name2 in synonyms:
        if name1 not in uf.parent:
            uf.parent[name1] = name1
        if name2 not in uf.parent:
            uf.parent[name2] = name2
        uf.union(name1, name2)
    result = defaultdict(int)
    for name, count in freq_map.items():
        root = uf.find(name)
        result[root] += count
    return dict(result)
names = {"John": 10, "Jon": 5, "Chris": 3, "Kris": 4, "Christopher": 8}
synonyms = [("John", "Jon"), ("Chris", "Kris"), ("Chris", "Christopher")]
print(baby_names(names, synonyms))
# 17.8 Circus Tower
def longest_circus_tower(pairs):
    pairs.sort(key=lambda x: (x[0], x[1]))  # Sort by height, then weight
    dp = []
    for _, w in pairs:
        idx = binary_search(dp, w)
        if idx == len(dp):
            dp.append(w)
        else:
            dp[idx] = w
    return len(dp)
def binary_search(dp, target):
    low, high = 0, len(dp) - 1
    while low <= high:
        mid = (low + high) // 2
        if dp[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return low
pairs = [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110)]
print(longest_circus_tower(pairs))  # Output: 4
#Summary of Problems and Solutions
#Problem			Solution				Time Complexity
#Add Without Plus	Bitwise XOR and shift	O(1)
#Shuffle			Fisher-Yates Shuffle	O(n)
#Random Set			HashMap + Array			O(1)
#Missing Number		XOR method				O(n)
#Letters & Numbers	Prefix sum + HashMap	O(n)
#Count of 2s		Digit counting			O(log n)
#Baby Names			Union-Find				O(n log n)
#Circus Tower		LIS with Binary Search	O(n log n)
# 18.1: Scale an Application
#Problem: How would you scale a website like Twitter?
#Solution Approach:
#Scaling an application like Twitter requires:
#Load Balancing – Distribute traffic across multiple servers.
#Database Sharding – Partition user data across multiple DB instances.
#Caching (Redis, Memcached) – Store frequently accessed data in-memory.
#Asynchronous Processing (Queues, Kafka) – Handle background jobs.
#CDN (Content Delivery Network) – Distribute static content.
#Replication – Ensure redundancy for high availability.
# 18.2: Web Crawler
#Problem: Design a web crawler that efficiently crawls web pages.
#Solution Approach:
#URL Frontier (Queue) – Maintain URLs to crawl.
#Distributed Crawlers – Parallel execution across multiple servers.
#Politeness Policy – Respect robots.txt and rate limits.
#Storage (NoSQL/SQL) – Store crawled pages and metadata.
#Duplicate Detection (Bloom Filter, Hashing) – Avoid redundant crawls.
#Python Implementation (Basic)
import requests
from bs4 import BeautifulSoup
from collections import deque
def web_crawler(start_url, max_pages=10):
    visited = set()
    queue = deque([start_url])
    while queue and len(visited) < max_pages:
        url = queue.popleft()
        if url in visited:
            continue
        visited.add(url)
        try:
            response = requests.get(url, timeout=5)
            soup = BeautifulSoup(response.text, 'html.parser')
            for link in soup.find_all('a', href=True):
                if link['href'].startswith('http'):
                    queue.append(link['href'])
        except Exception as e:
            print(f"Failed to fetch {url}: {e}")
    return visited
print(web_crawler("https://example.com"))
# 18.3: URL Shortener (e.g., Bit.ly)
#Problem: Design a URL shortener like Bit.ly.
#Solution Approach:
#Hash Function (Base62 Encoding) – Convert long URLs into short keys.
#Database (Key-Value Store like Redis) – Store mapping between short and long URLs.
#Redirection Service – Lookup and redirect users.
#Analytics – Track click counts.
#Python Implementation
import hashlib
import random
import string
class URLShortener:
    def __init__(self):
        self.url_map = {}
        self.short_to_long = {}
    def shorten_url(self, long_url):
        short = self._generate_short(long_url)
        self.url_map[long_url] = short
        self.short_to_long[short] = long_url
        return short
    def _generate_short(self, long_url):
        return ''.join(random.choices(string.ascii_letters + string.digits, k=6))
    def expand_url(self, short_url):
        return self.short_to_long.get(short_url, None)
shortener = URLShortener()
short = shortener.shorten_url("https://example.com/long-url")
print("Short URL:", short)
print("Expanded:", shortener.expand_url(short))
# 18.4: Cache System (e.g., LRU Cache)
#Problem: Design a caching system with Least Recently Used (LRU) eviction.
#Solution Approach:
#Doubly Linked List + HashMap – O(1) lookup and eviction.
#Eviction Policy – Remove least recently used items.
#Python Implementation
from collections import OrderedDict
class LRUCache:
    def __init__(self, capacity):
        self.cache = OrderedDict()
        self.capacity = capacity
    def get(self, key):
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]
    def put(self, key, value):
        if key in self.cache:
            self.cache.move_to_end(key)
        elif len(self.cache) >= self.capacity:
            self.cache.popitem(last=False)
        self.cache[key] = value
cache = LRUCache(2)
cache.put(1, "One")
cache.put(2, "Two")
print(cache.get(1))  # Output: One
cache.put(3, "Three")  # Removes 2
print(cache.get(2))  # Output: -1 (Evicted)
#18.5: Rank System (Leaderboard)
#Problem: Implement a ranking system for scores.
#Solution Approach:
#Sorted Data Structure (Balanced BST, Redis Sorted Set) – Maintain order.
#Binary Search / Prefix Sum – Efficient rank lookup.
#Python Implementation
from sortedcontainers import SortedList
class Leaderboard:
    def __init__(self):
        self.scores = SortedList()
    def add_score(self, score):
        self.scores.add(score)
    def get_rank(self, score):
        return len(self.scores) - self.scores.bisect_right(score) + 1
leaderboard = Leaderboard()
leaderboard.add_score(100)
leaderboard.add_score(200)
leaderboard.add_score(150)
print(leaderboard.get_rank(150))  # Output: 2
#18.6: Massive File Storage System
#Problem: Design a distributed storage system.
#Solution Approach:
#Distributed File System (HDFS, S3, Google Cloud Storage).
#Chunking & Replication – Store large files in smaller chunks.
#Consistent Hashing – Distribute data efficiently across nodes.
#18.7: Chat System (WhatsApp, Messenger)
#Problem: Design a chat system.
#Solution Approach:
#Message Queue (Kafka, RabbitMQ) – Handle real-time messaging.
#Database (MongoDB, DynamoDB) – Store messages efficiently.
#WebSockets / Long Polling – Enable real-time updates.
#18.8: Search Engine (Google)
#Problem: Design a search engine.
#Solution Approach:
#Crawling (Web Scraping) – Collect web pages.
#Indexing (Inverted Index) – Store words → documents mapping.
#Ranking (PageRank, TF-IDF) – Rank search results.
#Caching & Sharding – Optimize query speed.
#Summary of System Design Problems
#Problem	Solution
#Scale Twitter	Load balancing, caching, database sharding
#Web Crawler	Queue, duplicate detection, polite crawling
#URL Shortener	Hashing (Base62), key-value store
#LRU Cache	OrderedDict / Doubly Linked List + HashMap
#Leaderboard	Balanced BST / Sorted Data Structure
#Massive File Storage	Distributed File System (HDFS, S3)
#Chat System	WebSockets, message queues
#Search Engine	Crawling, indexing, ranking
#Key Takeaways
#Scalability – Handle millions of users efficiently.
#Data Structures – Use optimal structures for lookup and storage.
#Distributed Systems – Design for reliability and performance.
#Trade-offs – Balance between speed, memory, and consistency.
#These are Python implementations and architectural solutions for Chapter 18: System Design. 🚀 Let me know if you need further clarifications!
