// Questão 1 – Vetores e Matrizes (1,0 ponto)
// Escreva uma função em C que receba um vetor de inteiros e retorne a soma de seus elementos.

int somaVetor(int *v,int tamanho){
    int soma;
    for(int i = 0; i < tamanho ; i++){
        soma += v[i];
    }

    return soma;
}

// Questão 2 – Recursividade (1,0 ponto)
// Implemente uma função recursiva que calcule o máximo divisor comum (MDC) entre dois números inteiros.

int mdc(int a, int b){
    if(b == 0) return a;

    return mdc(b,a % b);
}

// Questão 5 – Pesquisa Linear e Binária (1,0 ponto)
// Implemente uma função que realize a busca linear em um vetor de inteiros.

int busca(int *v, int tamanho, int valor){
    for (int i = 0;i < tamanho; i++){
        if(valor == v[i]){
            return i;
        }
    }

    return NULL;
}

// BÔNUS – Remoção em ABB (1,0 ponto)
// Implemente a função de remoção de um nó em uma árvore binária de busca (ABB).

No* remover(No *raiz, int valor){
    if(raiz == NULL){
        return -1;
    } else {
        if(raiz->valor == valor){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            } else {
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                   No *aux = malloc(sizeof(No));
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }

                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esquerda = remover(raiz->esquerda, valor);
                    return raiz;
                } else {
                    No* aux;
                    if(raiz->esquerda != NULL){
                        aux = raiz->esquerda;
                    } else {
                        aux = raiz->direita;
                    }

                    free(raiz);
                    return aux;
                }
            }
        } else {
            if(valor < raiz->valor){
                raiz->esquerda = remover(raiz->esquerda , valor);
            } else {
                raiz->direita = remover(raiz->direita, valor);
            }
        }

        return raiz;
    }
}

// Questão 1 - Vetores Unidimensionais e Bidimensionais (1 ponto)

// Considere um vetor int v[5] = {2, 4, 6, 8, 10}; e uma matriz int m[2][2] = {{1, 2}, {3, 4}};. Escreva um trecho de código em C que exiba todos os elementos do vetor e da matriz.

void exibir(int v[], int m[][]){
    for(int i = 0;i < tamanho ; i++){
        for (int j = 0;j < tamanho; j++){
            printf("\nvetor : %d || matriz: %d",v[i], m[i][j]);
        }
    }
}