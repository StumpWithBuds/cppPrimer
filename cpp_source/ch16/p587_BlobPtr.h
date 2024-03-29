#ifndef BlobPtr_h
#define BlobPtr_h

#include "./p584_Blob.h"
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

template <typename T>
class BlobPtr {
public:
    BlobPtr() = default;
    BlobPtr(Blob<T> &a, size_t sz = 0):
        wptr(a.data), curr(sz) {}
    T& operator* () const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++ ();
    BlobPtr& operator++ (int);
    BlobPtr& operator-- ();
    BlobPtr& operator-- (int);
private:
    std::shared_ptr<std::vector<T>> 
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++ () {
    ++curr;
    return *this;
}  

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator-- () {
    --curr;
    return *this;
}  

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++ (int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator-- (int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

#endif