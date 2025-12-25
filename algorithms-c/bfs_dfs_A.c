#include <stdio.h>
int a[30][30];
int i,j,n;
	
void degree()
{	int d[30];
	for(i=1;i<=n;i++)
	{	d[i]=0;
		for(j=0;j<n;j++)
			if(a[i][j]==1)
				d[i]++;			
	}	
	for(i=1;i<=n;i++)
		printf("\nDegree of vertex %d= %d",i,d[i]);			
}

void input_graph()
{ 	printf("Enter the no. of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{	printf("Enter 1 if vertex %d is adjacent to vertex %d otherwise enter 0: ",i,j);
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0 && a[i][j]!=1)
			{ 	printf("Invalid Input");
				exit(0);  	
			}
		}		
}

void display()
{	printf("\nAdjacency Matrix\n");
	for(i=1;i<=n;i++)
	{ 	for(j=1;j<=n;j++)
		 	printf("%d	",a[i][j]);
		printf("\n"); 	
	}	
}

void dfs()
{	printf("\nDFS Traversal: ");
	int u,v;
    printf("Enter the starting index for DFS: ");
    scanf("%d",&v);
    printf("\nOrder of DFS Traversal: ");
	int visited[30]={0};
	int stack[30];
    int top=0;
	stack[top]=v;
	while(top>=0)
	{	u=stack[top--];
		if(visited[u]==0)
		{	printf("%d",u);
			visited[u]=1;
		}
		for(i=1;i<=n;i++)
		{	if(a[u][i]==1)
				if(visited[i]==0)
					stack[++top]=i; 				 
		}		
	}
}

void bfs()
{	 printf("\nBFS Traversal: ");
	int u,v;
    printf("Enter the starting index for BFS: ");
    scanf("%d",&v);
    printf("\nOrder of BFS Traversal: ");
    int visited[30]={0};
    int queue[30];
    int front=0, rear=0;
	queue[rear]=v;
	while(front<=rear)
	{	u=queue[front++];
		if(visited[u]==0)
		{	printf("%d",u);
			visited[u]=1;
		}
		for(i=1;i<=n;i++)
		{	if(a[u][i]==1)
				if(visited[i]==0)
					queue[++rear]=i; 				 
		}		
	}
}


void main()
{
	input_graph();
	display();
	dfs();
	bfs();
}	

