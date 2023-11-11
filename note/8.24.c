#include <stdio.h>
int main()
{
    // 常量的分类有四种
    // 1、字面变量 2、const修饰的常变量
    // 3、 define 定义的标识符常量 4、枚举常量
    4;
    "gg";
    // 以上都是字面常量

    const int sum = 8; 
    // const-->常属性 sum变量被const修饰，成为常变量。
    printf("%d\n", sum);

    enum Week
    {
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THUISDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY


    };
    printf("%d\n", MONDAY);
    printf("%d\n", TUESDAY);
    printf("%d\n", WEDNESDAY);
    printf("%d\n", THUISDAY);
    printf("%d\n", FRIDAY);
    printf("%d\n", SATURDAY);
    printf("%d\n", SUNDAY);
    // 枚举常量就是把值放进enum中，这里的每一个值分别对应0123
    printf("over!!");
    return 0;
}