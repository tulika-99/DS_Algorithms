#include <iostream>
#include<stdlib.h>
using namespace std;
//Defining the Structure for Node in LinkedList
typedef struct Node{
 int data;
 Node *next;
}Node;

//getNode Function to allocate the memory for new Node
Node* getNode(){
  Node *newNode;
  newNode= new Node;
  cout<< "Enter the data for the new node"<<endl;
  cin>>newNode->data;
  newNode-> next=NULL;
  return newNode;
}

//getNewNode FUnction to allocate the menory for the new Node to be inserted in the LinkedList
Node* getNewNode(){
  Node *newNode;
  newNode= new Node;
  cout<< "Enter the data for the node which we want to insert"<<endl;
  cin>>newNode->data;
  newNode-> next=NULL;
  return newNode;
}

//create Function to create the LinkedList
Node* create(Node* first){
char ch='y';
Node *temp, *newNode;
while(ch=='y'){
      newNode= getNode();
      if (first==NULL){
        first=newNode; //first and temp will point to newNode
        temp=newNode;
      }
      else{
        temp->next= newNode;  //join the temp node to the newNode
        temp=newNode; //temp point to newNode
      }
      cout<<"Do you want to add more nodes(y/n)?"<<endl;
      cin>>ch;
      }
  return first;
}

//Display Function to display the Created LinkedList
void display(Node* first){
 Node *temp;
 temp= first;
 if(temp==NULL){    //this means our LinkedList is empty.
    cout<<"List is empty"<<endl;

 }
  cout<<"Linked list is:"<<endl;
 while(temp!=NULL){

    cout<<temp->data<<"  "; //printing the data of each node in linkedlist
    temp=temp->next;

 }
 cout<<endl;
}

//addAt Function to add the new Node at the specified Position in LinkedList
Node* addAt(Node *first){
    int pos,count;
    Node *temp, *temp1,*newNode;
    newNode=getNewNode();
    temp=first;    //Initially temp point to first
    cout<<"Enter the position after which you wish to enter the Node"<<endl;
    cin>>pos;
    count=1; //initializing count with 1 for comparing it later with position
    while(temp!=NULL){//till the end of LinkedList
        if(pos==0){        //special case handled when we want to insert at the first location
            newNode->next=first;
            first=newNode;
            temp=newNode;
            break;
        }
        else if(pos==count){ //inserting after the given Position
            temp1=temp->next;
            temp->next=newNode; //inserting newNode between temp and temp1
            newNode->next=temp1;
            break;
        }else{
            temp=temp->next; //else move to next node
            count++; //incrementing the count variable for further reference

        }
    }
    return first;
}

//DeleteAt Function to delete the  Node at the specified Position in LinkedList
Node* DeleteAt(Node *first){
    int pos,count;
    Node *temp, *temp1;
    temp=first;
    cout<<"Enter the position of Node which you wish to delete"<<endl;
    cin>>pos;
    count=1;  //initializing count with 1 for comparing it later with position
    while(temp!=NULL){
    if(pos==1){    //special case handled when we want to delete at the first location
        temp=first;
        first=first->next;
        temp->next=NULL;
        delete(temp); //dealocating memory for the temp(first) node and thus deleting it.
        break;
    }
    else if(count==pos-1){
        temp1=temp->next;     //'temp1' is the node to be deleted and 'temp' is the previous node of temp1
        temp->next=temp->next->next;
        delete(temp1); //dealocating memory for the temp1 node and thus deleting it.
        break;

    }
    else{
        temp=temp->next; //else move to next node
            count++; //incrementing the count variable for further reference
    }
  }
  return first;
}
int main()
{
    Node *first=NULL;
    first=create(first); //creating a linked list
    display(first);
    //Note:- Enter the positon of the node by considering the size of the LinkedList
    //orelse nothing will happen !!! it will just display the previous LinkedList normally!!
    first=addAt(first);  //adding at position
    display(first);
    first=DeleteAt(first);
    display(first);
    return 0;
}

