#include <stdio.h>
typedef struct nodetype
{	int val;
	struct nodetype *link;
} node;
node *temp; 
node *list[100];
int i;
void input_graph(int n)
{	node *q;
	int v;
	printf("Enter the vertices adjacent to a vertex. Enter 0 when there is no more vertices.\n");
	for(i=1;i<=n;i++)
	{	list[i]=NULL;
		printf("Vertex %d -> ",i);
		while(1)
		{	scanf("%d",&v);
			if (v==0)
				break;
			q=(node *)malloc(sizeof(node));
			q->val=v;
			q->link=list[i];
			list[i]=q;
		}	
	}
	
}
void display(int n) // to display the list
{	for(i=1;i<=n;i++)
	{	temp=list[i];
		printf("|%d|->",i);
		while (temp!=NULL) //checking if end of list is reached
		{		printf ("|%d|->",temp->val); 
				temp=temp->link; //moving to the next node
		}
		printf("NULL\n");
	}
}

void dfs()
{	printf("\nDFS Traversal: ");
	int u,v,w;
    printf("Enter the starting index for DFS: ");
    scanf("%d",&v);
    printf("\nOrder of DFS Traversal: ");
	int visited[100]={0};
	int stack[100];
	int top=0;
	stack[top]=v;
	while(top>=0)
	{	u=stack[top--];
		if(visited[u]==0)
		{	printf("%d",u);
			visited[u]=1;
		}
		temp=list[u];
		while (temp!=NULL) //checking if end of list is reached
		{	w=temp->val;
			if(visited[w]==0)
				stack[++top]=w;
			temp=temp->link; //moving to the next node
		}
	}
}
void bfs()
{	printf("\nBFS Traversal: ");
	int u,v,w;
    printf("Enter the starting index for BFS: ");
    scanf("%d",&v);
    printf("\nOrder of BFS Traversal: ");
	int visited[100]={0};
	int queue[30];
    int front=0, rear=0;
	queue[rear]=v;
	while(front<=rear)
	{	u=queue[front++];
		if(visited[u]==0)
		{	printf("%d",u);
			visited[u]=1;
		}
		temp=list[u];
		while (temp!=NULL) //checking if end of list is reached
		{	w=temp->val;
			if(visited[w]==0)
				queue[++rear]=w;
			temp=temp->link; //moving to the next node
		}
	}
}

void main()
{
	int n;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	input_graph(n);
	display(n);
	bfs();
	dfs();
}
