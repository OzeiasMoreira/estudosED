// # Implemente uma função recursiva em C que calcule o fatorial de um número n, passado como parâmetro.

int fatorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    return n * fatorial(n - 1);
}