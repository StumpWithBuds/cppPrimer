#include <iostream>
#include <string>
using std::string;
using std::cin; 
using std::cout;
using std::endl;

int isspaceExperiment(int ch){
    return isspace(ch);
}

int main(){
    string s("some string");
    cout << s << endl; 
    cout << *(--s.end()) << endl;
    cout << s << endl;
    for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it){
        *it = toupper(*it);
        cout << *it << endl;
    }
    cout << s << endl;
    cout << isspaceExperiment('l') << endl;
    return 0;
}    


