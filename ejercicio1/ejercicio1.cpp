#include <iostream>
#include <vector>
#include "ejercicio1.h"

using namespace std;

// Crea matriz tamaño n
vector<vector<int>> crearMatriz(int n) {
    vector<vector<int>> matriz(n, vector<int>(n));
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valor++;
        }
    }
    return matriz;
}

// imprime matriz descendente
void imprimirMatrizDescendente(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    int total = n * n;
    for (int k = total - 1; k >= 0; k--) {
        int i = k / n;
        int j = k % n;
        cout << "M[" << i << "][" << j << "] = " << matriz[i][j] << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese un valor entero positivo mayor a 1: ";
    cin >> n;
    if (n <= 1) {
        cout << "El valor debe ser mayor a 1." << endl;
        return 1;
    }
    
    vector<vector<int>> matriz = crearMatriz(n);
    imprimirMatrizDescendente(matriz);
    
    return 0;
}