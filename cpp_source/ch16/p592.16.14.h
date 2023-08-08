#include <string>
#include <vector>
#include <iostream>

template <unsigned H, unsigned W>
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(char c): contents(H * W, c) {}
    char get() const {
        return contents[cursor];
    }
    Screen &move(pos r, pos c);
    friend std::ostream& operator<< (std::ostream& os, Screen& c) {
        unsigned i , j;
        for (i = 0; i < c.hight; ++i) {
            os << c.contents.substr(0, c.width) << std::endl;
        }
        return os;
    }

    friend std::istream & operator>> (std::istream &is, Screen &  c)
	{
		char a;
		is >> a;
		std::string temp(H*W, a);
		c.contents = temp;
		return is;
	}
    
private:
    pos cursor = 0;
    pos hight = H, width = W;
    std::string contents;

};