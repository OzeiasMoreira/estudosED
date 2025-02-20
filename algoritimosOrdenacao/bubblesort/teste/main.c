#include <stdlib.h>
#include <stdio.h>

void bubble(int *vetor, int tamanho){
    int aux;

    if(tamanho < 2) return;
    
    for(int i = 0;i < tamanho - 1;i++){
        if(vetor[i] > vetor[i + 1]){
            aux = v[i + 1];
            vetor[i + 1] = vetor[i];
            vetor[i] = aux;
        }
    }

    bubble(vetor, tamanho - 1); 
}

int main(){
    
    return 0;
}