#include <stdio.h>

int main()
{
    char arr1[]= "abc";  // 这是一个数组
    char arr2[]= {'a', 'b','c', 0, 'n'}; // \0是字符串的结束标志
    printf("%s\n", arr1);
    printf("%s\n", arr2);
    return 0;
}