#include "Alumnos.h"
#include "Asignaturas.h"
#include "GrafoPreviaturas.h"
#include <iostream>

using namespace std;

void mostrarOpciones() {
    cout << "=========================================\n";
    cout << "             MENU PRINCIPAL              \n";
    cout << "=========================================\n";
    cout << "1 - Registrar asignatura\n";
    cout << "2 - Agregar previatura\n";
    cout << "3 - Registrar alumno\n";
    cout << "4 - Registrar curso aprobado\n";
    cout << "5 - Listar Asignaturas\n";
    cout << "6 - Listar previas de una asignatura\n";
    cout << "7 - Listar datos de un alumno\n";
    cout << "8 - Listar escolaridad de un alumno";
    cout << "0 - Salir\n";
    cout << "=========================================\n";
    cout << "Seleccione una opcion: ";
}


bool tienePreviasInmediatasAprobadas(Alumno alumno, Grafo &grafo, int numeroAsignatura) {
    for (int previa = 0; previa < cantAsignaturas; previa++) {
        if (EsPreviaDirecta(grafo, previa, numeroAsignatura) &&
            !aproboAsignatura(escolaridadAlumno(alumno), previa)) {
            return false;
        }
    }
    return true;
}

bool registrarCursoAlumno(Alumnos alumnos, Asignaturas asignaturas, Grafo &grafo, int cedula, int numeroAsignatura, Fecha fecha, int calificacion) {

    if (hayAlumno(alumnos, cedula)){
        Alumno alumno = obtenerAlumno(alumnos, cedula);
    } else {
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

void mostrarResumenAlumno(Alumnos alumnos) {
    int cedula;

    cout << "Ingrese cedula: ";
    cin(cedula);

    if (hayAlumno(alumnos, cedula)){
        Alumno alumno = obtenerAlumno(alumnos, cedula);
         imprimirResumenAlumno(alumno);
    } else {
        cout << "Error: el alumno no esta registrado." << endl;
        return false;
    }
}

void mostrarEscolaridadAlumno(Alumnos alumnos) {
     int cedula;

    cout << "Ingrese cedula: ";
    cin(cedula);

    if (hayAlumno(alumnos, cedula)){
        Alumno alumno = obtenerAlumno(alumnos, cedula);
         listarEscolaridad(escolaridadAlumno(alumno));

    } else {
        cout << "Error: el alumno no esta registrado." << endl;
        return false;
    }

}

void registrarPreviatura(GrafoPreviaturas &g, Asignaturas &A, int numAsignatura, int numPrevia) {

    if (numAsignatura < 0 || numAsignatura >= A.tope || numPrevia < 0 || numPrevia >= A.tope) {
        cout << "\n Al menos una de las asignaturas ingresadas no existe en el sistema." << endl;
        return;
    }

    if (ExistePreviatura(g, numPrevia, numAsignatura, A.tope)) {
        cout << "\n No se puede registrar la asignatura por generar un ciclo" << endl;
        return;
    }

    AgregarPreviatura(g, numAsignatura, numPrevia);
    cout << "\n Previatura registrada correctamente." << endl;

}

void listarPreviaturas(Asignaturas &A, Grafo G, int numAsignatura) {

    int tope = cantAsignaturasRegistradas(A);

    if (numAsignatura < 0 || numAsignatura >= tope) {
        cout << "La asignatura " << numAsignatura << " no esta registrada." << endl;
        return;
    }

    bool visitado[cantAsignaturas] = { false };

    buscarPreviaturas(G, numAsignatura, tope, visitado);

    cout << "ASIGNATURAS PREVIAS: \n" << endl;
    for (int i = 0; i < tope; i++) {
        if (visitado[i]) {
            cout << "Numero: " << i
                 << "Nombre: " << obtenerNombreAsignatura(A, i)
                 << "--------------------------------" << endl; // [cite: 55]
        }
    }
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

                crearAsignaturas(A, numero, nombre, horas, optativa);
                strDestruir(nombre);
                break;
            }
            case 2:
                cout << "=== Agregar Previatura ===\n";
                int numAsignatura, numPrevia;
                cout << "Ingrese el numero de la Asignatura: ";
                cin >> numAsignatura;
                cout << "Ingrese el numero de la Asignatura que sera su previa: ";
                cin >> numPrevia;
                registrarPreviatura(G, A, numAsignatura, numPrevia)
                break;
            case 3:
                cout << "=== Registrar Alumno ===\n";
                String cedula;
                String nombre;
                String apellido;
                String telefono;

                strCrear(cedula);
                strCrear(nombre);
                strCrear(apellido);
                strCrear(telefono);

                cout << "Ingrese cedula: ";
                strScan(cedula);

                cout << "Ingrese nombre: ";
                strScan(nombre);

                cout << "Ingrese apellido: ";
                strScan(apellido);

                cout << "Ingrese telefono: ";
                strScan(telefono);

                inscribirAlumno(alumnos, cedula, nombre, apellido, telefono);
                strDestruir(cedula);
                strDestruir(nombre);
                strDestruir(apellido);
                strDestruir(telefono);
                break;
            case 4:
                cout << "=== Registrar Curso Aprobado ===\n";
                registrarCursoAlumno(alumnos, A, G, cedula, numeroAsignatura, fecha, calificacion))
                break;
            case 5:
                cout << "=== Listar Asignaturas ===\n";
               listarAsignaturas(A);
                break;
            case 6:
                cout << "=== Listar Previas de una asignatura ===\n";
                listarPreviaturas(A, G, numAsignatura);
                break;
            case 7:
                cout << "=== Listar datos de un alumno ===\n";
                mostrarResumenAlumno(alumnos);
                break;
            case 8:
                cout << "=== Listar escolaridad ===\n";
                mostrarEscolaridadAlumno(alumnos);
                break;
            case 0:
                cout << "Salir \n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
        cout << "\n";
    } while (opcion != 0);
}
