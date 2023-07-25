#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string&, const double);
    virtual ~Quote() = default;

    std::string isbn() const {return bookNo;}
    virtual double net_prices(size_t n) const {return n * price;}
private:
    std::string bookNo;
protected:
    double price;
};

Quote::Quote(const std::string& bn, const double p): bookNo(bn), price(p) {}

class Limit_quote: public Quote{
public:
    Limit_quote() = default;
    Limit_quote(const std::string& bn, const double p, const size_t mq, const double d):
        Quote(bn, p), max_qty(mq), discount(d) {}
    ~Limit_quote() {}

    double net_prices(size_t n) const override;
private:
    std::size_t max_qty = 0;
	double discount = 0.0;

};

double Limit_quote::net_prices(size_t n) const {
    if (n > max_qty)
		return max_qty * price * discount + (n - max_qty) * price;
	else
		return n * discount *price;
}

int main() {
    Limit_quote lq("123456", 3.1, 5, 12);
    std::cout << lq.net_prices(6) <<std::endl;
    return 0;
}