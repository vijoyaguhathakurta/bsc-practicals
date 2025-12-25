function fibo()
{
	if [ $1 -eq 0 ]
	then
		echo 0
	elif [ $1 -eq 1 ]
	then 
		echo 1
	else
		let x=$1-1
		let y=$1-2
		p=`fibo $x`
		q=`fibo $y`
		echo `expr  $p + $q `
	fi
} 
echo -n "ENTER THE RANGE : "
read n
let n=n-1	
i=0
while [ $i -le $n ]
do	
	res=`fibo $i`
	echo "$res"
	let i=i+1
done
