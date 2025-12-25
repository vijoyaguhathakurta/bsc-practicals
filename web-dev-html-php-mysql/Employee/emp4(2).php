<html>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {   $hra=$_POST["hra"];
        $da=$_POST["da"];
        $tax=$_POST["tax"];
        $no=$_POST["no"];
        // Create a connection
        $conn = mysqli_connect("localhost","root","","employee");
        if (!$conn)
            die("Sorry we failed to connect: ". mysqli_connect_error());  
        $sql=" select ename,e_id,$no,salary from employee natural join works order by $no ;";
        $result=mysqli_query($conn,$sql); 
    echo "<table border=2>
    <tr> <th>Employee name</th><th>Employee id</th><th> Order by $no </th> 
     <th>Salary</th> 
    <th>HRA</th><th>DA</th> <th> Professional tax</th> </tr>";
    while ($tup=mysqli_fetch_assoc($result))
        echo "<tr><td>".$tup['ename']."</td><td>".$tup['e_id']."</td> 
        <td>".$tup[$no]."</td><td>".$tup['salary']."</td>
      <td>".($tup['salary']*$hra/100)."</td> <td>".($tup['salary']*$da/100)."</td>
    <td>".($tup['salary']*$tax/100)."</td> </tr>";
    echo "</table><hr>";
    
            mysqli_close($conn); //Disconnecting   
        }
    ?>
</html>