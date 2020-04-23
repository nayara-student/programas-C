#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    /*<string.h>
    strlen(s1)  Devolve o tamanho da string s1.
    strcpy(s1, s2)  Copia a string s2 para s1.
    strcat(s1, s2)  Concatena s2 ao final de s1.
    strcmp(s1, s2)  Compara a string s1 com s2. Se iguais retorna 0, senão 1
    strchr(s1, ch)  Devolve o endereço de memória da primeira ocorrência do carácter ch na string s1.
    strstr(s1, s2)  Devolve o endereço de memória da primeira ocorrência da string s2 em s1. */

    char s1[80], s2[80];

    //scanf() lê uma palavra (sem espaço, sem tab)
    //gets() lê várias palavras, ou seja, não termina a leitura com o aparecimento de um espaço ou tab

    printf("Escreva duas string, para finalizar a escrita da primeira, dê um espaco: ");
    scanf("%s",s1);
    printf("%s",s2);

    //strlen retorna a quantidade de caracteres
    printf("\nComprimento da primeira string: %d\n",strlen(s1));
    printf("\nComprimento da segunda string: %d\n",strlen(s2));

    //strcmp compara a igualdade entre duas string
    if(strcmp(s1, s2) == 0) printf("As strings são iguais.\n");
    else printf("\nAs strings são diferentes.\n");

    //strcat concatena strings
    strcat(s1, "");
    strcat(s1, s2);

    //imprime a string sem espaço
    puts(s1);

    //strcpy copia uma string para outra
    strcpy(s1, "Isto é um teste.\n");
    puts(s1);

    //strchr procura um CARACTER dentro de uma string
    if(strchr(s2, 'i') != NULL) printf("i está em %s", s2);

    //strstr procura uma STRING dentro de outra
    if(strstr(s1, "to") != NULL) printf("to encontrado em: %s", s1);

    return 0;
}
