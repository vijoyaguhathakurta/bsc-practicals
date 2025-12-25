#include <stdio.h>
#include <math.h>
float a,b,m;
float f(float x)
{
	return x*x*x-x-1;
}
void main()
{
	int i;
	for (i=0;;i++)
	{
		if (f(i)<0)
		   a=i;
		else 
        	b=i;
       	if (f(a)*f(b)<0 && a<b)
       	   break;
	}
	printf("ASSUMED FUNCTION : x^3 - x - 1\n");
	printf ("INITIAL POINTS ARE :\ta= %f, b= %f\n",a,b);
	printf ("\nITERATION\ta\tb\tm=(a+b)/2\tf(m)\n---------\t-\t-\t----------\t-----\n");
	for(i=1;;i++)
	{
		m=(a+b)/2;
		printf("\t%d\t%.4f\t%.4f\t%.4f\t\t%.5f\n",i,a,b,m,f(m));
		if(floor(fabs(f(m))*10000)/10000==0)
		{
			printf("ANSWER= %.4f ",m);
			break;
		}   
		else if(f(m)*f(a)<0)
  			b=m;
        else if (f(m)*f(b)<0)
  			a=m;
	}
}
