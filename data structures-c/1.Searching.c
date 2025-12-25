#include <stdio.h>
int a[100],s,v; 
void binary()
{
	//Sorting in Ascending Order before searching
	int i,j,sw;
	for(i=0;i<s;i++)
		for(j=0;j<s-i-1;j++)
	    	if(a[j]>a[j+1])
	    	{
	    		sw=a[j];
	    		a[j]=a[j+1];
	    		a[j+1]=sw;	    	
			}
	 //Searching the given value in binary search method 
	int lb=0,ub=s-1,p=0,k=0;
	while(lb<=ub)
	{
		p=(lb+ub)/2;
		if(a[p]<v)
			lb=p+1;
		else if (a[p]>v)
			ub=p-1;
		else
		{
		  	k++;
		  	break;
		} 
	}
	printf("BINARY SEARCH SUCCESSFUL.");
	if (k==1)
		printf("\nELEMENT FOUND.");
	else
		printf("\nELEMENT NOT FOUND.");  
}

void linear()
{
	int i,k=0;
	for(i=0;i<s;i++)
		if(a[i]==v)
		{
			k++;
			break;
		}
	printf("LINEAR SEARCH SUCCESSFUL.");
	if (k==1)
		printf("\nELEMENT FOUND IN POSITION %d.\n",i+1);
	else
		printf("\nELEMENT NOT FOUND.");  
} 


void main()
{
	int i,c;
	while(1)
	{
		printf("ENTER SIZE OF ARRAY: ");
    	scanf("%d",&s);
    	if(s>0)
		{
			printf("ENTER ELEMENTS IN ARRAY:\n");
			for(i=0;i<s;i++)
    			scanf("%d",&a[i]);
   			printf("ENTER THE VALUE TO BE SEARCHED: ");
			scanf("%d",&v);
			printf("FOR SEARCHING VALUE BY :\n			LINEAR SEARCH TECHNIQUE, ENTER 1.\n			BINARY SEARCH TECHNIQUE, ENTER 2.\n");
			scanf("%d",&c);
			switch(c)
			{
				case 1:
					linear();
					break;
				case 2:
					binary();
					break;
				default:
					printf("WRONG CHOICE.");					
			}
			cnt:printf("\nDO YOU WANT TO CONTINUE SEARCHING FOR MORE ELEMENTS? [1-->YES][0-->NO]:");
			int w;
			scanf("%d",&w);
			if(w==0)
				break;
		}	
    	else
		{
			printf("INVALID SIZE\n");
			goto cnt;
		}
	}
}
