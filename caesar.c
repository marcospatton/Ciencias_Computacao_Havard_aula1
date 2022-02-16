#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
          if (argc != 2)
        { printf("argumento ausente ./caesar key\n");
        return 1;}
       
        string chave = argv[1];
        for (int i = 0, n = strlen(chave); i < n; i++)
        {
        if (isdigit(chave[i]) == false)
         {
         printf("ESQUECEU NÚMERO: ./caesar key\n");
         return 1;
         }
        }

    int key = atoi(argv[1]);
    if (key > 26) // MAIOR 26
    { key %= 26;    }
   
    string p = get_string("TEXTO SIMPLES: ");
    printf("TEXTO CRIPTOGRAFADO: ");
    for (int i = 0, n = strlen(p); i < n; i++)
   
    {
    if ((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z'))
        {
        if ((isupper(p[i]) && p[i] + key > 90) || (islower(p[i]) &&  p[i] + key > 122))
            { p[i] = (int) p[i] - 26;   }
           
        p[i] = (int) p[i] + key; //adiciona a chave ao valor ascii da letra
        }
    printf("%c", p[i]); //escreve a mensagem criptografada
    }
printf("\n");
return 0;
}