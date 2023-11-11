#include <stdio.h>
/*
分号就是隔开一条语句的
只写一个分号也可以是一条语句，类似pass
*/
/*
如果if while 语句要控制多条语句，就要使用{}代码块
else 主动与最近的未匹配的进行匹配 
else 有就近原则
*/
void func()
{
    int a = 1;
    int b = 2;
    if (a == 0)
        if (b == 2)
        {
            printf("第2个if");
        }

    else;
        printf("第一个if");
    printf("over");
    if (a == 1)
    ;
    return;
}
int main()
{
    func();
    return 0;
}