#include<stdio.h>
#include<stdlib.h>
int arr[50][50];
int r,c,i,j;
int rst[50][50];
void magic()
{
	if(r!=c)
	{
		printf("NOT A SQUARE MATRIX. THEREFORE CHECKING MAGIC SQUARE NOT POSSIBLE.");
		return;
	}
 	int sum=0,sn=0;
 	//Finding the sum of diagonal elemants and Sum of antidiaganal elemants
 	for(i=0;i<r;i++)
	{
 		sum=sum+arr[i][r-i-1];
  		sn=sn+arr[i][i];
	}
 	if(sum!=sn) // Further statements will be executed if sum=sn otherwise jump to notm
  		goto notm;
	//Finding the sum of elemants of each row 
 	for(i=0;i<r;i++)
 	{ 
		sn=0;
 		for(j=0;j<r;j++)
  			sn=sn+arr[i][j];
 		if(sn!=sum) // Further statements will be executed if sum=sn otherwise jump to notm
  			goto notm;
 	}
	//Finding the sum of elemants of each column
	for(i=0;i<r;i++)
 	{ 
 		sn=0;
 		for(j=0;j<r;j++)
  			sn=sn+arr[j][i];
 		if(sn!=sum) // Further statements will be executed if sum=sn otherwise jump to notm
  			goto notm;
 	}
	printf("THE GIVEN MATRIX IS A MAGIC SQUARE OF ORDER %dX%d WITH A SUM OF %d. ",r,r,sum);
		return;
	notm:printf("THE GIVEN MATRIX IS A NOT MAGIC SQUARE.\n");
}

void transpose()
{
	printf("TRANSPOSE OF THE GIVEN MATRIX IS:\n");
	for(i=0;i<c;i++)
 	{
	 	for(j=0;j<r;j++)
 		{
		 	rst[i][j]=arr[j][i]; //Storing the transpose in resultant matrix
			printf("%d\t",rst[i][j]);//Printing resultant matrix
		}
		printf("\n");
	}
}

void multiply()
{
	int m[50][50],rn,cn;
	//Entering the dimensions of 2nd matrix
	printf("ENTER DIMENSIONS OF THE 2ND MATRIX: ");
	scanf("%d",&rn);
	scanf("%d",&cn);
	if(cn<=0 || rn<=0)
	{
		printf("INVALID DIMENSIONS.");
		return;
	}
	//Entering elements in matrix
	if(c==rn)//Condition for multiplication
	{	
		printf("ENTER THE ELEMENTS IN THE 2ND MATRIX: \n");
			for(i=0;i<rn;i++)
 				for(j=0;j<cn;j++)
  					scanf("%d",&m[i][j]);
  		// Printing 2nd matrix
		printf("THE 2ND MATRIX IS: \n");
		for(i=0;i<rn;i++)
 		{ 
 			for(j=0;j<cn;j++)	
   				printf("%d\t",m[i][j]);
 			printf("\n");
 		}
		//Multiplying the two matrices	
		int k,s;
		for(i=0;i<r;i++)
 			for(j=0;j<cn;j++)
 			{
 				s=0;
			 	for(k=0;k<c;k++)
 					s=s+(arr[i][k]*m[k][j]);
 				rst[i][j]=s;
 			}
 		//Printing the product
		printf("THE PRODUCT MATRIX IS: \n");
		for(i=0;i<r;i++)
 		{ 
 			for(j=0;j<cn;j++)	
   				printf("%d\t",rst[i][j]);
 			printf("\n");
 		}	 				
	}
	else
		printf("MULTIPLICATION NOT POSSIBLE.");
}

void maxmin()
{
	int mx,mn;
	//Finding maximum minimum for each row
	for(i=0;i<r;i++)
 	{
 		mx=arr[i][0];
 		mn=arr[i][0];
		for(j=1;j<c;j++)
		{
			if(mx<arr[i][j])
				mx=arr[i][j];
			if(mn>arr[i][j])
				mn=arr[i][j];
		}
		printf("THE MINIMUM NUMBER IN ROW %d IS %d.\n",i+1,mn);
		printf("THE MAXIMUM NUMBER IN ROW %d IS %d.\n",i+1,mx);
	}
	//Finding maximum minimum for each column
	for(i=0;i<c;i++)
 	{
 		mx=arr[0][i];
 		mn=arr[0][i];
		for(j=1;j<r;j++)
		{
			if(mx<arr[j][i])
				mx=arr[j][i];
			if(mn>arr[j][i])
				mn=arr[j][i];
		}
		printf("THE MINIMUM NUMBER IN COLUMN %d IS %d.\n",i+1,mn);
		printf("THE MAXIMUM NUMBER IN COLUMN %d IS %d.\n",i+1,mx);
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("**********	MATRIX OPERATIONS	**********\n i)   ENTER 1 TO CALCULATE TRANSPOSE.\n ii)  ENTER 2 TO READ ANOTHER MATRIX AND PERFORM MATRIX MULTIPLICATION.\n iii) ENTER 3 TO CHECK IF A GIVEN SQUARE MATRIX IS MAGIC SQUARE OR NOT.\n iv)  ENTER 4 TO FIND OUT THE MINIMUM AND MAXIMUM NUMBERS IN EACH ROW AND EACH COLUMN INDIVIDUALLY.\nENTER: ");
		scanf("%d",&ch);
		if(ch<1 || ch>4)
			goto wc;
		printf("ENTER DIMENSIONS OF MATRIX: ");
		scanf("%d",&r);
		scanf("%d",&c);
		if(c>0 && r>0)
		{
			printf("ENTER THE ELEMENTS IN THE MATRIX: \n");
			for(i=0;i<r;i++)
 				for(j=0;j<c;j++)
  					scanf("%d",&arr[i][j]);
			printf("THE MATRIX IS: \n");
			for(i=0;i<r;i++)
 			{ 
 				for(j=0;j<c;j++)	
   					printf("%d\t",arr[i][j]);
 				printf("\n");
 			}
 			switch(ch)
			{
				case 1:
					transpose();
					break;
				case 2:
					multiply();
					break;
				case 3:
					magic();
					break;
				case 4:
					maxmin();
					break;
				default:
				wc:	printf("WRONG CHOICE.");								
			}
			cnt:printf("\nDO YOU WANT TO CONTINUE? [1-->YES][0-->NO]:");
			int w;
			scanf("%d",&w);
			if(w==0)
				break;
 		}
 		else
 		{
		 	printf("INVALID DIMENSIONS.\n");
		 	goto cnt;
		}
	}
}
 



