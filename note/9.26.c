#include <stdio.h>
/*
三数字排列问题
*/
void sort()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d", &a,&b,&c);
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b < c)
    {
        int tem = b;
        b = c;
        c = tem;
    }
    printf("%d%d%d", a, b, c);
    return;
}

void triple()  // 打印三的倍数
{
    int i = 0;
    for( i = 0 ; ; i++)
    {
        if (i%3 == 0)
            printf("%d\n", i);
    }
    return;
}

void func1()  // 求两个数的最大公约数，辗转相减法
{
    int a = 0;
    int b = 0;
    scanf("%d%d", &a,&b);
    while(a != b)
    {
        if (a < b )
        {
            b = b - a;
            // printf("%d\n", a);
        }
        else if (a > b)
        {
            a = a - b;
            // printf("%d", b);
        }
    }   

    printf("最大公约数是%d", a);
    return;
}

int main()
{
    func1();
    return 0;
}