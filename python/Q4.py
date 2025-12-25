"""4. Write a python script to perform the following operations on complex numbers:
1. Addition of two complex numbers
2. Multiplication of two complex numbers
3. Modulus of a complex number	"""


print("Complex No. 1:") # taking real and imaginary part from user 
a=float(input("Real part: "))
b=float(input("Imaginary part: "))
x=complex(a,b)  # forming the complex number
print("Complex No. 2:")  # taking real and imaginary part from user
a=float(input("Real part: "))
b=float(input("Imaginary part: "))
y=complex(a,b)  # forming the complex number
print("The 2 numbers are: ",x,",",y)
print("Sum = ",(x+y))   # adding the numbers
print("Product = ",(x*y))   # multiplying the numbers
print("Modulus of ",x,"= ",abs(x),"\nModulus of ",y,"= ",abs(y)) # modulus of the numbers
