#include <iostream>
#include <string>

class Quote {
public:
	friend bool operator!=(const Quote& lhs, const Quote& rhs);
	Quote() {std::cout << "default constructing Quote\n"; };
	Quote(std::string bn, double p): bookNo(bn), price(p) {std::cout << "Quote : constructor taking 2 parameters\n";}
	Quote(const Quote& q): bookNo(q.bookNo), price(q.price) {std::cout << "Quote: copy constructing\n";}
	Quote& operator=(Quote& q) noexcept {
		if(this != &q) {
			bookNo = q.bookNo;
			price = q.price;
		}
		std::cout << "Quote: copy =() \n";
		return *this;
	}
	Quote(const Quote&& q): bookNo(q.bookNo), price(q.price) {std::cout << "Quote: move constructing\n";}

	Quote& operator=(Quote&& q){
		if (*this != q) {
			bookNo = q.bookNo;
			price = q.price;
			q.bookNo = "";
			q.price = 0.0;
		}
		std::cout << "Quote: move =!!!!!!!!! \n";
		return *this;
	}

    virtual double  net_price(std::size_t n) const { return n * price; }
	std::string getBookNo() {return bookNo;}
private:
	std::string bookNo;
protected:
	double price;
};

bool operator!=(const Quote& lhs, const Quote& rhs) {
	if (lhs.bookNo == rhs.bookNo && lhs.price == rhs.price)
		return true;
	else	
		return false;
}

class Disc_quote: public Quote {
public:
	friend bool operator !=(const Disc_quote& lhs, const Disc_quote& rhs);

    Disc_quote() { std::cout << "default constructing Disc_quote\n"; }
	Disc_quote(std::string bn, double p, std::size_t q, double d):
		Quote(bn, p), quantity(q), discount(d) {}
	Disc_quote(const Disc_quote& dq): Quote(dq), quantity(dq.quantity), discount(dq.discount) {}
	Disc_quote& operator= (Disc_quote& dq) {
		if (*this != dq) {
			Quote::operator=(dq);
			quantity = dq.quantity;
			discount = dq.discount;
		}
		return *this;
	}
	Disc_quote(const Disc_quote&& dq): Quote(dq), quantity(dq.quantity), discount(dq.discount) {
		std::cout << "Disc_quote : move constructor.\n";
	}
	Disc_quote& operator= (Disc_quote&& dq) {
		if(*this != dq) {
			Quote::operator=(dq);
			quantity = dq.quantity;
			discount = dq.discount;
        	std::cout << "Disc_quote : move =()\n";
		}
		return *this;
	}

	virtual ~Disc_quote() = default;

	virtual double net_price(size_t n) const override = 0;
protected:
	std::size_t quantity = 3;
    double      discount = 0.0;
};

bool operator !=(const Disc_quote& lhs, const Disc_quote& rhs) {
	return Quote(lhs) != Quote(rhs)
            &&
            lhs.quantity != rhs.quantity
            &&
            lhs.discount != rhs.discount;
}

class Bulk_quote: public Disc_quote {
public:
	Bulk_quote() {std::cout << "default constructing Bulk_quote\n";}
	Bulk_quote(std::string bn, double p, size_t q, double d):
		Disc_quote(bn, p, q, d) {
		std::cout << "Bulk_quote : constructor taking 4 parameters\n";
	}
	Bulk_quote(const Bulk_quote& bq): Disc_quote(bq) {
		std::cout << "Bulk_quote : copy constructor\n";
	}
	Bulk_quote&operator=(Bulk_quote& bq) {
		Disc_quote::operator=(bq);
		std::cout << "Bulk_quote : copy =()\n";
		return *this;
	}
	Bulk_quote(const Bulk_quote&& bq): Disc_quote(bq) {
		std::cout << "Bulk_quote : move constructor\n";
	}

	double net_price(size_t n) const override {
		return 2.2;
	}

};

int main() {
	// Quote p("123", 3.2);
	// Quote q(std::move(p));
	// std::cout << q.getBookNo() << std::endl;
	// Quote r = p;
	// r = std::move(p);
	// std::cout << r.getBookNo() << std::endl;
	Bulk_quote p("123", 3.2, 2, 2.2);
	Bulk_quote q(p);

	return 0;
}