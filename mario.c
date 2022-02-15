#include <stdio.h>
#include <stdlib.h>

int main () {
    printf("*********************************************\n");
    printf("**   Bem vindo ao nosso jogo Mario Brother **\n");
    printf("*********************************************\n\n\n");

	int n;
	do
	{
	printf("Digite o tamanho da altura: ");
	scanf("%d", &n);
	}
	while(n < 1 || n > 8);
    
	for (int i =0 ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i + j < n -1)
			{
				printf(" ");
			}
			else{
				printf("#");
			}
		}
		
	printf("\n");
	}
	
}	

