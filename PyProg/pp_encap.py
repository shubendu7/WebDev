class Account:

    def __init__(self,bal,acc):
        self.accountno=acc
        self.balance=bal

    def debit(self):# - from acc
        debit_amt=int(input('Enter the amount you want to debit : '))
        self.balance-=debit_amt
        print('Debit successfull')
    
    def credit(self):# + to the acc
        credit_amt=int(input('Enter the amount you want to credit : '))
        self.balance+=credit_amt
        print('Credit successfull')

    def display(self):
        ch=input('You want a receipt (y/n) : ').lower()
        if(ch=='y'):
            print(f'=== Account no. : {self.accountno} ===\n=== Available balance : {self.balance} ===')
        elif(ch=='n'):
            print('===Thank you===')


acc=int(input('Enter your Account no. : '))
bal=int(input('Enter your balance : '))
A1=Account(bal,acc)
choice=input('You want to debit or credit? (D/C) : ').upper()
if(choice=='D'):
    A1.debit()
    A1.display()
elif(choice=='C'):
    A1.credit()
    A1.display()
else:
    print('Invalid')
