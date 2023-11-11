#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  int num = 0;
  int count = 0;
  for(i = 0; i <= 2; i ++)
  {
    for(a = 0; a<= 9; a ++)
    {
        for(b = 0; b<= 9; b ++)
        {
            for(c = 0; c <= 9; c ++)
            {
                num = i * 1000 + a *100 + b *10 + c;
                printf("%d\n", num);
                if(i == 2)
                {
                    count ++;
                }
                if(a == 2)
                {
                    count ++;
                }
                if(b == 2)
                {
                    count ++;
                }
                if(c == 2)
                {
                    count ++;
                }
                // printf("count\n%d", count);
                if(num == 2020)
                {
                    printf("%d\n", count);
                    int z = 0;
                    scanf("%d",&z);
                    return 0;
                }
            }
        }
    }
  }
}