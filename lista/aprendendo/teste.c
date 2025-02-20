#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No ;

void inserir_no_inicio(No *lista, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        return -1;
    }
}

void inserir_no_final(No **lista, int valor){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->proximo = NULL;
        if(*lista == NULL){
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }

            novo = aux->proximo;
        }
    } else {
        return -1;
    }
}

void inserir_no_meio(No **lista,int valor,int ant){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->proximo = NULL;
        if(*lista == NULL){
            *lista = novo;
        } else {
            aux = *lista;
            if(aux->valor != ant && aux->proximo){
                while(aux->proximo){
                    aux = aux->proximo;
                }

                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }
    } else {
        return -1;
    }

}

void inserir_ordenado(No **lista, int valor){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else if (novo->valor != (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else {
        return -1;
    }
}
int main(){
    return 0;
}