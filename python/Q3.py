#3. Write a python script to read the (x,y) coordinates of three points and test whether they form a triangle or not. Determine the type of the triangle if they form one.
import math 
print("Enter the 3 points of triangle")
x1=float(input("x1:"))
y1=float(input("y1:"))
x2=float(input("x2:"))
y2=float(input("y2:"))
x3=float(input("x3:"))
y3=float(input("y3:"))
d1=round(math.sqrt(((x2-x1)**2)+((y2-y1)**2)),4)    # distance between (x1,y1) and (x2,y2)
d2=round(math.sqrt(((x3-x1)**2)+((y3-y1)**2)),4)    # distance between (x1,y1) and (x3,y3)
d3=round(math.sqrt(((x2-x3)**2)+((y2-y3)**2)),4)    # distance between (x3,y3) and (x2,y2)
if d1+d2>d3 and d2+d3>d1 and d1+d3>d2:  #triangle checking (sum of 2 sides is greater than the 3rd side)
    print("The points form a triangle.The length of sides are: ",d1,",",d2,",",d3) 
    if d1==d2 and d2==d3: # if all sides are equal 
        print("Equilataral Triangle")
    elif d1==d2 or d2==d3 or d1==d3:    #if any 2 sides are equal
        print("Isosceles Triangle")  
    else:   # if all sides are unequal
        print("Scalene Triangle")
else:
     print("The points do not form a triangle.")   





