#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio , int fim){
    int pivo = (v[inicio] + v[fim] + v[(inicio + fim) / 2]) / 3;
    while (inicio < fim) {
        while(inicio  < fim && v[inicio] <= pivo){
            inicio = inicio + 1;
        }

        while(inicio < fim && v[fim] > pivo){
            fim = fim -1;
        }

        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }

    return inicio;
}

void quicksort(int *v, int inicio, int fim){
    if(inicio < fim){
        int pos = particiona(v, inicio , fim);
        quicksort(v , inicio , pos - 1);
        quicksort(v , pos , fim);
    } 
}

void imprimir(int *v,int tamanho){
    int i;
    for ( i = 0; i <= tamanho; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    
}

int main(){

    int vetor[] = {47, 23 , 21 , 67 , 45 , 80 , 32 , 11 , 7 , 123 , 99 , 101 , 55};

    imprimir(vetor, 12);
    quicksort(vetor, 0 , 12);
    imprimir(vetor, 12);
    return 0;
}