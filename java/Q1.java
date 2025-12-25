/*1. Write a program in java that:
 i. sorts half of element in ascending and rest half of the elements in descending order. 
 ii. remove a specific element from an array.
 iii. insert an element (specific position) into an array.
 v. find all pairs of elements in an array whose sum is equal to a specified number
 iv. remove the duplicate elements of a given array and return the new length of that array
 vi. find the length of the longest consecutive elements sequence from a given unsorted array of integers.
Sample array: [49, 1, 3, 200, 2, 4, 70, 5] 
The longest consecutive elements sequence is [1, 2, 3, 4, 5], therefore the program will return its 
length 5*/
import java.util.*;
class Q1
{   public static void main(String[] args)
    {   Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n=sc.nextInt();  // user input size
        int a[]=new int [n];
        System.out.println("Enter the elements in the array: ");
        int c,i,j;
        for(i=0;i<n;i++)
            a[i]=sc.nextInt(); // taking array from user
        // i    sorting
        for(i=0;i<n/2;i++)  // sorting 1st half in ascending order
	        for(j=0;j<n/2-i-1;j++)
	    	    if(a[j]>a[j+1])
	    	   	{   c=a[j];
                    a[j]=a[j+1];
                    a[j+1]=c;    }
        for(i=0;i<n/2;i++)  // sorting 2nd half in descending order
	        for(j=n/2;j<n-i-1;j++)
	    	    if(a[j]<a[j+1])
	    	   	{   c=a[j];
                    a[j]=a[j+1];
                    a[j+1]=c;   }
        System.out.print("\ni.   The resultant array:");
        for(int x:a)    // displaying the resultant array
            System.out.print(x+" ");

        // ii  deletion
        System.out.print("\n\nii.  Enter the element to be removed from the array: ");
        int d=sc.nextInt();  // taking user input
        for(i=0;i<n;i++)    
        {   if(a[i]==d)     // if the element d is found
            {   for(j=i;j<n-1;j++) // shift all elements after d to left
                    a[j]=a[j+1];   // to overwrite the element
                n--;break;    }     }
        System.out.print("The array after removal: ");
        for(i=0;i<n;i++)  // displaying the resultant array
            System.out.print(a[i]+" ");
        
        // iii. insertion
        System.out.print("\n\niii. Enter the position in which element is to be inserted in the array: ");
        int p=sc.nextInt(); 
        for(i=n;i>=p-1;i--) // shift all elements after position p to right
            a[i]=a[i-1];    // thus, making space for new element 
        System.out.print("Enter the element to be inserted from the array: ");
        a[p-1]=sc.nextInt();    // inserting the new element   
        System.out.print("The array after insertion: ");
        for(i=0;i<=n;i++)   // displaying the resultant array
            System.out.print(a[i]+" ");
        
        // iv.  removing duplicates
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[i]==a[j])  // if an element = another element in the array
                {   for(int k=j+1;k<n;k++) // deleting that element
                        a[k-1]=a[k];
                    n--;  j--;     }
        System.out.print("\n\nv.   the length of array with distinct elements is "+n+" and its elements are: ");
        for(i=0;i<n;i++)    // displaying the resultant array
            System.out.print(a[i]+" ");  
            
        // v. sum of pairs=s
        System.out.print("\n\niv.  Enter the number which will be the sum: ");
        int s=sc.nextInt(); // taking the sum from user
        System.out.print("All pairs of elements in an array whose sum is equal to "+s+" : ");
        for(i=0;i<n;i++)    // check for all pair
            for(j=i+1;j<n;j++)  
                if(a[i]+a[j]==s)    // if their sum=s
                    System.out.print("["+a[i]+","+a[j]+"]"); // displaying the pairs

        // vi. longest sequence
        int m=0;s=0;
        for(i=0;i<n;i++)  // sorting array in ascending order
	        for(j=0;j<n-i-1;j++)
	    	    if(a[j]>a[j+1])
	    	   	{   c=a[j];
                    a[j]=a[j+1];
                    a[j+1]=c;    }
        for(i=0;i<n;i++)
        {   c=1;    // length of the sequence initially
            for(j=i;j<n-1;j++)
                if(a[j]+1==a[j+1])  // if value of an element + 1= next element 
                   c++;    // increment the length of sequence
                else
                    break;
            if (m<c)
            {   m=c; s=i;    }     }
        System.out.print("\n\nvi.  The longest consecutive elements sequence: ");
        for (i=s;i<s+m;i++) // displaying the sequence
            System.out.print(a[i]+" ");
        System.out.println();   // displaying the length of sequence
        System.out.print("The length of longest consecutive elements sequence: "+m);
    }
}

