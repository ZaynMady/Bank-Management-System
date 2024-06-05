#include <string>
#include <exception>



class Balanceerror : std::exception
{
    private: 
    std::string message; 

    public: 
    Balanceerror(const char *msg) : message(msg){}

    const char * what() const throw()
    {
        return message.c_str();
    }
};

class Accounterror : std::exception
{
    private: 
    std::string message; 

    public: 
    Accounterror(const char *msg) : message(msg){}

    const char * what() const throw()
    {
        return message.c_str();
    }
};