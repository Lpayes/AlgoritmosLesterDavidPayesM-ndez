#include <iostream>
#include <string>
using namespace std;

// Definición de una estructura para un Producto
struct Producto {
    int codigo;
    string nombre;
    int cantidad;
};

// Definir un tamaño máximo para el inventario
const int MAX_PRODUCTOS = 100;
Producto inventario[MAX_PRODUCTOS];
int totalProductos = 0;

// Función para agregar un producto al inventario
void agregarProducto() {
    if (totalProductos < MAX_PRODUCTOS) {
        Producto nuevoProducto;
        cout << "Ingrese el código del producto: ";
        while (!(cin >> nuevoProducto.codigo)) {  // Validación de número
            cout << "Error: Ingrese un número válido para el código: ";
            cin.clear();  // Limpiar estado de error
            cin.ignore(1000, '\n');  // Descartar la entrada no válida
        }

        cin.ignore();  // Limpiar el buffer antes de leer cadenas
        cout << "Ingrese el nombre del producto: ";
        getline(cin, nuevoProducto.nombre);  // Leer el nombre del producto

        cout << "Ingrese la cantidad del producto: ";
        while (!(cin >> nuevoProducto.cantidad)) {  // Validación de número
            cout << "Error: Ingrese un número válido para la cantidad: ";
            cin.clear();  // Limpiar estado de error
            cin.ignore(1000, '\n');  // Descartar la entrada no válida
        }

        inventario[totalProductos] = nuevoProducto;
        totalProductos++;  // Actualizar el número total de productos
        cout << "Producto agregado exitosamente.\n";
    } else {
        cout << "El inventario está lleno.\n";
    }
}

// Función para mostrar todos los productos del inventario
void mostrarProductos() {
    if (totalProductos == 0) {
        cout << "No hay productos en el inventario.\n";
    } else {
        cout << "Inventario de productos:\n";
        for (int i = 0; i < totalProductos; i++) {  // Cambiado a < totalProductos
            cout << "Código: " << inventario[i].codigo
                 << " | Nombre: " << inventario[i].nombre
                 << " | Cantidad: " << inventario[i].cantidad << endl;
        }
    }
}

// Función para actualizar la cantidad de un producto
void actualizarProducto() {
    int codigo;
    cout << "Ingrese el código del producto a actualizar: ";
    while (!(cin >> codigo)) {  // Validación de número
        cout << "Error: Ingrese un número válido para el código: ";
        cin.clear();  // Limpiar estado de error
        cin.ignore(1000, '\n');  // Descartar la entrada no válida
    }

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            cout << "Ingrese la nueva cantidad: ";
            while (!(cin >> inventario[i].cantidad)) {  // Validación de número
                cout << "Error: Ingrese un número válido para la cantidad: ";
                cin.clear();  // Limpiar estado de error
                cin.ignore(1000, '\n');  // Descartar la entrada no válida
            }
            cout << "Cantidad actualizada exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función para eliminar un producto del inventario
void eliminarProducto() {
    int codigo;
    cout << "Ingrese el código del producto a eliminar: ";
    while (!(cin >> codigo)) {  // Validación de número
        cout << "Error: Ingrese un número válido para el código: ";
        cin.clear();  // Limpiar estado de error
        cin.ignore(1000, '\n');  // Descartar la entrada no válida
    }

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            for (int j = i; j < totalProductos - 1; j++) {  // Corregido el rango
                inventario[j] = inventario[j + 1];
            }
            totalProductos--;  // Decrementar el número total de productos
            cout << "Producto eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función principal con menú
int main() {
    int opcion;
    do {
        cout << "\n--- Sistema de Gestión de Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Actualizar cantidad de producto\n";
        cout << "4. Eliminar producto\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        while (!(cin >> opcion)) {  // Validación de número para la opción
            cout << "Error: Ingrese una opción válida (número): ";
            cin.clear();  // Limpiar estado de error
            cin.ignore(1000, '\n');  // Descartar la entrada no válida
        }

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                actualizarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}
//Lester David Payes Méndez 0905-24-22750