#include <stdio.h>
#include <math.h>
// 求根公式
// int qg()
// {
//     float a,b,c;
//     printf("请输入三个系数abc\n");
//     scanf("%f,%f,%f", &a,&b,&c);
//     while (a == 0)
//     {
//         printf("不是二元一次方程, 请重新输入！\n");
//         scanf("%f,%f,%f\n", &a,&b,&c);
//     }
//     float d = b*b - (4*a*c);
//     printf("%f\n", d);
//     if (d<0)
//         printf("该方程无解\n");
//     else if (d ==0)
//     {
//         printf("%f\n", (-b)/2*a);
//     }
//     else if (d>0)
//     {
//         printf("%f,%f\n", (-b + sqrt(b))/a *2, (-b - sqrt(b))/a *2);
//     }
//     return 0;
// }
int sum(int a,int b)
{
    int c = a + b;
    return c;
}
int main()
{
    int a,b;
    printf("请输入数字a，b= \n");
    scanf("%d,%d", &a,&b);
    printf("%d", sum(a,b));
    return 0;
}

  