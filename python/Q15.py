# Write iterative and recursive routines in Python to compute the GCD of two integers.

import math
def iterative_gcd(div,d): # iterative function
    while d!=0:  # calculating the gcd
        r=div%d
        div=d
        d=r
    return div

def recursive_gcd(div,d):  # recursive finction
    if(d==0):  # base case
        return div
    else:  # recursive case
        return recursive_gcd(d,div%d)
    
a=int(input("Enter first number: "))
b=int(input("Enter second number: "))
print("GCD:")
print("Using iterative routine: ",iterative_gcd(max(a,b),min(a,b))) # calling the iterative function
print("Using recursive routine: ",recursive_gcd(max(a,b),min(a,b))) # calling the recursive function