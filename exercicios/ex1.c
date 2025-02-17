// #Como descobrir o menor elemento de um vetor com recursão.#

#include <stdio.h>
#include <stdlib.h>

int menor(int *v,int tamanho,int indice){
    if(tamanho == 0) return v[indice];

    else {
        if(v[tamanho] < v[indice]){ 
            return menor(v, tamanho - 1,tamanho);
        } else{

            return menor(v, tamanho - 1, indice);
        }   
    }
}

int main(){

    int vet[] = {34, 43, 32, 56, 12, 2, 24, 11};

    printf("elemento encontrado: %d ", menor(vet, 7 , 0));

    return 0;

}