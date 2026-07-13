#include "Asignatura.h"
#include <iostream>

using namespace std;

void crearAsignatura(Asignatura &A, int numero, String nombre, int horas, bool optativa){
    strCrear(A.nombreAsignatura);
    A.numeroAsignatura = numero;
    strCop(A.nombreAsignatura, nombre);
    A.cantidadHoras = horas;
    A.optativa = optativa;
}

String obtenerNombre(Asignatura A){
    return A.nombreAsignatura;
}

void mostrarAsignatura(Asignatura A){
    cout << "-----------------------" << endl;
    cout << "NUMERO: \n" << endl;
    cout << A.numeroAsignatura << endl;;
    cout << "\n NOMBRE: \n" << endl;
    strPrint(A.nombreAsignatura);
    cout << "\n HORAS: \n" << endl;
    cout << A.cantidadHoras << endl;
    cout << "\n TIPO ASIGNATURA: \n" << endl;
    if (A.optativa) {
        cout << "Optativa" << endl;
    } else {
        cout << "Obligatoria" << endl;
    }
    cout << "-----------------------" << endl;
}

