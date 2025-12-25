#include <stdio.h>
int a[30][30]={[0 ... 29][0 ... 29]=999};
int vst[30]={0};
int i,j,v,e,min,p,k1,k2,x,y;
void input_graph()	//taking the graph from user
{ 	printf("Enter the no. of vertices: ");	scanf("%d",&v);
	printf("Enter the no. of edges: ");	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{	printf("Edge %i : Starting vertex: ",i);	scanf("%d",&x);
		printf("\tEnding vertex: ");	scanf("%d",&y);
		printf("\tWeight: ");	scanf("%d",&a[x][y]);	//creating the weight matrix
		a[y][x]=a[x][y];	}		
}
void select()
{	printf("\nThe Minimal Spanning Tree will contain the following edges:\n");
	vst[1]=1; //choosing the first vertex
	for(i=1;i<v;i++)	//loop runs till all v vertices are connected by (v-1) edges
	{	min=999;
		for(j=1;j<=v;j++)	//finding the minimum weighted edge
			if(vst[j]==1)
				for(p=1;p<=v;p++)
					if(vst[p]==0)
						if(min>a[j][p])	
				 			{	min=a[j][p];k1=j;k2=p; }//setting k1 and k2 with the vertices of minimum weighted edge
		printf("[v%d---v%d],",k1,k2);	//printing the edge
		vst[k2]=1;
	}
}
void main()
{	input_graph();
	select();
}	

