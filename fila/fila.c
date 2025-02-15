#include <stdio.h>
#include <stdlib.h>

typedef struct endereco{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50]; 
    int num, cep;
    
}Endereco;

typedef struct contrato{
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
}Contrato;

typedef struct d{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct p{
    char nome[50];
    Data dataNas;
    Endereco end;
    Contrato contrato;
}Pessoa;

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void imprimirData(Data d){
    printf("%d/%d/%d\n",d.dia,d.mes,d.ano);
}

void imprimirEndereco(Endereco end){
    printf("\tEndereco: \n");
    printf("\tRua: %s", end.rua);
    printf("\tBairro: %s",end.bairro);
    printf("\tCidade: %s",end.cidade);
    printf("\tPais: %s",end.pais);
    printf("\tNumero: %d\n",end.num);
    printf("\tCep: %d\n",end.cep );
}

void imprimirContrato(Contrato c){
    printf("\tContrato: %d\n",c.codigo);
    printf("\tCargo: %s\n",c.cargo);
    printf("\tSalario: R$%.2f\n",c.salario);
    printf("\tData de ad.:");
    imprimirData(c.dataAss);

}

void imprimirPessoa(Pessoa p){
    printf("\n\tNome: %s", p.nome);
    printf("\tData de nas.: ");
    imprimirData(p.dataNas);
    imprimirEndereco(p.end);
    imprimirContrato(p.contrato);
}

Data ler(){
    Data d;
    printf("\nDigite a data no formato dd mm aaaa");
    scanf("%d%d%d",&d.dia,&d.mes,&d.ano);
    return d;
}
void inserir_na_fila(No **fila, int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL){
            *fila = novo;
        } else {
            aux = *fila;
            while(aux->proximo){
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria.");
    }
}

No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    } else {
        printf("Vila vazia.");
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

int main(){

    No *fila = NULL;

    inserir_na_fila(&fila, 4);
    inserir_na_fila(&fila , 6);
    inserir_na_fila(&fila, 8);
    inserir_na_fila(&fila , 10);
    inserir_na_fila(&fila, 12);
    inserir_na_fila(&fila , 14);
    imprimir(fila);
    
    return 0;
}