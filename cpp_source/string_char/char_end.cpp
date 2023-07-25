#include <iostream>

char *s1 = "asdf";
char s2[5] = "qwer";

int main(){
    // for(int i = 0; i < 5 ; i++){
    //     std::cout << s2[i] << std::endl;
    // }
    // s1++;
    if (s2[4] == '\0')
        printf("the end is \'\\0\'.\n");
    for (int i = 0; i < 5 ; i++) {
        std::cout << s1[i] << std::endl;
    }
    std::cout << s1[10] <<std::endl;
    
    return 0;
}
