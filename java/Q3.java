/* 3. Write a program in java to 
i. delete all consonants from the input string and print the result string.
ii. count all words in the string.
Input the string: The quick brown fox jumps over the lazy dog.
Expected Output: Number of words in the string: 9
iii. compare two strings lexicographically.
iv. find whether a region in the current string matches a region in another string.
Sample Output: str1[0 - 7] == str2[28 - 35]? true
               str1[9 - 15] == str2[9 - 15]? false
*/
import java.util.*;
class Q3
{   public static void main(String[] args)
    {   Scanner sc=new Scanner(System.in);
        System.out.print("\nEnter a String: ");
        String s=sc.nextLine(); // taking the first string from user

        //i. count words
        int c=1;
        for(int i=0;i<s.length();i++) // loop through string 
           if (s.charAt(i)==' ')  // if character is whitespace
                c++;    // increment word count
        System.out.print("\ni.  Number of words in the string: "+c);
        
        
        //ii. delete consonants 
        String str="";
        for(int i=0;i<s.length();i++)   // loop through string to join the vowels
        {   char ch=s.charAt(i);
            if(ch=='a' || ch=='A' || ch=='E' || ch=='e' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='U' || ch=='u')
                str=str+ch;          // form a new string with them  
        }
        s=str;  // replacing the string with new string
        System.out.println("\n\nii.  The new string without consonants: "+s);
        
        System.out.print("\nEnter another string: ");
        String s1=sc.nextLine();
        
        //iii. lexicographical comparision
        System.out.println("\niii.  Result of lexicographical comparison of the 2 input strings: "+s.compareTo(s1));

        //iv. string region comparision
        // Specify the region to compare in both strings
        System.out.println("\niv. Enter the region to compare in both strings:");
        System.out.print("The start index of 1st string:");
        int start1=sc.nextInt();
        System.out.print("The end index of 1st string:");
        int end1=sc.nextInt();
        System.out.print("The start index of 2nd string:");
        int start2=sc.nextInt();
        System.out.print("The end index of 2nd string:");
        int end2=sc.nextInt();
        boolean res=false;
        if(start1!=start2 && end1!=end2)    
            res=s.substring(start1,end1+1).equals(s1.substring(start2,end2+1)); // check if the region of 2 strings match 
        System.out.println("Does the given region of the two strings match? i.e \nstr1["+start1+"-"+end1+"]==str2["+start2+"-"+end2+"]?"+res );
      
        }   
}
