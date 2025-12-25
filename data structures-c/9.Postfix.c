# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
char infix[100];
char stack[100];
char postfix[100];
int top=-1;

void push(char val)
{
	top++;
	stack[top]=val;
}

char pop()
{
	char p=stack[top];
	top--;
	return p;
}


int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
	case '%':
    case '*': 
    case '/': 
        return 2;  
    } 
    return -1; 
} 


int InfixToPostfix() 
{ 
	int i, j;
    for (i = 0, j = -1; infix[i]; ++i) 
    { 
        char c= infix[i];
 		if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) // if the character is operand 
            postfix[++j] = c ;
        else if (c == '(') // if the character is (, push it to the stack
            push(c);          
        else if (c == ')') // if character is ), pop from the stack and add to postfix until an ( is encountered in the stack.
        { 
            while (top!=-1 && stack[top] != '(') 
                 postfix[++j] = pop(); 
            if (stack[top] != '(') 
                return -1; // invalid expression              
            else
                pop(); 
        }
        else if (c=='%' || c=='*' || c=='+' || c=='-' || c=='/' ) // if the character is an opertor		
        { 
            while (top!=-1 && precedence(c) <= precedence(stack[top])) 
                 postfix[++j] = pop(); 
            push(c); 
        } 
        else
        	return -1; // invalid expression
    } 
    // Once all inital expression characters are traversed adding all left elements from stack to exp
    while (top!=-1) 
         postfix[++j] = pop(); 
     postfix[++j] = '\0'; 
    printf( "THE POSTFIX EXPRESSION: %s\n",postfix); 
    return 1;
} 

void evaluate()
{
	int stk[50],tp=-1,n1,n2,n3,num;
	char *e=postfix;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            stk[++tp]= num;
        }
        else if(*e=='%' || *e=='*' || *e=='+' || *e=='-' || *e=='/' )
        {
            n1 = stk[tp--];
            n2 = stk[tp--];
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            stk[++tp]=n3;
        }
        else
        {
        	printf("EXPRESSION WITH VARIABLES. EVALUATION NOT POSSIBLE.\n");
			return;	
		}
        e++;
    }
    printf("THE RESULT OF THE EXPRESSION (%s) = %d\n",postfix,stk[tp--]);
}

void main()
{
	printf("ENTER THE EXPRESSION:  ");
	scanf("%s",&*infix);
	int p= InfixToPostfix();
	if(p==-1)
	{
		printf("INVALID EXPRESSION.\n");
		exit(0);
	}
	evaluate();
}
