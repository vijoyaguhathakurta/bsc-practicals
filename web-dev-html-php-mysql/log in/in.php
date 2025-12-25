<html>
<body>
	<?php		$a=array("admin"=>"abc1","myadmin"=>"bcd2","okadmin"=>"cde3");
	$k=0;
	foreach($a as $x=>$xv)
	{	if($x===$_GET["ur"] && $xv===$_GET["pw"])
			{$k=1;echo "LOGIN SUCCESSFUL"; break;}
	}
	if($k==0)
	echo "LOGIN UNSUCCESSFUL";
	?>
	
</body>
</html>