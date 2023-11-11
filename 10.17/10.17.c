#include <stdio.h>

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    int* p = arr;
    // for(i = 1; i<= 9; i++)
    // {
    //     p ++;
    //     printf("%d\n", *p);
    // }
    printf("%d\n", &arr[0] - &arr[9]);

    int z = 0;
    printf("请输入任意字符继续...\n");
    scanf("%d", &z);
    return 0;  
}