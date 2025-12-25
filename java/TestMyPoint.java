/*4. A class called MyPoint, which models a 2D point with x and y coordinates. It contains:
• Two instance variables x (int) and y (int).
• A default (or "no-argument" or "no-arg") constructor that construct a point at the default location 
of (0, 0).
• A overloaded constructor that constructs a point with the given x and y coordinates.
• A method setXY() to set both x and y.
• A method getXY() which returns the x and y in a 2-element int array.
• A toString() method that returns a string description of the instance in the format "(x, y)".
• A method called distance(int x, int y) that returns the distance from this point to another point at the 
given (x, y) coordinates, d=sqrt((x2-x1)^2)+(y2-y1)^2)
Write the MyPoint class.
Also write a test driver (called TestMyPoint) to test all the public methods defined in the class. */

import java.util.*;
class MyPoint 
{   int x,y;    // instance variables
    MyPoint()   //default constructor
    {   x=y=0;  }
    MyPoint(int a,int b)    // parameterized constructor
    {   x=a;    
        y=b;    }
    void setXY() //method to set point
    {   Scanner sc=new Scanner(System.in);
        System.out.print("Enter the point: "); 
        x=sc.nextInt();
        y=sc.nextInt();    }
    int[] getXY()   // returns 2 element int array
    {   int a[]=new int [2];
        a[0]=x;
        a[1]=y;
        return a;    } 
    public String toString()    // overrides method in Object class
    {   return "("+x+","+y+")";    }
    double distance (MyPoint obj)   // calculates distance between this point and other point
    {   return Math.sqrt(Math.pow((this.x-obj.x),2)+Math.pow((this.y-obj.y),2));   }
}
class TestMyPoint
{    public static void main(String[] args)
    {   Scanner s=new Scanner(System.in);
        MyPoint ob=new MyPoint();   // creating a point(object) at (0,0)
        ob.setXY(); // setting its x,y coordinates
        int p[]= ob.getXY(); // converting point to array
        System.out.println(p[0]+"|"+p[1]);
        System.out.println(ob.toString());   //converting point to string
        System.out.print("Enter the 2nd point: "); 
        MyPoint ob1=new MyPoint(s.nextInt(),s.nextInt());  // creating a point(object) with given values
        int p1[]= ob1.getXY(); // converting point to array
        System.out.println(p1[0]+"|"+p1[1]);
        System.out.println(ob1.toString());   //converting point to string
        System.out.print("The distance between the 2 points: "+ob.distance(ob1));
        // distance between 2 points
    }
}