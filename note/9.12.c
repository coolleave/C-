#include <stdio.h>
#include <string.h>
void func()
{
    int a = 19;
    int b = 29;
    double c = 3.14;
    // printf("%d\n", a);
    double* pd = &c;
    int* pdf = &a ;
    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(double*));
    printf("%d\n", sizeof(long*));
    printf("%d\n", sizeof(short));

    return;
}
/*
描述复杂对象用结构体，是我们自己创造的类型
结构体类型有点像python中的类 class 就是python中的面向对象
.是结构体变量
-> 就是结构体指针用的
*/
struct student  // 创建类
{
    char name[20] ;
    short age;
    short hight;
    int class;
};
void students()
{
    struct student student1 = {"小明", 16,160,2302};
    printf("名字是%s\n", student1.name);
    printf("年龄是%d\n", student1.age);
    student1.age = 19;  // 修改年龄
    printf("修改后的年龄为%d\n", student1.age);
    struct student* pd = &student1;  // 拿到对象的指针，
    // struct student* 就是我们新创建的数据类型
    // 利用pd 打印出学生的名字和年龄
    printf("%s\n", (*pd).name);
    printf("%d\n", (*pd).age);
    // 更简单的方法
    printf("%s\n", pd->name);
    printf("%d\n", pd->age);
    // 想要修改小明的名字 
    strcpy(student1.name,"小小明");
    printf("%s\n", student1.name);
    
    return;
}

int main()
{
    students();
    return 0;
}