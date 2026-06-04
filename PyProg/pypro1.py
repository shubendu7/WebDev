#dice rolling project
#Ask : roll the dice
#If the user enters y
#   generate two random numbers
#   print them
#If user enter n
#   Print thank you message
#   Terminate
#Else
#   print invalid choice
import random
while True:
    choice = input(' Roll the dice? (y/n): ').lower()
    if choice == 'y':
        die1=random.randint(1,6)
        die2=random.randint(1,6)
        print('They rolled : ',die1,die2)
    elif choice == 'n':
        print('Thnx for playing')
        break
    else:
        print('Invald choice')