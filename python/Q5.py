'''5. Write a python script to read two strings from the user and print a new string 
where the first string is reversed, and the second string is converted to upper case. 
Sample strings: “Pets“, “party”, output: “steP PARTY”. 	 	 	 	 	 	 
[Only use string slicing and + operators.]'''
# taking the two strings as user inputs
s1=input("String 1: " )
s2=input("String 2: " )
# reversing the string 1 and converting string 2 to uppercase
print(s1[::-1]+" "+s2.upper())