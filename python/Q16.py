"""Create a class named adder with two data: sum and carry, which are initialized to 0.
  Create two subclasses full_adder and half_adder inheriting from adder class and using object initialization of the parent class
  using super() function. Data and methods may be added to the derived classes as appropriate"""

class adder:
    def __init__(self): #initializer
        self.sum=0
        self.carry=0
    def display(self):
        print("SUM=",self.sum,", CARRY=",self.carry,)    
class full_adder(adder):#SUM = (A ⊕ B) ⊕ Cin ; CARRY-OUT = A.B + ( Cin.(A ⊕ B) 
    def __init__(self,a,b,c):   #child class initializer
        super().__init__() #initializing the parent class members by calling its initializer
        self.A=a
        self.B=b 
        self.C=c  
    def show(self):  # displays the current object's values
        print("A=",self.A,"| B=",self.B,"| C=",self.C)     
    def calculate(self):  # performs the calculation
        self.sum=(self.A^self.B)^self.C
        self.carry=self.A & self.B | (self.C & (self.A ^ self.B))    
class half_adder(adder): #Sum = A XOR B ; Carry = A AND B 
    def __init__(self,a,b):   #child class initializer
        super().__init__() #initializing the parent class members by calling its initializer
        self.A=a
        self.B=b    
    def show(self):   # displays the current object's values
        print("A=",self.A,"| B=",self.B)     
    def calculate(self): # performs the calculation
        self.sum=self.A^self.B
        self.carry=self.A & self.B
print("FOR HALF ADDER:\n-----------------")
for i in range(2):
    for j in range(2):  
        obj_ha=half_adder(i,j)  # creating a half_adder class object
        obj_ha.show()       # calling show() of half_adder using obj_ha
        obj_ha.calculate()  # calling calculate() of half_adder using obj_ha
        obj_ha.display()   # calling display() of parent class (adder) using obj_ha 
print("\n\nFOR FULL ADDER:\n-----------------")
for i in range(2):
    for j in range(2): 
        for k in range(2):
            obj_fa=full_adder(i,j,k)   # creating a full_adder class object
            obj_fa.show()  # calling show() of full_adder using obj_fa
            obj_fa.calculate()  # calling calculate() of full_adder using obj_fa
            obj_fa.display()  # calling display() of parent class (adder) using obj_fa 

