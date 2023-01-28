#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef int arrT[10];
using arrU = int[10];

int main()
{
    arrT arr = {11,12,13};
    for (auto pre : arr){
        cout << pre << " ";
    }
    cout << endl;
    arrU arru = {1,2,3};
    for (auto pre : arru){
        cout << pre << " ";
    }
    cout << endl;
    return 0;
}