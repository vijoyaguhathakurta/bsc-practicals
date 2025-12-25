#7. Write a Python program to get data items from a list appearing odd number of times.

l=[]
print("Enter the list of words. Enter 0 when done")
while True:
    v=input()
    if v=='0':
        break
    l.append(v)
f=0    
print("Data items from a list appearing odd number of times:")

''' if 1 occurence of the item appearing odd no. of times is deleted 
then its occurence will become odd and will not satisfy the condition any further 
thereby repeatation is avoided.'''

for x in l:
    if l.count(x)%2!=0:
        print(x)
        f=1
        l.remove(x)  
if f==0:
    print ("NONE")