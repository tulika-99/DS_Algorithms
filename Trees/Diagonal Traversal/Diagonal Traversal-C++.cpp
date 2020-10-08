// C++ program for diagonal traversal of Binary Tree 

#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

void diagonalPrintUtil(Node* root, int d, 
					map<int,vector<int> > &diagonalPrint) 
{ 
	if (!root) 
		return; 

	diagonalPrint[d].push_back(root->data); 

	diagonalPrintUtil(root->left, d + 1, diagonalPrint); 

	diagonalPrintUtil(root->right, d, diagonalPrint); 
} 

void diagonalPrint(Node* root) 
{ 
	map<int, vector<int> > diagonalPrint; 
	diagonalPrintUtil(root, 0, diagonalPrint); 

	cout << "Diagonal Traversal of binary tree : "<<endl; 
	for (auto it = diagonalPrint.begin(); it != diagonalPrint.end(); ++it) 
	{ 
		for (auto itr = it->second.begin(); itr != it->second.end(); ++itr) 
			cout << *itr << ' '; 

		cout << endl; 
	} 
} 

Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

int main() 
{ 
	Node* root = newNode(8); 
	root->left = newNode(3); 
	root->right = newNode(10); 
	root->left->left = newNode(1); 
	root->left->right = newNode(6); 
	root->right->right = newNode(14); 
	root->right->right->left = newNode(13); 
	root->left->right->left = newNode(4); 
	root->left->right->right = newNode(7); 

	
	diagonalPrint(root); 

	return 0; 
} 

