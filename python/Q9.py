# 9. Write a program to remove duplicate items from a python list of integers

l=[]  # taking the inputs from user
print("Enter the list of items. Enter 0 when done.")
while True:
    v=input()
    if v=='0':
        break
    l.append(v)
r=[]   
for x in l:  # creating a new list r with the elements in l only once
    if x not in r:    # append x if it is not already present in r
        r.append(x)    
l=r
print("The list after removing duplicates: ",l)