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

NoArv* remover(NoArv *raiz, int valor){
    if(raiz == NULL){
        printf("\nElemento não encontrado\n");
        return NULL;
    } else {
        if(raiz->valor == valor){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                printf("\nElemento %d removido.\n",valor);
                return NULL;
            } else {
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    NoArv *aux = raiz->esquerda;
                    while (aux->direita != NULL)
                    {
                        aux = aux->direita;
                    }

                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esquerda = remover(raiz->esquerda, valor);
                    return raiz;
                    
                } else {
                    NoArv *aux;
                    if(raiz->esquerda != NULL){
                        aux = raiz->esquerda;
                    } else {
                        aux = raiz->direita;
                    }

                    free(raiz);
                    printf("\nElemento %d removido.\n",valor);
                    return aux;
                }
            }
        }  else {
            if(valor < raiz->valor) {
                raiz->esquerda = remover(raiz->esquerda, valor);
            } else {
                raiz->direita = remover(raiz->direita, valor);
            }

            return raiz;
        }
        
    }

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

    raiz = inserir(raiz , 100);
    raiz = inserir(raiz , 125);
    raiz = inserir(raiz , 50);
    raiz = inserir(raiz , 25);
    raiz = inserir(raiz , 101);
    raiz = inserir(raiz , 150);
    // imprimir(raiz);
    imprimir_ordenado(raiz);
    printf("\nElemento %d encontrado.\n", buscar(raiz, 101)->valor);
    printf("\n Altura da arvore: %d.\n", calcularAltura(raiz));
    printf("\n Quantidade de nos: %d.\n", quantidade_nos(raiz));
    printf("\n Quantidade de folhas: %d.\n", quantidade_folhas(raiz));
    raiz = remover(raiz, 125);
    imprimir_ordenado(raiz);
    return 0;
}