#include <iostream>

enum Week {MON, TUE, WED, THU, FRI, SAT, SUN};

int main(){
    enum Week A = THU;
    Week B = TUE;
    std::cout << A << std::endl;
    std::cout << MON << std::endl;
    std::cout << B << std::endl;
    return 0;
}