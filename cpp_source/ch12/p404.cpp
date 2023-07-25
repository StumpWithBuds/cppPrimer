#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <exception>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    // StrBlob(std::initializer_list<std::string> il);
    StrBlob(std::vector<std::string> v);
    size_type size() const {return data->size();} 
    bool empty() const {return data->empty();}
    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back();
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() {}
StrBlob::StrBlob(std::vector<std::string> v): data(std::make_shared<std::vector<std::string>> (v)) {}
void StrBlob::pop_back() {data->pop_back();}
std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();}
std::string& StrBlob::back() {
    check(0, "back on StrBlob");
    return data->back();}
void StrBlob::check(size_type i, const std::string &msg) const {
    if(i > data->size()) {
        throw std::out_of_range(msg);
    }
}
int main() {
    StrBlob b1({"a", "an", "the"});
    b1.push_back("quene");
    std::cout << b1.back() << std::endl;
    std::cout << b1.front() << std::endl;
    return 0;
}