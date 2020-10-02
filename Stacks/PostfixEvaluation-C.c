#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Node Node;

struct List {
Node *head;
int number_of_Nodes;
};

struct Node {
int data;
Node *link;
};

/* initializes a linked List */
List* List_initialize(List* List);

void List_insert_front(List* List, int data);

/* Inserts data at specified position 0 <= position < length(List).
 * Returns position if insertion is successful, else -1
 */
int List_insert_at(List* List, int data, int position);

void List_delete_front(List *List);

/* Returns pointer to the Node at specified index, if 0 <= index < length(List).
 * Returns NULL otherwise
 */
Node* List_get(List *List, int index);

/* Returns the element that (*Node_ptr) contains */
const int Node_get_data(Node* Node_ptr);

/* Removes the last Node of the linked List */
void List_delete_rear(List* List);

void List_reverse(List* List);
void List_print(List* List);

/* deallocates resources held by the List */
void List_destroy(List* List);


typedef struct {
List *ptr_list;
} stack;

void stack_initialize(stack* ptr_stack);
void stack_push(stack* ptr_stack, int data);
void stack_pop(stack* ptr_stack);
int stack_is_empty(stack* ptr_stack);
const int stack_peek(stack* ptr_stack);
void stack_destroy(stack* ptr_stack);

/* The implementations for the above functions are provided below main() */

/* Returns 1 if the parenthesis sequence is well formed, else returns 0 */
int match_parenthesis(const char * string);

/* TODO:
 * Provide suitable implementation for the above function declaration, namely, match_parenthesis()
 */

int main() {
printf("--------------------------------------------------------\n");
char parenthesis_sequence[100];
int number_of_inputs;
printf("Enter the number of inputs:");
scanf("%d", &number_of_inputs);
printf("\n-------------------------------------------------------\n");
for(int counter = 0; counter < number_of_inputs; ++ counter) {
printf("Enter the parentheses sequence:");
scanf("%s", parenthesis_sequence);
int ans = match_parenthesis(parenthesis_sequence);
if(ans==0)
	printf("It is not a well-matched paranthesis sequence\n");
if(ans==1)
	printf("It is a well-matched paranthesis sequence\n");
printf("\n-------------------------------------------------------\n");
}
return 0;
}

List* List_initialize(List* list){
    list=(List*)malloc(sizeof(List));
    list->head=NULL;
    return list;
}

void List_insert_front(List* list, int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->link=list->head;
    list->head=newNode;
}
void List_delete_front(List *list){
    if(list->head==NULL)
        return;
    Node *temp=list->head;
    list->head=list->head->link;
    free(temp);
}
void List_destroy(List* List){
    while(List->head!=NULL){
        List_delete_front(List);
    }
}

void stack_initialize(stack* ptr_stack){
    ptr_stack->ptr_list=List_initialize(ptr_stack->ptr_list);
}

void stack_push(stack* ptr_stack, int data){
    List_insert_front(ptr_stack->ptr_list,data);
}

void stack_pop(stack* ptr_stack){
    if(ptr_stack->ptr_list->head!=NULL){
        List_delete_front(ptr_stack->ptr_list);
    }
}

int stack_is_empty(stack* ptr_stack){
    if(ptr_stack->ptr_list->head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

const int stack_peek(stack* ptr_stack){
    return (ptr_stack->ptr_list->head->data);
}

void stack_destroy(stack* ptr_stack){
    List *temp=ptr_stack->ptr_list;
    ptr_stack->ptr_list=NULL;
    List_destroy(temp);
    ptr_stack=NULL;
}

int match_parenthesis(const char * string){
    stack new_stack;
    stack_initialize(&new_stack);
    for(int i=0;i<100;i++){
        switch(*(string+i)){
            case'{':
            case'(':
            case'[':{stack_push(&new_stack,*(string+i));
                break;
            }
            case'}':{
                if(stack_is_empty(&new_stack)||stack_peek(&new_stack)!='{'){
                    stack_destroy(&new_stack);
                    return 0;
                }
                stack_pop(&new_stack);
                break;
                }
            case']':{
                if(stack_is_empty(&new_stack)||stack_peek(&new_stack)!='['){
                    stack_destroy(&new_stack);
                    return 0;
                }
                stack_pop(&new_stack);
                break;
                }
            case')':{
                if(stack_is_empty(&new_stack)||stack_peek(&new_stack)!='('){
                    stack_destroy(&new_stack);
                    return 0;
                }
                stack_pop(&new_stack);
                break;
                }
            default:{
                if(stack_is_empty(&new_stack)){
                    stack_destroy(&new_stack);
                    return 1;
                }
                else return 0;
            }
        }
    }
}
