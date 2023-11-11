#include <stdio.h>

// 冒泡排序热热身
void bubble()
{
    int i = 0;
    int t = 0;
    int sz = 0;
    int arr[10] = {1,2,45,6,4243,4,5,6,54,67};
    sz = sizeof(arr) / sizeof(arr[0]);
    for(i = 0; i < sz; i ++)
    {
        for(t = 0; t < sz - i -1; t ++)
        {
            if(arr[t] > arr[t + 1])
            {
                int tmp = 0;
                tmp = arr[t];
                arr[t] = arr[ t + 1];
                arr[t + 1] = tmp;
            }
        }
    }
    int c = 0;
    for(c = 0; c < sz; c ++)
    {
        printf("%d\n", arr[c]);
    }
}


// 翻转数组
void reverse()
{
    int arr[8] = {1,2,3,4,5,6,8,11};
    int arr1[8] = {0};
    int a = 0 ;
    int i = 0;
    int sz = 0;
    sz = sizeof(arr)/sizeof(arr[0]);
    for(a = 0; a < sz; a ++)
    {
        arr1[a] = arr[a];
    }
    for(i = 0; i < sz; i++)
    {
        arr[i] = arr1[sz-1 - i];
        printf("%d\n", arr[i]);
    }
}

void reverse1()
{
    int arr[9] = {1,3,4,5,67,434,5,3,2};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int tmp = 0;
    for(i = 0; i < sz/2 ; i++)
    {
        tmp = arr[i];
        arr[i] = arr[sz - 1 -i];
        arr[sz - 1- i]  = tmp;
    }
    for(i = 0; i < sz ; i++)
    {
        printf("%d\n", arr[i]);
    }

    return;
}






int main()
{
    // bubble();
    reverse1();












    int z = 0;
    printf("输入任意键继续");
    scanf("%d", z);
    return 0;
}