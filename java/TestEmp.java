/*Create an abstract class employee, having its properties and abstract function for 
calculating net salary and displaying the information. Derive manager and clerk class 
from this abstract class and implement the abstract method net salary and override the
 display method */

abstract class employee
{   String name;
    int id;
    double basicSalary,allowance;
    // The constructor takes the name, id, basic salary and allowance as parameters
    employee(String name, int id, double basicSalary, double allowance)
    {   this.name = name;
        this.id = id;
        this.basicSalary = basicSalary;
        this.allowance = allowance;     } 
    abstract double netSalary(); // The abstract function for calculating net salary 
    void display() // The abstract function for displaying the information
    {   System.out.println("Name: " + name+"\tManager ID: " + id);    }
}
class manager extends employee
{   manager(String name, int id, double basicSalary, double allowance)
     {   super(name, id, basicSalary, allowance); } //calls the superclass constructor
    double netSalary() //implemented method
    {   return basicSalary + allowance - (basicSalary * 0.1);   }
    void display() // overriden method
    {   System.out.println("Manager: Name:" + name+"\t\tID:" + id+"\t\tNet_Salary:" + netSalary());   }
} 
class clerk extends employee
{    clerk(String name, int id, double basicSalary, double allowance) //calls the superclass constructor
     {   super(name, id, basicSalary, allowance);    }
     double netSalary() //implemented method
     {   return basicSalary + allowance - (basicSalary * 0.05);   }
     void display() // overriden method
     {   System.out.println("Clerk: Name:" + name+"\t\tID:" + id+"\t\tNet_Salary:" + netSalary());   }
}
class TestEmp
{   public static void main(String args[])
    {   manager m=new manager(args[0],Integer.parseInt(args[1]),Double.parseDouble(args[2]),Double.parseDouble(args[3]));
        m.display();  //calling manager class methods via its object
        clerk c=new clerk(args[4],Integer.parseInt(args[5]),Double.parseDouble(args[6]),Double.parseDouble(args[7]));
        c.display();  //calling clerk class methods via its object  
    }
}
