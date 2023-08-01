#ifndef Blob_h
#define Blob_h

#include <iostream>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>

template <typename T>
class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    bool empty() const {return data->size();}
    void push_back(const T &t) {data->push_back(t);}
    void push_back(T &&t) {data->push_back(std::move(t));}
    void pop_back();
    T& back();
    T& operator[] (size_type i);
    size_type size() const {return data->size();}
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[] (size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "back on empty Blob");
    data->pop_back();
}

template <typename U>
Blob<U>::Blob(): data(std::make_shared<std::vector<U>> ()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>> (il)) {}

#endif
