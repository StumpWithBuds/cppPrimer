#include <string>
#include <iostream>

struct Person 
{
    // std::string const& getName()    const { return name; }
    // std::string const& getAddress() const { return address; } //这两行等价于下面两行
    const std::string & getName()    const { return name; }
    const std::string & getAddress() const { return address; }
 
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    return os << person.name << " " << person.address;
}

int main()
{
    int a = 1, b = 2;
    int const &c = a;
    const int &d = a;
    // c = b;
    // d = b;
    // std::cout << c << std::endl;    
    // std::cout << d << std::endl;
    return 0;
}