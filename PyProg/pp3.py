class Avg:
    def __init__(self,name,m1,m2,m3):
        self.name=name
        self.m1=m1
        self.m2=m2
        self.m3=m3

    def avgmarks(self):
        return(self.m3+self.m2+self.m1)/3

    def display(self):
        print("The name of the student : ",self.name)

s1=Avg("Shubendu",98,95,90)
s1.display()
print(f'The avg of the student is : {s1.avgmarks()}')
## The other way to do this prgm is :
#   def __init__(self,marks):
#       self.name=name
#       self.marks=marks
#       
#   def getavg(self):
#       sum=0
#       for val in self.marks:
#           sum+=val
#       print("The avg :",sum/3)
#  s1=Student("Shubendu",[99,90,98])##