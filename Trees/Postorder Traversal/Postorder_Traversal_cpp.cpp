#include<iostream> 
using namespace std;

/* Each node of a tree contains 1 data field and 2 links, 1 link to left child and 1 link to right child */
/* Typedef function is used to assign an alternative name to the existing datatype. Here, using typedef function we can write 'struct Node' as just 'Node' */
typedef struct Node
{ 
  int data; 
  Node* left; 
  Node* right; 
}Node; 


Node* new_node(int );
void morris_postorder_traversal(Node*);

int main() 
{ 
  Node* root = new_node(1); 
  root->left = new_node(2); 
  root->right = new_node(5); 
  root->left->left = new_node(3); 
  root->left->right = new_node(4);
  /* this input tree is shown in above diagram */ 

  cout<<"\nMorris Postorder Traversal of the graph: ";
  morris_postorder_traversal(root);
  
  return 0; 
} 

/* This function is used to create new node with the given data */
Node* new_node(int data) 
{ 
  Node* node = new Node; 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return node; 
}

/* p may point to any arbitrary position after giving whole valid output and to avoid that we have used this function */
int is_nodevalid(Node* p)
{
  if(p->data==1 || p->data==2 || p->data==3 || p->data==4 || p->data==5 || p->left->data==1)
  return 1;
  
  return 0;
}

void morris_postorder_traversal(Node *root)
{
  Node *curr, *predecessor, *t1, *t2, *t3;
  Node *temp = new Node;
  
  /* make input tree left subtree of temp */
  temp->left = root;

  curr=temp;

  while(is_nodevalid(curr))
  {        
      if(curr->left==NULL)
        {
           curr=curr->right;
      } 
    else
    {
      /* Finding postorder predecessor */
          predecessor=curr->left;
          while(predecessor->right!=NULL && predecessor->right != curr)
                {
               predecessor=predecessor->right;
            }

          if(predecessor->right == NULL)
                { 
                 predecessor->right=curr;    
                 curr=curr->left;
            }
      else 
      {                          

               /* if predeccessor's right child is curr */
        /* reverse the right references from predecessor to curr */
              t1=curr;
              t2=curr->left;              
              while(t2!=curr)
                {            
                  t3=t2->right;
                  t2->right=t1;
                  t1=t2;
                  t2=t3;
                }
              
              /* visit all the nodes from predecessor to curr again and reverse the right references from predecessor to curr */
              t1=curr;
              t2=predecessor;
              while(t2!=curr)
                {

                  cout<<t2->data<<" ";  
                  t3=t2->right;          
                  t2->right=t1;
                  t1=t2;
                  t2=t3;
                }
              
              /* remove reference between predecessor to curr */
              predecessor->right=NULL; 
              curr=curr->right;
          }
      }
  }    
}
