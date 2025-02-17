#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *v,int n){
    if(n < 2) return;

    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i + 1]){
            int aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
    }

    bubblesort(v , n - 1);
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

    int vetor[] = {5 , 4 , 3 , 2 ,1};
    imprimir(vetor, 4);
    bubblesort(vetor, 5);
    imprimir(vetor, 4);
    return 0;
}