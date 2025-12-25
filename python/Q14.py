"""14. Write iterative and recursive routines in Python to compute Fibonacci series upto nth 
term."""

def iterative_fibonacci(n):  # iterative function 
    a=0
    b=1
    for i in range(n):  # generating the series
        print(a)
        c=a
        a=b
        b+=c
    
def recursive_fibonacci(a,b,n): # recursive function
    if n==0:  # base case
        return
    else:  # recursive case
        print(a)
        return recursive_fibonacci(b,a+b,n-1)
        
n1=int(input("Enter n: "))
print("Fibonacci Series:\nUsing iterative routine: ")
iterative_fibonacci(n1)  # calling the iterative function
print("Using recursive routine")
recursive_fibonacci(0,1,n1)  # calling the recursive function