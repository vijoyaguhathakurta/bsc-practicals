echo  -n "ENTER THE FILENAME :  "
read file
grep -E -o '\w+' $file > ab.txt
echo "FREQUENCY OF EACH WORD STORED IN $file : "
while read word
do
	echo -n "$word : "
	grep -c $word $file	
done < ab.txt
echo -n "TOTAL WORDS IN $file :  "
wc -w $file
