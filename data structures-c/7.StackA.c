#include <stdio.h>
int stack[50];
int top=-1;

void display()
{
	printf("THE CURRENT STACK IS:\n")
	int i;
	for(i=0;i<=top;i++)
		printf("|%d|",stack[i]);
}

void push(int val)
{
	if(top==50)
	{
		printf("STACK OVERFLOW");
		return;
	}
	top++;
	stack[top]=val;
}

void pop()
{
	if(top==0)
	{
		printf("STACK UNDERFLOW");
		return;
	}
	printf("THE VALUE POPPED: %d \n",stack[top]);
	top--;
	display();
}


void main()
{
	int n,i,c,s;
	while(1)
	{
		printf("ENTER THE SIZE OF STACK: ");
		scanf("%d",&s);
		printf("ENTER THE ELEMENTS OF STACK:\n");
		for(i=0;i<s;i++)
			scanf("%d",&stack[i]);
		top=s-1;
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
	}	
}
