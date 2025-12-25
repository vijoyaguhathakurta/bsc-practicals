echo "ENTER THE CO-ORDINATES OF THREE POINTS."
echo -n " x1= "
read x1
echo -n " y1= "
read y1
echo -n " x2= "
read x2
echo -n " y2= "
read y2
echo -n " x3= "
read x3
echo -n " y3= "
read y3
echo "Point 1 = ( $x1 , $y1 )"
echo "Point 2 = ( $x2 , $y2 )"
echo "Point 3 = ( $x3 , $y3 )"
a=`echo "scale=4 ; sqrt((($x2 - $x1) ^ 2)+(($y2 - $y1) ^ 2))" | bc`
b=`echo "scale=4 ; sqrt((($x3 - $x2) ^ 2)+(($y3 - $y2) ^ 2))" | bc`
c=`echo "scale=4 ; sqrt((($x3 - $x1) ^ 2)+(($y3 - $y1) ^ 2))" | bc`
s1=`echo "scale=4 ; $a + $b" | bc`
s2=`echo "scale=4 ; $b + $c" | bc`
s3=`echo "scale=4 ; $a + $c" | bc`
if [ $s1 -gt $c -o $s2 -gt $a -o $s3 -gt $b ]
then
	echo " $a $b $c $s1 $s2 $s3 Yes"
else
	echo "No"
fi
