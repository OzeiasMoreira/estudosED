#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita,*esquerda;
} NoArv;

NoArv* inserir(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *novo = malloc(sizeof(NoArv));
        novo->valor = num;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;

    } else {
        if(num < raiz->valor){
            raiz->esquerda = inserir(raiz->esquerda, num);
        } else {
            raiz->direita = inserir(raiz->direita, num);
        }
    }

    return raiz;
}

NoArv* buscar(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor) return raiz;

        else if(num < raiz->valor) return buscar(raiz->esquerda, num);

        else return buscar(raiz->direita, num);
    } 

    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    } else {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir){
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL){
        return 0;
    } else {
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
    }
}

void imprimir_ordenado(NoArv *raiz){
    if(raiz){
        imprimir_ordenado(raiz->esquerda);
        printf("%d ",raiz->valor);
        imprimir_ordenado(raiz->direita);
    } 
}

int main(){

    NoArv *raiz = NULL;

    raiz = inserir(raiz , 34);
    raiz = inserir(raiz , 23);
    raiz = inserir(raiz , 54);
    raiz = inserir(raiz , 27);
    raiz = inserir(raiz , 31);
    raiz = inserir(raiz , 29);
    // imprimir(raiz);
    imprimir_ordenado(raiz);
    printf("\nElemento %d encontrado.\n", buscar(raiz, 29)->valor);
}