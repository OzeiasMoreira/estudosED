// # Função que imprime os elementos de uma árvore em ordem simétrica (in-order)

void inOrder(No *raiz){
    if(raiz != NULL){
        inOrder(raiz->esq);
        printf("%lf ", raiz->chave);
        inOrder(raiz->dir);
    }
}

// # Função booleana de busca

int busca(No *raiz, double chave){
    if(raiz == NULL) return 0;
    if(raiz->chave == chave) return 1;
    if(chave < raiz->chave) return busca(raiz->esq, chave);
    return busca(raizz->dir, chave);
}

// # Função de inserção em árvore binária de busca (sem permitir duplicatas)

No* inserir(No *raiz, double chave){
    No* novo = malloc(sizeof(No));

    if(raiz == NULL){
        novo->chave = chave;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if(chave < raiz->chave){
        raiz->esq = inserir(raiz->esq, chave);
    } else if(chave > raiz->chave){
        raiz->dir = inserir(raiz->dir, chave);
    }

    return raiz;
}