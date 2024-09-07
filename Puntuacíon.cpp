#include <iostream>
#include <vector>
using namespace std;

int main() {
    int filas, columnas;

    cout << "Ingrese el número de filas: ";
    cin >> filas;

    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

    vector<vector<int>> matriz(filas, vector<int>(columnas));

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << "Ingrese el valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    int puntuacionTotal = 0;

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if (matriz[i][j] == 5) {
                puntuacionTotal += 5;
            } else if (matriz[i][j] % 2 == 0) {
                puntuacionTotal += 1;
            } else {
                puntuacionTotal += 3;
            }
        }
    }

    cout << "Puntuación total: " << puntuacionTotal << endl;

    return 0;
}
//Lester David Payes Méndez 0905-24-22750
