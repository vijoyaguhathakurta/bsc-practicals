#include <stdio.h>
int a[30][30]={[1 ... 29][1 ... 29]=999};
int vst[30]={0};
int path[30]={0};
int dist[30]={[1 ... 29]=999}; 
int i,j,v,e,s,d;
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
	}
	printf("Enter the source vertex: ");	//taking source and destication
	scanf("%d",&s);
	printf("Enter the destination vertex: ");
	scanf("%d",&d);
}
void dijkstra()
{	int k,u,w,min;
	dist[s]=0;
	for(i=1;i<=v;i++)	//finding u for which distance is minimum from s 
	{	min=999;
		for(k=1;k<=v;k++)
			if(min>dist[k] && vst[k]==0)
				{	min=dist[k]; u=k;   }
		vst[u]=1;		   	
		for(w=1;w<=v;w++)	
		{	if(a[u][w]!=999 && vst[w]==0)	//for each vertex adjacent to u
			{	if(dist[w]>(dist[u]+a[u][w]))
				{	dist[w]=dist[u]+a[u][w]; path[w]=u;	}
			}
		}
	}
	printf("The Shortest Path between Source and destination: ");
	printpath(d);	
}

void printpath(int x)	//printing the shortest path
{	if(x!=0)
		printpath(path[x]);
	if(x!=0)	
	printf("v%d->",x);	
}
 void main()
 {	input_graph();
 	dijkstra(); 	
 }
