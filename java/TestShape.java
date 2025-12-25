/*interface drawing
{
    void draw();
    
}*/
interface Shape //extends drawing
{   double pi=3.14; //constant value that can be used by implementing classes
    void draw();  // methods to be implemented
    double getArea();   }
class Circle implements Shape
{   double r;
    Circle(double p)
    {   r=p;    }
    public void draw() // implementing the interface method
    {   System.out.println("Circle is drawn");  }
    public double getArea() // implementing the interface method
    {   return pi*r*r;  }
}
class Rectangle implements Shape
{   double l,b;
    Rectangle(double a,double c)
    {   l=a;
        b=c;    }
    public void draw() // implementing the interface method
    {   System.out.println("Rectangle is drawn");   }
    public double getArea() // implementing the interface method
    {   return b*l;     }
}
class TestShape 
{   public static void main(String[] args)
    {   Circle c= new Circle(Double.parseDouble(args[0])); //creating objects
        Rectangle r=new Rectangle(Double.parseDouble(args[1]),Double.parseDouble(args[2]));
        Shape s; // reference of shape interface
        s=c; // s points to Circle object
        s.draw();
        System.out.println("Circle Area :"+s.getArea());
        s=r;    // s points to Rectangle object
        s.draw();
        System.out.println("Rectangle Area :"+s.getArea());    
    }
}

