#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int *aux = malloc(sizeof(int)) * (fim - inicio + 1);
    
    while(i <= meio && j <= fim){
        if(vetor[i] < vetor[j]){
            aux[k++] = vetor[i++];
        } else {
            aux[k++] = vetor[j++];
        }
    }

    while(i <= meio){
        aux[k++] = vetor[i++];
    }

    while(j <= fim){
        aux[k++] = vetor[j++];
    }

    for(i = inicio; i <= fim; i++){
        vetor[i] = aux[i - inicio];
    }

    free(aux);
    
}

void mergesort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

int main(){
    return 0;
}