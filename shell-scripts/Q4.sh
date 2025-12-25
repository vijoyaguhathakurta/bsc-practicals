echo "ENTER THE NUMBERS"
echo -n "X =  "
read x
echo -n "Y =  "
read y
echo "INPUT :  X = $x ,  Y= $y "
x=$(($x+$y))
echo "STEP 1 :  X = $x ,  Y= $y "
y=$(($x-$y))
echo "STEP 2 :  X = $x ,  Y= $y "
x=$(($x-$y))
echo "STEP 3 :  X = $x ,  Y= $y "
echo "FINAL RESULT :  X = $x ,  Y= $y "
