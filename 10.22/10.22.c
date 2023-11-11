#include <stdio.h>

void test()
{
    int i  = -1;
    printf("%d\n", (unsigned)i);
    return ;
}

// 统计二进制中1的个数
void test1()
{
    int i = 0;
    int a = 15;
    int count = 0;
    int b = 0;
    for(i  = 0; i < 32; i ++)
    {
        b = a >> i;
        if(b & 1 == 1)
        {
            count ++ ;
        }
    }

    printf("%d\n", count);
    return;
}

void test2()
{
    int a = -1;
    int count = 0;
    while(a)
    {
        a = a & (a -1);
        count ++;
    }
    printf("%d\n", count);
}

int main()
{
    test2();


    int z = 0;
    printf("输入任意键继续");
    scanf("%d", &z);
    return 0;
}