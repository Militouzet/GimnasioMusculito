#include "clientes.h"
#include "clases.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    ifstream archivoClientes("../../iriClientesGYM.csv");
    if(!archivoClientes.is_open()){
        cout<<" No abrio";
    }
    ifstream archivoClases("../../iriClasesGYM.csv");
    if(archivoClases.is_open()){
        cout<<" abrio";
    }



    //-----------------------------------CLIENTES------------------------------------------------------

    archivoClientes.clear();
    archivoClientes.seekg(0);
    str encabezado;
    getline(archivoClientes,encabezado);
    str linea;
    int contClientes=0;
    char delim=',';
    while(getline(archivoClientes,linea))
        contClientes++;

    eClientes* clientes=new eClientes[contClientes];
    eLectura resultadoArchivoCliente;
    resultadoArchivoCliente=ArchivoClientes(clientes,archivoClientes);
    //------------------------------------CLASES----------------------------------------------------------------

    archivoClases.clear();
    archivoClases.seekg(0);
    getline(archivoClases,encabezado);
    int contClases=0;
    while(getline(archivoClientes,linea))
        contClases++;

    eClases* clases=new eClases[contClases];
    eLectura resultadoArchivoClases;
    resultadoArchivoClases=ArchivoClases(clases,archivoClases);
    for(int i=0; i<contClases;i++){
        cout<<""<<clases[i].nombreclase<<endl;
    }

    return 0;

}
