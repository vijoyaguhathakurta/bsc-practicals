/*20. Write a program in java with class Employee and do the following operations on it
a) Create two constructor default and with Object as parameter to initialize class variables.
b) Create a function Calculate which calculates the pf and allowances on the salary of employee and 
return the all values as an object. 

Basic salary,
Dearness Allowance,
Duration of employment,

EPF balance = Employee's contribution + Employer's contribution + Interest
Employee's contribution = 12% of (Basic salary + Dearness allowance)
Employer's contribution = 3.67% of (Basic salary + Dearness allowance) + 
                        8.33% of (Basic salary + Dearness allowance) towards Employee Pension Scheme
DA = (Basic Salary + Grade Pay) x DA Rate(15%) / 100
*/

import java.util.*;
class Employee
{   String name;
    double salary,epf,da;
    Employee()  //default constructor
    {   name="Unknown";
        salary=0.0; epf=0.0; da=0.0;      }
    Employee(Employee em)   // constructor with object parameter
    {   name=em.name;
        salary=em.salary;
        epf=em.epf;
        da=em.da;       }
    Employee calculate() // method returning object
    {   da=(15.0/100)*salary;
        epf=(12.0/100)*(salary+da)+(3.67/100)*(salary+da);
        return this;    }
}

class TestEmployee
{   public static void main(String[] args)
    {   Scanner sc=new Scanner(System.in);
        Employee emp=new Employee(); // creating an object
        System.out.print("Enter Employee Name: ");
        emp.name=sc.nextLine();
        System.out.print("Salary: ");
        emp.salary=sc.nextDouble();
        Employee e=new Employee(emp);   // creating new object e with emp values 
        e=e.calculate(); // calling the method
        System.out.println("Employee Name: "+e.name+"\tSalary: "+e.salary+"\t\tDA: "+e.da+"\tEPF: "+e.epf);
    }
}