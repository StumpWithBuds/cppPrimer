/*
练习题7.12
*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

struct Sales_data {
   //新增的构造函数
   Sales_data() = default;
   Sales_data(const string &s): bookNo(s) {}
   Sales_data(const string &s, unsigned n, double p): 
                bookNo(s), units_sold(n), revenue(p*n){}
   Sales_data(istream &is){
      is >> bookNo >> units_sold >> revenue;
   }
   //新成员
   string isbn() const { return bookNo;}
   Sales_data& combine(const Sales_data&);
   double avg_price() const { return revenue/units_sold; }
   //数据和成员
   string bookNo;
   unsigned units_sold = 0;
   double revenue = 0.0;
};

//Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(ostream&, const Sales_data&);
std::istream &read(istream&, Sales_data&);

istream &read(istream& is, Sales_data &item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream& os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os; 
}

int main()
{
    Sales_data sd("ellery", 3, 4);
    print(cout, sd);
    cout << endl;
    Sales_data sdCin(cin);
    print(cout, sdCin);
    return 0;
}