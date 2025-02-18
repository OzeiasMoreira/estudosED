// # Dado o código abaixo, preencha os espaços para que a função troque os valores de duas variáveis usando ponteiros.

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    troca(&x, &y);
    printf("%d %d\n", x, y); 
    return 0;
}