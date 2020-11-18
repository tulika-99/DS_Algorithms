#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
  node(int key)
  {
    data = key;
    left = nullptr;
    right = nullptr;
  }
}

void preorder(root){
  stack <node*> S;
  S.push(root);
  node* temp = nullptr;
  while(!S.empty())
  {
    temp = S.top();
    if(temp->right!=nullptr) S.push(temp->right);
    if(temp->left!=nullptr) S.push(temp->left);
    S.pop();
    cout<<temp->data<<' ';
  }

}

int main()
{
  struct node *root = new node(1);
  root->left	 = new node(2);
  root->right	 = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  /*
    tree:
          1
        /  \
      2     3
    / \
    4  5
  */
preorder(root);

}
