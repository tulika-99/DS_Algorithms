# This code is written in Python3

"""

Uses of Postorder
Postorder traversal is used to delete the tree. 
Postorder traversal is also useful to get the postfix expression of an expression tree.

Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.
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
		
	# IMP : Code to do Postorder traversal of the tree.			
	def postorder_tree(self, temp):
		while temp:
			self.postorder_tree(temp.left)
			self.postorder_tree(temp.right)
			print(temp.data, end="-")			
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
print("postorder traversal of Tree: ")
T.postorder_tree(T.root)
print("end")