#include <stdio.h>
#include <stdlib.h>
float a[30][30];
char v[30];
void main()
{
	int n,i,j,k;
	printf("ENTER THE NO. OF VARIABLES IN THE EXPRESSION:\t");
	scanf("%d",&n);
	printf("ENTER THE EXPRESSION IN MATRIX FORM [AX=B]:\nA = \n");
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
            scanf("%f",&a[i][j]);
    printf("X = \n");
	for(i=1;i<=n;i++)
	    scanf("%s",&v[i]);
    printf("B = \n");
	for(i=1;i<=n;i++)
	    scanf("%f",&a[i][n+1]);
	    
    
	float p,m;
	for(i=1;i<=n;i++)
	{
		p=a[i][i];
		if(p==0)
		{
			printf("THE EQUATIONS CANNOT BE SOLVED IN THIS ORDER");
			exit(0);
		}		
 		for(j=1;j<=n;j++)
		{
			if (i!=j)
			{
				m=a[j][i]/p;
				for(k=1;k<=n+1;k++)
					a[j][k]-=a[i][k]*m;
			}
		}	
	}
	printf("FINAL AUGMENTED MATRIX:\n");
	for(i=1;i<=n;i++)
	{    
 		 for(j=1;j<=n+1;j++)
            printf("%f\t",a[i][j]);
  		printf("\n");
	}
	float x[30];	
	for(i=1;i<=n;i++)
		x[i]=a[i][n+1]/a[i][i];
	
 	printf("\nSOLUTION:\n ");
	for(i=1;i<=n;i++)
   	{
        printf("%c = %.4f ",v[i],x[i]);
      	printf("\n");
	} 
}
