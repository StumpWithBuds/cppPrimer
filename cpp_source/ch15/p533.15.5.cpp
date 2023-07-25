#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& bn, const double p): bookNo(bn), price(p) {}
    virtual ~Quote() = default;

    std::string isbn() const {return bookNo;}
    virtual double net_price(const size_t n) const {return n * price;}
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& bn, const double p, const size_t min_qty, const double discount):
        Quote(bn,p), min_qty(min_qty), discount(discount) {}
    ~Bulk_quote() = default;
    double net_price(const size_t n) const override;
private:
    size_t min_qty;
    double discount;
};

double Bulk_quote::net_price(const size_t n) const {
    if (n >= min_qty)
        return n * (1 - discount) * price;
    else 
        return n * price;
}

double print_total(std::ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << "# sold: " << n << "total due: " << ret << std::endl;
    return ret; 
}

int main() {
    Quote q("textbook", 10.60);
	Bulk_quote bq("textbook", 10.60, 10, 0.3);

	print_total(std::cout, q, 12);
	print_total(std::cout, bq, 12);

	return 0;
}