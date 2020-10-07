#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
}node;
typedef node *tree;

void inorder(node* root) {
	if (!root)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

struct node* newNode(int data) 
{ 
     struct node* node = (struct node*)malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 
int main() {
	struct node* root = newNode(15);
	root->left = newNode(10);
	root->right = newNode(20);
	root->left->right = newNode(12);
	inorder(root);
	printf("\n");
	return 0;
}
	
