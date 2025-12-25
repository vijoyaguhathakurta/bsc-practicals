<html>
    <?php
            if ($_SERVER["REQUEST_METHOD"] == "POST")
            {   $ename=$_POST["ename"];
                $e_id=$_POST["e_id"];
                $address=$_POST["address"];
                $email=$_POST["email"];
                $phno=$_POST["phno"];
                $gender=$_POST["G"];
                $super_id="NULL";
				if (!empty($_POST["super_id"]))
					$super_id=$_POST["super_id"];
                $salary=$_POST["salary"];
				$lang="";
				if(!empty($_POST["lang"]))
					$lang=join(", ",$_POST["lang"]);
                $join_date=$_POST["join_date"];
                $dno=$_POST["dno"];
				$hrs=$_POST["hrs"];
                // Create a connection
                $conn = mysqli_connect("localhost","root","","employee");
                if (!$conn)
                    die("Sorry we failed to connect: ". mysqli_connect_error());  
                $sql="INSERT INTO EMPLOYEE VALUES('$ename', $e_id, '$address', '$email', $phno, '$gender', $super_id, $salary, '$lang', '$join_date');";
                $sql .="INSERT INTO WORKS VALUES($e_id,$dno,$hrs);";
                if(mysqli_multi_query($conn,$sql))
                    echo "<hr>DETAILS INSERTED IN THE DATABASE.";   
                mysqli_close($conn); //Disconnecting   
            }	 ?>	
</html> 