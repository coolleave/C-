#include <stdio.h>
#include <string.h>
#include <windows.h>  // 暂停程序时间
#include <stdlib.h>  // 清屏命令头文件


void twofind(int k)  // 二分法进行查找
{
    int arr[] = {1,2,4,5,6,7,8,11,23,43,56};
    int left = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    int right = sz - 1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if (arr[mid]<k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        
        else
        {
            printf("找到了是%d\n", arr[mid]);
            break;
        }
    if (right<left)
    {
        printf("没找到");
    }
        
    }
    return ;
}

void relstr()  // 字符串替换
{
    char input1[] = "hi,good weekend!";
    char output1[] = "@@@@@@@@@@@@@@@@";
    printf("%s\n", output1);
    Sleep(1000);
    system("cls");

    int right = strlen(input1)-1; 
    // 找到字符串的最大索引，就是字符串个数-1
    // 但是字符串里还有个\0，不能用size法进行计算
    int left = 0;
    while(right>=left)
    {
        output1[right] = input1[right];
        output1[left] = input1[left];
        printf("%s\n", output1);
        Sleep(1000);
        system("cls");  // 清屏命令
        left ++;
        right --;
    }

    return;
}

void login()
{
    char password[20] = {0};
    int i = 0;
    for(i = 0; i<3; i++)
    {
        printf("请输入密码\n");
        scanf("%s", &password);
        if(strcmp(password, "123456") == 0)
        {
            printf("密码正确，登录成功！\n");
            return ;
        }
        else
        {
            printf("密码错误，登录失败！\n");
        }
    }
    if(i == 3)
    {
        printf("登录失败次数过多，请稍后尝试！\n");
    }
    return;
}

int main()
{
    // int t;
    // printf("请输入要找到的数字");
    // scanf("%d", &t);
    // twofind(t);
    // relstr();
    login();
    return 0;
}