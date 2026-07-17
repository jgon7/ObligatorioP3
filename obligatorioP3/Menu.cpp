#include "Menu.h"

using namespace std;

void mostrarOpciones() {

     printf("=========================================\n");
     printf("             MENU PRINCIPAL              \n");
     printf("=========================================\n");
     printf("1 - Registrar asignatura\n");
     printf("2 - Agregar previatura\n");
     printf("3 - Registrar alumno\n");
     printf("4 - Registrar curso a escolaridad alumno\n");
     printf("5 - Listar Asignaturas\n");
     printf("6 - Listar previas de una asignatura\n");
     printf( "7 - Listar datos de un alumno\n");
     printf( "8 - Listar escolaridad de un alumno\n");
     printf( "0 - Salir\n");
     printf( "=========================================\n");
     printf( "Seleccione una opcion: ");
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

void registrarCursoAlumno(Alumnos &alumnos, Asignaturas asignaturas, Grafo &grafo, int cedula, int numeroAsignatura, Fecha fecha, int calificacion) {

    bool ok = true;
    if (!Pertenece(alumnos, cedula)) {
        printf("Error: el alumno no esta registrado.\n");
        ok = false;
    }

    if (ok) {

        Alumno &alumno = Obtener(alumnos, cedula);

        if (aproboAsignatura(escolaridadAlumno(alumno), numeroAsignatura)) {
            printf("Error: el alumno ya aprobo esa asignatura anteriormente.");
            ok = false;
        }
        else if (!tienePreviasInmediatasAprobadas(alumno, grafo, numeroAsignatura)) {
            printf("Error: el alumno no tiene aprobadas todas las previas inmediatas.");
            ok = false;
        }
        else if (!fechaPosteriorOIgualAlUltimoCurso(escolaridadAlumno(alumno), fecha)) {
            printf("Error: la fecha debe ser igual o posterior a la fecha del ultimo curso registrado.");
            ok = false;
        }
        else if (!existeAsignatura(asignaturas, numeroAsignatura)) {
            printf("Error: la asignatura no esta registrada.");
            ok = false;
        }
        else if (!esValidaFecha(fecha)) {
            printf("Error: la fecha no es valida.");
            ok = false;
        }
        else if (calificacion < 0 || calificacion > 12) {
            printf("Error: la calificacion debe estar entre 0 y 12.");
            ok = false;
        }

        if (ok) {
            Asignatura asignatura = obtenerAsignatura(asignaturas, numeroAsignatura);
            Curso curso;
            crearCurso(curso, numeroAsignatura, obtenerNombre(asignatura), fecha, calificacion);
            InsBack(escolaridadAlumno(alumno), curso);
            printf("Curso agregado a la escolaridad correctamente.\n");
        }
    }
}

void mostrarResumenAlumno(Alumnos alumnos) {
    int cedula;

    printf("Ingrese cedula: ");
    scanf("%d", &cedula);

    if (Pertenece(alumnos, cedula)){
        Alumno alumno = Obtener(alumnos, cedula);
         imprimirResumenAlumno(alumno);
    } else {
        printf("Error: el alumno no esta registrado.");
    }
}

void mostrarEscolaridadAlumno(Alumnos alumnos) {
     int cedula;

    printf("Ingrese cedula: ");
    scanf("%d", &cedula);

    if (Pertenece(alumnos, cedula)){
        Alumno alumno = Obtener(alumnos, cedula);
         listarEscolaridad(escolaridadAlumno(alumno));

    } else {
        printf("Error: el alumno no esta registrado.");
    }

}

void registrarPreviatura(Grafo &g, Asignaturas &A, int numAsignatura, int numPrevia) {

    if (!existeAsignatura(A, numAsignatura) || !existeAsignatura(A,numPrevia)) {
        printf("\n Al menos una de las asignaturas ingresadas no existe en el sistema.");
    } else if (ExisteArista(g, numAsignatura, numPrevia, A.tope)) {
        printf("\n No se puede registrar la asignatura por generar un ciclo");
    } else {
        AgregarArista(g, numPrevia, numAsignatura);
        printf("\n Previatura registrada correctamente.");
    }
}

void listarPreviaturas(Asignaturas &A, Grafo G, int numAsignatura) {

    if (existeAsignatura(A, numAsignatura)) {
        bool visitado[cantAsignaturas] = { false };
        int tope = cantAsignaturasRegistradas(A);

        buscarArista(G, numAsignatura, tope, visitado);

        printf("ASIGNATURAS PREVIAS: \n");
        for (int j = 0; j < tope; j++) {
            int numMateriaActual = obtenerNumeroAsignatura(A, j);

            if (visitado[numMateriaActual]) {
                printf("Numero: %d",numMateriaActual);
                printf("\n Nombre: ");
                strPrint(obtenerNombreAsignatura(A, numMateriaActual));
                printf("\n --------------------------------");
            }
        }
    } else {
        printf("La asignatura %d no esta registrada", numAsignatura);
    }

}

void ejecutarMenu(Grafo &G, Asignaturas &AS, Alumnos &AL) {
    int opcion, cedula, horas, opaux, numAsignatura, numPrevia, telefono, calificacion;
    String nombre, apellido;
    bool optativa;
    do {
        mostrarOpciones();
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion) {

            case 1: {
                printf("=== Registrar Asignatura ===\n");
                strCrear(nombre);
                printf("Ingrese nombre: ");
                strScan(nombre);
                printf("Ingrese horas: ");
                scanf("%d", &horas);
                printf("Es optativa? (1: Si, 0: No): ");
                scanf("%d", &opaux);
                optativa = (opaux == 1 ? true : false);
                crearAsignaturas(AS, nombre, horas, optativa);
                strDestruir(nombre);
                break;
            }
            case 2:
                printf("=== Agregar Previatura ===\n");
                printf("Ingrese el numero de la Asignatura: ");
                scanf("%d", &numAsignatura);
                printf("Ingrese el numero de la Asignatura que sera su previa: ");
                scanf("%d", &numPrevia);
                registrarPreviatura(G, AS, numAsignatura, numPrevia);
                break;
            case 3:
                printf("=== Registrar Alumno ===\n");
                strCrear(nombre);
                strCrear(apellido);

                printf("Ingrese cedula: ");
                scanf("%d", &cedula);

                printf("Ingrese nombre: ");
                strScan(nombre);

                printf("Ingrese apellido: ");
                strScan(apellido);

                printf("Ingrese telefono: ");
                scanf("%d", &telefono);

                inscribirAlumno(AL, cedula, nombre, apellido, telefono);

                strDestruir(nombre);
                strDestruir(apellido);
                break;
            case 4:
                printf("=== Registrar Curso ===\n");
                printf("Ingrese cedula del alumno: ");
                scanf("%d", &cedula);
                printf("Ingrese numero de asignatura aprobada: ");
                scanf("%d", &numAsignatura);
                printf("Ingrese fecha (en el formato DD MM YYYY): ");
                Fecha fecha;
                cargarFecha(fecha);
                printf("Ingrese calificacion obtenida: ");
                scanf("%d", &calificacion);
                registrarCursoAlumno(AL, AS, G, cedula, numAsignatura, fecha, calificacion);
                break;
            case 5:
                printf("=== Listar Asignaturas ===\n");
                listarAsignaturas(AS);
                break;
            case 6:
                printf("=== Listar Previas de una asignatura ===\n");
                printf("Ingrese asignatura para listar sus previas: ");
                scanf("%d", &numAsignatura);
                listarPreviaturas(AS, G, numAsignatura);
                break;
            case 7:
                printf("=== Listar datos de un alumno ===\n");
                mostrarResumenAlumno(AL);
                break;
            case 8:
                printf("=== Listar escolaridad ===\n");
                mostrarEscolaridadAlumno(AL);
                break;
            case 0:
                printf("Chau chau! \n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
        printf("\n");
    } while (opcion != 0);
}
