// # Dada a função de busca binária abaixo, identifique os erros e corrija o código para que ele funcione corretamente.

int buscaBinaria(int vet[], int inicio, int fim, int chave) {
    if (inicio > fim) return -1;
    
    int meio = inicio + (fim - inicio) / 2;
    
    if (vet[meio] == chave)
        return meio;
    
    else if (vet[meio] < chave)
        return buscaBinaria(vet, meio + 1, fim, chave);
    
    else
        return buscaBinaria(vet, inicio, meio - 1, chave);
}