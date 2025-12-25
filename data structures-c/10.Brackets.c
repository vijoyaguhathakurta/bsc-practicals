# include <stdio.h>
# include <string.h>

char ex[100];
char stack[100];
int top=-1;

void push(char val)
{
	top++;
	stack[top]=val;
}

int pop()
{
	int p=stack[top];
	top--;
	return p;
}

void main()
{
	printf("ENTER THE EXPRESSION:  ");
	scanf("%s",ex);
	int i,temp, flag=1;
	char c;
	for(i=0;i<strlen(ex);i++)
	{
		c=ex[i];
		if (c=='{' || c=='(' || c=='[')
			push(c);
		else if (c=='}' || c==')' || c==']')
			if(top == -1)
				flag=0;
		else
		{		
			temp=pop();
			if(c==')' && (temp=='{' || temp=='['))
				flag=0;
 			else if(c=='}' && (temp=='(' || temp=='['))
				flag=0;
 			else if(c==']' && (temp=='(' || temp=='{'))
				flag=0;
		}	
	}
	if (top>=0)
		flag=0;
		if (flag==1)
		printf("VALID EXPRESSION.\n");
	else
		printf("INVALID EXPRESSION.\n");	
}
