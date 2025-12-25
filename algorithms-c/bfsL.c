#include <stdio.h>
int n;
typedef struct nodetype
{	int val;
	struct nodetype *link;
} node;
node *temp; 
node *list[100];
int i;
void input_graph()
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
			list[i]=q;		}	
	}	
}
void display() // to display the list
{	printf("The Adjacency List:\n");
	for(i=1;i<=n;i++)
	{	temp=list[i];
		printf("|%d|->",i);
		while (temp!=NULL) //checking if end of list is reached
		{		printf ("|%d|->",temp->val); 
				temp=temp->link; 	}
		printf("NULL\n");	}
}
void bfs()
{	printf("\nBFS Traversal: ");
	int u,v,w;
    printf("Enter the starting vetex for BFS: ");
    scanf("%d",&v);
    printf("Order of BFS Traversal: ");
	int visited[100]={0};
	int queue[30];
    int front=0, rear=0;
	queue[rear]=v;	//enqueue v
	while(front<=rear)	//while queue is not empty
	{	u=queue[front++];	//dequeue
		if(visited[u]==0)
		{	printf("v%d-->",u);
			visited[u]=1;	}
		temp=list[u];		//adjacent vertices of u
		while (temp!=NULL) //checking if end of list is reached
		{	w=temp->val;	//each adjacent vertex w
			if(visited[w]==0)
				queue[++rear]=w;	//enqueue i
			temp=temp->link;	}
	}
}
void main()
{	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	input_graph();
	display();
	bfs();
}
