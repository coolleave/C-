#include <stdio.h>

void prm()
{
    int a = 0;
    while (a <= 100)
    {
        if(a%2 != 0)
            ;
        if (a%2 == 0)
            printf("%d为偶数\n", a);
        a ++ ;
    }
    
    return ;
}
/*
多分支条件判断问题，用switch
switch  语法 
switch(条件)
case :
case :
但是要注意的是，switch 的case1成立 那么后边的case就都成立了 
所以要想后边不成立，就把代码下边就加一个break 
switch 的意思是 如果遇到了符合条件的代码，就把后边的语句全部执行。
case决定入口，break 决定出口

day 的数据类型必须是整型。  
case 必须是整型常量的表达式
case 也可以合并同类项，case1，case2  多个入口进入同一个语句
如果所有入口都没有进去，那就使用default是默认，出错的情况显示什么
case和default没有顺序的。
*/
void fz(int day)
{
    switch(day)
    {
    case 1:
        printf("今天星期一");
        break;
    case 2:
        printf("今天星期2");
    }
    return;
}
int main()
{
    fz(1);
    return 0;
}