#include "Fecha.h"
#include <iostream>

using namespace std;

bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int diasDelMes(int mes, int anio) {
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes < 1 || mes > 12) {
        return 0;
    }
    if (mes == 2 && esBisiesto(anio)) {
        return 29;
    }
    return dias[mes];
}

void cargarFecha(Fecha &fecha) {
    cin >> fecha.dia;
    cin >> fecha.mes;
    cin >> fecha.anio;
}

void mostrarFecha(Fecha fecha) {
    cout << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
}

int darDia(Fecha fecha) {
    return fecha.dia;
}

int darMes(Fecha fecha) {
    return fecha.mes;
}

int darAnio(Fecha fecha) {
    return fecha.anio;
}

bool esValidaFecha(Fecha fecha) {
    if (fecha.anio < 1 || fecha.mes < 1 || fecha.mes > 12) {
        return false;
    }
    return fecha.dia >= 1 && fecha.dia <= diasDelMes(fecha.mes, fecha.anio);
}

bool esMayorFechas(Fecha a, Fecha b) {
    if (a.anio != b.anio) {
        return a.anio > b.anio;
    }
    if (a.mes != b.mes) {
        return a.mes > b.mes;
    }
    return a.dia > b.dia;
}

bool sonIgualesFechas(Fecha a, Fecha b) {
    return a.dia == b.dia && a.mes == b.mes && a.anio == b.anio;
}
