#include <stdio.h>
#include <stdlib.h>

void selection(int *v,int tamanho){
    int menor;
    
    for (int i = 0; i <  tamanho; i++)
    {
        menor = i;
        for(int j = i; j < tamanho; j++){
            if(v[j] < v[menor]){
                menor = j;
            }

            int aux = v[j];
            v[j] = v[menor];
            v[menor] = aux;
        }
    }
    
}

int main(){
    return 0;
}