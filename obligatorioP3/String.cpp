#include "String.h"
#include <iostream>

using namespace std;

int largo(String s) {
    int i = 0;

    while (s != NULL && s[i] != '\0') {
        i++;
    }
    return i;
}

void copiarCaracteres(String destino, String origen) {
    int i = 0;

    while (origen != NULL && origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

void strCrear(String &s) {
    s = new char[1];
    s[0] = '\0';
}

void strDestruir(String &s) {
    if (s != NULL) {
        delete[] s;
        s = NULL;
    }
}

void strCop(String &s1, String s2) {
    strDestruir(s1);

    if (s2 == NULL) {
        strCrear(s1);
    } else {
        s1 = new char[largo(s2) + 1];
        copiarCaracteres(s1, s2);
    }
}

void strScan(String &s) {
    char buffer[MAX + 1];

    cin.getline(buffer, MAX + 1);
    strCop(s, buffer);
}

void strPrint(String s) {
    if (s != NULL) {
        cout << s;
    }
}

bool strEq(String s1, String s2) {
    int i = 0;

    if (s1 == NULL || s2 == NULL) {
        return s1 == s2;
    }
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] == s2[i];
}
