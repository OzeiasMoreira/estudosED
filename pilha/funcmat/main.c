#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char caracter;
    struct no *proximo;
} No;

No *empilhar(No *pilha, char valor)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
    {
        printf("\tErro ao alocar memoria.\n");
    }

    return NULL;
}

No *desempilhar(No **pilha)
{
    No *remover = NULL;

    if (*pilha)
    {
        remover = *pilha;
        *pilha = remover->proximo;
        return remover;
    }
    else
    {
        printf("\Pilha vazia.\n");
    }

    return remover;
}

void imprimir(No *pilha)
{
    printf("\t---------- PILHA ----------\n");
    while (pilha)
    {
        printf("\t%c\n", pilha->caracter);
        pilha = pilha->proximo;
    }

    printf("\t---------- FIM PILHA ----------\n\n");
}

int forma_par(char f,char d){
    switch (f)
    {
    case ')':
        if(d == '(')
            return 1;
        else 
            return 0;    
        break;
    
    case ']':
        if(d == '[')
            return 1;
        else 
            return 0; 
        break;

    case '}':
        if(d == '{')
            return 1;
        else 
            return 0; 
        break;    
    }
}

int identifica_formacao(char x[]){
    int i = 0;
    No *remover,*pilha = NULL;

    while (x[i] != '\0'){
        if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
            pilha = empilhar(pilha, x[i]);
            imprimir(pilha);
        }

        else if(x[i] == ']' || x[i] == ')' || x[i] == '}'){
            remover = desempilhar(&pilha);
            if(forma_par(x[i], remover->caracter) == 0){
                printf("\tExpressao mal formada.\n");
                return 1;
            }

            free(remover);
        }

        i++;
    }

    imprimir(pilha);
    if(pilha){
        printf("\tExpressao mal formada\n");
        return 1;
    } else {
        printf("\tExpressao bem formada\n");
        return 0;
    }

    
}

int main()
{

    char exp[50];

    printf("\tDigite uma expressao: ");
    scanf("%c49[^\n]",exp);
    printf("\tExpressao: %s\nRetorno: %d\n",exp,identifica_formacao(exp));
    

}