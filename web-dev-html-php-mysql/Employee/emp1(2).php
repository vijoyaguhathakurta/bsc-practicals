<html>
    <?php
        $conn=mysqli_connect("localhost","root","","employee");	
        if (!$conn)
            die("Sorry we failed to connect: ". mysqli_connect_error());    

        //displaying table description
        $sql="desc employee;";
        $result=mysqli_query($conn,$sql); 
        echo"<table border=1 style='display:inline-table; margin:10px'> 
        <caption>DESCRIPTION OF EMPLOYEE</caption> <tr> <th>Field</th> <th>Type</th> 
        <th>Null</th> <th>Key</th> <th>Default</th><th>Extra</th> </tr>";
        while ($tup=mysqli_fetch_assoc($result))
            echo "<tr><td>".$tup['Field']."</td><td>".$tup['Type']."</td>
                <td>".$tup['Null']."</td><td>".$tup['Key']."</td>
                <td>".$tup['Default']."</td><td>".$tup['Extra']."</td></tr>";   
        echo "</table>";

        $sql="desc dept;";
        $result=mysqli_query($conn,$sql); 
        echo"<table border=1 style='display:inline-table; margin:10px'>
        <caption>DESCRIPTION OF DEPT</caption><tr> <th>Field</th> <th>Type</th>
        <th>Null</th><th>Key</th> <th>Default</th><th>Extra</th> </tr>";
        while ($tup=mysqli_fetch_assoc($result))
        echo "<tr><td>".$tup['Field']."</td><td>".$tup['Type']."</td>
                    <td>".$tup['Null']."</td><td>".$tup['Key']."</td>
                    <td>".$tup['Default']."</td><td>".$tup['Extra']."</td></tr>";   
        echo "</table>";

        $sql="desc works;";
        $result=mysqli_query($conn,$sql); 
        echo"<table border=1 style='display:inline-table; margin:10px'>
        <caption>DESCRIPTION OF WORKS</caption><tr> <th>Field</th> <th>Type</th> 
        <th>Null</th> <th>Key</th> <th>Default</th><th>Extra</th> </tr>";
        while ($tup=mysqli_fetch_assoc($result))
            echo "<tr><td>".$tup['Field']."</td><td>".$tup['Type']."</td>
                    <td>".$tup['Null']."</td><td>".$tup['Key']."</td>
                    <td>".$tup['Default']."</td><td>".$tup['Extra']."</td></tr>";   
        echo "</table>";     

        //Displaying the records
        $sql="select * from dept;";
        $result=mysqli_query($conn,$sql); 
        echo"<hr><table border=2>
        <caption>DEPARTMENT TABLE</caption> <tr> <th>DEPARTMENT_NAME</th> 
        <th>DEPT_NO</th> <th>DEPT_LOCATION</th> </tr>";
        while ($tup=mysqli_fetch_assoc($result))
            echo "<tr><td>".$tup['dname']."</td><td>".$tup['dno']."</td>
                    <td>".$tup['dlocation']."</td></tr>";   
        echo "</table>";
         
        mysqli_close($conn); //Disconnecting     
     ?>       
</html>