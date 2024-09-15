#include <iostream>
#include <string>
using namespace std;

// Definición de una estructura para un Empleado
struct Empleado {
    int id;
    string nombre;
    float salario;
};

// Definir el tamaño máximo para la lista de empleados
const int MAX_EMPLEADOS = 50;
Empleado empleados[MAX_EMPLEADOS];
int totalEmpleados = 0;

// Función para agregar un empleado
void agregarEmpleado() {
    if (totalEmpleados < MAX_EMPLEADOS) {
        Empleado nuevoEmpleado;

        // Ingresar el ID del empleado, solo permitir números
        cout << "Ingrese el ID del empleado: ";
        while (!(cin >> nuevoEmpleado.id)) {  // Validación de número
            cout << "Error: Ingrese un número válido para el ID: ";
            cin.clear();  // Limpiar estado de error
            cin.ignore(1000, '\n');  // Descartar la entrada no válida
        }

        // Limpiar el buffer antes de leer cadenas
        cin.ignore();  
        cout << "Ingrese el nombre del empleado: ";
        getline(cin, nuevoEmpleado.nombre);  // Leer el nombre del empleado

        // Ingresar el salario del empleado, solo permitir números
        cout << "Ingrese el salario del empleado: ";
        while (!(cin >> nuevoEmpleado.salario)) {  // Validación de número
            cout << "Error: Ingrese un número válido para el salario: ";
            cin.clear();  // Limpiar estado de error
            cin.ignore(1000, '\n');  // Descartar la entrada no válida
        }

        empleados[totalEmpleados] = nuevoEmpleado;
        totalEmpleados++;
        cout << "Empleado agregado exitosamente.\n";
    } else {
        cout << "No se puede agregar más empleados.\n";
    }
}

// Función para mostrar todos los empleados
void mostrarEmpleados() {
    if (totalEmpleados == 0) {
        cout << "No hay empleados registrados.\n";
    } else {
        cout << "Lista de empleados:\n";
        for (int i = 0; i < totalEmpleados; i++) {  // Cambiar <= a < para evitar acceder fuera del rango
            cout << "ID: " << empleados[i].id
                 << " | Nombre: " << empleados[i].nombre
                 << " | Salario: " << empleados[i].salario << endl;
        }
    }
}

// Función para actualizar el salario de un empleado
void actualizarSalario() {
    int id;
    cout << "Ingrese el ID del empleado: ";
    while (!(cin >> id)) {  // Validación de número
        cout << "Error: Ingrese un número válido para el ID: ";
        cin.clear();  // Limpiar estado de error
        cin.ignore(1000, '\n');  // Descartar la entrada no válida
    }

    for (int i = 0; i < totalEmpleados; i++) {
        if (empleados[i].id == id) {
            cout << "Ingrese el nuevo salario: ";
            while (!(cin >> empleados[i].salario)) {  // Validación de número
                cout << "Error: Ingrese un número válido para el salario: ";
                cin.clear();  // Limpiar estado de error
                cin.ignore(1000, '\n');  // Descartar la entrada no válida
            }
            cout << "Salario actualizado exitosamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

// Función para eliminar un empleado
void eliminarEmpleado() {
    int id;
    cout << "Ingrese el ID del empleado a eliminar: ";
    while (!(cin >> id)) {  // Validación de número
        cout << "Error: Ingrese un número válido para el ID: ";
        cin.clear();  // Limpiar estado de error
        cin.ignore(1000, '\n');  // Descartar la entrada no válida
    }

    for (int i = 0; i < totalEmpleados; i++) {
        if (empleados[i].id == id) {
            // Mover todos los empleados después del eliminado una posición hacia adelante
            for (int j = i; j < totalEmpleados - 1; j++) {  // Cambiar <= a < para evitar acceder fuera del rango
                empleados[j] = empleados[j + 1];
            }
            totalEmpleados--;
            cout << "Empleado eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

// Función principal con menú
int main() {
    int opcion;
    do {
        cout << "\n--- Sistema de Gestión de Empleados ---\n";
        cout << "1. Agregar empleado\n";
        cout << "2. Mostrar empleados\n";
        cout << "3. Actualizar salario de empleado\n";
        cout << "4. Eliminar empleado\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        while (!(cin >> opcion)) {  // Validación de número para opción del menú
            cout << "Error: Ingrese un número válido para la opción: ";
            cin.clear();  // Limpiar estado de error
            cin.ignore(1000, '\n');  // Descartar la entrada no válida
        }

        switch (opcion) {
            case 1:
                agregarEmpleado();
                break;
            case 2:
                mostrarEmpleados();
                break;
            case 3:
                actualizarSalario();
                break;
            case 4:
                eliminarEmpleado();
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