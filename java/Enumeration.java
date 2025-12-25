enum Week{ // An enumeration of week's days
   Sun,Mon,Tue,Wed,Thr,Fri,Sat    }
class Enumeration
{   public static void main(String args[])
    {   Week wk=Week.valueOf(args[0]);
        switch(wk) // Use an enum to control a switch statement.
        {   case Sun:
                System.out.println("Today is Sunday.");
                break;
            case Mon:
                System.out.println("Today is Monday.");
                break;
            case Tue:
                System.out.println("Today is Tuesday.");
                break;
            case Wed:
                System.out.println("Today is Wednesday.");
                break;
            case Thr:
                System.out.println("Today is Thrusday.");
                break;
            case Fri:
                System.out.println("Today is Friday.");
                break;
            case Sat:
                System.out.println("Today is Saturday.");
                break;
        }
    }
}