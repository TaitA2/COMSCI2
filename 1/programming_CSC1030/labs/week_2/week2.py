# horse class
class Horse:
    # class initialiaser, takes ranking and value ints as arguments
    def __init__(self, ranking, value):
        # assign private attributes to given arguments
        self.__ranking = ranking
        self.__value = value

    # display method for printing objects ranking and value
    def display(self):
        print(f"The horse at rank: {self.__ranking} is valued at €{self.__value:.2f}.")

# function to run Q1 
def horse_menu():
    # list of horses initialised to include base case 100th place horse
    horses = [Horse(100, 1000)]
    # previous horse value starting at 1000
    prev = 1000
    # multiplier to increase the horses value by each time
    mult = 1.1
    # 99 iteration loop to populate horses list to total 100 horses
    for i in range(1, 100):
        # set rank to count down from 99 to 1
        rank = 100-i
        # calculate horse's value as previous horses value + 10% ( prev * 1.1 )
        value = round(prev*mult,2)
        # add new horse with rank and value to the list of horses
        horses.append(Horse(rank,value))
        # update the previous value to be the current value for use in next iteration
        prev = value
        # menu for the user to enter 3 horse's rankings 
    for _ in range(3):
        # take the rank from user input
        rank = input("Enter a horse's rank: ")
        # give an error if the rank is invalid
        if not rank.isnumeric() and rank != "-1":
            print(f"invalid A horse with rank {rank} was not found!")
        else:
            # cast the user input as an int
            rank = int(rank)
            # list all horse ranks and values from 1 to 100 if user enters -1
            if rank == -1:
                [horse.display() for horse in horses[::-1]]
            # give an error if the rank is not in the list of horses
            elif rank > len(horses) or rank < 1:
                print(f"A horse with rank {rank} was not found!")
            # display the horse at the given rank
            else:
                horses[-rank].display()  

# Q2 function to square every number in a list of numbers
def square_nums(nums):
    return [n**2 for n in nums]


# Q3 function to reverse and uppercase every string in a list of strings
def reverse_upper(strings):
    return [s[::-1].upper() for s in strings]





# Q4
# base bank account class
class BankAccount:
    # initialises private attributes to given arguments with default account type set to "Bank Account"
    def __init__(self, first_name, last_name, balance, account_type="Bank Account"):
        # dictionary of interest rates for each account type
        self.__interest_rates = {"Bank Account": 0.00, "Savings Account": 0.02, "Current Account": 0.01}
        self.__first_name = first_name
        self.__last_name = last_name
        self.__balance = balance
        self.__account_type = account_type
        self.__interest_rate = self.__interest_rates[self.__account_type]

    # method for adding given amount to balance
    def deposit(self, amount):
        self.__balance += amount

    # method for withdrawing given amount from balance if available
    def withdraw(self, amount):
        # checks if balance is sufficient
        if self.__balance >= amount:
            # withdraws the amount
            self.__balance -= amount
        else:
            # prints error if there is insufficient balance
            print("Insufficient funds!")

    # method for printing account balance
    def get_balance(self):
        return self.__balance

    # method for printing account type
    def get_account_type(self):
        return self.__account_type

    # method for applying interest rate to account balance
    def apply_interest(self, i):
        # print an error if the interest rate is wrong for the given account type
        if float(i) != self.__interest_rate:
            print("Invalid interest rate!")
        else:
            # increase the balance by interest rate
            self.__balance *= 1+self.__interest_rate

# savings account class inheriting from BankAccount
class SavingsAccount(BankAccount):
    def __init__(self, first_name, last_name, balance):
        # initialise parent class with "Savings Account" as account type kwarg
        super().__init__(first_name, last_name, balance, account_type="Savings Account")

# current account class inheriting from BankAccount
class CurrentAccount(BankAccount):
    def __init__(self, first_name, last_name, balance):
        # initialise parent class with "Current Account" as account type kwarg
        super().__init__(first_name, last_name, balance, account_type="Current Account")












# run the various programmes if this file is run as main
if __name__ == "__main__":
    #Q1
    horse_menu()

    #Q2
    squared = square_nums([1,2,3,4,5,6,7,8,9,10])
    print(squared)

    #Q3
    converted = reverse_upper(["abc", "cat", "string with spaces"]) 
    print(converted)

    #Q4-6
    account = BankAccount("first", "last", 50)
    savings = SavingsAccount("john", "smith", 100)
    current = CurrentAccount("mary", "hill", 990)
    print(account.get_account_type())
    print(savings.get_account_type())
    print(current.get_account_type())
    savings.apply_interest(.02)
    current.apply_interest(.01)
    savings.deposit(100)
    current.deposit(300)
    print(savings.get_balance())
    print(current.get_balance())
    savings.withdraw(10)
    print(savings.get_balance())

