#include <stdio.h>
int queue[50], front=-1, rear=-1, max=50; 
void enqueue(int v)
{	if (rear==max-1)
	{	printf("OVERFLOW");
		return;
	}
	if (front==-1 && rear==-1)
		front=0;
	rear++;
	queue[rear]=v;	
}
void dequeue()
{	if(front==-1 || front>rear)
	{	printf("UNDERFLOW");
		return;
	}
	printf("THE VALUE DELETED: %d \n",queue[front]);
	front++;
}
void display()
{	printf("THE CURRENT QUEUE IS:\n");
	int i;
	for(i=front;i<=rear;i++)
		printf("|%d|",queue[i]);
}
void main()
{	int n,i,c,s;
	printf("ENTER THE SIZE OF QUEUE: ");
	scanf("%d",&s);
	printf("ENTER THE ELEMENTS OF QUEUE:");
	for(i=0;i<s;i++)
		scanf("%d",&queue[i]);
	rear=s-1; front=0;
	printf("OPERATIONS ON QUEUE: \n ENTER 1 TO ENQUEUE.\n ENTER 2 TO DEQUEUE.\n ENTER 3 TO DISPLAY THE QUEUE.\n");
	while(1)
	{	printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				printf("ENTER THE VALUE TO BE INSERTED: ");
				scanf("%d",&n);
				enqueue(n);
 				display();
				break;
			case 2:
				dequeue();
				display();
				break;
			case 3:
				display();
				break;
			default:
				printf("WRONG CHOICE");
		}
		printf("\nDO YOU WANT TO CONTINUE? [1-->YES][0-->NO]: ");
		int w;
		scanf("%d",&w);
		if(w==0)
			break;
	}	
}

