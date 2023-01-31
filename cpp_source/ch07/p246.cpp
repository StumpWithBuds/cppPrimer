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
        Screen(pos ht, pos wd): height(ht), width(wd),
            contents(ht * wd, ' ') {}
        char get() const {
            return contents[cursor];
        }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
        pos size() const;

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
        friend class Window_mgr;
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

Screen::pos Screen::size() const {
    return height * width;
}


class Window_mgr{
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
    private:
        vector<Screen> screen {Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i){
    Screen &s = screen[i];
    s.contents = string(s.height * s.width, ' ');
}


int main()
{
    return 0;
}