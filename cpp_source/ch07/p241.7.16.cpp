#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sales_data{
    friend std::istream &read(std::istream &, Sales_data & );
    friend std::ostream &print(std::ostream &, Sales_data & );
    public:
        Sales_data() = default;
        Sales_data(string &s):bookNo(s) {}
        Sales_data(string &s, unsigned n, double p): bookNo(s), unit_sold(n), revenue(n*p) {}
        Sales_data(std::istream &is){
            is >> bookNo >> unit_sold >> revenue;
            revenue *= unit_sold;
        }
    private:
        string bookNo;
        unsigned unit_sold = 0;
        double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item){
    is >> item.bookNo >> item.unit_sold >> item.revenue;
    item.revenue *= item.unit_sold;
    return is;
}
std::ostream &print(std::ostream &os, Sales_data &item){
    os << item.bookNo << "  " << item.unit_sold << " " << 
    item.revenue;
    return os; 
}

int main()
{
    Sales_data sd(cin);
    print(cout, sd);
    return 0;
}