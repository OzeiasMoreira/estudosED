#include <stdio.h>
#include <stdlib.h>


void selectionSort(int *v,int n){
    int menor;

    for (int i = 0; i < n; i++)
    {
        menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if(v[j] < v[menor]){
                menor = j;

            }

            int aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
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
    int vetor[] = {5, 34, 54 , 2 , 1 , 45, 78, 12, 34 , 21};

    imprimir(vetor , 9);
    selectionSort(vetor , 9);
    imprimir(vetor , 9);

    return 0;
}