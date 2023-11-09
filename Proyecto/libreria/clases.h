#ifndef CLASES_H
#define CLASES_H
#include "clientes.h"
#include <iostream>
#include <string>


using namespace std;
typedef std::string str;

struct clases{

    str idClase, horario, nombreclase;
    /*unsigned int cupo;*/
};typedef struct clases eClases;

eLectura ArchivoClases(eClases* clases,ifstream& archivo);
unsigned int asignarcupos(eClases* clase);
#endif // CLASES_H
