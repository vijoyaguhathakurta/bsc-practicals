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
	for(k=1;k<n;k++)
	{
		p=a[k][k];
		if(p==0)
		{
			printf("THE EQUATIONS CANNOT BE SOLVED IN THIS ORDER");
			exit(0);
		}		
 		for(i=k+1;i<=n;i++)
		{
			m=a[i][k];
			for(j=1;j<=n+1;j++)
				a[i][j]-=a[k][j]/p*m;
		}	
	}
	
	float x[30],s;
	x[n]=a[n][n+1]/a[n][n];
	for(i=n-1;i>=1;i--)
	{
		s=0;
		for(j=n;j>i;j--)
		   s+=a[i][j]*x[j];
        x[i]=(a[i][n+1]-s)/a[i][i];
	}
 	printf("SOLUTION: ");
	for(i=1;i<=n;i++)
   	{
        printf("%c = %.4f ",v[i],x[i]);
      	printf("\n");
	} 
}
	
	
