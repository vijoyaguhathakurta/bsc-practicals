/*Create a superclass ‘Person’ and two subclasses ‘Student’ and ‘Staff’. The following
 are the instance variables and methods:
a. For ‘Person’ instance variables: name:String, address:String. Initiate variable 
through constructor, incorporate one method setPerson() that updates Person variables,
 another method tostring() that shows Person details as “Person[Name=?,Address=?”.
b. For ‘Student’ sub class instance variables: program:String, year:String, fees:double.
 Initiate both ‘Student’ and ‘Person’ variables through constructor, incorporate one 
 method setStudent() that updates both student and ‘Person’ data, another method 
 tostring() that shows ‘Person-Student’ details as “Person[Name=?,Address=?,Program=?,
 Year=?,Fees=?”.
c. For ‘Staff’ subclass instance variables: school:String, pay:double. Initiate both 
‘Staff’ and ‘Person’ variables through constructor, incorporate one method setStaff() 
that updates both ‘staff’ and ‘Person’ data, another method tostring() that shows 
‘Person-Staff’ details as “Person[Name=?,Address=?,School=?,Pays=?”.
Write the classes and a test driver main class to test all functions mentioned above.
 */

class Person
{   String name,address; //instance variables of Person
    Person()    // superclass constructor 
    {   name=address="?";    }
    void setPerson(String n,String a) //update Person variables
    {   name=n;
        address=a;     }
    void tostring() // shows Person variables
    {   System.out.print("Person [Name="+name+", Address="+address);   }
}
class Student extends Person    // subclass of Person
{   String year,program;    //instance variables of Student
    double fees;
    Student()   // constuctor of Student
    {   super(); //calling the superclass constructor
        year=program="?";
        fees=0.0;    }
    void setStudent(String n,String a,String y,String p,double f) 
    {   setPerson(n,a); //update Person variables
        program=p;  //update Student's own variables
        year=y;
        fees=f;    }
    void tostring()
    {   super.tostring(); // shows Person variables
        System.out.println(", Program="+program+", Year="+year+", Fees="+fees);   }
}
class Staff extends Person // subclass of Person 
{   String school;  //instance variables of Staff
    double pay;
    Staff() // constuctor of Student
    {   super();    //calling the superclass constructor
        school="?"; 
        pay=0.0;    }
    void setStaff(String n,String a,String s,double p)
    {   setPerson(n,a); //update Person variables
        school=s;   //update Staff's own variables
        pay=p;   }
    void tostring()
    {   super.tostring(); // shows Person variables
        System.out.println(", School="+school+", Pays="+pay);   }
}

class TestPerson {
    public static void main(String[] args) {
        Person pr=new Person(); // creating object of Person
        if (args.length==2)
            pr.setPerson(args[0],args[1]); //set Person variables
        System.out.print("Person: "); pr.tostring(); //calling Person method
        Student sd=new Student();  // creating object of Student
        if(args.length==5)
            //set Student variables
            sd.setStudent(args[0],args[1],args[2],args[3],Double.parseDouble(args[4]));
        System.out.print("\nStudent: "); sd.tostring(); //calling Student method
        Staff sf=new Staff();  // creating object of Staff
        if(args.length==4)
            //set Staff variables
            sf.setStaff(args[0],args[1],args[2],Double.parseDouble(args[3]));
        System.out.print("Staff: "); sf.tostring();  //calling Staff method
    }     
}
