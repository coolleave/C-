#include <stdio.h>
/*
小试牛刀
给定一个数字，分别打印它的每一位。例如输入 1234 打印 1 2 3 4
*/
void bolckprint(int a)
{
    if(a>10)
    {
        int b = a % 10;  // 取模拿到末位数字
        a = a / 10;      // 去掉末位数字
        bolckprint(a);   // 进入递归
        printf("%d\n", b);//等待里边递归结束，打印末位数字
        
        // printf(" a 是 %d\n", a);
        
        return;
    } 
    else
        {
            printf("%d\n", a);
            return;
        }
}

/*
写一个函数 模拟strlen() 的功能

*/
int my_strlen(char* arr)
{
    int count = 0;

    while(*arr != '\0')
    {
        count ++;
        printf("%x\n", arr);
        arr ++;
    }
    return count;
}
/*
递归函数写法
*/
int recursion(char* arr)
{
    if(*arr != '\0')
        return 1 + recursion(arr+1);  // 1+1+1+recusion()
    else
        return 0;
}

/*
运用递归求n的阶乘
*/

int factorial(int n)
{
    if(n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}


/*
运用递归解决斐波那契数列问题
*/

int fib(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    
    else
    {
        return fib(n-1)+fib(n-2);
    }
}

/*
使用循环解决斐波那契数列问题
*/

int fib1(int n)
{
    int i = 3;
    int a = 1;
    int b = 1;
    int c = 0;
    if(n<3)
        return 1;
    else
        for(i = 3; i< n+1; i++)
        {   // printf("i是 %d\n", i);
            c = a + b;
            a = b;
            b = c; 
            // printf("c 是 %d\n", c);
        }
    return c;
}
int main()
{
    printf("hello, 10.2!\n");



    // int a = 0;
    // scanf("%d", &a);
    // bolckprint(a);

    // char arr[] = "hahaha";  
    // int len = my_strlen(arr);
    // int len = recursion(arr);
    // printf("长度是%d", len);

    // int a = 0 ;
    // scanf("%d", &a);  //输入要计算的阶乘数
    // printf("%d\n", factorial(a));

    // int n = 0;  // 初始化要得到斐波那契的第n个数字
    // scanf("%d", &n);
    // printf("%d", fib1(n));




   
    return 0;
}