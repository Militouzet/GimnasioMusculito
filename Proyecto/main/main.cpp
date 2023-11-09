#include "clientes.h"
#include "clases.h"
#include "asistencias.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    //---------------------------------------ABERTURA DE ARCHIVOS----------------------------------------------------------

    ifstream archivoClientes("../../iriClientesGYM.csv");
    if(!archivoClientes.is_open()){
        cout<<" No abrio";
    }
    ifstream archivoClases("../../iriClasesGYM.csv");
    if(!archivoClases.is_open()){
        cout<<"No abrio";
    }
    ifstream archivoAsistencias("../../asistencias_1697673600000.dat",ios::binary);
    if(!archivoAsistencias.is_open()){
        cout<<"No abrio";
    }


    //-----------------------------------CLIENTES------------------------------------------------------

    archivoClientes.clear();
    archivoClientes.seekg(0);
    str encabezado;
    getline(archivoClientes,encabezado);
    str linea;
    int contClientes=0;
    while(getline(archivoClientes,linea))
        contClientes++;

    eClientes* clientes=new eClientes[contClientes];
    eLectura resultadoArchivoCliente;
    resultadoArchivoCliente=ArchivoClientes(clientes,archivoClientes);


    //------------------------------------CLASES----------------------------------------------------------------

    str encabezadoClases;
    archivoClases.clear();
    archivoClases.seekg(0);
    getline(archivoClases,encabezadoClases);
    int contClases=0;
    while(getline(archivoClases,linea))
        contClases++;

    eClases* clases=new eClases[contClases];
    eLectura resultadoArchivoClase;
    resultadoArchivoClase=ArchivoClases(clases,archivoClases);


    //---------------------------------ASISTENCIA--------------------------------------------------------------------

    str encabezadoAsistencias;
    archivoAsistencias.clear();
    archivoAsistencias.seekg(0);
    int contAsistencias=-1;//como no le saco el encabezado
    int aux;
    while(!archivoAsistencias.eof()){
        archivoAsistencias.read((char *)&aux,sizeof(int));
        archivoAsistencias.read((char *)&aux,sizeof(int));
        eInscripcion* Inscripciones;
        for(int i=0; i<aux;i++){
            archivoAsistencias.read((char *)&Inscripciones,sizeof(eInscripcion));
        }
        contAsistencias++;
    }
    cout << "assitencias" << contAsistencias << endl;
    Asistencia *asistencias = new Asistencia[contAsistencias - 1];
    eLectura resultadoAsistencias;
    resultadoAsistencias = ArchivoAsistencia(archivoAsistencias, asistencias);
    for(int i=0;i<contAsistencias;i++){
        cout<<""<<asistencias[i].idCliente;
        cout<<""<<asistencias[i].CursosInscriptos;
    }

    delete [] clientes;
    delete[] clases;
    delete[] asistencias;

    archivoClases.close();
    archivoClientes.close();
    archivoAsistencias.close();
    return 0;
}
