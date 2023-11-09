#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <string>
#include "clases.h"
#include "clientes.h"
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;
enum Archivo{ ExitoAbrio=1, Noabrio=-1};
typedef enum Archivo Archi;

struct sInscripcion{
    unsigned int idClase;
    time_t fechaInscripcion;
}; typedef struct sInscripcion eInscripcion;

typedef struct Asistencia{
    unsigned int idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
};typedef struct Asistencia eAsistencia;

#endif // ARCHIVOS_H
