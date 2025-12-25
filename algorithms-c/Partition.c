#include <stdio.h>
int a[30][30]={0};
int color[30]={0};
int queue[30];
int i,j,v,e,k=0,u,front=0,rear=0;
void input_graph()	//take the graph from user
{ 	printf("Enter the no. of vertices: ");
	scanf("%d",&v);
	printf("Enter the no. of edges: ");
	scanf("%d",&e);
	int x,y;
	for(i=1;i<=e;i++)
	{	printf("Edge %i : Starting vertex: ",i);
		scanf("%d",&x);
		printf("\tEnding vertex: ");
		scanf("%d",&y);
		a[x][y]=1;	//creating the adjacency matrix
		a[y][x]=1;	}		
}
void partition()
{	color[1]=1;	//assigning color 1 to vertex 1
	queue[rear]=1;
	while(front<=rear)	//colouring the graph with two colors using bfs
	{	u=queue[front++];
		for(i=1;i<=v;i++)
			if(a[u][i]==1)
				if(color[i]==0) //assigning the color not assigned to adjacent vertex
				{	if(color[u]==2)
						color[i]=1;
					else
						color[i]=2;		   
					queue[++rear]=i;	}
				else if(color[i]==color[u]) 	//chromatic number of graph is not 2 
				{	printf("Graph is not bipartite."); return;	 }			
	}
	printf("\nThe Two Set of vertices after Partition:\n");
	for(i=1;i<=2;i++)
	{	printf("Set %d: ",i);
		for(j=1;j<=v;j++)
			if(color[j]==i)
				printf("v%d, ",j);
		printf("\n");	}
}
void main()
{	input_graph(); 	partition();	}
