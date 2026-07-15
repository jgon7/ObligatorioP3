#include "String.h"


void strCrear(String &s){
    s = new char[1];
    s[0] = '\0';
}

int strlar (String s){
    int i = 0;
    while(s[i] != '\0')
        i++;

    return i;
}

    void strScan(String &s) {
        char buffer[256];
        //String aux = new char[MAX];
        int i = 0;
        char c;
        scanf (" %c", &c);
        while (c != '\n' && i < 255)
        {
            buffer[i] = c;
            //aux[i] = c;
            i++;
            scanf("%c", &c);
        }
        //aux[i] = '\0';
        buffer[i] = '\0';
        /*
        strCop(s, aux);
        strDestruir(aux);
        */
        delete [] s;
        s = new char[i + 1];
        for (int j = 0; j <= i; j++) {
            s[j] = buffer[j];
        }
    }
/*
    void strCop(String &s1, String s2) {
        int i = 0;
        int largo = strlar(s2) + 1;
        delete [] s1;
        s1 = new char[largo];
        while (s2[i] != '\0')
        {
            s1[i] = s2[i];
            i++;
        }
        s1[i] = '\0';
    }
*/
    void strCop(String &s1, String s2) {
    if (s2 != NULL) {
        int largo = strlar(s2) + 1;

        // Liberamos la memoria anterior de s1 de forma segura
        delete [] s1;

        s1 = new char[largo];
        int i = 0;
        while (s2[i] != '\0') {
            s1[i] = s2[i];
            i++;
        }
        s1[i] = '\0';
    }
}

    void strDestruir(String &s){
        delete [] s;
        s = NULL;
    }

void strPrint(String s){
    int i=0;
    while(s[i]!='\0'){
        printf("%c", s[i]);
        i++;
    }
}

