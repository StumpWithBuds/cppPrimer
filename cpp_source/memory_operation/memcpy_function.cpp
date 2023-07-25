#include <iostream>
#include <stdlib.h>
#include <cstring>


int main() {
    typedef struct lept_context {
        const char* json;
        char* stack;
        size_t top, size;
    } lept_context;

    char *string = (char*) malloc(sizeof(char));
    char*str = "abcd";
    printf("%x\n", string);
    printf("%x\n", str);
    printf("___________\n");
    memcpy(string, str, 5 * sizeof(char));
    printf("%x\n", string);
    printf("%x\n", str);
    return 0;
}