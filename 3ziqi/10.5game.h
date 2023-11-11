#define row 3
#define col 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 函数声明
void initboard(char arr[row][col], int row1 , int col1);
void display(char arr[row][col], int row1, int col1);
void playermove(char arr[row][col], int row1, int col1);
void commove(char arr[row][col], int row1, int col1);
char iswin(char arr[row][col], int row1, int col1);