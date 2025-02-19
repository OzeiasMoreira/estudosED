#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    short altura;
} NoArv;

NoArv* inserir(No *raiz, int valor){
    NoArv *novo = malloc(sizeof(NoArv));

    if(novo){
        novo->valor = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    } else {
        printf("\nERRO ao alocar.\n");
    }

    return novo;
}

short maior(short a , short b){
    return (a > b) ?  a : b;
} 

short altura(NoArv *raiz){
    if(no == NULL) return -1;

    else return raiz->altura;
}

short fator_balenceamento(NoArv *raiz){
    if(raiz) return altura(raiz->esquerdo) - altura(raiz->direito);

    else return 0;

}

int main(){
    return 0;
}