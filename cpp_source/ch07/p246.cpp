#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Screen {
    public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd, char c): height(ht), width(wd),
            contents(ht * wd, c) {}
        Screen(pos ht, pos wd, char c): height(ht), width(wd),
            contents(ht * wd, ' ') {}
        char get() const {
            return contents[cursor];
        }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

inline Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}


class Window_mgr{
    private:
        vector<Screen> screen {Screen(24, 80, ' ')};
};


