#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sales_data {
    public:
        Sales_data() = default;
        Sales_data(string s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) {}
        Sales_data(const string s): bookNo(s) {}
        Sales_data(std::istream &is){
            is >> bookNo >> units_sold >> revenue;
            revenue *= units_sold; 
        }

        string getBookNo() {
            return bookNo;
        }
        
        unsigned getUnit_sold() {
            return units_sold;
        }

        double getRevenue() {
            return revenue;
        }

    private:
        double avg_price() const
            { return units_sold ? revenue / units_sold : 0;}
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

std::ostream &print(std::ostream &os, Sales_data &item){
    os << "bookNO " << " " << item.getBookNo() << endl 
    << "units_sold: " << " " << item.getUnit_sold() << endl
    << "revenue: " << " " << item.getRevenue();
    return os;
}

inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}
    
int main()
{
    Sales_data sd(cin);
    print(cout, sd);
    cout << endl;
    return 0;
}