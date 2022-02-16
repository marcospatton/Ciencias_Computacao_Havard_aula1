#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
int x, y;
int anos = 0;

  // TODO: Solicite o valor inicial ao usuário
    do
    {
    x = get_int("populacao inicial: ");
    }
    while (x < 9);

     // TODO: Solicite o valor final ao usuário
    do
    {
    y = get_int("populacao fim: ");
    }
    while (y < x);

 // TODO: Calcule o número de anos até o limite
        {
        if (x >= y)
        printf("%d\n", x + (x/3 - x/4));
        }

     // TODO: Imprima o número de anos
            {printf("%d\n", (y-x) / (x + (x/3 - x/4)));}
}
