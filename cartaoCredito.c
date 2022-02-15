#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)

{
    long num_cart = get_long("digite número cartão sem traços ou pontos: ");


    int veri_par = 0;
    int totalpar = 0;
    int totalimpar = 0;
    int compr = 0;


    int empres = 0;


    while (num_cart > 0){


        int n = num_cart % 10;

        veri_par++;

        if (veri_par % 2 == 0)
        {
            n *=2;
            if (n >= 10)
            {
                n = (n % 10) + (n / 10);
            }

            totalpar += n;
        }
        else
        {
            totalimpar += n;
        }

        if (num_cart < 100 && num_cart > 10)
        {
            if (num_cart == 34 || num_cart == 37)
                (empres = 1);
            else if (num_cart >= 40 && num_cart < 50)
                (empres = 2);
            else if (num_cart > 50 && num_cart < 56)
                (empres = 3);
        }

        num_cart = num_cart / 10;
    }
}
