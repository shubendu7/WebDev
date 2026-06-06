#print all the prime numbers between a range

x=int(input('Enter the value of x : '))
y=int(input('Enter the value of y : '))

print(f'All the prime numbers between {x} and {y}:')

for num in range(x, y + 1):
    if num > 1:
        for i in range(2, int(num**0.5) + 1):# ** means exponential ^ , * means multipilcation 
            if (num % i) == 0:
                break
        else:
            print(num)