#include <stdio.h>
typedef struct nodetype
{	int start;
	int end;
	int wt;
	struct nodetype *link;
} node;
node *temp,*head=NULL; 
int i,d,n;
int c[30]={0};
void input_sort()	//taking the edges from user and inserting it in priority queue
{	node *q;
	printf("Enter the start vertex, end vertex and weight of each edge. Enter 0 when no edge is left.\n");
	for(i=1;;i++)
	{	printf("Edge %d: ",i);
		q=(node *)malloc(sizeof(node));
		printf("Start Vertex : ");
		scanf("%d",&d);
		if(d==0)
			break;
		q->start=d;
		printf("\tEnd Vertex : ");
		scanf("%d",&q->end);
		printf("\tWeight : ");
		scanf("%d",&q->wt);
		if(head==NULL || q->wt<head->wt)
		{  q->link=head;
		   head=q;		}
		else
		{	temp=head;
			while(temp->link!=NULL && temp->link->wt<=q->wt)
				temp=temp->link;
 			q->link=temp->link;
			temp->link=q;		}
	}	
}
void cycle()	//check if the selected edge forms a cycle with the existing subgraph or not 
{	int s=head->start;
	int e=head->end;
	if(c[s]==0 || c[e]==0)
	{	c[s]=1;
		c[e]=1;
		printf("[v%d---v%d],",s,e);	}
	head=head->link;	
}	
void main()
{ 	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	input_sort();
	printf("\nTHE MINIMAL SPANNING TREE WILL HAVE THE FOLLOWING EDGES:\n ");
	for(i=1;i<n;i++)	//display the edges with minimum weight that don't form a cycle
		cycle();			
	
}
