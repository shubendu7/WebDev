class Student:
    
    clg_name="St Xavier's college"
    #parameterised constructor
    def __init__(self,fullname):#self is pointing to the object only 
        self.name=fullname#self calling the object 
        print(fullname)
        print(self)

s1=Student("Shubendu")#Student is the class name and the () are showing the call of constructor
print(s1.name)# it is printing the type of the object i.e, class type 

s2=Student("William")
print(s2.name)

print (f'{s1.clg_name}')