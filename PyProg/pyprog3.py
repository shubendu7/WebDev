import random
emoji={'r':'🪨','p':'📃','s':'✂️'}#dictionary
choices = ('r','p','s')#tuple

while True:
    user_choice = input('Rock , Paper or Scissors? (r/p/s):').lower()
    #if user_choice != 'r' and user_choice != 'p' and user_choice != 's':

    if user_choice not in choices:
        print('Invalid choice')
        continue
     
    computer_choice = random.choice(choices)

    print(f'You chose {emoji[user_choice]}')
    print(f'Computer chose {emoji[computer_choice]}')

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
    choice_to_continue=input('Do you wish to continue y/n : ').lower()
    if choice_to_continue=='n':
        break
