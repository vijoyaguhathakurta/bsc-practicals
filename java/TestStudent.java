/*22. Create a class Student with following operations
a) create parameterized constructor to initialize the objects.
b) create a overloaded function isEqual() one to check whether the two objects are equal another to check if values of two objects are equal.
c) print the result in main method if objects are equals or not (take variables as command line arguments) */

import java.util.*;
class Student
{   String name;
    int roll;
    Student(String n,int r)
    {   name=n;
        roll=r;    }
    boolean isEqual(Student y) //method to check if values of objects are equal
    {   if (this.name.equals(y.name) && this.roll==y.roll)
            return true;
        return false;    }
    static boolean isEqual(Student x,Student y) //method to check if objects are equal
    {   if(x==y)
            return true;
        return false;    }
}
class TestStudent
{   public static void main(String args[])
    {   Scanner sc= new Scanner(System.in);
        // creating two objects with different values 
        Student a=new Student(args[0],Integer.parseInt(args[1])); 
        Student b=new Student(args[2],Integer.parseInt(args[3]));
        System.out.println("For two different objects:\nAre the objects equal? "+Student.isEqual(a,b)+"\tAre the objects' values equal? "+a.isEqual(b));
        Student d=new Student(a.name,a.roll); // deep copy of object a
        System.out.println("For deep copy of objects:\nAre the objects equal? "+Student.isEqual(a,d)+"\tAre the objects' values equal? "+a.isEqual(d));
        Student s=a; // shallow copy of the object a
        System.out.println("For shallow copy of objects:\nAre the objects equal? "+Student.isEqual(a,s)+"\tAre the objects' values equal? "+a.isEqual(s));     
    }
}