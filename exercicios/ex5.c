Implemente uma função de enfileiramento (enqueue) para uma fila dinâmica de inteiros.

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void enfileirar(Fila* f, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->prox = NULL;

        if(f->inicio == NULL){
            f->inicio = novo;
        } else {
            f->fim->prox = novo;
        }
    }

    f->fim = novo;
}


