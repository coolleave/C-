#include <stdio.h>
#include <string.h>
int main()
{
    // printf("(are you sure)?? \n");
    // printf("%d\n", strlen("c:\test\32\test.c"));
    // printf("%c\n", "\234");;
    // int input = 0;
    // scanf("%d", &input);
    // printf("%d\n", input);
    // if(input == 1)
    //     printf("if条件执行\n");
    // else
    //     printf("else条件执行");
    int line = 0;
    while (line < 20000)
    {
        printf("第%d天\n", line);
        line ++;
    }
    if(line>=20000)
        printf("达到两万天");
    return 0;
}