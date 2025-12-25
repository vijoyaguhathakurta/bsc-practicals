#include <stdio.h>
int a[30][30]={[0 ... 29][0 ... 29]=999};
int path[30][30]={[0 ... 29][0 ... 29]=999};
int z[30][30]={0};
int i,j,k,v,e;
void input_graph()	//taking graph from user
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
		printf("\tWeight: ");
		scanf("%d",&a[x][y]);
		path[x][y]=a[x][y];	// assigning the path matrix
		z[x][y]=y;	//assigning the z matrix
	}
}
void floyd()	//decides the shortest path
{	for(k=1;k<=v;k++)
		for(i=1;i<=v;i++)
			for(j=1;j<=v;j++)
				if(path[i][j]>path[i][k]+path[k][j])
				{	path[i][j]=path[i][k]+path[k][j];
					z[i][j]=z[i][k];	 }	
}
void print()	//printing the shortest path betwwen the vertex pairs
{	printf("The Shortest Path between the following pairs:\n");
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
		{	printf("[v%d,v%d] : Cost= ",i,j);
			if(i==j)
				printf("0: Same vertex.");	
			else if(path[i][j]==999)
				printf("0: No path exists.");
			else
			{	int l=i;
				printf("%d: v%d ->",path[i][j],l);
				while(z[l][j]!=j)
				{	printf("v%d ->",z[l][j]);
					l=z[l][j]; 	}
				printf("v%d",j);
			}
			printf("\n");
		}
}
void main()
{	input_graph();
	floyd();
	print();
}

