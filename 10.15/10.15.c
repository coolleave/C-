#include <stdio.h>

//三目操作符练习
void test1()
{
    int a = 1;
    int b = -1;
    printf("%d大\n", a > b ? a : b);
    // 等价于
    if(a > b)
    {
        printf("%d\n", a);
    }

    else
    {
        printf("%d", b);
    }
    return ;
}

void test2()
{
    int a = 12;
     
    char b = 1;
    printf("%d\n", sizeof(char));
    return;
}
int main()
{
    // test1();

    test2();




    char z = '0';
    printf("按任意键继续");
    scanf("%s", &z);
    return 0;
}