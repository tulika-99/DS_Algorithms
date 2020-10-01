
#include <iostream>
using namespace std;


class LinkedList {
public:
    struct node{

        int data;
        node *next;
    };
    typedef struct node* nodePtr;
    nodePtr head;
    nodePtr temp;
public:
    LinkedList(){
        head = NULL;
        temp = NULL;
    }

    void insert(int value){
        nodePtr toadd = new node;
        toadd->next = NULL;
        toadd->data = value;

        if(head != NULL){
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = toadd;
        }
        else{
            head = toadd;
        }
    }
    
    
    void insertatstart(int value){
        nodePtr addatstart = new node;
        addatstart->data = value;
        if(head != NULL){
            temp = head;
            addatstart->next = temp;
            head = addatstart;

        }

    }
    
    void del(){
        temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }temp->next = NULL;
    }
    
    void delatstart(){
        temp = head;
        temp = NULL;
        head = head->next;

    }

void display(){
        temp = head;
        while(temp != NULL){

            cout<<temp->data<<endl;
            temp = temp->next;

        }


    }

};
int main(){

    LinkedList l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.display();
   l.delatstart();
   l.display();



    return 0;
}


