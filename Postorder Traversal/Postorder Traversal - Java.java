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
    void printPostorder(Node node) 
	{ 
		if (node == null) 
			return; 

        printPostorder(node.left);  //recursive call on left child
        printPostorder(node.right);   //recursive call on right child
		System.out.print(node.key + " "); 
	} 

	public static void main(String[] args) 
	{ 
               //creating a binary tree
		Node root = new Node(1)
		root.left = new Node(2); 
		root.right = new Node(3); 
		root.left.left = new Node(4); 
		root.left.right = new Node(5); 
 
        System.out.println("\nPostorder traversal of binary tree is "); 
        tree.printPostorder(); 
 
	} 
}
