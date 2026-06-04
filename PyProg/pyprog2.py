#Guess a number between 1 to 100
import random

number_to_guess = random.randint(1, 100)

while True:
    try:
        user_input = int(input('Guess the number between 1 to 100: '))
        if user_input > number_to_guess:
            print('Too high!')
        elif user_input < number_to_guess:
            print('Too low!')
        else:
            print('Congratulations! You guessed the number.')
            break
    except ValueError:
        print('Please enter a valid number')
        