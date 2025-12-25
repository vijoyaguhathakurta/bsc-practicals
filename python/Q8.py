""" 8. Create a list of floats in python. Find the smallest and largest items from the list. 
Also compute the mean, median and variance from the list."""

import numpy as np
l=[]
print("Enter the list of floats. Enter 0 when done.")
while True:
    v=float(input())
    if v==0:
        break
    l.append(v)
print("The smallest item: ",np.min(l),"\nThe largest item: ",np.max(l))
print("Mean:",np.mean(l))
print("Median:",np.median(l))
print("Variance:",np.var(l))
