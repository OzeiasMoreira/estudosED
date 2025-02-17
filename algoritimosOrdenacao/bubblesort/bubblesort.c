#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *v,int n){

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if(v[i] > v[i + 1]){
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
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

    int vetor[] = {5 , 4 , 3 , 2 ,1};
    bubblesort(vetor, 5);
    imprimir(vetor, 4);
    return 0;
}