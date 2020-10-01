/*
Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
*/

class Node 
{ 
	int key; 
	Node left, right; 

	public Node(int item) 
	{ 
		key = item; 
		left = right = null; 
	} 
} 

class Solution
{
	void printInorder(Node node) 
	{ 
		if (node == null) 
			return; 

		printInorder(node.left);  //recursive call on left child
		System.out.print(node.key + " "); 
		printInorder(node.right);   //recursive call on right child
	} 

	public static void main(String[] args) 
	{ 
               //creating a binary tree
		Node root = new Node(1)
		root.left = new Node(2); 
		root.right = new Node(3); 
		root.left.left = new Node(4); 
		root.left.right = new Node(5); 
 
		System.out.println("\nInorder traversal of binary tree is "); 
		tree.printInorder(); 
 
	} 
} 
