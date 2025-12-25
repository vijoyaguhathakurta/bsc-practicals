<html>
    <?php
        //Create a connection
        $conn=mysqli_connect("localhost","root","","employee"); 
        if (!$conn)
            die("Sorry we failed to connect: ". mysqli_connect_error());    
        
        //Creating the table
        $sql="create table employee(ename varchar(30),e_id int primary key,
        address varchar(60), email varchar(30),phno long,gender varchar(10),
        super_id int references employee,salary double,lang varchar(30),
        join_date date not null, check (salary>=10000));";
        $sql .="create table dept(dname varchar(30),dno int primary key, dlocation varchar(60));";
        $sql .="create table works(e_id int,dno int,avg_hrs int,primary key(e_id,dno));";
        
        //Inserting the  records in the tables
        $sql .="insert into dept values ('research',1,'Mumbai');";
        $sql .="insert into dept values ('finance',2,'Mumbai');";
        $sql .="insert into dept values ('marketing',3,'Kolkata');";
        $sql .="insert into dept values ('technical',4,'Delhi');";
        $sql .="insert into dept values ('human resource',5,'Kolkata');";
         
        if (mysqli_multi_query($conn, $sql)) 
        {  echo "Tables created and New records inserted successfully!<br>";    }
        else 
        {  echo "Error: " . $sql . "<br>" . mysqli_error($conn);   }
        mysqli_close($conn); //Disconnecting
        ?>
        <br><a href="emp1(2).php">SHOW THE CREATED TABLES</a> 
</html>
