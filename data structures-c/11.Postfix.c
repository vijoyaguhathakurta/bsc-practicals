# include <stdio.h>
# include <string.h>
# include <ctype.h>

char ex[100];
char stack[100];
//char brak[100];
char post[100];
int top=-1;
//int topb=-1;

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


int InfixToPostfix(char* expression) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        // Here we are checking is the character we scanned is operand or not
        // and this adding to to output
        char c= expression[i];
        if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) 
            expression[++j] = c ; 

        // Here, if we scan character (, we need push it to the stack. 
        else if (c == '(') 
            push(c); 

        // Here, if character is an ), pop from the stack and add to postfix until an ( is encountered in the stack. 
        else if (c == ')') 
        { 
            while (top!=-1 && stack[top] != '(') 
                expression[++j] = pop(); 
            if (stack[top] != '(') 
                return -1; // invalid expression              
            else
                pop(); 
        }
        else if (c=='%' || c=='*' || c=='+' || c=='-' || c=='/' ) // if an opertor		
        { 
            while (top!=-1 && precedence(c) <= precedence(stack[top])) 
                expression[++j] = pop(); 
            push(c); 
        } 
        else
        	return -1; // invalid expression
    } 

    // Once all inital expression characters are traversed adding all left elements from stack to exp
    while (top!=-1) 
        expression[++j] = pop(); 

    expression[++j] = '\0'; 
    printf( "THE POSTFIX EXPRESSION: %s", expression); 
    return 1;
} 

void main()
{
	
	printf("ENTER THE EXPRESSION:  ");
	scanf("%s",&*ex);
	int p= InfixToPostfix(ex);
	if(p==-1)
		printf("INVALID EXPRESSION");
}
