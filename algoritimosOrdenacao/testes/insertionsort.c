#include <stdio.h>
#include <stdlib.h>

void insertion(int *v,int fim,int tamanho){

    if (fim >= tamanho) return;

    int aux , j = fim;

    aux = v[j];

    while (j > 0 && aux < v[j - 1])
    {
        v[j] = v[j - 1];
        j--;
    }
    
    v[j] = aux;
    insertion(v, fim  + 1 ,tamanho);
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

    int vetor[] = {5, 34, 54 , 2 , 1 , 45, 78, 12, 34 , 21};

    imprimir(vetor , 9);
    insertion(vetor ,1, 10);
    imprimir(vetor , 9);
    return 0;
}