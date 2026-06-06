class Student:
    def __init__(self, name, marks):
          self.name=name
          self.marks=marks
          
    def getavg(self):
        total_sum = 0
        for val in self.marks:
            total_sum += val
        print(f"The average for {self.name} is: {total_sum / len(self.marks)}")

s1=Student("Shubendu",[99,97,98])
s1.getavg()