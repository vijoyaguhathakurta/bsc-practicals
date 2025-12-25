<html>
<body>
	<?php 	
	if ($_GET["year"]%4 == 0)
		echo $_GET["name"].", ur birth year is a leap year.";
	  else			
		echo $_GET["name"].", ur birth year is not a leap year.";
	?>
</body>
</html>