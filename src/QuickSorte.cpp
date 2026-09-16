#include <bits/stdc++.h>

using namespace std;

// Função para trocar dois elementos de posição
void trocar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Particiona o vetor usando o último elemento como pivô
// Retorna o índice final do pivô
int particionar(vector<int> &vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1; // índice do menor elemento

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(vetor[i], vetor[j]);
        }
    }

    trocar(vetor[i + 1], vetor[fim]);
    return i + 1;
}

// Função principal do Quick Sort (recursiva)
void quickSort(vector<int> &vetor, int inicio, int fim) {
    if (inicio < fim) {
        int posPivo = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, posPivo - 1); // ordena a parte esquerda
        quickSort(vetor, posPivo + 1, fim);     // ordena a parte direita
    }
}

// Função auxiliar para imprimir o vetor
void imprimirVetor(const vector<int> &vetor) {
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numeros = {10, 7, 8, 9, 1, 5, 2, 45, 3, 22};

    cout << "Vetor original: ";
    imprimirVetor(numeros);

    quickSort(numeros, 0, numeros.size() - 1);

    cout << "Vetor ordenado: ";
    imprimirVetor(numeros);

    return 0;
}