#include <stdio.h>
#include <stdlib.h>

int main () {
    printf("*********************************************\n");
    printf("**   Bem vindo ao nosso jogo Mario Brother **\n");
    printf("*********************************************\n\n\n");

	int i, j, n, chute;
	printf("Digite o tamanho da altura: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++){
        for(j = n - i; j >= 1; j --)
            printf(" ");
		for(j = 1 ; j <= i; j++)
			printf("#");
	
	printf("\n");
}	

if(n == 8){
    printf("Você digitou maior que 8");
}else{
    printf("Você digitou menor que 1");
}

}