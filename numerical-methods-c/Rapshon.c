#include <stdio.h>
#include <math.h>
float a,b,m;
float f(float x)
{
	return x*x*x+x*x-3;
}
float f1(float x)
{
	return 3*x*x+2*x;
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
	float h,x1,x=b;
	printf("ASSUMED FUNCTION : x^3 + x^2 - 3\n");
	printf ("INITIAL POINT x0 LIES BETWEEN a AND b WHERE a= %f, b= %f\nLET x0 = %.4f\n",a,b,x);
	printf ("\nITERATION(n)\tXn\tf(Xn)\tf1(Xn)\th= -[f(Xn)/f1(Xn)]\tX(n+1)=Xn+h\n------------\t--\t-----\t------\t------------------\t-----------\n");
	for(i=1;;i++)
	{
		h=-(f(x)/f1(x));
		x1=x+h;
		printf("\t%d\t%.4f\t%.4f\t%.4f\t\t%.5f%\t%.5f\n",i,x,f(x),f1(x),h,x1);
		if((floor(x*10000)/10000)==(floor(x1*10000)/10000))
		{
			printf("ANSWER= %.4f ",x);
			break;
		}  
		x=x1;
	}
}

