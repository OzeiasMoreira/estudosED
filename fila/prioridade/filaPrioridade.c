#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

void inserir_na_fila(No **fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            aux = *fila;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }
    }
    else
    {
        printf("Nao eh possivel alocar\n");
    }
}

void inserir_com_prioridade(No **fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            if (num > 59)
            {
                if((*fila)->valor < 60){
                    novo->proximo = *fila;
                    *fila = novo;
                }
                else{
                    aux = *fila;
                    while(aux->proximo && aux->proximo->valor > 59){
                        aux = aux->proximo;

                    }

                    novo->proximo = aux->proximo;
                    aux->proximo = novo;
                }
            }
            else
            {

                aux = *fila;
                while (aux->proximo)
                {
                    aux = aux->proximo;
                }

                aux->proximo = novo;
            }
        }
    }
    else
    {
        printf("Nao eh possivel alocar\n");
    }
}

No *remover_da_fila(No **fila)
{
    No *remover = malloc(sizeof(No));

    if (*fila)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
    {
        printf("fila vazia.\n");
    }

    return remover;
}

void imprimir(No *fila){
    printf("\t ----- FILA ------ \n\t");
    while (fila)
    {
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    
    printf("\n\t----- FIM FILA -------\n");
}

int main()
{

    No *fila = NULL;

    inserir_na_fila(&fila, 40);
    inserir_na_fila(&fila, 14);
    inserir_na_fila(&fila, 54);
    inserir_na_fila(&fila,45);
    inserir_com_prioridade(&fila,56);
    inserir_com_prioridade(&fila,67);
    imprimir(fila);
    return 0;
}