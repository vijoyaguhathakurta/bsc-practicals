echo -n "PRESENT WORKING DIRECTORY :  "
pwd
ls -l > ff.txt
> ASSIGN_1_output.txt
echo "THE DETAILS OF ALL FILES WHOSE NAME START WITH THE LETTER “D” IN THE PRESENT DIRECTORY : "
while read line
do
	fname=`echo $line | cut -d" " -f 9 | grep -i "^D"`
	if [ $fname ]
	then 
		echo "$line" >> ASSIGN_1_output.txt		
	fi	
done < ff.txt
cat  ASSIGN_1_output.txt
