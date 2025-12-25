#include <stdio.h> 
#include <stdlib.h>
struct node //implementing concept of node using structures
{
	int info; 
	struct node *prev;
	struct node *next;
} *head=NULL, *q ;

void display() // to display the list
{
	struct node *temp; 
	temp=head; 
	if (head==NULL) 
	printf ("LIST IS EMPTY.") ; 
	else 
	temp=head; 
	while (1) //traversing through the list
	{
		printf ("|%d|->",temp->info); 
		if(temp->next == head)
			break;
		temp=temp->next; //moving to the next node
	}
	printf ("|head=%d|\n",head->info); 
}

void create_node(int val) //creating a new node
{
	q=(struct node *) malloc (sizeof (struct node));
	q->info=val;
	q->prev=q;
	q->next=q;
}

void create_LL() //creating a linked list
{
	int i,e,n;
	printf("ENTER THE SIZE OF THE LIST: ");
	scanf("%d",&n);
	printf("ENTER THE LIST:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&e);
		create_node(e);
		struct node *temp;
		if (head==NULL) // Checking if list is empty
		head=q; 
		else 
		{
			temp=head;
			while (temp->next != head) 
			temp=temp->next;
			q->prev =temp;
			q->next =head;
			temp->next =q;
			head->prev =q;
		}
	}
		printf("THE CREATED LIST IS:\n");
		display();	
}


void insert()
{
	int el,v;
	printf("ENTER THE ELEMENT TO BE INSERTED: ");
	scanf ("%d",&el);
	printf("ENTER THE NODE'S VALUE AFTER WHICH ELEMENT IS TO BE INSERTED: ");
	scanf ("%d",&v);
	create_node(el); //creating the node to inserted
	struct node *temp;
	temp=head; 
	while (1) //traversing through the list and finding the given value
	{	
		if(head==NULL) // Checking if list is empty
		{
			printf("LIST IS EMPTY");
			return;
		}		
		if (temp->info == v) //insert at any position except begin and end
		{
			q->prev = temp;
			q->next = temp->next;
			temp->next =q;
			printf("THE LIST AFTER INSERTION:\n");
			display();
			return;
		}
		if(temp->next == head)
			break;
		temp= temp->next; //moving to the next node
	}
	printf("VALUE NOT FOUND IN THE LIST.INSERTION NOT POSSIBLE");
}	


void deletion() //to delete nodes in list
{
	int pos;
	printf("ENTER THE POSITION OF THE ELEMENT TO BE DELETED: ");
	scanf ("%d",&pos);
	if(head==NULL) //checking if list is empty
	{
		printf("LIST IS EMPTY. NOTHING TO DELETE.");
		return;
	}
	if(pos==1) //delete from begin
	{
		if (head->next == head && head->prev == head)
		{
			head=NULL;
			free(head);
			printf("LIST IS EMPTY AFTER DELETION.");
		}
		else
		{
			q=head;
			head= head->next;
			head->prev = q->prev;
			q->prev->next = head;
			free(q);
			printf("THE LIST AFTER DELETION:\n");
			display();
			return;
		}
	}
	q=head->next;
	int p=2;
	while (1) //traversing through the list and finding the given position
	{
		if(p==pos)
		{
			q->prev->next = q->next;
			if(q->next != head)
				q->next->prev = q->prev;
			free(q); //deallocating the deleted node
			printf("THE LIST AFTER DELETION:\n");
			display(head);
			return;
		}
		if(q->next == head)
			break;		
		q= q->next; //moving to the next node
		p++;
	}
	printf("THE POSITION DOES NOT EXIST. DELETION NOT POSSIBLE.");
}	
	
	
void print_rev()
{
	if(head==NULL) //checking if list is empty
	{
		printf("THE LIST IS EMPTY:\n");
		return;
	}
	q= head->prev; //last node
	printf("THE REVERSED LIST:\n");
	while(1) //traversing through the list in reverse order
	{
		printf("|%d|->",q->info);
		if(q==head)
			break;
		q= q->prev; //moving to previous node
	}
}

void main()
{	
	create_LL();
	while(1)
	{
		int c;
		printf("******	OPERATIONS ON CIRCULAR DOUBLY LINKED LIST 	******\n i) ENTER 1 TO CREATE LIST BY APPENDING THE NODES AT THE END OF THE LINKED LIST.\n ii) ENTER 2 TO INSERT A NEW NODE AFTER A GIVEN NODE. (INSERTION AFTER SEARCHING). \n iii) ENTER 3 TO DELETE A NODE FROM A GIVEN POSITION.\n iv) ENTER 4 TO PRINT THE LIST ELEMENTS IN REVERSE ORDER, WITHOUT CHANGING THE LINKS.\n ENTER THE OPTION: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				create_LL();
				break;
			case 2:
				insert();					
				break;
			case 3:
				deletion();
				break;
			case 4:
				print_rev();
				break;
			default:
				printf("WRONG CHOICE.");					
		}
		printf("\nDO YOU WANT TO CONTINUE SEARCHING FOR MORE ELEMENTS? [1-->YES][0-->NO]:");
		int w;
		scanf("%d",&w);
		head=NULL;
		if(w==0)
			break;
	
	}
}
