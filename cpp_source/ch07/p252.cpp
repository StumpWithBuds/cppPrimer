#include <iostream>
using namespace std;

class Box {
public:
    double width;
    double length;
    // friend void printWidth( Box box ); // 友元函数在类中声明
    friend void printWidth(Box box) { // 友元函数在类中定义
        cout << "Width of box : " << box.width <<endl;
    }
    void setWidth( double wid );
};

// 友元函数在类外定义
// void printWidth( Box box ) {
//     cout << "Width of box : " << box.width <<endl;
// }

// 友元函数在类外再次声明，这样用户才能调用它
void printWidth( Box box );

void Box::setWidth(double wid) {width = wid;}

int main() {
    Box box;
    box.setWidth(10.0);
    printWidth(box); // 调用友元函数
    return 0;
}
