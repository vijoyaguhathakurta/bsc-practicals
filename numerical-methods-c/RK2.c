#include <stdio.h>
#include <math.h>
float f(float x,float y)
{	return x+y;
}
void main()
{
	float a,b,h,x,y,k1,k2;
	int n,i;
	printf("PROBLEM : y' = x+y , y(0)=1 ; taking n=5 intervals: find y(0.1)\n");
	a=0;b=0.1;n=5,x=0,y=1;
	h= (b-a)/n;
	printf ("\nITERATION(n)\tXn\tYn= f(Xn)\n------------\t--\t--------\n");
	for(i=0;i<=n;i++)
	{
		printf("\t%d\t%.4f\t%.4f\n",i,x,y);
		if(i==n)
  		    break;
		k1=h*f(x,y);
		x=x+h;
		k2=h*f(x,y+k1);
  		y=y+((k1+k2)/2);  		
	}
	printf("\nANSWER: y(%.1f)= %.4f",b,y);
}

