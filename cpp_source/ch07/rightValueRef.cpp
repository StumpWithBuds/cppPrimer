/*
对右值引用的概念，用法不熟悉，故亲手尝试
*/
#include <iostream>

class Buffer {
    public:
        Buffer() {
            buf = (char*) malloc(100);
        }

        ~Buffer() {
            if(buf != nullptr)
                free(buf);
                buf = nullptr;
        }

        char *buf = nullptr;
};

Buffer getBuffer() {
    Buffer buf;
    return buf;
}

void setBuffer(Buffer &buf){
    std::cout << "Buffer &buf" << std::endl;
}

void setBuffer(const Buffer &buf){
    std::cout << "const Buffer &buf" << std::endl;
}

void setBuffer(Buffer &&buf){
    std::cout << "Buffer &&buf" << std::endl;
}

int main()
{
    setBuffer(getBuffer());

    Buffer buf;
    std::cout << &buf << std::endl;
    setBuffer(buf);

    const Buffer cBuf;
    setBuffer(cBuf);


    return 0;
}