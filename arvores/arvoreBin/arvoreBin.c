#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir(NoArv *raiz, int num){
    if(raiz == NULL){
            NoArv *aux = malloc(sizeof(NoArv));
            aux->valor = num;
            aux->esquerda = NULL;
            aux->direita = NULL;
            return aux;
    } else {
        if(num < raiz->valor){
            raiz->esquerda = inserir(raiz->esquerda, num);
        } else {
            raiz->direita = inserir(raiz->direita , num);
        }
        
        return raiz;
    }
}

void imprimir(NoArv *raiz){
    if(raiz){
        printf("%d ",raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    } 
}

NoArv* buscar(NoArv *raiz,int num){
    if(raiz){
        if(num == raiz->valor){
            return raiz;
        } else if (num < raiz->valor) {
            return buscar(raiz->esquerda, num);
        } else {
            return buscar (raiz->direita, num);
        }
    } 

    return NULL;

}

int calcularAltura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    } else {
        int esq = calcularAltura(raiz->esquerda);
        int dir = calcularAltura(raiz->direita);
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
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);;
    }
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL){
        return 0;
    } else if(raiz ->esquerda && raiz->direita == NULL){
        return 1;
    } else {
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
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
    imprimir(raiz);
    imprimir_ordenado(raiz);
    printf("\nElemento %d encontrado.\n", buscar(raiz, 34)->valor);
    printf("\n Altura da arvore: %d.\n", calcularAltura(raiz));
    printf("\n Quantidade de nos: %d.\n", quantidade_nos(raiz));
    printf("\n Quantidade de folhas: %d.\n", quantidade_folhas(raiz));
    return 0;
}