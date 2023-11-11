#include <stdio.h>
#include <Windows.h>
#include <math.h>

// 复习一个数含有多少个1
void test1()
{
    int a = 0;
    scanf("有%d个1", &a);
    int count = 0;
    while(a)
    {
        a = a&(a - 1);
        count ++;
    }
    printf("%d\n", count);
    return ;
}


// 水仙花数
void Narcissistic_number()
{
    int a = 0;
    int e = 0;
    for( a = 10; a <= 10000; a = a + 1)
    {
        // printf("a 是 %d\n", a);
        int b = 0;
        b = a;
        int d = 0;
        d = a;
        int f = 0;
        f = a;
        
        // 判断是几位数
        int count = 0;
        int sum = 0;
        while(b > 0)
        {
            b = b / 10;
            count ++;
        }
        // printf("%d是%d位数", d,count);
        while(f > 0)
        {
            int c = 0;
            c = f % 10;
            f = f / 10;
            sum += pow(c,count) ;
        }

        if(sum == d)
        {
            printf("%d是自幂数\n", d);
            e ++;
        }
    

        
    }
    printf("有%d个自幂数", e);
    return ;
}

int main()
{
    Narcissistic_number();

    int b = 1;

    system("pause");
    return 0;
}