#include <iostream>
#include "Sales_data.h"
#include <string>

int main(){
    Sales_data data1, data2;
    double price;
    std::cout << "input the bookNo and units_sold" << std::endl;
    std::cin >> data1.bookNO >> data1.units_sold >> data2.bookNO >> data2.units_sold;
    std::cout << "input the price" << std::endl;
    std::cin >> price;
    data1.revenue = data1.units_sold * price;
    data2.revenue = data2.units_sold * price;
    if(data1.bookNO == data2.bookNO){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNO << "  " << totalCnt << "  " << totalRevenue << "  ";
        if(totalCnt != 0){
            std::cout << totalRevenue/totalCnt << std::endl;
        }
        else{
            std::cout << " (no sales) " << std::endl;
        }
        return 0;
    }
    else{
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}