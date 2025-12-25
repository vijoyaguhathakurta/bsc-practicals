'''12. Sets and dictionaries
a. Use sets to de-duplicate a list of numbers, and a string such that they contain 
only the unique elements
b. Use the set union and intersection operations to implement the Jaccard and 
Cosine similarity of two sets. 
c. Use dictionaries to count the word and letter occurrences in a long string of 
text.
d. Invert a dictionary such the previous keys become values and values keys. 
Eg: if the initial and inverted dictionaries are d1 and d2, where d1 = {1: ‘a’, 2: 
‘b’, 3: 120}, then d2 = {‘a’: 1, 2: ‘b’, 120: 3}. 
e. What if the values in (d) are not immutable? Use frozensets. For repeated 
values, use lists. Eg: if d1 = {1: ‘a’, 2: ‘a’, 4: [1, 2]}, then d2 = {‘a’: [1, 2], 
frozenset([1, 2]): 4}. '''

""" Jaccard Similarity = (number of observations in both sets) / (number in either set)
Or, written in notation form: J(A, B) = |A∩B| / |AUB|

Cosine similarity is a measure of similarity between two non-zero vectors of an inner product space that measures the cosine of the angle between them.
Similarity = (A.B) / (||A||.||B||) where A and B are vectors. 
Example : Consider an example to find the similarity between two vectors – ‘x’ and ‘y’, using Cosine Similarity. 
The ‘x’ vector has values, x = { 3, 2, 0, 5 } The ‘y’ vector has values, y = { 1, 0, 0, 0 } 
The formula for calculating the cosine similarity is : S_C(x, y) = x . y / ||x|| \times ||y||

x . y = 3*1 + 2*0 + 0*0 + 5*0 = 3

||x|| = √ (3)^2 + (2)^2 + (0)^2 + (5)^2 = 6.16

||y|| = √ (1)^2 + (0)^2 + (0)^2 + (0)^2 = 1

∴ S_C(x, y) = 3 / (6.16 * 1) = 0.49 
"""

import math
# a.
l=[]  # taking list from user
print("Enter the list of items. Enter 0 when done.")
while True: 
    v=int(input())
    if v==0:
        break
    l.append(v)
print("a. List containing only the unique elements: ",list(set(l)))  # de-duplicating the list
s=input("Enter a String: ")  # taking the string from user
print("a. String containing only the unique elements: ","".join(set(s)))  # de-duplicationg the string
#b
a=set(l)  # using the user input list as 1st set 
b=set()   # taking the 2nd set from user
print("Enter the 2nd number set. Enter 0 when done.")
while True:
    v=int(input())
    if v==0:
        break
    b.add(v)
j=len(a.intersection(b))/(len(a.union(b)))  # J(A, B) = |A∩B| / |AUB| 
print("b. JACCARD SIMILARITY: ",j)
xy=0 
x1=0
y1=0
for x,y in zip(a,b):
    xy=xy+(x*y)   # sum of XiYi where Xi , Yi represent each item in to a,b resp.
    x1=x1+(x**2)  # sum of Xi^2
    y1=y1+(y**2)  # sum of Yi^2
s_c=xy/(math.sqrt(x1)*math.sqrt(y1)) # S_C(A,B)=sum(AiBi)/[(sqrt(sum(Ai^2)))*(sqrt(sum(Bi^2)))]
print("b. COSINE SIMILARITY: ",s_c)
#c  using the user input string in a
word_count = {}  
for word in s.split():  # fetching each word and counting it
    if word in word_count:  
        word_count[word] += 1
    else:
        word_count[word] = 1
print("\nc. Word Occurrences: ",word_count)
letter_count = {}
for letter in s:   # fetching each letter and counting it
    if letter in letter_count:  
        letter_count[letter] += 1
    else:
        letter_count[letter] = 1
print("c. Letter Occurrences: ",letter_count)
di={}
#d    
for k1,v1 in letter_count.items():  # using the word_count dictionary
    if list(letter_count.values()).count(v1)==1:
        di[v1]=k1   # inverting values and keys
    else:
        k=[key for key in letter_count if letter_count[key]==v1]
        di[v1]=k
print("\nd. Inverted Dictionary (when values are immutable): ",di)
#e
d={}
for k1,v1 in di.items():  # using the letter_count dictionary
    if list(di.values()).count(v1)==1:
        d[frozenset(v1)]=k1
    else:
        k=[key for key in di if di[key]==v1]
        d[v1]=k
print("\nd. Inverted Dictionary (when values are mutable): ",d)
