#include <iostream>
#include <string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string& bn, const double p): 
        bookNo(bn), price(p) {}
    virtual ~Quote() = default; 

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
