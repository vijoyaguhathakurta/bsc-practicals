<html><center>
  <?Php
    $conn=mysqli_connect("localhost","root","","employee");//create a connection
    if (!$conn)
      die("sorry we failed to connect: ". mysqli_connect_error());    
    //a
    $sql="select * from employee natural join works natural join dept;";
    $result=mysqli_query($conn,$sql); 
    echo "<table border=2><caption>EMPLOYEE AND THEIR DEPARTMENT DETAILS</caption>
    <tr> <th>Employee name</th><th>Employee id</th><th>Address</th> <th>Email</th>
    <th>Phone no.</th> <th>Gender</th> <th>Super's id</th><th>Salary</th>
    <th>Languages</th><th>Joining_date</th> <th>Avg_Work_Hours</th><th>Dept no.</th>
    <th>Department name </th> <th>Department location</th> </tr>";
    while ($tup=mysqli_fetch_assoc($result))
        echo "<tr><td>".$tup['ename']."</td><td>".$tup['e_id']."</td> 
      <td>".$tup['address']."</td><td>".$tup['email']."</td> <td>".$tup['phno']."</td>
      <td>".$tup['gender']."</td> <td>".$tup['super_id']."</td>
    <td>".$tup['salary']."</td> <td>".$tup['lang']."</td><td>".$tup['join_date']."</td>
    <td>".$tup['avg_hrs']."</td><td>".$tup['dno']."</td> <td>".$tup['dname']."</td>
    <td>".$tup['dlocation']."</td> </tr>";
    echo "</table><hr>";
    //b
    $sql="select distinct salary from employee;";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>DISTINCT SALARIES</caption>";
    while ($tup=mysqli_fetch_assoc($result))
        echo "<tr><td>".$tup['salary']."</td></tr>"; 
    echo "</table>";
    //c
    $sql=" select dname,max(salary), min(salary), avg(salary) from employee 
    natural join works natural right outer join dept group by dno;";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>SALARIES OF EACH DEPARTMENT</caption><th>Department</th>
    <th>Maximum Salary</th><th>Minimum Salary</th><th>Average Salary</th>";
    while ($tup=mysqli_fetch_assoc($result))
        echo "<tr><td>".$tup['dname']."</td><td>".$tup['max(salary)']."</td><td>".$tup['min(salary)']."</td> <td>".$tup['avg(salary)']."</td></tr>";
    echo "</table>";
    //d
    $sql=" select  e.ename as ename,e.e_id as e_id,s.ename as sname,s.e_id as s_id
     from employee as e left outer join employee as s on e.super_id=s.e_id; ";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>EMPLOYEES AND THEIR SUPER</caption> <tr> <th>Employee name</th>
    <th>Employee id</th><th>Super name</th> <th>Super id</th> </tr>";
    while ($tup=mysqli_fetch_assoc($result))
       echo "<tr><td>".$tup['ename']."</td><td>".$tup['e_id']."</td> <td>".$tup['sname']."</td><td>".$tup['s_id']."</td></tr>";
    echo "</table>";
    //e
    $sql="select * from employee where salary<(select max(salary) from employee where 
    salary in ((select salary from employee) except (select max(salary) from employee)));";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>THE EMPLOYEES WHOSE SALARIES ARE LESS THAN SECOND HIGHEST SALARY</caption> 
    <tr> <th>Employee name</th> <th>Employee id</th><th>Salary</th> </tr>";
    while ($tup=mysqli_fetch_assoc($result))
       echo "<tr><td>".$tup['ename']."</td><td>".$tup['e_id']."</td> <td>".$tup['salary']."</td></tr>";
    echo "</table><hr>";
    //f
    $sql="select dno,dname,count(e_id) from works natural join dept group by dno;";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>THE DEPARTMENTS HAVING EMPLOYEES ALONG WITH THE COUNT OF EMPLOYEES IN THAT DEPARTMENT</caption> 
    <tr> <th>Deaprtment name</th>
    <th>Department no.</th><th>Count of Employees</th> </tr>";
    while ($tup=mysqli_fetch_assoc($result))
       echo "<tr><td>".$tup['dname']."</td><td>".$tup['dno']."</td> <td>".$tup['count(e_id)']."</td></tr>";
    echo "</table>";
    //g
    $sql="select ename from employee where salary>(select max(salary) from
     employee natural join works where dno=3);";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>THE NAMES OF EMPLOYEES WHOSE SALARY IS GREATER THAN THE HIGHEST SALARY IN DEPARTMENT 3 </caption>";
    while ($tup=mysqli_fetch_assoc($result))
       echo "<tr><td>".$tup['ename']."</td></tr>";
    echo "</table>";
    //h
    $sql="select ename,e_id from works natural join employee where dno in (2,4,5);";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>EMPLOYEES WHO WORK IN EITHER DEPARTMENT 2,4,5</caption>
    <tr> <th>Employee name</th><th>Employee id</th></tr>";
    while ($tup=mysqli_fetch_assoc($result))
       echo "<tr><td>".$tup['ename']."</td><td>".$tup['e_id']."</td></tr>";
    echo "</table>";
    //i
    $sql="select dno,sum(avg_hrs) from works group by dno;";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>THE SUM OF AVERAGE DAILY WORKING HOURS OF EMPLOYEES IN EACH INDIVIDUAL DEPARTMENT</caption>
    <tr> <th>Department No.</th><th>Avg Hours</th></tr>";
    while ($tup=mysqli_fetch_assoc($result))
       echo "<tr><td>".$tup['dno']."</td><td>".$tup['sum(avg_hrs)']."</td></tr>";
    echo "</table>";
    //j
    $sql="select ename from employee where ename like 'M____%';";
    $result=mysqli_query($conn,$sql);
    echo "<table border=1 style='display:inline-table; margin:10px'>
    <caption>THE EMPLOYEE NAME/S HAVING ATLEAST 5 CHARACTERS AND STARTS WITH M</caption>";
    while ($tup=mysqli_fetch_assoc($result))
       echo "<tr><td>".$tup['ename']."</td></tr>";
    echo "</table><hr>";
   
   
    mysqli_close($conn); //disconnecting     
    ?>              
</center></html>


