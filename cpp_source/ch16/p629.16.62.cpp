#include <iostream>
#include <unordered_map>

namespace std{
    template<>
    struct hash<Sale_date> {
        typedef size_t result_type;
        typedef Sale_data argument_type;
        size_t operator() (const Sales_data& s) const; 
    };

    size_t hash<Sale_data>::operator() (const Sales_data& s) const {
        return hash<string>() (s.bookNo)^
               hash<unsigned> (s.units_sold)^
               hash<double>() (s.revenue);
    }
}