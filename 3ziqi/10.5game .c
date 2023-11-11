#include "10.5game.h"
#include <stdio.h>

/*
初始化棋盘
*/
void initboard(char arr[row][col], int row1, int col1)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row1; i ++)
    {
        for(j = 0; j < col1; j ++)
        {
            arr[i][j] = ' ';
        }
    }
}


/*
展示当前棋盘
*/
void display(char arr[row][col], int row1, int col1)
{
    int i = 0;
    int j = 0;
    //printf("%d%d\n", row1, col1);
    printf("\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf(" %c ", arr[i][j]);
            if (j < col1 - 1)
            {
                printf("|");
            }
        }

        printf("\n");
        if (i < col1 - 1)
        {
            for(j = 0; j < col1; j++)
            {
                printf("---");
                if (j < col1 - 1)
                {
                    printf("|");
                }
            }
            printf("\n");

        }
    }

    return;
}



/*
玩家移动
*/
void playermove(char arr[row][col], int row1, int col1)
{
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("请输入坐标\n");
        scanf("%d%d", &x,&y);
        if(x >= 1 && x <= row1 && y <= col1 && y >= 1)
        {
            if(arr[x - 1][y - 1] != ' ')
            {
                printf("该位置已经被占用，请重新下\n");
            }
            else
            {
                arr[x - 1][y - 1] = '*';
                break;
            }
        }
        else
        {
            printf("请输入1-3范围内的坐标\n");
        }
    }
    return;
}


/*
电脑移动
*/
void commove(char arr[row][col], int row1, int col1)
{
    while(1)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        if(arr[x][y] == ' ')
        {
            arr[x][y] = '#';
            printf("电脑落子的坐标是%d %d\n", x + 1, y + 1);
            break;
        }
    }
    
   return;
}


/*
定义判胜负函数
*/
char iswin(char arr[row][col] , int row1, int col1)
{
    int i = 0;
    int j = 0;
    // 横着赢
    for(i = 0; i < row1; i ++)
    {
        if(arr[i][1] == arr[i][0] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
        {
            return arr[i][1];
        }
    }

    // 竖着赢
    for(j = 0; j < col1; j ++)
    {
        if(arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[1][j] != ' ')
        {
            return arr[1][j];
        }
    }


    // 斜着赢
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
    {
        return arr[0][0];
    }

    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
    {
        return arr[0][2];
    }

    //平局
    int flag = 0;
    for(i = 0; i < row1; i++)
    {
        for(j = 0; j < col1; j ++)
        {
            if(arr[i][j] == ' ')
            {
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        return 'p';
    }

    // 继续游戏
    return '0';
}   

