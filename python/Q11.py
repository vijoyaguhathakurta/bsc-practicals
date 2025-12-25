# 11. Write a Python program to remove empty strings from the list of strings.

l=[]  # taking input from user
print("Enter the list of strings. Enter 0 when done")
while True:
    v=input()
    if v=='0':
        break
    l.append(v)
print("Original List: ",l)
for i in range(l.count("")):  # removing all the empty strings
    l.remove("")
print("The list without empty strings: ",l)