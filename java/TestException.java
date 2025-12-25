/*Write a program in java to handle both ‘ArrayIndexOutOfBoundsException’ and  
‘ArithmeticException’ and create a new exception as ‘NegativeSizeException’ whenever
 negative values are put in an array. */
 import java.util.*;
class NegativeSizeException extends Exception //user defined exception
{   public String toString()
    {   return ("NegativeSizeException:negative values are put in the array.");    }
}
class TestException
{   static void func(int n) throws NegativeSizeException 
    // method throws the new created exception
    {   if(n<0)
            throw new NegativeSizeException();  }
    public static void main(String[] args)
    {   try { // contains statements which cause exception
            Scanner sc= new Scanner(System.in);
            System.out.print("Enter size of array:");
            int n=sc.nextInt();
            int a[]=new int[n];
            System.out.print("Enter elements:");
            for(int i=0;i<n;i++)
            {    a[i]=sc.nextInt();
                 func(a[i]);    }       
            System.out.println("Dividing a[n-2] by a[n-1]:"+a[n-2]/a[n-1]); 
            System.out.println("Dividing a[n] by a[n-1]:"+a[n]/a[n-1]); 
        }
        catch (ArrayIndexOutOfBoundsException e) //handling the exceptions
        {   System.out.println("Index is not found: "+e);   }
        catch (ArithmeticException e) 
        {   System.out.println("Division by zero: "+e);     }
        catch (NegativeSizeException e) 
        {   System.out.println(e);   }
    }  
}
