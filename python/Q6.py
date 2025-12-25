'''6. Write a python script to read a list of words. Join all the words in the odd and even 
indices to form two strings. Use list slicing and join methods'''

l=[]    # taking list from user
print("Enter the list of words. Enter 0 when done")
while True:
    v=input()
    if v=='0':
        break
    l.append(v)
print("The words in even indices: "+" ".join(l[::2]))   # words in even indices
print("The words in odd indices: "+" ".join(l[1::2]))   # words in odd indices

