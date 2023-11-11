#include <stdio.h>

void operators()
{
    // 1000000001  1111111111110   111111111111111
    int a = -1;
    int b = -2;
    int c = a & b;
    printf("%d\n", c);

}

// 小小面试题,交换两个变量，不能创建int变量
int test()
{
    int a = 4;
    int b = 3;

    // // 加减法带入互换
    // a = a + b;
    // b = a - b;
    // a = a - b;
    // printf("a = %d, b = %d\n", a,b);  
    // a = (a - b)/ 2;
    // b = (a + b)/ 2;

    // 方法2 按位异或 密码法带入  
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a = %d, b = %d\n", a,b);

    // 以上的原理就是， b = a ^ b ^ b 相应的 a = a  ^ b ^a (此时 ab都是原值)
    // 110 ^ 111 = 001   001 ^ 111 = 110   001 ^ 110 = 111

    int c = -1111;
    int d = c >> 31;
    printf("d = %d", d);
    
}

// 练习题，数出机器的储存码中有多少个1
void test1()
{
    int a = 6;
    int count = 0;
    int i = 0;
    // // 方法1  这种方法有局限性，就是不能计算负数有多少个1
    // while(a)
    // {
    //     if(a % 2 == 1)
    //     {
    //         count ++;
    //     }
    //     a = a / 2;
    // }

    // 方法2 利用操作符
    // 思路 使用循环，将int a 依次右移i个位，确保每个位都能到末位，然后
    // 将a >> i 与 1（0*31 1） 做按位与计算，这样的话如果计算结果等于1 就证明
    // 倒数第 i+1 位就是 1，如果结果等于 0 就证明倒数第i+1位是0.
    char arr[32] = {0};
    for(i = 31; i >= 0; i--)
    {
        if((a>>i) & 1 == 1)  // i + 1 位是1
        {
            printf("1");
            arr[31 - i] = '1';
            count ++;
        }


        else // i + 1 位是0
        {
            printf("0");
            arr[31 - i] = '0';
        }
        
    }
    printf("\n");
    printf("%s\n", arr);
    printf("\n");
    printf("有%d个1\n", count);
    return;
}

int main()
{
    // operators();
    // test();
    // test1();
    int a = 10;
    printf("%d \n", a++);
    printf("%d\n", a);
    char input = 'o';
    scanf("%d", &input);
    return 0;
}