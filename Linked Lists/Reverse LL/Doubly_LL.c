#include<stdio.h>
#include<stdlib.h>

void initialize_List(dlist_t* list)
{
	list -> head = list -> tail = NULL;
	list -> no_Of_Nodes = 0;
}

node_t* create_Node(int data, node_t* llink, node_t* rlink)
{
	node_t* new = (node_t*)malloc(sizeof(node_t));
	new -> data = data;
	new -> llink = llink;
	new -> rlink = rlink;

	return new;
}

void insert_Beginning(dlist_t* list, int data)
{
	node_t* new = create_Node(data, NULL, list -> head);

	if(list -> head != NULL)
	{
		new -> rlink -> llink = new;
	}
	else
	{
		list -> tail = new;
	}
	list -> head = new;
	++list -> no_Of_Nodes;
}


void insert_Rear(dlist_t* list, int data)
{
	node_t* new = create_Node(data, list -> tail, NULL);

	if(list -> head != NULL)
	{
		list -> tail -> rlink = new;
		list -> tail = new;
	}
	else
	{
		list -> head = list -> tail = new;
	}

	++list -> no_Of_Nodes;
}

void display_List(dlist_t* list)
{
	node_t* temp = list -> head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> rlink;
	}
	printf("\n");
}


int main()
{
	dlist_t dl;
	initialize_List(&dl);
	int ch;
	int ele;
	while(1)
	{
		printf("1. Insert beginning\n");
		printf("2. Display list\n");
		printf("3. Insert rear\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be inserted\n");
					scanf("%d", &ele);
					insert_Beginning(&dl, ele);
					break;

			case 2: display_List(&dl);
				    break;

			case 3: printf("Enter the element to be inserted\n");
					scanf("%d", &ele);
					insert_Rear(&dl, ele);
					break;

			default: exit(0);
		}
	}
}
