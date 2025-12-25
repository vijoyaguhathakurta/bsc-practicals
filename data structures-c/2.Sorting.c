#include <stdio.h>
int a[50],n;

void print()
{
	int i;
	for(i=0;i<n;i++)
		printf("| %d |",a[i]);
}
int swap(int x,int y)
{
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}

void bubble_sort()
{
	int i,j,temp,flag;
	for(i=0;i<n;i++)
	{
		//Optimized bubble sort
		flag=0;
		for(j=0;j<n-i-1;j++)
	    	if(a[j]>a[j+1])
	    	{
	    		swap(j,j+1);
				flag=1;	    	
			}
		// If no two elements were swapped by inner loop then break from outer loop
		if(flag==0)
			break;
	}
}

void insertion_sort()
{
    int i,j,key;
    for(i=1;i<n;i++)
	{
		key=a[i];
        j=i-1;
        //key is compared with each element in its left till a element smaller than it is found
        while(j>=0 && a[j]>key)
		{
			//placing every unsorted element in correct position
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void selection_sort()
{
	int index,i,j,sw;
	for(i=0;i<n;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[index])
				index=j;
		swap(i,index);
	}
}

void quick_sort(int low,int high) 
{
	int pi,i,j;
	if (low < high)
    {
		int pivot=a[high];
		i=low-1; // indicates the right position of pivot found so far
    	for(j=low;j<high;j++)
    	{        
        	if (a[j]<pivot) // If current element is smaller than the pivot
        	{
				i++;
            	swap(i,j);
        	}
   		}
    	swap(i+1,high);
   		pi=i+1; // pi is partitioning index is now at right place 
        // Separately elements are sorted before partition and after partition
        quick_sort(low,pi-1);
        quick_sort(pi+1,high);
    }
}

void merge_sort(int l,int r) // l is left index and r is right index of the subarray to be sorted
{	
    if(l<r) 
	{
        int m=(l+r)/2; 
        // Sort first and second halves
        merge_sort(l,m);
        merge_sort(m+1,r);
        int i,j,k, n1=(m-l)+1, n2=r-m; 
    	int L[n1],R[n2]; // create temporary arrays 
	 	// Copy data to temporary arrays L[] and R[]
    	for(i=0;i<n1;i++)
       		L[i]=a[l+i];
    	for(j=0;j<n2;j++)
       		R[j]=a[m+1+j];
    	// Merge the temporary arrays back into a[]
    	i=0,j=0,k=l;
    	while(i<n1 && j<n2)
		{
       		if(L[i]<=R[j])
			{
           		a[k]=L[i];
				i++;
			}
       		else
			{
	           	a[k]=R[j];
				j++;
			}
			k++;
   		}
  		for(;i<n1;i++) //Copy the remaining elements of L[], if there are any
		{
	       	a[k]=L[i];
			k++;
    	}
    	for(;j<n2;j++) //Copy the remaining elements of R[], if there are any
		{
	       	a[k]=R[j];
	       	k++;
	   	}
    }
}
	
void radix_sort() 
{
 	// Getting maximum element
  	int mx=a[0];
  	int i;
  	for(i=1;i<n;i++)
    	if(a[i]>mx)
    		mx=a[i];      
 	int place;
    for(place=1;mx/place>0;place*=10)
	{
    	int output[n+1];
    	int max=(a[0]/place)%10;
    	for(i=1;i<n;i++)
			if (((a[i]/place)%10)>max)
      			max=a[i];
		int count[max+1];
  		for(i=0;i<max;++i)
	    	count[i]=0;
		// Calculation for count of elements
  		for(i=0;i<n;i++)
	    	count[(a[i]/place)%10]++;
	    // Calculation for cumulative count
	  	for(i=1;i<10;i++)
	    	count[i]+=count[i-1];
	    // Placing the elements in sorted order
	  	for(i=n-1;i>=0;i--)
		{
	    	output[count[(a[i]/place)%10]-1]=a[i];
    		count[(a[i]/place)%10]--;
		}
    	for(i=0;i<n;i++)  
	    	a[i]=output[i];  
  	}
}

void shell_sort()
{
  	// Rearrange elements at each n/2, n/4, n/8, ... intervals
  	int i,j,k,temp;
 	for(i=n/2;i>0;i/=2)
	{
    	for(j=i;j<n;j+=1)
		{
     		temp=a[j];
			for(k=j; k>=i && a[k-i]>temp; k-=i)
				a[k]=a[k-i];  
      	a[k] = temp;
    	}
  	}
}
    
void main()
{
	int i;
	int ch;
	while(1)
	{
		printf("ENTER SIZE OF ARRAY: ");
    	scanf("%d",&n);
    	if(n>0)
		{
			printf("ENTER ELEMENTS IN ARRAY:\n");
			for(i=0;i<n;i++)
    			scanf("%d",&a[i]);
    		printf("FOR SORTING ARRAY BY :\n* BUBBLE SORT (OPTIMIZED WITH FLAG VARIABLE), ENTER 1.\n* INSERTION SORT, ENTER 2.\n* SELECTION SORT, ENTER 3.\n* QUICK SORT, ENTER 4.\n* MERGE SORT, ENTER 5.\n* RADIX SORT, ENTER 6.\n* SHELL SORT, ENTER 7.\n ENTER OPTION: ");
			scanf("%d",&ch);
			printf("\nTHE UNSORTED ARRAY: \n");
			print();
			printf("\nTHE SORTED ARRAY:\n");
   			switch(ch)
			{
				case 1:
					bubble_sort();
					print();
					break;
				case 2:
					insertion_sort();
					print();
					break;
				case 3:
					selection_sort();
					print();
					break;
				case 4:
					quick_sort(0,n-1);
					print();
					break;
				case 5:
					merge_sort(0,n-1);
					print();
					break;
				case 6:
					radix_sort();
					print();
					break;
				case 7:
					shell_sort();
					print();
					break;
				default:
					printf("WRONG CHOICE.");					
			}
			cnt:printf("\nDO YOU WANT TO CONTINUE? [1-->YES][0-->NO]:");
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

