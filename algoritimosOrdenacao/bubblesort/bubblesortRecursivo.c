#include <stdio.h>
#include <stdlib.h>

void bubble(int *v,int tamanho){
    if(tamanho < 2) return ;
    
    for(int i = 0; i < tamanho - 1; i++){
        if(v[i] > v[i + 1]){                
                
            int aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
            
        }
    }

    bubble (v, tamanho - 1);
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
    bubble(vetor, 5);
    imprimir(vetor, 4);
    return 0;
}