# This code is written in Python3

"""
Uses of Boundary traversal

Boundary traversal is used to find the overall boundary of the tree by starting moving in anti clockwise
direction with respect to root node.

Algorithm Boundary Traversal:
   1. Traverse the left boundary add it to the current answer
   2. Traverse the leaf nodes and add it to the current answer
   3. At last travel the right boundary and add it to the answer
"""

import copy


class node:
    def __init__(self, value):
        self.val = value
        self.right = None
        self.left = None


def leaves_find(root, val):

    if root:
        leaves_find(root.left, val)

        if root.left is None and root.right is None:
            val.append(root.val)

        leaves_find(root.right, val)


def left_right_boundary(root, val, leftOrRight):

    if leftOrRight == "left":

        if root.left is None and root.right is None:
            return

        val.append(root.val)

        if root.left:
            left_right_boundary(root.left, val, leftOrRight)

        elif root.right:
            left_right_boundary(root.right, val, leftOrRight)

    else:

        if root.left is None and root.right is None:
            return

        if root.right:
            left_right_boundary(root.right, val, leftOrRight)

        elif root.left:
            left_right_boundary(root.left, val, leftOrRight)

        val.append(root.val)


def boundary(root):

    # left boundary + leaf nodes + right boundary

    if root.left == None and root.right == None:  # if we are having only the root
        print([root.val])
        return

    val = [root.val]

    if root.left:
        left_right_boundary(root.left, val, "left")

    leaves_find(root, val)

    if root.right:
        left_right_boundary(root.right, val, "right")

    print("Boundary traversal of the tree is: " + " ".join(str(i) for i in val))


class BinaryTree:
    def __init__(self, value):
        self.root = node(value)


# making the tree
tr = BinaryTree(1)

tr.root.left = node(2)

tr.root.right = node(3)

tr.root.left.right = node(5)
tr.root.left.left = node(4)
tr.root.left.left.right = node(11)

tr.root.left.right.left = node(7)
tr.root.left.right.right = node(8)

tr.root.right.left = node(6)
tr.root.right.left.left = node(9)
tr.root.right.left.right = node(10)

boundary(tr.root)
