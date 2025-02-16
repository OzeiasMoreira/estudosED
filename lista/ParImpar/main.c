#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_no_inicio(No **lista,int num){
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

No* buscar(No **lista,int num){
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

void dividir(No **lista, No **P, No **I){
    No *aux = *lista;
    while(aux){
        if(aux->valor > 0){
            if(aux->valor %2 == 0){
                inserir_ordenado(P, aux->valor);
            } else {
                inserir_ordenado(I, aux->valor);
            }
            aux = aux->proximo;
        }
    }

    printf("\n Divisão realizada com sucesso! ");
}

void imprimir (No *no){
	printf ("\n Lista: ");
	
	while (no){
		printf ("%d ", no->valor);
		no = no -> proximo;
	}
}


int main(){
    No *lista = NULL;
    No *par = NULL;
    No *impar = NULL;

    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 33);
    inserir_ordenado(&lista, 13);
    inserir_ordenado(&lista, 60);
    dividir(&lista,&par,&impar);
    imprimir(lista);
    imprimir(par);
    imprimir(impar);
    return 0;
}