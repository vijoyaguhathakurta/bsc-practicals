echo -n " ENTER THE FILENAME : "
read file
echo -n " ENTER THE STARTING LINE NUMBER [n1] : "
read n1
echo -n " ENTER THE ENDING LINE NUMBER [n2] : "
read n2
i=1
echo "OUTPUT :"
while read line 
do
	if [ $i -ge $n1 -a $i -le $n2 ]
	then
		echo "$line"
	fi
	let i=i+1
done < $file
