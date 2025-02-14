#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL){
            *fila = novo;
        } else {
            aux = *fila;
            while(aux->proximo){
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria.");
    }
}

No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    } else {
        printf("Vila vazia.");
    }

    return remover;
} 

int main(){
    return 0;
}