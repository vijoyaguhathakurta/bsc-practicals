#include <stdio.h> 
#include <stdlib.h>
struct node //implementing concept of node using structures
{	int data; 
	struct node *left;
	struct node *right;
};
struct node * create() //creating a tree 
{	int v;
	struct node *q;
	q=(struct node *) malloc (sizeof (struct node));
	printf("ENTER THE NODE VALUE [-1 for NULL]: ");
	scanf("%d",&v);
	if (v== -1)
		return 0;
	q->data =v;
	printf("THE LEFT NODE.");
	q->left =create();
	printf("THE RIGHT NODE.");
	q->right =create();
	return q;
}
int height(struct node *q) //height of tree
{	if (q==NULL)
		return 0;
	int max=height(q->left);
	int a=height(q->right);
	if (max<a)
		max=a;
	return max+1;	
}
void preorder(struct node *r)
{
	if (r==NULL)
	return;
	struct node * stack[10];
	int top=-1;
	stack[++top]=r;
	while (top!=-1)
	{
		struct node *q=stack[top--];
		if (q==NULL)
		continue;
		printf("%d",q->data);
		stack[++top]=q->right;
		stack[++top]=q->left;
	}
}

void inorder(struct node *root)
{
  /* set current to root of binary tree */
  struct node *q = root;
  struct node *stack[10]; 
  int top=-1; /* Initialize stack s */
  while (1)
  {
    /* Reach the left most tNode of the current tNode */
    if(q!=NULL)
    {
      /* place pointer to a tree node on the stack before traversing the node's left subtree */
      stack[++top]=q;                                              
      q = q->left; 
    }        
    /* backtrack from the empty subtree and visit the tNode at the top of the stack; however, if the stack is empty,you are done */
    else                                                             
    {
      if (top!=-1)
      {
        q= stack[top--];
        printf("%d ", q->data);
        /* we have visited the node and its left subtree. Now, it's right subtree's turn */
        q= q->right;
      }
      else
        break;
    }
  } /* end of while */ 
}    
 
void postorder(struct node *root)
{
    if (root == NULL)
        return;
 
    // Create two stacks
    struct node *s1[10];
    int top1=-1;
    struct node *s2[10];
 	int top2=-1;
    // push root to first stack
    s1[++top1]=root;
    struct node * q;
 
    // Run while first stack is not empty
    while (top1!=-1)
	 {
        // Pop an item from s1 and push it to s2
        q=s1[top1--];
        s2[++top2]=q;
         // Push left and right children of removed item to s1
        if (q->left)
            s1[++top1]=q->left;
        if (q->right)
            s1[++top1]=q->right;      
    }
 
    // Print all elements of second stack
    while (top2!=-1) 
	{
        printf("%d ",s2[top2--]->data);
    }
}

void levelorder(struct node* root)
{
    int rear=-1, front=0;
    struct node *queue[10];    
	struct node *q= root;
 
    while (q!=NULL) 
	{
        printf("%d ",q->data);
 
        /*Enqueue left child */
        if (q->left)
            queue[++rear]=q->left;
 
        /*Enqueue right child */
        if (q->right)
            queue[++rear]=q->right;
        /*Dequeue node and make it temp_node*/
        q=queue[front++];
    }
}
 
 void search(struct node * root, int v)
 {
 	if(root->data==v)
 		printf("Sucess");
 	else if(root==NULL)
 		printf("UnSucess");
 	else if(v< root->data)
 		search(root->left,v);
 	else //if (v>root->data)
 		search(root->right,v); 	
 }
void main()
{	struct node * root;
	printf("ENTER ROOT NODE.");
	root =create();
	int h= height(root);
	printf("HEIGHT= %d\n",h);
	levelorder(root);
	search(root,32);
}
