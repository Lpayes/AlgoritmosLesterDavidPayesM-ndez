#include <iostream>
using namespace std;

void generarTribonacci(int cantidad) {
    int numero1 = 0, numero2 = 1, numero3 = 1, siguienteNumero;

    cout << numero1 << " " << numero2 << " " << numero3 << " ";

    for (int contador = 3; contador < cantidad; contador++) {
        siguienteNumero = numero1 + numero2 + numero3;
        cout << siguienteNumero << " ";
        numero1 = numero2;
        numero2 = numero3;
        numero3 = siguienteNumero;
    }

    cout << endl;
}

int main() {
    int cantidadNumeros;

    cout << "Ingresar la cantidad de números de la secuencia Tribonacci: ";
    cin >> cantidadNumeros;

    if (cantidadNumeros < 3) {
        cout << "Por favor, ingrese un número mayor o igual a 3." << endl;
        return 1;
    }

    generarTribonacci(cantidadNumeros);

    return 0;
    //Lester David Payes Méndez 0905-24-22750
}