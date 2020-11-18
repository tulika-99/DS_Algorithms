
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

void postorder(node* root)
{
	// create an empty stack and push root node
	stack<node*> stk;
	stk.push(root);

	// create another stack to store post-order traversal
	stack<int> out;

	// loop till stack is empty
	while (!stk.empty())
	{
		node *curr = stk.top();
		stk.pop();
    out.push(curr->data);
    if (curr->left)
			stk.push(curr->left);

		if (curr->right)
			stk.push(curr->right);
	}
  while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
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
postorder(root);

}
