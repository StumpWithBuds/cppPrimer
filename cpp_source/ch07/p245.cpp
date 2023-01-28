/*
p245 可变数据成员
*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Screen{
    public:
        Screen(size_t ac): access_ctr(ac) {}
        void some_member() const;
        size_t getAccess_ctr(){
            return access_ctr;
        }
    private:
        mutable size_t access_ctr;
};

void Screen::some_member() const {
    ++access_ctr;
}

int main()
{
    Screen scr(0);
    scr.some_member();
    cout <<  scr.getAccess_ctr() << endl;
    scr.some_member();
    cout <<  scr.getAccess_ctr() << endl;
    scr.some_member();
    cout <<  scr.getAccess_ctr() << endl;
    scr.some_member();
    cout <<  scr.getAccess_ctr() << endl;
    return 0;
}