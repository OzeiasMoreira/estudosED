#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
} No;

void inserir_no_inicio(No **lista , int valor){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = *lista;
        novo->anterior = NULL;
        if(*lista ){
            (*lista)->anterior = novo;
            *lista = novo;
        }
    }
}

void inserir_no_fim(No **lista, int valor){
    No *aux*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->proximo = NULL;
        if(*lista == NULL){
            novo->anterior = NULL;
            *lista = novo;

        } else {
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo
            }

            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
}

void inserir_no_meio(No **lista, int valor, int ant){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
}

int main(){
    return 0;
}