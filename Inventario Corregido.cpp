#include <iostream>
#include <string>
#include <locale.h>
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
	if (totalProductos <= MAX_PRODUCTOS) {
	Producto nuevoProducto;
	cout << "Ingrese el código del producto: ";
	cin >> nuevoProducto.codigo;
	for (int i = 0; nuevoProducto.codigo  == inventario[i].codigo ; i++) {//esta for es para evaluar los códigos ya existentes. y no agregar el mismo código a dos o más productos
		if (nuevoProducto.codigo  == inventario[i].codigo) {
		cout << "Este código ya esta en uso." <<endl;
		cout <<"Ingrese el código del producto: ";
		cin >> nuevoProducto.codigo;
		}
	}
	cin.ignore(); // Limpiar el buffer antes de leer cadenas
	cout << "Ingrese el nombre del producto: ";
	// getline(cin, nuevoProducto.nombre);
	cin>> nuevoProducto.nombre;
	cout << "Ingrese la cantidad del producto: ";
	cin >> nuevoProducto.cantidad;
	inventario[totalProductos] = nuevoProducto;
	// totalProductos += 1;
	totalProductos +=1; //Linea agregada
	cout << "Producto agregado exitosamente.\n";
	// cout << "Total de productos: " << totalProductos << endl;
	cout <<"Total de productos: " <<totalProductos <<endl; //Linea agreada
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
	for (int i = 0; i < totalProductos; i++) { //tiene que ser i<total producto, si es <= se mostrara un producto extra con los valores de 0
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
	cin >> codigo;
	for (int i = 0; i < totalProductos; i++) {
	if (inventario[i].codigo == codigo) {
	cout << "Ingrese la nueva cantidad: ";
	cin >> inventario[i].cantidad;
	// Falta mensaje de confirmación aquí
	cout<<"Nueva cantidad agregada exitosamente." <<endl;
	cout <<"Total de productos: " <<inventario[i].cantidad <<endl;
	return;
	}
	}
	cout << "Producto no encontrado.\n";
}

// Función para eliminar un producto del inventario
void eliminarProducto() {
	int codigo;
	cout << "Ingrese el código del producto a eliminar: ";
	cin >> codigo;
	for (int i = 0; i < totalProductos; i++) {
		if (inventario[i].codigo == codigo) {
			for (int j = i; j < totalProductos - 1; j++) { // Error: debe ser j < totalProductos - 1;
			inventario[j] = inventario[j + 1];
			}
			// totalProductos --;
			totalProductos --;
			cout <<"Producto Eliminado con exito." <<endl;
			return;
		}
	}
	cout << "Producto no encontrado.\n";
}

// Función principal con menú
int main() {
	setlocale(LC_CTYPE, "Spanish");
	int opcion;
	do {
	cout << "\n--- Sistema de Gestion de Inventario ---\n";
	cout << "1. Agregar producto\n";
	cout << "2. Mostrar productos\n";
	cout << "3. Actualizar cantidad de producto\n";
	cout << "4. Eliminar producto\n";
	cout << "5. Salir\n";
	cout << "Seleccione una opcion: ";
	cin >> opcion;
	// cin.ignore();
	cin.clear(); // Agregue esta función para evitar un bucle a la hora de agregar un caracter o numero que no corresponde al solicitado.
				//en este caso me sucedio al presionar por error el punto ( . ). Esto me genero el bucle
	cin.ignore();
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
// Lester David Payes Méndez 0905-24-22750