#include <stdio.h>
int a[30][30]={0};
int used[30]={0};
int color[30]={0};
int i,j,v,e,k,m=0;
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
		a[y][x]=1;
	}		
}
void coloring()
{	color[1]=1; //assign the first color to the first vertex
	for(i=2;i<=v;i++)
	{	for(j=1;j<=v;j++)	//adjacent vertices cannot have the same color
			if(a[i][j]==1 && color[j]!=0)	
				used[color[j]]=1;
		for(k=1;k<=v;k++)	//to find the unused color
			if(!used[k])
				break;
		if(k>m)	//to find the number of partitions
			m=k;		
		color[i]=k;
		for(j=1;j<=v;j++)	//resetting the used[] array for next iteration
			used[j]=0;	  			 							 			
	}
	printf("The chromatic number of the graph= %d\nThe Independent Sets of the Graph are:\n ",m);
	for(j=1;j<=m;j++)	//fetching the vertices in each set
	{	printf("Color %i: ",j);
		for(i=1;i<=v;i++)
			if(color[i]==j)			 
				printf("v%d, ",i);
		printf("\n");
	}
}
void main()
{	input_graph();
	coloring();
}
