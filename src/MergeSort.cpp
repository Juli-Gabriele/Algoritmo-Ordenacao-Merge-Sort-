#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int inicio, int meio, int fim) {
    int i, j, k, n1 = meio - inicio + 1;
    int n2 = fim - meio;

    vector<int> esquerda(n1);
    vector<int> direita(n2);

    for (i = 0; i < n1; i++) {
        esquerda[i] = arr[inicio + i];
    }
    for (j = 0; j < n2; j++) {
        direita[j] = arr[meio + j + 1];
    }

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            arr[k++] = esquerda[i++];
        } else
            arr[k++] = direita[j++];
    }

    while (i < n1) {
        arr[k++] = esquerda[i++];
    }
    while (j < n2) {
        arr[k++] = direita[j++];
    }

}


void mergeSort(vector<int> &arr, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

int main() {

    cout << "Informe o tamanho do vetor:  ";
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);


    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


