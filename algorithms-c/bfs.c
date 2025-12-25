#include <stdio.h>
int a[30][30]={0};
int i,j,e,n;
void input_graph() //taking the graph from user
{ 	printf("Enter the no. of vertices: ");
	scanf("%d",&n);
	printf("Enter the no. of edges: ");
	scanf("%d",&e);
	int x,y;
	for(i=1;i<=e;i++)
	{	printf("Edge %i : Starting vertex: ",i);
		scanf("%d",&x);
		printf("\tEnding vertex: ");
		scanf("%d",&y);
		a[x][y]=1; //forming the adjacency matrix
		a[y][x]=1;
	}		
}
void bfs()
{	int u,v;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d",&v);
    printf("\nOrder of BFS Traversal: ");
    int visited[30]={0}; int queue[30]; int front=0, rear=0;
	queue[rear]=v;	//enqueue v
	while(front<=rear)	//while queue is not empty
	{	u=queue[front++];	//dequeue 
		if(visited[u]==0)
		{	printf("v%d --> ",u);
			visited[u]=1;
		}
		for(i=1;i<=n;i++)	//for each adjacent vertex of u
		{	if(a[u][i]==1)
				if(visited[i]==0)
					queue[++rear]=i; 	//enqueue i			 
		}		
	}
}
void main()
{	input_graph();
	bfs();
}	

