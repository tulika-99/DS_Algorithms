
#include <bits/stdc++.h> 
using namespace std; 
  

class node  
{  
    public: 
    int data;  
    node* left, *right;  
};  
  
/* Function protoypes */
void printGivenLevel(node* root, int level);  
int height(node* node);  
node* newNode(int data);  
  
/* Function to print level  
order traversal a tree*/
void printLevelOrder(node* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}  
  
/* Print nodes at a given level */
void printGivenLevel(node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  
  

int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
      
  
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}  
  
/* Helper function that allocates  
a new node with the given data and 
NULL left and right pointers. */
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return(Node);  
}  
  
/* Driver code*/
int main()  
{  
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
  
    cout << "Level Order traversal of binary tree is \n";  
    printLevelOrder(root);  
  
    return 0;  
}  
