"""13. 
Compute the sum of the following series upto nth term 
    1-x+(x^2)/2!-(x^3)/3!+(x^4)/4!...
 
 """

import math
x=int(input("Enter x: "))  # taking x from user
n=int(input("Enter n: ")) # taking n from user
s=0
for i in range(n):  # finding the sum using general formula
    s=s+(((-1)**i)*((x**i)/math.factorial(i)))  # sum=summation[((-1^i)*(x^i))/i!)] where i=0 to n-1
print("The Sum of the series: ",s)