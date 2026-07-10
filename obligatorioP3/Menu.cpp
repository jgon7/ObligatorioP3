#include <iostream>
#include "menu.h"

using namespace std;

void mostrarOpciones() {
    cout << "=========================================\n";
    cout << "      ACADEMIA DE MODA - MENU PRINCIPAL  \n";
    cout << "=========================================\n";
    cout << "1 - Registrar asignatura\n";
    cout << "2 - Agregar previatura\n";
    cout << "3 - Registrar alumno\n";
    cout << "4 - Registrar curso aprobado\n";
    cout << "5 - Listar escolaridad de un alumno\n";
    cout << "6 - Listar previas de una asignatura\n";
    cout << "7 - Determinar asignaturas habilitadas para un alumno\n";
    cout << "8 - Listar alumnos habilitados para una asignatura\n";
    cout << "0 - Salir\n";
    cout << "=========================================\n";
    cout << "Seleccione una opcion: ";
}

void ejecutarMenu(Grafo &g) {
    int opcion;

    do {
        mostrarOpciones();
        cin >> opcion;
        cout << "\n";

        switch (opcion) {
            case 1: {
                cout << "=== Registrar Asignatura ===\n";
                String nombre;
                int horas;
                bool optativa;

                strCrear(nombre);
                cout << "Ingrese nombre: ";
                strScan(nombre);

                cout << "Ingrese horas: ";
                cin >> horas;
                cout << "Es optativa? (1: Si, 0: No): ";
                cin >> optativa;

                registrarAsignatura(g, nombre, horas, optativa);
                strDestruir(nombre);
                break;
            }
            case 2:
                cout << "=== Agregar Previatura ===\n";
                break;
            case 3:
                cout << "=== Registrar Alumno ===\n";
                break;
            case 4:
                cout << "=== Registrar Curso Aprobado ===\n";
                break;
            case 5:
                cout << "=== Listar Escolaridad ===\n";
                break;
            case 6:
                cout << "=== Listar Previas ===\n";
                break;
            case 7:
                cout << "=== Asignaturas Habilitadas ===\n";
                break;
            case 8:
                cout << "=== Alumnos Habilitados ===\n";
                break;
            case 0:
                cout << "Saliendo del sistema. ¡Hasta luego!\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
        cout << "\n";
    } while (opcion != 0);
}
