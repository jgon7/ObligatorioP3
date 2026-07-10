#include "Alumnos.h"
#include "Asignaturas.h"
#include "GrafoPreviaturas.h"
#include <iostream>

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
    cout << "9 - Mostrar Datos de Alumno\n";
    cout << "0 - Salir\n";
    cout << "=========================================\n";
    cout << "Seleccione una opcion: ";
}


static bool tienePreviasInmediatasAprobadas(Alumno alumno, Grafo &grafo, int numeroAsignatura) {
    for (int previa = 0; previa < cantAsignaturas; previa++) {
        if (ExistePreviatura(grafo, previa, numeroAsignatura) &&
            !aproboAsignatura(escolaridadAlumno(alumno), previa)) {
            return false;
        }
    }
    return true;
}

bool registrarCursoAlumno(Alumnos alumnos, Asignaturas asignaturas, Grafo &grafo, String cedula, int numeroAsignatura, Fecha fecha, int calificacion) {
    Alumno alumno = obtenerAlumno(alumnos, cedula);

    if (alumno == 0) {
        cout << "Error: el alumno no esta registrado." << endl;
        return false;
    }
    if (!existeAsignatura(asignaturas, numeroAsignatura)) {
        cout << "Error: la asignatura no esta registrada." << endl;
        return false;
    }
    if (!esValidaFecha(fecha)) {
        cout << "Error: la fecha no es valida." << endl;
        return false;
    }
    if (calificacion < 0 || calificacion > 12) {
        cout << "Error: la calificacion debe estar entre 0 y 12." << endl;
        return false;
    }
    if (aproboAsignatura(escolaridadAlumno(alumno), numeroAsignatura)) {
        cout << "Error: el alumno ya aprobo esa asignatura anteriormente." << endl;
        return false;
    }
    if (!tienePreviasInmediatasAprobadas(alumno, grafo, numeroAsignatura)) {
        cout << "Error: el alumno no tiene aprobadas todas las previas inmediatas." << endl;
        return false;
    }
    if (!fechaPosteriorOIgualAlUltimoCurso(escolaridadAlumno(alumno), fecha)) {
        cout << "Error: la fecha debe ser igual o posterior a la fecha del ultimo curso registrado." << endl;
        return false;
    }

    Asignatura asignatura = obtenerAsignatura(asignaturas, numeroAsignatura);
    Curso curso;
    crearCurso(curso, numeroAsignatura, obtenerNombre(asignatura), fecha, calificacion);
    registrarCurso(escolaridadAlumno(alumno), curso);
    return true;
}

static void mostrarResumenAlumno(Alumnos alumnos) {
    String cedula;
    strCrear(cedula);

    cout << "Ingrese cedula: ";
    strScan(cedula);

    Alumno alumno = obtenerAlumno(alumnos, cedula);
    if (alumno == 0) {
        cout << "Error: el alumno no esta registrado." << endl;
    } else {
        imprimirResumenAlumno(alumno);
    }

    strDestruir(cedula);
}

static void mostrarEscolaridadAlumno(Alumnos alumnos) {
    String cedula;
    strCrear(cedula);

    cout << "Ingrese cedula: ";
    strScan(cedula);

    Alumno alumno = obtenerAlumno(alumnos, cedula);
    if (alumno == 0) {
        cout << "Error: el alumno no esta registrado." << endl;
    } else {
        listarEscolaridad(escolaridadAlumno(alumno));
    }

    strDestruir(cedula);
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
                mostrarEscolaridadAlumno(alumnos);
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
            case 9:
                cout <<  "=== Mostrar Datos de Alumno ===\n";
                mostrarResumenAlumno(alumnos);
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
