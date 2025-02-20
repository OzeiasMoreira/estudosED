#include <stdio.h>
#include <stdlib.h>

int buscaBinariaRecursiva(int *vetor,int chave, int inicio, int fim){
    int meio;
    if(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(chave == vetor[meio]){
            return meio;
        } else{
            if(chave < vetor[meio]){
                return buscaBinariaRecursiva(vetor,chave,inicio,meio - 1);
            } else {
                return buscaBinariaRecursiva(vetor,chave,meio + 1,fim);
            }
        }
    } else {
        return -1;
    }
}

int main(){

    int vetor [10] = {1,2,3,4,5,6,7,8,9,10};
    printf("elemento encontrado na posicao %d do vetor.\n",buscaBinariaRecursiva(vetor,1,0,9));

    return 0;
}