#include <stdio.h> 
#include <stdlib.h>
struct node //implementing concept of node using structures
{
	int info; 
	struct node *link;
} *head=NULL, *q;

 create_node(int val) //creating a new node
{
	q=(struct node *) malloc (sizeof (struct node));
	q->info=val;
	q->link=NULL;
}

struct node * create_LL(struct node *h) //joining a new node into a list
{
	struct node *temp;
	if (h==NULL) //if list is empty
		h=q; 
	else
	{
		temp=h; 
		while (temp->link!=NULL) 
		temp=temp->link; 
		temp->link=q;
	}
	return h;
}

void display(struct node *hd) // to display the list
{
	int i; 
	struct node *temp; 
	temp=hd; 
	while (temp!=NULL) //checking if end of list is reached
	{
		printf ("|%d|->",temp->info); 
		temp=temp->link; //moving to the next node
	}
	printf("NULL\n");
}

void insert() //to insert nodes in list
{
	int el,pos;
	printf("ENTER THE ELEMENT TO BE INSERTED: ");
	scanf ("%d",&el);
	printf("ENTER THE POSITION IN WHICH ELEMENT IS TO BE INSERTED: ");
	scanf ("%d",&pos);
	create_node(el);
	if(pos==1) //insert at begin
	{
		q->link =head;
		head=q;
		display(head);
	}
	else
	{
		int p=2;
		struct node *temp;
		temp=head; 
		while (1) //traversing through the list and finding the given position
		{			
			if(p==pos) //insert at any position except begin and end
			{
				q->link = temp->link;
				temp->link =q;
				display(head);
				return;
			}
			if(temp->link == NULL)
			break;
			temp= temp->link; //moving to the next node
			p++;
		}
		printf("INVALID POSITION.INSERTION NOT POSSIBLE");
	}	
}

void deletion() //to delete nodes in list
{
	int v;
	printf("ENTER THE ELEMENT TO BE DELETED: ");
	scanf ("%d",&v);
	if(head==NULL) //checking if list is empty
	{
		printf("LIST IS EMPTY. NOTHING TO DELETE.");
		return;
	}
	if(v == head->info) //delete from begin
	{
		q=head;
		head= head->link;
		free(q);
		display(head);
	}
	else
	{
		struct node *temp;
		temp=head; 
		while (temp->link!=NULL) //traversing through the list and finding the given value
		{
			if(temp->link->info == v) //delete from any position except begin
			{
				q= temp->link;
				temp->link = q->link;
				free(q);
				display(head);
				return;
			}
			temp= temp->link; //moving to the next node
		}
		printf("UNSUCCESSFUL SEARCH. DELETION NOT POSSIBLE");				
	}	
}

void reverse() //to reverse the links of the list
{
    struct node *prev=NULL;
    struct node *current = head;
    struct node *next=NULL; 
	while (current != NULL) //traversing through the list 
	{   
        next= current->link; // Store next						                 
        current->link = prev; // Reverse current node's pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    head = prev;
    printf("LIST AFTER REVERSING THE LINKS:");
    display(head);
}       

void odd_even() //to find the odd and even positioned numbers
{
	struct node *odd=NULL;
	struct node *even=NULL;
	struct node *temp;
	temp=head; 
	int p=1; //denotes the position of each node
	while (temp!=NULL) //traversing through the list
	{
		create_node (temp->info);
		if(p%2==0) //even number cheching
			even=create_LL(even);
		else
			odd=create_LL(odd);
		temp= temp->link; //moving to the next node
		p++;
	}
	printf("LIST CONTAINING ODD NUMBERED NODES:");
	display(odd);
	printf("LIST CONTAINING EVEN NUMBERED NODES:");
	display(even);
}

void main()
{
	int i,e,n;
	while(1)
	{
		printf("ENTER THE SIZE OF THE LIST: ");
		scanf("%d",&n);
    		printf("ENTER THE LIST:\n");
			for(i=1;i<=n;i++)
			{
				scanf("%d",&e);
				create_node(e);
				head=create_LL(head);	
			}
			int c;
			display(head);
			printf("******	OPERATIONS ON NON-CIRCULAR SINGLY LINKED LIST	******\n i) ENTER 1 FOR INSERTION AT ANY GIVEN POSITION.\n ii) ENTER 2 FOR DELETION AFTER SEARCHING A GIVEN VALUE. \n iii) ENTER 3 TO DISPLAY THE LIST.\n iv) ENTER 4 TO REVERSE THE LINKS OF THE LIST.\n v) ENTER 5 TO SPLIT THE LIST INTO TWO LISTS: ONE LIST CONTAINING ODD NUMBERED NODES AND ANOTHER LIST CONTAINING EVEN NUMBERED NODES OF THE ORIGINAL LINKED LIST.\n ENTER THE OPTION: ");
			scanf("%d",&c);
			switch(c)
			{
				case 1:
					insert();
					break;
				case 2:
					deletion();					
					break;
				case 3:
					display(head);
					break;
				case 4:
					reverse();
					break;
				case 5:
					odd_even();
					break;
				default:
					printf("WRONG CHOICE.");					
			}
			printf("\nDO YOU WANT TO CONTINUE? [1-->YES][0-->NO]:");
			int w;
			scanf("%d",&w);
			head=NULL;
			if(w==0)
				break;
		}
}
