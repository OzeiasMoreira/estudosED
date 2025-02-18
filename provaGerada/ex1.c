// # Escreva uma função em C que receba uma matriz 3x3 de inteiros e retorne o maior elemento presente nela.

#include <stdio.h>
#include <stdlib.h>

void maior(int matriz[][],int tamanho){
    int maior = matriz[tamanho][tamanho];
    for(int i = 0;i < tamanho;i++){
        for(int j = 0;j < tamanho; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j]
            }
        }
    }

    return maior;
}

int main(){
    return 0;
}