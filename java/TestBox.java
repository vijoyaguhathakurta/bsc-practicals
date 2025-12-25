/*19. Write a program in java to create Box class with parameterized constructor with an object
argument to initialize length, breadth and height also create a function volume which returns the
volume of the box and print it in main method */
import java.util.*;
class Box
{
    double length,breadth,height;   // instance variables
    Box(double l,double b,double h) // parameterized constructor with double parameters
    {   length=l;
        breadth=b;
        height=h;    }
    Box(Box ob)  // parameterized constructor with object parameter(copy constructor)
    {   this.length=ob.length;
        this.breadth=ob.breadth;
        this.height=ob.height;     }
    double volume() // method to find volume
    {   return length*breadth*height;    }
}

class TestBox
{   public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter length,breadth,height: ");
        Box o_arg=new Box(sc.nextDouble(),sc.nextDouble(),sc.nextDouble());
        // creating a object with double arguments
        Box obj=new Box(o_arg); // copying that object to new object
        System.out.println("Volume= "+obj.volume());
    }
}