#include <iostream>
// 
void fn(void)
{
    int n = 10;

    printf("n=%d\n", n);
    n++;
    printf("n++=%d\n", n);
}

void fn_static(void)
{
    static int n = 10; //这里是定义并初始化一个静态变量n,第二次调用fn_static时，不会再定义并初始化这个n

    printf("static n=%d\n", n);
    n++;
    printf("n++=%d\n", n);
}

int main(void)
{
    fn();
    printf("--------------------\n");
    fn_static();
    printf("--------------------\n");
    fn();
    printf("--------------------\n");
    fn_static();

    return 0;
}
