#include <iostream>
#include <string>
#include <utility>

class Shape {
public:
    typedef std::pair<double, double> Coordinate; 
    Shape() = default;
    Shape(const std::string& n): name(n) {}
    // virtual ~Shape() = default;
    ~Shape() {}

    virtual double area() = 0;
    virtual double perimeter() = 0;
private:
    std::string name;
};

class Rectangle: public Shape {
public:
    Rectangle(const std::string& name, Coordinate a, Coordinate b, Coordinate c, Coordinate d);
    ~Rectangle() = default;
    double area() override;
    double perimeter() override;
private:
    Coordinate a;
    Coordinate b;
    Coordinate c;
    Coordinate d;
};

Rectangle::Rectangle(const std::string& name, Coordinate a, Coordinate b, Coordinate c, Coordinate d):
    Shape(name), a(a), b(b), c(c), d(d) {}

double Rectangle::area() {
    return (b.first - a.first) * (a.second - c.second);
}

double Rectangle::perimeter() {
    return  2 * (b.first - a.first + a.second - c.second);
}

int main() {
    Rectangle rec("rec", {3,2}, {5,2}, {3,1}, {5,1});
    std::cout << rec.area() << std::endl;
    std::cout << rec.perimeter() << std::endl;
    return 0; 
}
