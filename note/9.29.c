#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 在一个列表中取最大值
void findmax()
{
    int arr[] = {1,2,3,5,3,5,8,999,19,23,45};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    int i = 0;
    for(i=0;i<sz;i++)
    {
        if (max<arr[i])
            max = arr[i];
    }
    printf("最大的数字是%d\n", max);
    return ;
}


void findtheyears()  // 找出1000-2000年内所有的闰年
{
    int i = 1000;
    for (i = 1000; i<= 2000; i++)
    {
        if(i%4 == 0 && i%100 != 0)
            printf("%d\n", i);


        else if (i%400 == 0)
        {
            printf("%d\n", i);
        }
        
    }
    return;
}

void mul()  // 打印乘法口诀
{
    int i = 1;
    int a = 1;
    for(i = 1; i<10 ; i++)
    {
        for(a = 1; a<=i; a++)
        {
            printf("%dx%d=%-2d ", a,i,a * i);
        }
        printf("\n");
        
        
    }
    return;
}

/*
c语言中 生成随机数使用rand() 函数，但是rand函数需要一个
起始点，srand() , 一个种子 一套随机数体系。
我们要想做到随机数真正地随机，就要让种子也随机。
我们就可以使用时间戳来实现。时间戳使用time() 函数
*/


void randgenerate()  // 生成随机数
{
    long a = time(NULL);  // 获取时间戳
    printf("%d\n", a);
    srand((unsigned)a);  // 将时间戳转化为无符号类型，并且输入起始点
    int i = 0;
    for(i = 0; i<100; i++)
    {
        int a = rand();
        printf("%d\n", a%100 + 1); // 重点 获得范围内的整数直接取模
    }
    return;
}

/*

goto 语句 就是随意乱跳
可以自己创建一个标签，然后随时跳到标签，并且跳过中途所有的代码行。
下面以一个函数为例
*/
void goto1()
{
    printf("before goto\n");
    goto break1;
    printf("behind goto\n");
    break1:
        printf("goto\n");
    return;
}

void aushutdown()  // 自动关机函数
{
    system("shutdown -s -t 60");  // 在60秒后自动关机
    Sleep(10000);
    system("shutdown -a");  // 取消自动关机
    return;
}

int main()
{
    // findmax();
    // findtheyears();
    // mul();
    // randgenerate();
    // goto1();
    aushutdown();
    return 0;
}