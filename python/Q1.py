#1. Write a program to input a number in decimal number system and output its Binary,Octal and Hexadecimal equivalent.
n=int(input("Enter the decimal number: "))  #taking user input 
print("OCTAL: ",oct(n)[2:])     #converting to octal
print("BINARY: ",bin(n)[2:])    #converting to binary
print("HEXADECIMAL: ",hex(n)[2:])   #converting to hexadecimal