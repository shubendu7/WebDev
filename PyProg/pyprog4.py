#Refactoring 
#modulization
#applying this on pyprog3.py

import random

emoji={'r':'🪨','p':'📃','s':'✂️'}#dictionary
choices = ('r','p','s')#tuple

#in this technique we pack definations in a function

def get_user_choice():
    while True:    
        user_choice = input('Rock , Paper or Scissors? (r/p/s):').lower()
        if user_choice in choices:
            return user_choice
        else :
            print('Invalid choice')



def winner_choices(user_choice,computer_choice):
    print(f'You chose {emoji[user_choice]}')
    print(f'Computer chose {emoji[computer_choice]}')

def determine_winner(user_choice,computer_choice):
        if user_choice == computer_choice:
                print('Draw')
        elif ((user_choice=='r' and computer_choice=='s') 
            or 
            (user_choice=='s' and computer_choice=='p') 
            or 
            (user_choice=='p' and computer_choice=='r')):
            print('You Win')
        else:
            print('Computer won')

def game():
    while True:
        user_choice=get_user_choice()
        computer_choice=random.choice(choices)

        winner_choices(user_choice,computer_choice)

        determine_winner(user_choice,computer_choice)

        choice_to_continue=input('Do you wish to continue y/n : ').lower()
        if choice_to_continue=='n':
            break

game()



    
