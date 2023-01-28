/*
p233,练习7.4
*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

struct Person{
    Person() = default;
    Person(string name, string address): name(name), address(address){}
    string name = "Ellery";
    string address = "New York";
    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
};

istream &read(istream &is, Person &item){
    is >> item.name >> item.address;
    return is;
}

ostream &print(ostream &os, Person &item){
    os << item.name << endl << item.address;
    return os;
}

int main()
{
    Person el;
    read(cin,el);
    cout << el.getName() << endl;
    cout << el.getAddress() << endl;
    const Person ell;
    cout << ell.getName() << endl;
    cout << ell.getAddress() << endl;
    Person queen("queen", "American");
    print(cout, queen);
    return 0;
}