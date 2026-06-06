class Student:
    clg_name="St Xavier's College"
    name="Anonymous"

    def __init__(self,name,marks):
        self.name=name
        self.marks=marks

    def welcome(self):
        print("Welcome Student : ",self.name)
    
    def getmarks(self):
        return self.marks
    
s1=Student("Shubendu",47)
s1.welcome()
print(s1.getmarks())