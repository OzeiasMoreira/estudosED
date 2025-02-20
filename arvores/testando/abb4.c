#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita,*esquerda;
} No;

No* inserir(No *raiz, int valor){
    No *novo = malloc(sizeof(No));

    if(novo) {
        if(raiz == NULL){
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
            return novo;
        } else {
            if(valor < raiz-> valor){
                raiz->esquerda = inserir(raiz->esquerda,valor);
            } else {
                raiz->direita = inserir(raiz->direita, valor);
            }
        }
    } else {
        return NULL;
    }
}
int main(){
    return 0;
}