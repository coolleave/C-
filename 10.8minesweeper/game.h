#define row 9
#define col 9
#define rows row + 2
#define cols col + 2
#define mines 10

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void initboard(char board[rows][cols], int row1, int col1, char set);                // ��ʼ������
void display(char board[rows][cols], int row1, int col1);                            // չʾ����
void setmines(char board[rows][cols], int row1, int col1);                           // ����
void findmines(char board[rows][cols], char board1[rows][cols], int row1, int col1); // ����
int iswin(char board3[rows][cols], char board4[rows][cols], int row1, int col1, int x1, int y1);
