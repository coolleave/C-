#include <stdio.h>
// int main()  // 比较两个数字的大小
// {
//     int num1 = 0;
//     int num2 = 0;
//     scanf("%d,%d", &num1, &num2);
//     if(num1<num2)
//         {
//             printf("%d大\n", num2);
//         }
//     else if (num1<num2)
//         {
//             printf("%d大", num1);
//         }
    
//     return 0;
// }
// 写一个函数比较两个函数的大小
int com()
{
    int x = 0;
    int y = 0;
    scanf("%d,%d", &x, &y);
    if(x>y)
    {
        printf("%d 比较大", x);
    }
    else if (y>x)
    {
        printf("%d 比较大", y);
    }
    else
    {
        printf("两个数一样大");
    }
    return 0;
}
void czf() // 操作符
/*
操作符运算就是将数字对应的二进制位数  （如1 对应的0000001）
使用操作符<<1 将0000001 移动一位 变为0000010 此时对应的是2
>> 同理
规则
1、当所求的数字不为0时 就是乘2或者除以2
2、当所求的数字为0时 使用 >> 就是将0变成1 ，以后遵循规则1
                    使用 << 数字还是0，不变。

~ 操作符
按（二进制）位取反
0的按位取反是-1 
重要知识点补充
原码，反码，补码

他们的变换过程是
原码 ->>> 补码
原码 最高位不变 然后剩下的31位全部取反位，得到结果后再减去1，这时的最终结果就是补码
同理 ，上述过程的逆过程
补码 - >>> 原码
补码的最高位不变， +1 然后再将31位进行按位取反，得到的最终结果就是原码
负数在内存中的存储方式是二进制的补码
二进制的最高位表示的符号位，就是正负号
原码就是给的原始的码 
我们打印的就是原码。
如在函数中的例子 
0对应的码就是00000000000（省略了几个零）
当我们使用~ 按位取反之后，就变成了111111111111（位数同上，0全部变为1）
但是 11111111 是补码 不能够直接打印，所以，进行补码 ->>>到原码的过程
11111111111 最高位为1不变， 然后 减去1 变为 111111111110 ，在进行按位取反 则位 10000000001 也就是结果-1
这时我们输入进打印程序
此时 由于最高位是 1  所以这时候 输入就是补码 


*/
{
    int x = 0;
    x = x>>1;  
    printf("%d", x);
    int y = 1073741824;
    int z = ~y;
    printf("%d的按位取反计算结果是%d",y,z);
    return ;
}
void arrs()
{
    int arr[] = {1,2,3,4,524,24,4};
    printf("%d", sizeof(arr)/sizeof(int));
    return;
}
void lj()
{
    int a = " "&& 1;
    printf("%d", a);
    return;
}
void keywords()
{
    auto int a = 10; // 叫局部变量也叫自动变量，前边省略了auto
    return ;
}
int main()
{
  
    // com();
    // czf();
    // arrs();
    lj();
    return 0;
}

