#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;}

private:
    void free();

    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }

    void reallocate();

    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
         

private:
    static std::allocator<std::string> alloc;
    
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}