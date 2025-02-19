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
        if(valor < raiz->valor) {
            raiz->esquerda = inserir(raiz->esquerda, valor);
        } else {
            raiz->direita = inserir(raiz->direita, valor);
        }
    }

    return raiz;
}

NoArv* buscar(NoArv *raiz,int valor){
    if(raiz){
        if(valor == raiz) return raiz;

        else if(valor < raiz->esquerda) return buscar(raiz->esquerda, valor);

        else return buscar(raiz->direita, valor);
    }

    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    } else {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq < dir) return esq + 1;

        else return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL) return 0;

    else return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int main(){
    return 0;
}