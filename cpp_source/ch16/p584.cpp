#include "./p584_Blob.h"
#include "./p587_BlobPtr.h"

int main() {
    Blob<int> ia;
    Blob<int> squares = {0,1,2,3,4,5,6,7,8,9,10};
    for (size_t i = 0; i < squares.size(); ++i) {
        squares[i] = i * i;
        std::cout << squares[i] << std::endl;
    }
    BlobPtr<
    return 0;
}