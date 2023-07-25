#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    static int unique;

    Employee();
    Employee(const std::string&);
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;

};

int Employee::unique = 0;
Employee::Employee() {unique++;}
Employee::Employee(const std::string& name): name(name) {unique++;}

int main() {
    Employee eply("ellery");
    std::cout << eply.name << std::endl;
    std::cout << eply.unique << std::endl;
    return 0;
}