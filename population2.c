#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
int x, y;
int anos = 0;

  // TODO: Solicite o valor inicial ao usu�rio
    do
    {
    x = get_int("populacao inicial: ");
    }
    while (x < 9);

     // TODO: Solicite o valor final ao usu�rio
    do
    {
    y = get_int("populacao fim: ");
    }
    while (y < x);

 // TODO: Calcule o n�mero de anos at� o limite
        {
        if (x >= y)
        printf("%d\n", x + (x/3 - x/4));
        }

     // TODO: Imprima o n�mero de anos
            {printf("%d\n", (y-x) / (x + (x/3 - x/4)));}
}
