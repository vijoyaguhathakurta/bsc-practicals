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


void insert (int v)
{
	create_node(v);
	if (head->info > v) //insert at begin if the given value is smaller than the first value of the list
	{
		q->link =head;
		head=q;
	}
	else
	{
		struct node *temp;
		temp=head; 
		while (temp->link != NULL) //traversing through the list and finding the given position
		{			
			if ((temp->info <v  &&  temp->link->info >v) || temp->info ==v) //insert at any position except begin and end
			{
				q->link = temp->link;
				temp->link =q;
				return;
			}
			temp= temp->link; //moving to the next node			
		}
		temp->link =q; //insert at end i.e value given is the largest
	}
}

void merge()
{
	struct node *h1;
	h1=NULL;
	int i,e,n;
	printf("ENTER THE SIZE OF ANOTHER LIST: ");
		scanf("%d",&n);
	if (n==0)
	{
		printf("THE NEW GIVEN LIST IS EMPTY.");
		return;
	}
    		printf("ENTER THE SORTED LIST:\n");
			for(i=1;i<=n;i++)
			{
				scanf("%d",&e);
				create_node(e);
				h1=create_LL(h1);	
			}
	struct node *t;
	t=h1;
	while (t!=NULL) //checking if end of list is reached
	{
		insert(t->info); 
		t=t->link; //moving to the next node
	}
	printf("THE LIST AFTER MERGING: \n");
	display(head);	
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
		printf("******	OPERATIONS ON SORTED SINGLY LINKED LIST	******\n i) ENTER 1 FOR INSERT A GIVEN ELEMENT AT APPROPRIATE POSITION OF THE LIST (INSERT AFTER FINDING THE POSITION).\n ii) ENTER 2 TO MERGE TWO SORTED LINKED LISTS, INTO ONE SORTED LIST.\n ENTER THE OPTION: ");
		scanf("%d",&c);
		int v;
		switch(c)
		{
			case 1:
				printf("ENTER THE ELEMENT TO BE INSERTED: ");
				scanf ("%d",&v);
				insert(v);
				printf("THE LIST AFTER INSERTION: \n");
				display(head);
				break;
			case 2:
				merge();					
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
	
	
