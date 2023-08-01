#include <iostream>
#include <deque>
#include <list>

void divide_list(std::list<int> li, std::deque<int>& deq1, std::deque<int>& deq2) {
    for (std::list<int>::iterator iter = li.begin(); iter != li.end(); ++iter) {
        if (*iter % 2 == 0) {
            deq1.emplace_back(*iter);
        }
        else {
            deq2.emplace_back(*iter);
        }
    }
}

template <typename T>
void print(std::deque<T> deq) {
    for (typename std::deque<T>::const_iterator iter = deq.cbegin(); iter != deq.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> li{1,2,3,4,5,6,7,8,9};
    std::deque<int> deq1, deq2;
    divide_list(li, deq1, deq2);
    print<int>(deq1);
    print<int>(deq2);
    return 0;
}