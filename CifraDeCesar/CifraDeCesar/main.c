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
    char alfabeto[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //referencial de compara��o
    int tamanho_c = strlen(cifra); //string lenght
    char descod;

    for(int i=0;i<tamanho_c;i++){
        for(int j=0;j<26;j++){ //cada caracter da string cifra[], ser� comparado com uma letra do vetor alfabeto
            if(*(cifra+i) == *(alfabeto+j)){

                descod = *((alfabeto+j)-casas);
                //descod � o valor da letra descodificada.
               //EX: para shiftLeft/casas = 2; se C (na cifra[]) == C (no alfabeto[])
              //ent�o descod vale o �ndice de alfabeto[] - casas, uma vez que foram deslocadas n-casas para a esquerda

                if(descod==0){ //se n�mero de casas = x, ent�o toda opera��o *((alfabeto+j)-casas) em que o �ndice
                              // de alfabeto[j] for menor que x, resultar� em n�mero negativo
                             //os caracteres em que a opera��o resultar em negativo, s�o aqueles caracteres que
                            //dever�o ser deslocados para as posi��es � direita, a contar de = (26 - casas)
                           //este resultado dir� quantas casas finais dever�o ser preenchidas porque simboliza
                          // quantos caracteres a partir do 'A' tiveram suas posi��es "tomadas" e estes dever�o
                         //ocupar as posi��es vazias a contar de (26 - casas).

                    int valor = alfabeto[j]-casas; //sem usar nota��o de apontadores ( *((alfabeto+j)+casas) ),
                                                  //for�a-se a var. valor a ser negativa. Ainda n�o sei o porqu�

                    descod = valor + 26; //diz qual n� posi��o a partir de (26 - casas) o caracter deve ocupar
                                        //poderia ser descod = valor + 25, desde que int valor = alfabeto[j]-(casas-1)
                                       //pois a primeira posi��o de todo vetor em C � zero
                    printf("%c",descod);
                    break;
                }else if(descod>0){
                    printf("%c",descod);
                    break;
                }
            break; //break if externo
            }else{
                continue; //salta para a pr�xima itera��o do la�o, sem exigir o incremento j++
                         //j++ aqui n�o funciona, pois com o pr�prio incremento do for, contaria de 2 em 2
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
