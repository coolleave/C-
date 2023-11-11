#include <stdio.h>

// 指针模拟str
int pointer_str( char* str)
{
    char* start = str;
    char* end = str;
    while( *end != '\0')
    {
        end++;
    }
    return end - start;

}

// 指针比较
void pointer_com()
{
    int arr[] = {1, 2,3,4,5,6};
    int* ap = arr;
    int i = 0;
    for(ap = &arr[5]; ap >= &arr[0];)  // 满足地址大于最前边一个元素的地址
    {
        * ap-- = 0;
    }


    for(i = 0; i <= 5; i ++)
    {
        printf("%d\n", arr[i]);
    }
    return;
}

void display()
{
    int arr[] = {1,2,4};
    printf("%p\n", arr);
    printf("%p\n", &arr);
    printf("%p\n", &arr[0]);
    return;
}

int main()
{
    char arr[] = "afaf";
    // printf("%d\n", pointer_str(arr));
    // pointer_com();
    display();


    int z = 0;
    printf("输入任意字符继续");
    scanf("%d", &z);
    return 0;
}