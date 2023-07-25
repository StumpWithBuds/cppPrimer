/*
委托构造函数
*/

#include <iostream>
#include <string>

// class Sales_data{
//     public:
//         //非委托构造函数使用对应的实参初始化成员
//         Sales_data(std::string s, unsigned cnt, double price):
//             bookNo(s), units_sold(cnt), revenue(cnt * price) { std::cout << "被调用" << std::endl; }
//         //其余构造函数全部都委托给另一个构造函数
//         Sales_data(): Sales_data(" ", 0, 0) {}
//         Sales_data(std::string s): Sales_data(s, 0, 0) { std::cout << "委托构造函数 "  << std::endl; }
    
//     private:
//         std::string bookNo;
//         unsigned units_sold;
//         double revenue;
// };

class Sales_data {
public:
    Sales_data(std::string s, unsigned cnt, double price):
    bookNo(s), units_sold(cnt), revenue(cnt * price){}

    Sales_data(std::string s): Sales_data(s, 0, 0) {}
    Sales_data(unsigned cnt): Sales_data("0", cnt, 0) {}
    std::string getbookNo() {return bookNo;}
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

int main()
{
    // Sales_data sd("12");
    Sales_data sd(8);
    std::cout << sd.getbookNo() << std::endl;
    return 0;
}