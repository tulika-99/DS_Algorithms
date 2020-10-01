# This code is written in Python3
"""
 This is the implementation of the Inorder traversal in Tree.
Algorithm Inorder(tree)
    1. Traverse the left subtree, i.e., call Inorder(left-subtree)
    2. Visit the root.
    3. Traverse the right subtree, i.e., call Inorder(right-subtree)

Uses of Inorder
In case of binary search trees (BST), 
Inorder traversal gives nodes in non-decreasing order. 
To get nodes of BST in non-increasing order, 
a variation of Inorder traversal where Inorder traversal s reversed can be used.
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
	
	# IMP : Code to do inorder traversal of the tree.
	def inorder_tree(self, temp):
		while temp is not None:
			self.inorder_tree(temp.left)
			print(temp.data, end="-")
			self.inorder_tree(temp.right)
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
print("inorder_tree: ")
T.inorder_tree(T.root)
print("end")