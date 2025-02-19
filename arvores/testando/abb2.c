#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
} NoArv;

NoArv* inserir(NoArv *raiz, int valor){
    if(raiz == NULL){
        NoArv *novo = malloc(sizeof(NoArv));

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if(valor < raiz->valor){
            raiz->esquerda = inserir(raiz->esquerda, valor);
        } else {
            raiz->direita = inserir(raiz->direita, valor);
        }
    }

    return raiz;
}

NoArv* buscar(NoArv *raiz, int valor){
    if(raiz){
        if(valor == raiz->valor) return raiz;

        else if(valor < raiz->valor) return buscar(raiz->esquerda, valor);

        else return buscar(raiz->direita, valor);
    } else {
        return -1;
    }

    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    } else {
        int esq =  altura(raiz->esquerda);
        int dir = altura(raiz->direita);
    }
}

int main(){
    return 0;
}