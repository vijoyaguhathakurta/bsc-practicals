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
	int i,b;
	char c;
	for(i=0;i<strlen(ex);i++)
	{
		c=ex[i];
		if (c=='{' || c=='(' || c=='[')
			push(c);
		else if (c=='}' || c==')' || c==']')
		{
			b=pop();
			if ((b!='{' && c=='}') || (b!='(' && c==')') || (b!='[' && c==']'))
				break;
		}	
	}
	if (top==-1)
		printf("\nVALID EXPRESSION.");
	else
		printf("\nINVALID EXPRESSION.");	
}
