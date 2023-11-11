#include <stdio.h>
/*
EOF的意思就是end of file 文件结束标志，本质是-1的代码
python中就是 -1
使用 ctrl + z就算是


数组不用取地址符

在输入函数中，有个输入缓冲区，也就是123456\n 
读取到123456时 \n 就回到缓冲区等待
getchar 就会读取到缓冲区的 \n 
因为我们就要把 缓冲区的东西清理干净。

for(初始化表达式;判断表达式;调整表达式;)
初始化表达式只是执行一次。

for(;;)
部分省略就是恒为真，已知循环，

while 的判断表达式中，如果只有一个等号，那么就是赋值，而不是判断
并且 只要赋值不是0，就是正确的，死循环



*/
// void fun1()
// {
//     int a = 0;
//     while((a = getchar()) != EOF)
//     {
//         printf("%c", a);
//     }
//     return;
// }
// void fun2()
// {
//     int a = 0;
//     while((a = getchar() != EOF))
//     {
//         if(a < '0' || a > '9')
//             continue;
//         putchar(a);
//     }


//     return;
// }
// int jc(int a)
// {
//     int i = 0;
//     int s = 1;
//     for (i = 1; i<=a; i++)
//     {
//         s = s * i;
//     }
//     printf("最终结果%d\n", s);
//     return s;
// }


// c语言实现二分法
int find()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int c = 5;
    int left = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    int right = sz;
    printf("%d",sz);
    while(left < right)
    {
        int mid = (left + right) / 2;
        printf("%d\n", mid);
        if(c>arr[mid])
       {
            right = mid -1 ;
            printf("%d\n", mid);

        }
        else if (c<arr[mid])
        {
            left = mid + 1;
            printf("%d\n", mid);
        }
        else if (c == arr[mid])
        {
            printf("%d\n", mid);
            printf("%d\n", arr[mid]);
            break;
        }
        
        
    }
    return 0;

}

int main()
{
    // int b = 1;
    // int c = 0;
    // for( ;b<=10;b++)
    // {
    //     c = c + jc(b);
    // }
    // printf("加起来的总和是%d\n",c);
    find();
    return 0;
}
