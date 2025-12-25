#include <stdio.h>
#include <math.h>
float t[30][30];
void main()
{	int n,i,f=0,j;
	float x,h,s=0,p,fc,u,v,w=1;
	printf("ENTER THE NO. OF ENTRIES: ");
	scanf("%d",&n);
	printf("ENTER THE VALUES OF x: ");
	for(i=0;i<n;i++)
	    scanf("%f",&t[i][0]);
 	printf("ENTER THE VALUES OF y=f(x) : ");
	for(i=0;i<n;i++)
	    scanf("%f",&t[i][1]);	
	printf("ENTER x FOR WHICH f(x) IS TO BE CALCULATED: ");
 	scanf("%f",&x);
    h=t[1][0]-t[0][0];
	for(i=1;i<n-1;i++)
 	{	if (t[i+1][0]-t[i][0]!=h)
		{	f=1;	break;		} 		 
	}
	if(f==0)
	{	for(i=2;i<=n;i++)
			for(j=0;j<=n-i;j++)
				t[j][i]=t[j+1][i-1]-t[j][i-1];		
		printf("\nTHE DIFFERENCE TABLE\nx\ty\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<=n-i;j++)
				printf("%.4f\t",t[i][j]);
			printf("\n");		}
		if (fabs(t[0][0]-x)<fabs(t[n-1][0]-x))
		{	printf("\nNEWTON'S FORWARD INTERPOLATION FORMULA IS APPLIED.\n");
			u=(x-t[0][0])/h;
			for(i=0;i<n;i++)
			{	p=1,fc=1;
				for(j=0;j<i;j++)
					p=p*(u-j);
				for(j=1;j<=i;j++)
					fc=fc*j;			 
				s=s+(p*t[0][i+1]/fc);
			}
			printf("ANSWER= %f",s);
		}
		else
		{	printf("\nNEWTON'S BACKWARD INTERPOLATION FORMULA IS APPLIED.\n");
			v=(x-t[n-1][0])/h;
			for(i=0;i<n;i++)
			{	p=1,fc=1;
				for(j=0;j<i;j++)
					p=p*(v+j);
				for(j=1;j<=i;j++)
					fc=fc*j;			 
				s=s+(p*t[n-1-i][i+1]/fc);
			}
			printf("ANSWER= %f",s);	
		}		
	}
	else
	{	printf("\nLAGRANGE'S INTERPOLATION FORMULA IS APPLIED.\n");		
		for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
			{	if(i==j)
				{	t[j][i+2]=x-t[i][0];
					w=w*t[j][i+2];	}
				else
					t[j][i+2]=t[j][0]-t[i][0];
			}
		}
		for(i=0;i<n;i++)
		{	p=1;
			for(j=0;j<n;j++)
				p=p*t[i][j+2];		
			t[i][n+2]=p;			
		}
		for(i=0;i<n;i++)
		{	t[i][n+3]=t[i][1]/t[i][n+2];
			s=s+t[i][n+3];
		}
		printf("\nTHE COMPUTATIONAL TABLE:\nx\ty");
		for(i=0;i<=n;i++)
			printf("\t");
		printf("  D\t   y/D\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<=n+3;j++)
				printf("%.3f\t",t[i][j]);
			printf("\n");
		}
		printf("ANSWER= %f ",s*w);		
	}	
}
