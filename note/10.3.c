#include <stdio.h>
#include <string.h>
/*
在c语言中 用递归解决汉诺塔问题
*/
void hanio(char a, char b, char c, int n)
{
    if(n>0)
    {
        hanio(a,c,b,n-1);
        printf("把%c移动到%c\n", a,c);
        hanio(b,a,c,n-1);
    }
    return;
}

/*
青蛙跳台阶问题
青蛙只能跳一个台阶或者两个台阶，跳到n种台阶有多少种跳法。

思路： 青蛙跳台阶主要是一个斐波那契数列问题，运用递归来解决。
反向思考，当有n个台阶时，分两种情况讨论
1、第一步跳了一格，那么剩下的台阶就有f(n-1)种跳法
2、第一步跳了两铬，那么剩下的台阶就有f(n-2)种跳法
总共就有f(n) = f(n-1) + f(n-2) 种跳法
*/
int frog_jump(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if(n >= 3)
    {
        return frog_jump(n - 1) + frog_jump(n - 2);
    }
}
int main()
{
    // hanio('a','b','c',2);
    
    // int i = 1;
    // for(i = 1; i<50; i++)
    // {
    //     printf("%d\n", frog_jump(i));
    // }


    // 测试数组
    char arr[] = "abc";
    char arr1[] = {"abc"};
    printf("%d\n%d\n%d\n", sizeof(arr1), sizeof(arr), strlen(arr));

    return 0;
}