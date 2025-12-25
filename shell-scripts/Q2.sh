echo "FILE  BEFORE  CONVERSION :"
cat abc.txt
cat abc.txt | tr '[:lower:]' '[:upper:]' > abc1.txt
echo "AFTER CONVERTING THE LOWERCASE LETTERS OF THE FILE INTO UPPERCASE:"
cat abc1.txt
