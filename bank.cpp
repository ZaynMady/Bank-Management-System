#include "account.cpp"
#include <vector>
#include <iostream> 
#include "bankexceptions.cpp"


class bank
{
public:

//deposit to the account 

void deposit_to_account(int number, double amount)
{
    account * acc; 
    try{acc = find_account(number);}
    catch(Accounterror err)
    {
        std::cout << err.what() << std::endl;
    }

    acc->deposit(amount);

    
}
void withdraw_from_account(int number, double amount)
{
    account * acc; 
    try{acc = find_account(number);}
    catch(Accounterror err)
    {
        std::cout << err.what() << std::endl;
    }
    try{acc->withdraw(amount);}
    catch(Balanceerror err)
    {
        std::cout << err.what() << std::endl;
    }

}

    account* find_account(int number) const
{
    for (auto acc : accounts)
    {
        if (acc.get_number() == number)
        {
            return &acc;
        }
    }
    throw Accounterror("Account Does not exist");
}

std::vector<account> accounts;
};