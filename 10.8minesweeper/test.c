#include "game.h"

// 定义菜单函数
void menu()
{
    printf("************************************\n");
    printf("**********1、game  0、exit**********\n");
    printf("*************请输入 》》》》》*******\n");
    return;
}

// 定义游戏函数
void game()
{
    //定义棋盘
    char mine[rows][cols] = {0};
    char show[rows][cols] = {0};

    // 初始化棋盘
    initboard(show, row, col, '*');
    initboard(mine, row, col, '0');
    // 展示棋盘
    display(show, row, col);
    // display(mine, row, col);

    // mine setting
    srand( (unsigned int ) time(NULL) );
    setmines(mine, row, col);
    
    // display(mine,row,col);
    // mine finding
    findmines(show, mine, row, col);
    return;
}


//定义主测试函数
void test()
{

    
    int input = 0;
    do{
        menu();
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                {
                    game();
                    printf("game\n");
                    break;
                }

            case 0:
                {
                    printf("欢迎下次再来，再见！");
                    break;

                }
            default:
            {
                printf("输入有误，请重新输入");
            }
            
        }
    }while (input);
    return;
}

int main()
{
    test();
    return 0;
}