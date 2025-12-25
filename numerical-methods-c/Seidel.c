#include <stdio.h>
#include <math.h>
int a[30][30];
char v[30];
int b[30];
void main()
{
	int n,i,j,l,k=0,s,p,f=0;
	printf("ENTER THE NO. OF VARIABLES IN THE EXPRESSION:\t");
	scanf("%d",&n);
	printf("ENTER THE EXPRESSION IN MATRIX FORM [AX=B]:\nA = \n");
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("X = ");
	for(i=1;i<=n;i++)
	    scanf("%s",&v[i]);
    printf("B = ");
	for(i=1;i<=n;i++)
	    scanf("%d",&b[i]);
	    
    for(i=1;i<=n;i++)
    {
    	s=0;
    	for(j=1;j<=n;j++)
        {
        	if (i!=j)
			   s+= a[i][j];	 
		}
		if (a[i][i]>s)
		   f++;    
       
	}
	if(f==n)
	{
		float x[30]={0}, d,r;
		int f[10]={0};
		printf("k\t");
		for(i=1;i<=n;i++)
	 	    printf("%c(k)\t",v[i]);
		printf("\n0\t");
		for(i=1;i<=n;i++)
            printf("%.3f\t",x[i]);
        printf("\n");
		for (l=1;;l++)
		{
			printf("%d\t",l);
		 	for (i=1;i<=n;i++)
			{
			 	d=b[i];
		   		for (j=1;j<=n;j++)
		    		if (i!=j)
			       	   d-=(a[i][j]*x[j]);       
  			    r= floor(1000* (d/a[i][i]))/1000;
	    		if (x[i]==r)
	    			f[i]++;
   				x[i]=r;
            	printf("%.3f\t",x[i]);
     		}
        	printf("\n");
        	k=0;
        	for (p=1;p<=n;p++)
           		if(f[p]>0)
   				    k++;
			if (k==n)
		   	   break;		           
        }
        printf("SOLUTION:");
		for(i=1;i<=n;i++)
    	{
            printf("%c = %.3f ",v[i],x[i]);
        	printf("\n");
		} 		
	}
	else 
		 printf("ITERATIVE METHOD CANNOT BE APPLIED AS THE SET OF EQUATIONS ARE NOT DIAGNALLY DOMINANT.");	
}
