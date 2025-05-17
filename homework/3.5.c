#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int test1()
{
   /*  Write C code in this online editor and run it. */
	int a,b,c;
	scanf("%d%d", &a,&b);
	c = abs(a-b);
   printf("c=%d\n", c);
   system("pause");
   return 0;
}


/*
请编写程序，输入梯形的上底 t、下底 b 和高 h，计算并输出梯形的面积 a。
要求：输出 2 位小数(末尾四舍五入)。
4.493 5.507 5.765
28.83
*/
int test2(){
    float t,b,h,a;
    scanf("%f%f%f",&t,&b,&h);
    a = 0.5*(t+b)*h;
    a = a*100;
    a = round(a);
    a = a / 100.0;
    printf("%.2f", a);
    return 0;
}

int test3(){
    float t,b,h,a;
    int s,z;
    scanf("%f%f%f",&t,&b,&h);
    a = 0.5*(t+b)*h;
    printf("%f\n", a);
    a = a*1000;
    printf("a=%.2f\n", a);
    s = (int)a;
    printf("s1=%d\n", s);
    z = s % 10;
    printf("z=%d\n", z);
    if (z>4)
    {
        s = s + 1;
    }
    printf("s1=%d\n", s);
    printf("%.2f", s / 1000.0);

    return 0;
}

int main(){
    
    test3();
    system("pause");
    return 0;
}