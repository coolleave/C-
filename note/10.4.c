#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
// void arr()
// {
//     char arr1[] = "abc";
//     char arr2[] = {'a', 'b', 'c'};
//     printf("%d\n%d\n%d\n%d\n",sizeof(arr1),sizeof(arr2),strlen(arr1),strlen(arr2));
//     return;
// }

/*
复习一下随机数
原理，rand 是个伪随机数，需要用stand设置起始点。
*/
int randint()
{
    srand(time(NULL));
    int ret = rand()%100;
    return ret;
}



/*
冒泡排序
原理：
1，2，3，4，5 将1，2比较然后按照大小顺序换位，再比较第二个第三个，知道最后一个归位
我们把比较这一次叫做一趟冒泡排序，经过有限趟冒泡排序后，就可以把所有的元素都归位
例如一个数组有n个元素
那么 一共需要n - 1趟排序
在第i趟排序中，需要做n - i - 1 对排序
下面这是一个升序冒泡排序
*/
void bubble_sort(int arr[] , int sz)
{
    int i = 1;
    int j = 1;
    for(i=0; i < sz - 1; i++)  // 每趟循环
    {
        int flag = 1;
        for(j=0; j< sz - i -1; j++)  // 一趟循环中的每对循环
        {
            if(arr[j]>arr[j+1])  // 每对循环中，两个数的比较
            {
                int tmp = arr[j];  //  如果不符合条件，则交换位置。
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("触发优化条件");
            break;
        }
    }
    int a = 0;
    for(a = 0; a < sz; a++)
    {
        printf("%d ", arr[a]);
    }
    return;
}
/*
上边是正序，再来个倒序练习一下。
*/
void reverse_bubble_sort(int arr[], int sz)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < sz - 1; i ++)
    {
        int flag = 1;   // 算法优化，如果一整趟都没有交换，那么排序已经完成，不需要继续比较
        for(j = 0; j < sz - i -1; j ++)
        {
            if(arr[j]<arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;  // 本趟数组不完全有序。
            }
        }
        if (flag == 1)
        {
            printf("触发优化条件");
            break;
        }

    }
    int a = 0;
    for(a = 0; a < sz; a ++)
    {
        printf("%d ", arr[a]);
    }
    return;
}


int main()
{
    // arr();

    // printf("%d", randint());  //生成随机数
    // return 0;

    int arr[] = {8,7,6,5,4,3,2,1};
    int sz = sizeof(arr)/sizeof(arr[0]); // 求出数组元素个数
    bubble_sort(arr,sz);  //正序
    printf("\n");
    reverse_bubble_sort(arr,sz);  // 倒序
}