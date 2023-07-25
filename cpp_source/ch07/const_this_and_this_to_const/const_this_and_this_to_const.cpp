#include <iostream>
#include <cstring>
using namespace std;

class Person {
public:
    Person():age(0), gender(0), name("null"){}
    Person(int age, int gender):age(age), gender(gender), name("null"){}
    Person(int age, int gender, string name): age(age), gender(gender), name(name){}
    ~Person() {
        cout << "destroy done" <<endl;
    }
    int getAge() {return age;}
    int getGender() {return gender;}
    // string getName() {return name;}
    string getName() const;
private:
    int age;
    int gender;
    string name;
};

string Person::getName() const {return name;}

int main() {
    Person sasuka(19, 1, "sasuka");
    const Person naruto(19, 1, "naruto");
    string sasukaName = sasuka.getName();
    string narutoName = naruto.getName();
    cout << sasukaName << endl;
    cout << narutoName << endl; // 这行代码会出错，因为naruto是一个const的对象，在成员函数getName中，return name实际上是return this->name
    //而this是const pointer,而非pointer to const。假如this可以指向一个const对象，就说明可以通过这个this更改这个对象里的数据成员，显然这是错误的。
    // 解决办法就是在定义和声明getName的参数表后加上const, 以表明this是一个pointer to const。
    return 0;
}
