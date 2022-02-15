#include <stdio.h>
#include<cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Digite a altura: ");
    }
    while( n < 1 || n > 8);

        for (int i = 0; i <= n; i ++)
        {
            for(int k = 1;k < n; k ++)
            {
                printf(" ");
            }
            for(int j = 1; j < i; j++)
            {
                printf("#");
            }
            printf(" ");
            for (int j = 1 ; j < i ; j++)
            {
                printf("#");
            }
            printf("\n");
        }
}