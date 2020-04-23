#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40

//TESTE DE MESA SHIFT LEFT = 2

/*
A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z

0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25


C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z  A  B

0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
*/


void shiftLeft(int casas, char *cifra){
    char alfabeto[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //referencial de comparação
    int tamanho_c = strlen(cifra); //string lenght
    char descod;

    for(int i=0;i<tamanho_c;i++){
        for(int j=0;j<26;j++){ //cada caracter da string cifra[], será comparado com uma letra do vetor alfabeto
            if(*(cifra+i) == *(alfabeto+j)){

                descod = *((alfabeto+j)-casas);
                //descod é o valor da letra descodificada.
               //EX: para shiftLeft/casas = 2; se C (na cifra[]) == C (no alfabeto[])
              //então descod vale o índice de alfabeto[] - casas, uma vez que foram deslocadas n-casas para a esquerda

                if(descod==0){ //se número de casas = x, então toda operação *((alfabeto+j)-casas) em que o índice
                              // de alfabeto[j] for menor que x, resultará em número negativo
                             //os caracteres em que a operação resultar em negativo, são aqueles caracteres que
                            //deverão ser deslocados para as posições à direita, a contar de = (26 - casas)
                           //este resultado dirá quantas casas finais deverão ser preenchidas porque simboliza
                          // quantos caracteres a partir do 'A' tiveram suas posições "tomadas" e estes deverão
                         //ocupar as posições vazias a contar de (26 - casas).

                    int valor = alfabeto[j]-casas; //sem usar notação de apontadores ( *((alfabeto+j)+casas) ),
                                                  //força-se a var. valor a ser negativa. Ainda não sei o porquê

                    descod = valor + 26; //diz qual n° posição a partir de (26 - casas) o caracter deve ocupar
                                        //poderia ser descod = valor + 25, desde que int valor = alfabeto[j]-(casas-1)
                                       //pois a primeira posição de todo vetor em C é zero
                    printf("%c",descod);
                    break;
                }else if(descod>0){
                    printf("%c",descod);
                    break;
                }
            break; //break if externo
            }else{
                continue; //salta para a próxima iteração do laço, sem exigir o incremento j++
                         //j++ aqui não funciona, pois com o próprio incremento do for, contaria de 2 em 2
            } //else
        } //for interno
    } //for externo
} //funcao

int main()
{
    char cifra[max];
    printf("Cifra 2: \n");
    scanf("%s",cifra);
    shiftLeft(2, cifra);
    getch();
    return 0;
}
