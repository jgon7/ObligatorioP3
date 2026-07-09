#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

const int MAX = 80;
typedef char * String;

void strCrear(String &s);
void strDestruir(String &s);
void strCop(String &s1, String s2);
void strScan(String &s);
void strPrint(String s);
bool strEq(String s1, String s2);

#endif // STRING_H_INCLUDED
