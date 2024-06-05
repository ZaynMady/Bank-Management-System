//imported libraries
#include <iostream> 
#include <vector>
#include <string>
#include <exception>
#include "bankexceptions.cpp"
#include <optional>

class account {
//private attributes
private: 
    struct info {
        std::string name; 
        int number;
        std::string email; 
    };
        std::string name; 
        int number;
        std::string email; 

    float balance;

//public methods
public: 

typedef account::info info; 

account(std::string Name, int Age, float Balance, std::string Email)
{
    name = Name; 
    number = Age; 
    balance = Balance; 
    email = Email; 
}
//withdrawing money from the account
void withdraw(float amount)
{
    //check if the amount is available in balance
    if (amount > balance)
    {
        throw Balanceerror("Insufficient Funds");
    }
    else
    {
        balance -= amount;
    }
}
void deposit(float amount)
{
    balance += amount; 
}
float get_balance()
{
    return balance; 
}
info get_info()
{
    info account_info; 
    account_info.name = name;
    account_info.number = number; 
    account_info.email = email; 


    return account_info;
}
void set_info(std::optional<std::string> Name, std::optional<std::string> Email)
{
    if(Name)
    {
        name = Name.value();
    }
    if(Email)
    {
        email = Email.value();
    }
}
void set_acc_num(int num)
{
    number = num;
}
int get_number()
{
    return number;
}
};