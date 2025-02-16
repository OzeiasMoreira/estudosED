 #include <stdio.h>
 #include <stdlib.h>

 typedef struct no{
    int valor;
    struct no *proximo;
 }No;

 void inserir_no_inicio(No **lista,int num){

    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        return -1;
    }
 }

 void inserir_no_fim(No **lista,int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*lista == NULL){
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }

    } else {
        return -1;
    }

 }

 void inserir_no_meio(No **lista,int num, int ant){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo; 

        } else {
            aux = *lista;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else {
        return -1;
    }
 }

 void imprimir (No *no){
	printf ("\n LIsta: ");
	
	while (no){
		printf ("%d ", no->valor);
		no = no -> proximo;
	}
}                    

 int main(){

    No *lista = NULL;

    inserir_no_inicio(&lista, 45);
    inserir_no_inicio(&lista, 32);
    inserir_no_inicio(&lista,32);
    inserir_no_inicio(&lista, 12);
    inserir_no_inicio(&lista, 11);
    inserir_no_fim(&lista, 87);
    inserir_no_fim(&lista, 67);
    inserir_no_meio(&lista,59,12);
    inserir_no_meio(&lista, 99, 59);
    
    imprimir(lista);
    return 0;
 }