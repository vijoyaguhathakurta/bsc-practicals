//17. A Java program to print all permutations of a given string with repetition
import java.util.*;

class Q4
{    // A method to print all the permutations of a given string
    static void printPermutations(String s1, String s2)
    {   if (s1.length()==0)
            System.out.print(s2+" , ");
        // The recursive case is when we loop through all the characters in the string
        // and append them to the prefix and call the method again
        else 
            for (int i = 0; i < s1.length(); i++)
                printPermutations(s1.substring(0,i)+s1.substring(i+1), s2+s1.charAt(i));
    }

    public static void main(String[] args)
    {   Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = sc.nextLine();   // Get the input string from the user
        System.out.print("The permutations of " + input + " are: ");
        printPermutations(input, "");
    }
}
