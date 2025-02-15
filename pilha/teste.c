#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No *empilhar(No *pilha,int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    } else {
        return -1;
    }

    return NULL;

}

No *desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    } else {
        return -1;
    }

    return remover;
}

void imprimir(No *pilha){
    
    
    while(pilha){
        
        printf("%d ",pilha->valor);
        pilha = pilha->proximo;
        
    }
    
}

int main(){

    No *pilha = NULL;

    pilha = empilhar(pilha, 5);
    pilha = empilhar(pilha, 10);
    pilha = empilhar(pilha, 3);
    imprimir(pilha);

    return 0;
}