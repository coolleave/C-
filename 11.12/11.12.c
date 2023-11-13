#include <stdio.h>
#include <stdlib.h>

// 编写一个程序，返回 1！+ 2！ + 3！+ …… + n！
int Factorial()
{
    int num = 0;
    scanf("%d", &num);
    int i = 0;
    int ret = 0;
    int j = 1;
    for(i = 1; i <= num; i++)
    {
        int sum = 1;
        for(j = 1; j <= i; j ++)
        {
           sum *= j; 
        }
        ret += sum;
    }
    return ret;
}
int main()
{
    printf("%d\n", Factorial());
    system("pause");
    return 0;
}