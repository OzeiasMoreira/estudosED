#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
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

void inserir_no_meio(No **lista, int num, int ant){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            aux  = *lista;
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

void inserir_ordenado(No **lista,int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else if(novo->valor != (*lista)->valor){
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

No* buscar(No **lista, int num){
    No *aux,*no = NULL;

    aux = *lista;
    while(aux && aux->valor != num){
        aux = aux->proximo;
    }

    if(aux){
        no = aux;
    }

    return no;
}

No* remover(No **lista, int num){
    No *aux,*remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
        } else {
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }

            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    } else {
        return -1;
    }

    return remover;
}

void copiar_lista(No **lista, No **copiar){
    No *aux = *lista;
    while(aux){
        inserir_ordenado(copiar, aux->valor);
        aux = aux->proximo;
    }
}

void imprimir (No *no){
	printf ("\n LIsta: ");
	
	while (no){
		printf ("%d ", no->valor);
		no = no -> proximo;
	}
}

int main(){
    No *lista = NULL;
    No *lista2 = NULL;
    No *lista3 = NULL;
    
    inserir_no_inicio(&lista, 45);
    inserir_no_inicio(&lista, 32);
    inserir_no_inicio(&lista,32);
    inserir_no_inicio(&lista, 12);
    inserir_no_inicio(&lista, 11);
    inserir_no_fim(&lista, 87);
    inserir_no_fim(&lista, 67);
    inserir_no_meio(&lista,59,12);
    inserir_no_meio(&lista, 99, 59);
    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 33);
    inserir_ordenado(&lista, 13);
    inserir_ordenado(&lista, 60);
    inserir_ordenado(&lista2, 4);
    inserir_ordenado(&lista2, 145);
    inserir_ordenado(&lista2, 23);
    inserir_ordenado(&lista2, 654);
    copiar_lista(&lista, &lista3);
    copiar_lista(&lista2, &lista3);
    imprimir(lista3);
    
    return 0;
}