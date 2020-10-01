#include <iostream> 
using namespace std; 
  

struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
void Inorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    Inorder(node->left); 
  
    cout << node->data << " "; 
  
    Inorder(node->right); 
} 
  