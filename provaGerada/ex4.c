// # Implemente uma função de enfileiramento (enqueue) para uma fila dinâmica de inteiros.

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void enfileirar(Fila* fila, int valor){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->prox = NULL;
        if(*fila == NULL){
            *fila = novo;
        } else {
            aux = *fila;
            while(aux->prox){
                aux = aux->prox;
            }

            aux->prox = novo;
        }
    } else {
        return -1;
    }
}