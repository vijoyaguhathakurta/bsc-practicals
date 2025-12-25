#include <stdio.h>
int a[30][30]; int visited[30]={0}; int stack[30];
int i,j,e,n,x,y,u,v,top=0;
void input_graph()	//taking the graph from user
{ 	printf("Enter the no. of vertices: "); scanf("%d",&n);
	printf("Enter the no. of edges: "); scanf("%d",&e);
	for(i=1;i<=e;i++)
	{	printf("Edge %i : Starting vertex: ",i); scanf("%d",&x);
		printf("\tEnding vertex: "); scanf("%d",&y);
		a[x][y]=1; a[y][x]=1;	}	//forming the adjacency matrix 			
}
void display()
{	printf("Adjacency Matrix\n");
	for(i=1;i<=n;i++)
	{ 	for(j=1;j<=n;j++)
		 	printf("%d	",a[i][j]);
		printf("\n");	}	
}
void dfs()
{	printf("Enter the starting vertex for DFS: "); scanf("%d",&v);
    printf("Order of DFS Traversal: ");    
	stack[top]=v;	//push v
	while(top>=0)	//while stack is not empty
	{	u=stack[top--];	//pop
		if(visited[u]==0)	//if u is not visited
		{	printf("v%d --> ",u); visited[u]=1;	}
		for(i=1;i<=n;i++)	//for each adjacent vertex of u
		{	if(a[u][i]==1)
				if(visited[i]==0)	//push i
					stack[++top]=i;	 }			
	}
}
void main()
{	input_graph(); display(); dfs(); }	
