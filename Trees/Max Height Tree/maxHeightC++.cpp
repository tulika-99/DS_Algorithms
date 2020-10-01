#include <bits/stdc++.h> 
using namespace std; 
  

/* class to store all the data about Node of a tree */
class TreeNode  
{  
    public: 
    int data;
    TreeNode* left;  
    TreeNode* right;  
};  
  
/* Recursive function to get maximum depth/Height of a tree based 
on the maximum of left or right subtree of every node. */
int maxHeight(TreeNode* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree */
        int leftH = maxHeight(node->left);  
        int rightH = maxHeight(node->right);  
      
        /* return the larger among left and right */
        return (max(leftH, rightH) + 1);
    }  
}  
  
/* Function to create New Node */
TreeNode* newNode(int data)  
{  
    TreeNode* Node = new TreeNode(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  
      
//Main function   
int main()  
{  
    TreeNode *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5); 
    root->left->left->right = newNode(6); 
      
    cout << "Height of the Tree is " << maxHeight(root) << endl;  
    return 0;  
}