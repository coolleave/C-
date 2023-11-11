#include <stdio.h>
#include <string.h>
/*
学习两个函数，strcpy和memset
1、strcpy 是将后边的字符串source 将前边的destination全部覆盖（不保留destination的任何痕迹）
strcpy替换会带着\0 
2、memset  mem是memory的意思，是内存。
memset(str, int value, num), str 是需要替换的的内存地址，value是替换内容
但是value可是是单个字符，因为对应的ascll码，是int，不能放字符串。num是替换的数目
memset替换不会携带\0，不影响未替换的内容
*/
void copy()
{
    char arr1[] = {"afafa"};
    strcpy(arr1, "ff");
    printf("%s\n", arr1);

    return;
}
/*
使用指针通过函数来改变全局变量的数值
由于变量的值无法通过函数内部来改变，也就是形式参数无法改变实际参数
可以借助内存地址来直接改变，方法如下
首先将变量的内存使用取地址符&拿到
然后将内存地址传参传进函数
函数使用int*来接收
然后通过*pa 解引用来改变内存地址中变量的数值。
*/
void Swap(int* pa, int* pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
    return;
}

void add(int* pn)
{
    *pn = *pn + 1;
    return;
}
int main()
{
    printf("hello,10.1\n");
    // copy();
    // int a = 10;
    // int b = 20;
    // printf("%d%d\n", a,b);
    // Swap(&a,&b);
    // printf("%d%d\n", a,b);
    int num =0;
    int* pn = &num;
    add(pn);
    printf("%d\n", num);
    add(pn);
    printf("%d\n", num);
    return 0;
}
