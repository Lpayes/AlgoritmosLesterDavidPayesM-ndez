#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <vector>vector

using namespace std;

struct Estudiante {
    string codigo;
    string nombres;
    string apellidos;
    string carrera;
    string departamento;
    string municipio;
    string aldea;
    string telefono_personal;
    string telefono_casa;
    string telefono_emergencia;
    string fecha_nacimiento;
    int edad;
    int anio_ingreso;
    string correo;

    // Constructor
    Estudiante(string _nombres, string _apellidos, string _carrera, string _departamento, 
                string _municipio, string _aldea, string _telefono_personal, string _telefono_casa, 
                string _telefono_emergencia, string _fecha_nacimiento, int _anio_ingreso, string _correo, int numEstudiantes) {
        nombres = _nombres;
        apellidos = _apellidos;
        carrera = _carrera;
        departamento = _departamento;
        municipio = _municipio;
        aldea = _aldea;
        telefono_personal = _telefono_personal;
        telefono_casa = _telefono_casa;
        telefono_emergencia = _telefono_emergencia;
        fecha_nacimiento = _fecha_nacimiento;
        anio_ingreso = _anio_ingreso;
        correo = _correo;

        // Calcular la edad y generar el código
        edad = calcularEdad(fecha_nacimiento);
        codigo = to_string(anio_ingreso) + carrera[0] + to_string(numEstudiantes + 1); // Generación de código único por estudiante
    }

    // Método para calcular la edad
    int calcularEdad(const string& fecha_nacimiento) {
        int dia, mes, anio;
        sscanf(fecha_nacimiento.c_str(), "%d/%d/%d", &dia, &mes, &anio);
        
        time_t t = time(0);
        tm* now = localtime(&t);
        
        int edad = now->tm_year + 1900 - anio;

        if (now->tm_mon + 1 < mes || (now->tm_mon + 1 == mes && now->tm_mday < dia)) {
            edad--;
        }

        return edad;
    }
};

// Función para seleccionar una carrera
string seleccionarCarrera() {
    string carrera;
    cout << "Seleccione la carrera:" << endl;
    cout << "1. Ingeniería en Sistemas" << endl;
    cout << "2. Ingeniería Civil" << endl;
    cout << "3. Derecho" << endl;
    cout << "4. Psicología" << endl;
    int opcion;
    
    while (true) {
        cin >> opcion;
        if (cin.fail() || opcion < 1 || opcion > 4) { // Validar la entrada
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
            cout << "Opción no válida. Intente de nuevo: ";
        } else {
            break; // Salir del bucle si la entrada es válida
        }
    }

    switch(opcion) {
        case 1: carrera = "Ingeniería en Sistemas"; break;
        case 2: carrera = "Ingeniería Civil"; break;
        case 3: carrera = "Derecho"; break;
        case 4: carrera = "Psicología"; break;
    }
    cin.ignore(); // Limpiar el buffer después de leer un número
    return carrera;
}

// Contador de estudiantes y vector para almacenar estudiantes
int contadorEstudiantes = 0;
vector<Estudiante> estudiantes; // Vector para almacenar estudiantes

// Estructura para almacenar cursos
struct Curso {
    string nombre;
    string carrera;
};

// Cursos por carrera
vector<Curso> cursosSistemas = {
    {"Programación I", "Ingeniería en Sistemas"},
    {"Estructuras de Datos", "Ingeniería en Sistemas"},
    {"Base de Datos", "Ingeniería en Sistemas"},
    {"Redes de Computadoras", "Ingeniería en Sistemas"},
    {"Ingeniería de Software", "Ingeniería en Sistemas"}
};

vector<Curso> cursosCivil = {
    {"Cálculo I", "Ingeniería Civil"},
    {"Mecánica de Fluidos", "Ingeniería Civil"},
    {"Resistencia de Materiales", "Ingeniería Civil"},
    {"Construcción Civil", "Ingeniería Civil"},
    {"Geotecnia", "Ingeniería Civil"}
};

vector<Curso> cursosDerecho = {
    {"Introducción al Derecho", "Derecho"},
    {"Derecho Civil", "Derecho"},
    {"Derecho Penal", "Derecho"},
    {"Derecho Administrativo", "Derecho"},
    {"Derecho Internacional", "Derecho"}
};

vector<Curso> cursosPsicologia = {
    {"Psicología General", "Psicología"},
    {"Psicología del Desarrollo", "Psicología"},
    {"Psicología Social", "Psicología"},
    {"Psicología Clínica", "Psicología"},
    {"Neuropsicología", "Psicología"}
};

// Función para validar la fecha
bool validarFecha(const string& fecha) {
    int dia, mes, anio;
    sscanf(fecha.c_str(), "%d/%d/%d", &dia, &mes, &anio);
    
    // Verificar que la fecha sea válida
    if (anio < 2023 || anio > 2024) return false; // No puede ser un año muy antiguo o futuro
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;
    
    // Verificar días del mes
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;
    if (mes == 2) {
        bool bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        if (bisiesto && dia > 29) return false;
        if (!bisiesto && dia > 28) return false;
    }
    return true;
}

// Función para registrar un estudiante
void registrarEstudiante() {
    string nombres, apellidos, carrera, departamento, municipio, aldea, telefono_personal, telefono_casa, telefono_emergencia, fecha_nacimiento;
    int anio_ingreso;
    string correo;

    // Seleccionar la carrera antes de registrar el estudiante
    carrera = seleccionarCarrera();

    cout << "Ingrese los nombres del estudiante: "; 
    getline(cin, nombres);
    
    cout << "Ingrese los apellidos del estudiante: "; 
    getline(cin, apellidos);
    
    cout << "Ingrese el departamento: "; 
    getline(cin, departamento);
    
    cout << "Ingrese el municipio: "; 
    getline(cin, municipio);
    
    cout << "Ingrese la aldea (opcional): "; 
    getline(cin, aldea);
    
    cout << "Ingrese el teléfono personal: "; 
    getline(cin, telefono_personal);
    
    cout << "Ingrese el teléfono de casa: "; 
    getline(cin, telefono_casa);
    
    cout << "Ingrese el teléfono de emergencia: "; 
    getline(cin, telefono_emergencia);
    
    cout << "Ingrese la fecha de nacimiento (dd/mm/yyyy): "; 
    getline(cin, fecha_nacimiento);
    while (!validarFecha(fecha_nacimiento)) {
        cout << "Fecha no válida. Intente de nuevo (dd/mm/yyyy): ";
        getline(cin, fecha_nacimiento);
    }

    cout << "Ingrese el año de ingreso a la universidad: "; 
    while (true) {
        cin >> anio_ingreso;
        if (cin.fail() || anio_ingreso < 1900 || anio_ingreso > 2024) { // Validar la entrada
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
            cout << "Entrada no válida. Intente de nuevo: ";
        } else {
            break; // Salir del bucle si la entrada es válida
        }
    }
    cin.ignore(); // Limpiar el buffer después de la entrada numérica

    cout << "Ingrese el correo electrónico: "; 
    getline(cin, correo);

    // Crear el estudiante usando el constructor
    Estudiante estudiante(nombres, apellidos, carrera, departamento, municipio, aldea, 
                          telefono_personal, telefono_casa, telefono_emergencia, 
                          fecha_nacimiento, anio_ingreso, correo, contadorEstudiantes);

    cout << "Estudiante registrado con éxito! Código asignado: " << estudiante.codigo 
         << " | Edad: " << estudiante.edad << endl;

    // Almacenar el estudiante en el vector
    estudiantes.push_back(estudiante);
    // Incrementar el contador de estudiantes
    contadorEstudiantes++;
}

// Función para asignar cursos a un estudiante
void asignarCurso() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "Seleccione un estudiante para asignar un curso: " << endl;
    for (int i = 0; i < estudiantes.size(); i++) {
        cout << i + 1 << ". " << estudiantes[i].nombres << " " << estudiantes[i].apellidos 
             << " | Código: " << estudiantes[i].codigo << endl;
    }

    int opcion;
    cout << "Ingrese el número del estudiante: ";
    cin >> opcion;
    cin.ignore(); // Limpiar el buffer
    opcion--; // Ajustar el índice

    if (opcion < 0 || opcion >= estudiantes.size()) {
        cout << "Opción no válida." << endl;
        return;
    }

    // Seleccionar un curso
    string curso;
    cout << "Seleccione un curso para " << estudiantes[opcion].nombres << " " << estudiantes[opcion].apellidos << ":" << endl;
    cout << "1. " << cursosSistemas[0].nombre << endl;
    cout << "2. " << cursosSistemas[1].nombre << endl;
    cout << "3. " << cursosSistemas[2].nombre << endl;
    cout << "4. " << cursosSistemas[3].nombre << endl;
    cout << "5. " << cursosSistemas[4].nombre << endl;
    
    cout << "Ingrese el número del curso: ";
    cin >> opcion; // Utilizando la misma variable para el curso
    cin.ignore(); // Limpiar el buffer

    if (opcion < 1 || opcion > 5) {
        cout << "Opción no válida." << endl;
        return;
    }

    curso = cursosSistemas[opcion - 1].nombre;
    cout << "Curso asignado a " << estudiantes[opcion - 1].nombres << ": " << curso << endl;
}

// Función para mostrar las notas de los estudiantes (solo como ejemplo, sin implementación)
void mostrarNotas() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "Notas de los estudiantes:" << endl;
    for (const auto& estudiante : estudiantes) {
        cout << "Código: " << estudiante.codigo << " | Nombre: " << estudiante.nombres << " " << estudiante.apellidos << endl;
        // Aquí puedes agregar la lógica para mostrar las notas de cada estudiante
    }
}

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "===============================" << endl;
    cout << "Sistema de Registro Universitario" << endl;
    cout << "===============================" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Asignar curso" << endl;
    cout << "3. Mostrar notas de los estudiantes" << endl; // Nueva opción
    cout << "4. Salir" << endl;
}

// Función principal
int main() {
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                asignarCurso();
                break;
            case 3:
                mostrarNotas(); // Llamada a la función para mostrar notas
                break;
            case 4:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

        cout << endl;

    } while (opcion != 4); // Termina el bucle al salir

    return 0;
}