#include "game.h"

void initboard(char board[rows][cols], int row1, int col1, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
    return;
}

void display(char board[rows][cols], int row1, int col1)
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= row1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row1; i++)
    {
        printf("%d", i);
        for (j = 1; j <= col1; j++)
        {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

void setmines(char board[rows][cols], int row1, int col1)
{
    int count = mines;

    while (count)
    {
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

//               show                       mine
int iswin(char board3[rows][cols], char board4[rows][cols], int row1, int col1, int x1, int y1)
{
    if (board4[x1][y1] == '1')
    {
        return '0';
    }
    else
    {
        printf("���׳ɹ��� \n");
        // display(board4, row, col);
        printf("\n");
        return board4[x1 - 1][y1 - 1] +
               board4[x1 - 1][y1] +
               board4[x1 - 1][y1 + 1] +
               board4[x1 + 1][y1 - 1] +
               board4[x1 + 1][y1] +
               board4[x1 + 1][y1 + 1] +
               board4[x1][y1 + 1] +
               board4[x1][y1 - 1] - 8 * '0';
    }
}

//                   show                          mine
void findmines(char board[rows][cols], char board1[rows][cols], int row1, int col1)
{
    int x = 0;
    int y = 0;
    int count = row1 * col1 - mines;
    while (count)
    {

        printf("���������꡷����\n");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row1 && y >= 1 && y <= col1)
        {
            if (board[x][y] == '*')
            { // show   mine
                int ret = iswin(board, board1, row, col, x, y);
                // display(board, row, col);
                if (ret == '0')
                {
                    printf("�㱻ը����\n");
                    display(board1, row, col);
                    break;
                }

                else
                {
                    board[x][y] = ret + '0';
                    display(board, row, col);
                    printf("\n");
                    count--;
                }
            }

            else
            {
                printf("�������������ɨ����������ѡ����������\n");
            }
        }

        else
        {
            printf("�����������������룡����");
        }
    }
    if (count == 0)
    {
        printf("��ϲ���ʤ���� �ų���%d����\n", mines);
        display(board1, row, col);
    }
    return;
}