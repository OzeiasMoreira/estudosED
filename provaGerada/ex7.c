// # Complete a função Insertion Sort abaixo:

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        
        while (j && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = chave;
    }
}