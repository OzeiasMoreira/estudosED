// 1. Busca Binária (2 pontos)

// Dado o array ordenado A = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72},
//  execute a busca binária para encontrar o número 23. Mostre os passos da busca.

int buscar(int *v, int valor){
    for(int i = 0;i < tamanho; i++){
        if(v[i] == valor){
            return valor;
        } else {
            return NULL;
        }
    }

    return v;
}

// Implemente um algoritmo em C que utilize uma pilha para inverter uma string inserida pelo usuário.

void inverterString(char c[]){
    int i = 0;
    No *remover , *pilha = NULL;

    while(x[i] != '\0'){
        if(x[i] != ' '){
            pilha = empilhar(pilha, x[i]);
        } else {
            while(pilha){
                remover = desempilhar(&pilha);
                free(remover);
            }
        }

        i++;
    }

    while(pilha){
        remover = desempilhar(&pilha);
        free(remover);
    }
}

// Dado o seguinte conjunto de números {30, 15, 50, 10, 20, 40, 60}, desenhe a árvore binária de busca (BST) 
// resultante e escreva a ordem dos nós em percurso in-ordem.

                30
        15             50
    10     20        40  60