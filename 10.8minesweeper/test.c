#include "game.h"

// ����˵�����
void menu()
{
    printf("************************************\n");
    printf("**********1��game  0��exit**********\n");
    printf("*************������ ����������*******\n");
    return;
}

// ������Ϸ����
void game()
{
    // ��������
    char mine[rows][cols] = {0};
    char show[rows][cols] = {0};

    // ��ʼ������
    initboard(show, row, col, '*');
    initboard(mine, row, col, '0');
    // չʾ����
    display(show, row, col);
    // display(mine, row, col);

    // mine setting
    srand((unsigned int)time(NULL));
    setmines(mine, row, col);

    // display(mine,row,col);
    // mine finding
    findmines(show, mine, row, col);
    return;
}

// ���������Ժ���
void test()
{

    int input = 0;
    do
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            game();
            printf("game\n");
            break;
        }

        case 0:
        {
            printf("��ӭ�´��������ټ���");
            break;
        }
        default:
        {
            printf("������������������");
        }
        }
    } while (input);
    return;
}

int main()
{
    test();
    return 0;
}