// Escreva uma função em C que receba uma matriz 3x3 de inteiros 
// e retorne o maior elemento presente nela.

#include <stdio.h>
#include <stdlib.h>

int maiorElemento(int matriz[3][3]){
    int = maior = matriz[0][0];
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }

    return maior;

}

int main(){
    return 0;
}