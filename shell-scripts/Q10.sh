function prime()
{
	if [ $1 -eq $2 ]
	then
		echo 0
	elif [ `expr $1 % $2` -eq 0 ]
	then
		echo 1
	else
		i=`expr $2 + 1`
		return prime $1 $i
	fi
}
n=7
i=1
r=`prime $n $i`
echo "$r"
