# This code is written in Python3

"""
Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
Uses of Preorder
Preorder traversal is used to create a copy of the tree.
Preorder traversal is also used to get prefix expression on of an expression tree. 
"""
# To create a node

class node:
	"""docstring for node"""
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

# TO create class of Tree data Structure
class TreeDS:
	"""docstring for TreeDS"""
	def __init__(self):
		self.root = None
	
	# To check if the tree is empty or not
	def is_empty(self):
		return self.root is None

	# IMP : Code to do Preorder traversal of the tree.			
	def preorder_tree(self, temp):
		while temp:
			print(temp.data, end="-")
			self.preorder_tree(temp.left)
			self.preorder_tree(temp.right)
			return
			
	# To push node with a value into the tree based on the data inside it
	def push(self, data):
		newnode = node(data)
		if self.is_empty():
			self.root = newnode
			return
		temp = self.root
		while True:
			if newnode.data < temp.data:
				if temp.left is None:
					temp.left = newnode
					return
				temp = temp.left
			if newnode.data > temp.data:
				if temp.right is None:
					temp.right = newnode
					return
				temp = temp.right
			
# Code to declare the Tree			
T = TreeDS()
# Code to push following values into the tree.
T.push(5)
T.push(3)
T.push(4)
T.push(1)
T.push(7)
T.push(6)

# calling inorder tree and other print functions to make it readable
print("preorder traversal of Tree: ")
T.preorder_tree(T.root)
print("end")