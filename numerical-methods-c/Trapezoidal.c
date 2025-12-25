#include <stdio.h>
#include <math.h>
float f(float x)
{	return x*x-1;
}
void main()
{
	float a,b,h,i,s=0;
	int n,k=0;
	printf("ASSUMED FUNCTION :f(x)= x^2 - 1 in [0,1] ; taking n=10 intervals \n");
	a=0;b=1;n=10;
	float y[n];
	h= (b-a)/n;
	printf ("\nITERATION(n)\tXn\tYn= f(Xn)\n------------\t--\t--------\n");
	for(i=a;i<=b+h;i+=h)
	{
		y[k]=f(i);
		printf("\t%d\t%.4f\t%.5f\n",k,i,y[k]);
		s=s+y[k];
		k++;			
	}
	printf("Area= h/2 [y0 + y(n) + 2 (y1 + y2 + ... + y(n-1))]");
	s=s-y[0]-y[n];
	float ar= (h/2)*(2*s+y[0]+y[n]);
	printf("\nANSWER= %f",ar);
}

