/* 2. Write a program in java that accepts a 2D matrix and prints the matrix with row minimum and column minimum values.
    4 3 5 3
    1 0 7 0
    8 4 6 4
    1 0 5   */

import java.util.*;
class Q2 
{    public static void main(String[] args)
    {   Scanner sc=new Scanner(System.in);
        System.out.print("Enter the no. of columns in the array: ");
        int n=sc.nextInt(); // taking no. of columns from user
        System.out.print("Enter the no. of rows in the array: ");
        int m=sc.nextInt(); // taking no. of rows from user
        int a[][]=new int [m+1][n+1]; // creating the 2D array
        System.out.println("Enter the elements in the array: ");
        int i,j,min;
        for(i=0;i<m;i++)
        {   min=999;
            for(j=0;j<n;j++)
            {   a[i][j]=sc.nextInt(); // taking the elements from user
                if(min>a[i][j])  // finding minimum in each row
                    min=a[i][j];     }
            a[i][j]=min;    // placing the minimum at the end of column
        }   
        for(i=0;i<n;i++)
        {   min=999;
            for(j=0;j<m;j++)
                if(min>a[j][i]) // finding minimum in each column
                    min=a[j][i];
            a[j][i]=min;    // placing the minimum at the end of column
        }     
        System.out.println("RESULT:");
        for(i=0;i<=m;i++)   // displaying the matrix with minimums
        {   for(j=0;j<=n;j++)
            {   if(i==m && j==n)    
                    break;
                System.out.print(a[i][j]+" ");  
            }    
            System.out.println();
        }            
    }     
}
