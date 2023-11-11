#include <stdio.h>
#include "10.5game.h"

/*
定义菜单函数
*/
void menu()
{
    printf("************************************\n");
    printf("**********1、game  0、exit**********\n");
    printf("*************请输入 》》》》》*******\n");
    return;
}

/*
定义主游戏函数
*/
void game()
{
    char arr[row][col] = {0};  // 定义棋盘
    initboard(arr, row, col);  // 初始化棋盘
    display(arr, row, col);    // 展示棋盘

    // 开始下棋
    char ret = '0';
    while(1)
    {
        playermove(arr, row, col);  // 玩家移动
        display(arr, row, col);
        ret = iswin(arr, row, col);  // 判断输赢
        if(ret != '0')
        {
            break;
        }

        //运用时间戳定义srand
        srand((unsigned int)time(NULL));
        commove(arr, row, col);  // 电脑移动
        display(arr, row, col);
        ret = iswin(arr, row, col);  // 判断输赢

        if(ret != '0')
        {
            break;
        }
    }


    if(ret == 'p')
    {
        printf("平局！");
    }

    if(ret == '*')
    
    {
        printf("恭喜你！ 胜利！");
    }

    if( ret == '#')
    {
        printf("电脑赢!!");
    }

    
    return;

}



void gamestart()
{
    int input = 0;
    
    
    do
    {
        menu();
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                {
                    printf("游戏开始喽\n");
                    printf("你是 * , 系统是 # \n");
                    game();
                    break;
                }
            case 0:
                {
                    printf("欢迎下次再来！\n");
                    break;
                }
            default:
                {
                    printf("输入错误，请重新输入\n");
                    break;
                }
        }
    }while(input);

    return;
}
int main()
{
    gamestart();
    return 0;
}