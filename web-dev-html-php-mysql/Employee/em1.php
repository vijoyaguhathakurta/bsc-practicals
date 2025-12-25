<html>
    <?php
        //Create a connection
        $conn=mysqli_connect("localhost","root","","employee"); 
        if (!$conn)
        {    die("Sorry we failed to connect: ". mysqli_connect_error());    }
        $sql="CREATE TABLE EMPLOYEE(ENAME VARCHAR(30),E_ID INT PRIMARY KEY,
                ADDRESS VARCHAR(60), EMAIL VARCHAR(30),PHNO LONG,GENDER VARCHAR(10),
                SUPER_ID INT REFERENCES EMPLOYEE,SALARY DOUBLE,LANG VARCHAR(30),JOIN_DATE DATE NOT NULL,
                DNO INT REFERENCES DEPT,
                CHECK (SALARY>=10000));";
        if(mysqli_query($conn,$sql))
        {    echo "The employee table was created successfully!<br>"; }
        else
        {   echo "ERROR:". mysqli_error($conn); }
        $sql="CREATE TABLE DEPT(DNAME VARCHAR(30),DNO INT PRIMARY KEY,
              DLOCATION VARCHAR(60));";
        if(mysqli_query($conn,$sql))
        {    echo "The department table was created successfully!<br>"; }
        else
        {   echo "ERROR:". mysqli_error($conn); }
        //Inserting the 5 records in the table
        $sql ="INSERT INTO DEPT VALUES ('RESEARCH',1,'MUMBAI');";
        $sql .="INSERT INTO DEPT VALUES ('FINANCE',2,'MUMBAI');";
        $sql .="INSERT INTO DEPT VALUES ('MARKETING',3,'KOLKATA');";
        $sql .="INSERT INTO DEPT VALUES ('TECHNICAL',4,'DELHI');";
        $sql .="INSERT INTO DEPT VALUES ('HR',5,'KOLKATA');";
        if (mysqli_multi_query($conn, $sql)) 
        {  echo "New records created successfully!<br>";    }
        else 
        {  echo "Error: " . $sql . "<br>" . mysqli_error($conn);   }
        mysqli_close($conn); //Disconnecting
        //Create a connection
        $conn=mysqli_connect("localhost","root","","employee");	
        if (!$conn)
        {    die("Sorry we failed to connect: ". mysqli_connect_error());    }
        //Displaying the records
        $sql="SELECT * FROM DEPT;";
        $result=mysqli_query($conn,$sql); 
        echo "<hr><h3><u>RECORDS IN THE DATABASE:</u></h3><br> <table border=1>
             <tr> <th>DEPARTMENT NAME</th> <th>DEPARTMENT NO.</th> 
             <th>DEPARTMENT LOCATION</th> </tr>";
        while ($tup=mysqli_fetch_assoc($result))
           echo "<tr><td>".$tup['DNAME']."</td><td>".$tup['DNO']."</td>
            <td>".$tup['DLOCATION']."</td> </tr>";   
        mysqli_close($conn); //Disconnecting     ?>
    </table>
</html>
