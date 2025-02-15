#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila,int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL){
            *fila = novo->proximo;
        } else {
            aux = *fila;
            while(aux->proximo){
                aux->proximo = aux;
                
            }

            aux->proximo = novo;
        }
    } else {
        return -1;
    }
}

No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;

    } else {
        return -1;
    }

    return remover;

}

void imprimir(No *fila){
    printf("\t ----- FILA ------ \n\t");
    while (fila)
    {
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    
    printf("\n\t----- FIM FILA -------\n");
}

int main(){
    return 0;
}