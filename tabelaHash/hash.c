#include <stdio.h>
#include <stdlib.h>
#define TAM 31 

void inicializarTabela(int tabela[]){
    for(int i = 0;i < TAM;i++){
        tabela[i] = 0;
    }
}

int funcaoHash(int valor){
    return valor % TAM;
}

void inserir(int tabela[], int valor){
    int id = funcaoHash(valor);

    while(tabela[id] != 0){
        id = funcaoHash(id + 1);
    }

    tabela[id] = valor;
}

int buscar(int tabela[],int valor){
    int id = funcaoHash(valor);
    while(tabela[id] != 0){
        if(tabela[id] == valor){
            return tabela[id];
        } else {
            id = funcaoHash(id + 1);
        }
    }

    return 0;

}

void imprimir(int tabela[]){
    for(int i = 0;i < TAM;i++){
        printf("%d = %d\n",i, tabela[i]);
    }
}
int main(){

    int tabela[TAM];

    inserir(tabela, 23);
    inserir(tabela, 7);
    inserir(tabela, 54);
    inserir(tabela, 34);
    inserir(tabela, 12);
    inserir(tabela, 44);
    inserir(tabela, 68);
    imprimir(tabela);
    return 0;
}