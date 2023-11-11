#include <stdio.h>

int arr()
{
    int arr[3] = {3,5,2};
    int i = 0;
    while(i<3)
    {
        printf("%d\n", arr[i]);
        i ++;
    }
    return 0;
}
int main()
{
    arr();
    return 0;
}