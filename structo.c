 
Anotações da Aula 3
Nesta aula, vimos sobre...
Revisão ao Módulo Anterior
Busca
Big O
Pesquisa linear, pesquisa binária
Realizando a busca em código
Structs
Ordenação
Selection sort
Bubble sort
Recursão
Merge sort
Quero compartilhar meu aprendizado e/ou minha dúvida...
Ir para o Fórum Ir para o Discord

Recomendamos que você leia as anotações da aula, isso pode te ajudar!

 

Módulo Anterior
Aprendemos sobre ferramentas para resolver problemas, ou bugs, em nosso código. Em particular, descobrimos como usar um depurador, uma ferramenta que nos permite percorrer lentamente nosso código e examinar os valores na memória enquanto nosso programa está em execução.

Outra ferramenta poderosa, embora menos técnica, é a duck debugging (“depuração de pato de borracha”), onde tentamos explicar o que estamos tentando fazer com um pato de borracha (ou algum outro objeto) e, no processo, encontramos o problema (e esperamos, a solução!) sozinhos.

Olhamos para a memória, visualizando bytes em uma grade e armazenando valores em cada caixa, ou byte, com variáveis ​​e matrizes.

 

Busca/Searching
Acontece que, com matrizes, um computador não pode olhar para todos os elementos de uma vez. Em vez disso, um computador só pode olhar para eles um de cada vez, embora a ordem possa ser arbitrária. (Lembre-se de que, na semana 0, David só conseguia olhar uma página de cada vez na lista telefônica, quer folheasse em ordem ou de maneira mais sofisticada.)

Searching (“busca”) é como resolvemos o problema de encontrar um valor específico. Um caso simples pode ter como input algum array de valores, e a saída pode ser simplesmente um bool, esteja ou não um determinado valor no array.

Hoje veremos algoritmos de pesquisa. Para discuti-los, consideraremos o tempo de execução, ou quanto tempo um algoritmo leva para ser executado dado algum tamanho de input.

 

Big O
Na semana 0, vimos diferentes tipos de algoritmos e seus tempos de execução:

”Gráfico

Lembre-se de que a linha vermelha está pesquisando linearmente, uma página por vez; a linha amarela está pesquisando duas páginas por vez; e a linha verde está pesquisando logaritmicamente, dividindo o problema pela metade a cada vez.

E esses tempos de execução são para o pior caso, ou o caso em que o valor leva mais tempo para ser encontrado (na última página, ao contrário da primeira página).

A maneira mais formal de descrever cada um desses tempos de execução é com a notação Big O(“grande O”), que podemos pensar como “na ordem de”. Por exemplo, se nosso algoritmo for uma pesquisa linear, ele levará aproximadamente O (n) etapas, lidas como “grande O de n” ou “na ordem de n”. Na verdade, mesmo um algoritmo que analisa dois itens por vez e executa n / 2 etapas tem O (n). Isso ocorre porque, à medida que n fica cada vez maior, apenas o fator dominante, ou o maior termo, n, importa. No gráfico acima, se afastássemos o zoom e mudássemos as unidades em nossos eixos, veríamos as linhas vermelha e amarela ficando muito próximas.

Um tempo de execução logarítmico é O (log ⁡ n), não importa qual seja a base, pois isso é apenas uma aproximação do que acontece fundamentalmente com o tempo de execução se n for muito grande.

Existem alguns tempos de execução comuns:

O(n²)
O (n log ⁡ n)
O(n)
(pesquisando uma página por vez, em ordem)
O (log ⁡ n)
(dividindo a lista telefônica pela metade a cada vez)
O (1)
Um algoritmo que executa um número constante de etapas, independentemente do tamanho do problema.
Os cientistas da computação também podem usar a notação big Ω, grande Omega, que é o limite inferior do número de etapas de nosso algoritmo. Big O é o limite superior do número de etapas ou o pior caso.

E temos um conjunto semelhante de tempos de execução mais comuns para big Ω:

Ω (n²)
Ω (nlog ⁡ n)
Ω (n)
Ω (log ⁡ n)
Ω (1)
(pesquisar em uma lista telefônica, pois podemos encontrar nosso nome na primeira página que verificarmos)
 

Pesquisa linear, pesquisa binária
No palco, temos algumas portas de mentira, com números escondidos atrás delas. Como um computador só pode olhar para um elemento de cada vez em um array, só podemos abrir uma porta de cada vez.

Se quisermos procurar o número zero, por exemplo, teríamos que abrir uma porta por vez, e se não soubéssemos nada sobre os números atrás das portas, o algoritmo mais simples seria ir da esquerda para a direita.

Então, podemos escrever pseudocódigo para busca linear com:

For i from 0 to n–1
    If number behind i'th door
         Return true
Return false
Rotulamos cada uma das n portas de 0 a n – 1 e verificamos cada uma delas em ordem.
“Return false” está fora do for loop, já que só queremos fazer isso depois de olharmos por trás de todas as portas.
O big O para este algoritmo seria O(n), e o limite inferior, big Ω, seria Ω(1).
Se soubermos que os números atrás das portas estão classificados, podemos começar pelo meio e encontrar nosso valor com mais eficiência.

Para busca binária, nosso algoritmo pode ser semelhante a:

If no doors
     Return false
If number behind middle door
     Return true
Else if number < middle door
     Search left half
Else if number > middle door
     Search right half
O limite superior da pesquisa binária é O(log ⁡ n), e o limite inferior também Ω(1), se o número que procuramos estiver no meio, onde começamos.
Com 64 lâmpadas, notamos que a pesquisa linear leva muito mais tempo do que a pesquisa binária, que leva apenas alguns passos.

Desligamos as lâmpadas na frequência de um hertz, ou ciclo por segundo, e a velocidade de um processador pode ser medida em gigahertz, ou bilhões de operações por segundo.

 

Realizando a busca em código
Vamos dar uma olhada em numbers.c :

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    for (int i = 0; i < 7; i++)
    {
         if (numbers[i] == 0)
         {
               printf("Found\n");
               return 0;
         }
    }
    printf("Not found\n");
    return 1;
}
Aqui, inicializamos uma matriz com alguns valores entre chaves e verificamos os itens na matriz, um de cada vez, para ver se eles são iguais a zero (o que estávamos originalmente procurando atrás das portas no palco).
Se encontrarmos o valor zero, retornamos um código de saída 0 (para indicar sucesso). Caso contrário, após nosso loop for, retornamos 1 (para indicar falha).
Podemos fazer o mesmo com os nomes:

· #include · #include · #include · · int main(void) · { · string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"}; · · for (int i = 0; i < 7; i++) · { · if (strcmp(names[i], "Ron") == 0) · { · printf("Found\n"); · return 0; · } · } · printf("Not found\n"); · return 1; · }
Observe que os names é uma matriz ordenada de strings.
Não podemos comparar strings diretamente em C, uma vez que não são um tipo de dados simples, mas sim um array de muitos caracteres. Felizmente, a biblioteca de string tem uma função strcmp (“string compare”) que compara strings para nós, um caractere por vez, e retorna 0 se forem iguais.
Se checarmos apenas strcmp (nomes [i], "Ron") e não strcmp (nomes [i], "Ron") == 0 , então imprimiremos Encontrado mesmo se o nome não for encontrado. Isso ocorre porque strcmp retorna um valor que não é 0 se duas strings não corresponderem, e qualquer valor diferente de zero é equivalente a verdadeiro em uma condição.
 

Structs
Se quisermos implementar um programa que pesquisa uma lista telefônica, podemos querer um tipo de dado para uma “pessoa”, com seu nome e número de telefone.

Acontece que em C podemos definir nosso próprio tipo de dados, ou data structure (“estrutura de dados”), com um struct na seguinte sintaxe:

typedef struct
{
      string name;
      string number;
}
person;
Usamos string para o number, pois queremos incluir símbolos e formatação, como sinais de mais ou hifens.
Nossa estrutura contém outros tipos de dados dentro dela.
Vamos tentar implementar nossa lista telefônica sem structs primeiro:

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Brian", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};
    for (int i = 0; i < 2; i++)
    {
          if (strcmp(names[i], "David") == 0)
          {
               printf("Encontrado %s\n", numbers[i]);
               return 0;
          }
    }
    printf("Nao encontrado\n");
    return 1;
}
Precisamos ter cuidado para garantir que firstname nos names corresponda ao primeiro número em numbers e assim por diante.
Se o nome em um determinado índice i na matriz de names corresponder ao que estamos procurando, podemos retornar o número de telefone em numbers no mesmo índice.
Com structs, podemos ter um pouco mais de certeza de que não teremos erros humanos em nosso programa:

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
     string name;
     string number;
}
person;

int main(void)
{
     person people[2];
     people[0].name = "Brian";
     people[0].number = "+1-617-495-1000";
     people[1].name = "David";
     people[1].number = "+1-949-468-2750";

     for (int i = 0; i < 2; i++)
     {
         if (strcmp(people[i].name, "David") == 0)
         {
              printf("Encontrado %s\n", people[i].number); return 0;
         }
     }
     printf("Não encontrado\n");
     return 1;
}