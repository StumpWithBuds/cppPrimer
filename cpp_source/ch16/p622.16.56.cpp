#include <iostream>
#include <string>

template <typename... Args>
std::ostream& errorMsg(std::ostream& os, Args& ... rest) {
    return print(os, debug_rep(rest)...);
}
