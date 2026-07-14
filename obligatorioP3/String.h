#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>

const int MAX = 80;

typedef char * String;


void strCrear(String &s);
void strScan(String &st);
void strCop (String &s1, String s2);
void strDestruir(String &s);
void strPrint(String s);
#endif // STRING_H_INCLUDED
