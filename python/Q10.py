''' 10. Write a Python program to reverse every Kth row in a matrix. Take the matrix and 
the value of K as input.'''

n=int(input("Enter the no. of rows: "))  
m=int(input("Enter the no. of columns: "))
mat=[]  # taking the matrix from user
print("Enter the elements: ")
for i in range(n):
    l=[]
    for j in range(m):
        l.append(input())
    mat.append(l)
print("The original matrix : ",mat)  
k=int(input("Enter the value of K (row to be reversed) : "))
mat[k-1]=mat[k-1][::-1]  # reversing the Kth row
print("The matrix after reversal: ",mat)