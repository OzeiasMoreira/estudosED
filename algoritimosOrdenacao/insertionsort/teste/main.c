#include <stdio.h>
#include <stdlib.h>

void insertion(int *vetor,int fim,int tamanho){
    if(fim >= tamanho) return;

    int aux, j = fim;

    aux = vetor[j];

    while(j > 0 && aux < vetor[j - 1]){
        vetor[j] = vetor[j - 1];
        j --;
    }

    vetor[j] = aux;
    insertion(vetor. fim + 1, tamanho);
}

int main(){
    
    return 0;
}