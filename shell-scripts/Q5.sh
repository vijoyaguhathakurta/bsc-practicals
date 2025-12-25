echo -n "ENTER THE INPUT BASE :  "
read x
echo -n "ENTER THE OUTPUT BASE :  "
read y
echo -n "ENTER THE NUMBER TO BE CONVERTED :  "
read n 
echo -n "VALUE OF $n (BASE $x) IN BASE $y = "
echo "ibase=$x ; obase=$y ; $n" | bc
