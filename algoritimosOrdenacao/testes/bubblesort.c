#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *v, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho - 1; j++)
        {
            if(v[j] > v[j + 1]){

                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
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