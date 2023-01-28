/*
main:处理命令行选项
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    cout << argc << endl;
    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;
    cout << "argv[2]: " << argv[2] << endl;
    cout << "argv[3]: " << argv[3] << endl;
    return 0;
}

