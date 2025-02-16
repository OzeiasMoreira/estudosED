#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_no_incio(No **lista,int num){
    No *novo = malloc(sizeof(No));

    if(novo){  
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        return -1;
    }
}

void inserir_no_meio(No **lista,int num,int ant){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;

        }
    } else {
        return -1;
    }
}

void inserir_no_fim(No **lista,int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*lista == NULL){
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }
    } else {
        return -1;
    }
}

void inserir_ordenado(No **lista,int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else if(novo->valor < (*lista)->valor){

        }
    } else {
        return -1;
    }
}

int main(){
    return 0;
}