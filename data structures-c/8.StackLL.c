#include <stdio.h> 
#include <stdlib.h>

struct node //implementing concept of node using structures
{
	int info; 
	struct node *link;
} *top=NULL, *q;

void create_node(int v) //creating a new node
{
	q=(struct node *) malloc (sizeof (struct node));
	q->info=v;
	q->link=NULL;
}


void display() // to display the list
{
	printf("THE CURRENT STACK: ");
	int i; 
	struct node *temp; 
	temp=top; 
	while (temp!=NULL) //checking if end of list is reached
	{
		printf ("|%d|->",temp->info); 
		temp=temp->link; //moving to the next node
	}
	printf("NULL\n");
}

void push(int val) //to insert nodes in list
{
	create_node(val);
	if(top!=NULL)
		q->link =top;
	top=q;
}

void pop() //to delete nodes in list
{
	if(top==NULL) //checking if list is empty
	{
		printf("STACK UNDERFLOW");
		return;
	}
	q=top;
	top= top->link;
	printf("THE POPPED VALUE: %d\n",q->info);
	free(q);
	display();
}

void main()
{
	int n,i,c,s;
	while(1)
	{
		printf("ENTER THE SIZE OF STACK: ");
		scanf("%d",&s);
		if(s!=0)
		{
			printf("ENTER THE ELEMENTS OF STACK:\n");
			for(i=0;i<s;i++)
			{
				scanf("%d",&n);
				push(n);
			}
		}
		printf("OPERATIONS ON STACK: \n ENTER 1 TO PUSH ELEMENTS IN THE STACK.\n ENTER 2 TO POP ELEMENTS FROM THE STACK.\n ENTER 3 TO DISPLAY THE STACK.\nENTER YOUR CHOICE: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("ENTER THE VALUE TO BE PUSHED: ");
				scanf("%d",&n);
				push(n);
 				display();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				printf("WRONG CHOICE");
		}
		printf("\nDO YOU WANT TO CONTINUE? [1-->YES][0-->NO]:");
		int w;
		scanf("%d",&w);
		if(w==0)
			break;
		top=NULL;
	}	
}
