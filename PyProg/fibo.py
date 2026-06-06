#print the fibonacci series upto a number given by user

n=int(input('Enter the number upto which the series is to be printed : '))

a=0
b=1
c=0
print(f'{a}\n{b}')
while (c<n):
    c=a+b
    a=b
    b=c
    if(c<n):
        print(c)