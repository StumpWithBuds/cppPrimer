#include <iostream>
#include <cstring>
#include <stdlib.h>

// std::string file_path = "./text.txt";

char* file_path = "./text.txt";

int main(){
    FILE* fp;
    fp = fopen(file_path, "w+");
    fprintf(fp, "%s:%d: expect: " "%d" " actual: " "%d" "\n",__FILE__, __LINE__, 1, 2);
    return 0;


}