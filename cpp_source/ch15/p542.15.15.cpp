#include <iostream>
#include <string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string& bn, const double p): 
        bookNo(bn), price(p) {}
    virtual ~Quote() = default; 

    virtual double net_prices(const size_t n) const {return n * price;}

    virtual void debug() const {
        std::cout << "data members of this class:\n"
              << "bookNo= " <<this->bookNo << " "
              << "price= " <<this->price<< " ";
    }
private:
    std::string bookNo;
protected:
    double price;
};

class Disc_quote: public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& bn, double price, size_t qty, double disc):
        Quote(bn, price), quantity(qty), discount(disc) {}
    double net_prices(const size_t n) const = 0;
private:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote: public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& bn, double price, size_t qty, double disc):
        Disc_quote(bn, price, qty, disc) {}
    
    double net_prices(const size_t n) const override;
};

double Bulk_quote::net_prices(const size_t n) const {
    std::cout << "147258369" << std::endl;
    return 1.23;
}

int main() {
    Bulk_quote bq("123456789", 3.1, 2, 1.2);
    std::cout << bq.net_prices(5) << std::endl;
    // Disc_quote dq("123456789", 3.1, 2, 1.2); //不能定义一个抽象基类的变量
    return 0;
}