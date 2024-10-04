#include <stdio.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para criar um heap máximo
void heapify(int arr[], int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;    
    int right = 2 * i + 2;  

    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }


    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursivamente fazer o heapify no sub-heap afetado
        heapify(arr, n, largest);
    }
}

// Função principal de Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai um elemento do heap de cada vez
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        swap(&arr[0], &arr[i]);

        // Chama o heapify na raiz
        heapify(arr, i, 0);
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}