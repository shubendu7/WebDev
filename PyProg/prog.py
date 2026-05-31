import math
print(math.floor(3.52))
print('Hello World')
a=10
b=9
c="s"
print(str(a+b)+c)
print("10+9 is ",10+9,c)
for i in range(0,101):
    print(i)

def average(num1,num2):
    arv=(num1+num2)/2
    return arv

print(average(3,6))
index=0;
try:
    print(index)
except Exception as e:
    print(e)