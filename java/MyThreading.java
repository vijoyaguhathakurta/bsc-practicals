class newThread implements Runnable
{   Thread t;
    newThread() // defining a new thread
    {   t=new Thread(this,"NewThread");
        System.out.println("The child thread: "+t);
        t.start();    } //start the thread
    public void run()   //statements to be executed by child thread
    {   try
        {   for(int n=5;n>0;n--)
            {   System.out.println("The child thread: "+n);
                Thread.sleep(500);  }   }
        catch(InterruptedException e)
        {   System.out.println("Interruption caused: "+e);  }
        System.out.println("Exiting child thread: "+t);        
    }
}
class MyThreading 
{   public static void main(String[] args)
    {   Thread t=Thread.currentThread();
        System.out.println("The main thread: "+t);
        new newThread();    //creating a new thread
        try{ //statements to be executed by main thread
           for(int n=5;n>0;n--)
            {   System.out.println("The main thread: "+n);
                Thread.sleep(1000);    }
        }
        catch(InterruptedException e)
        {   System.out.println("Interruption caused: "+e);  }
        System.out.println("Exiting main thread: "+t);        
    }
}
    


