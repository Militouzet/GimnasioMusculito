#include "clases.h"
/*unsigned int asignarcupos(eClases* clase){
    if(clase->nombreclase=="Spinning" || clase->nombreclase=="spinning"){
        clase->cupo=45;
    }
    if(clase->nombreclase=="Yoga" || clase->nombreclase=="yoga"){
        clase->cupo=25;
    }
    if(clase->nombreclase=="Pilates" || clase->nombreclase=="pilates"){
        clase->cupo=15;
    }
    if(clase->nombreclase=="Stretching" || clase->nombreclase=="stretching"){
        clase->cupo=40;
    }
    if(clase->nombreclase=="Zumba"|| clase->nombreclase=="zumba"){
        clase->cupo=50;
    }
    if(clase->nombreclase=="Boxeo"|| clase->nombreclase=="boxeo"){
        clase->cupo=30;
    }
    return clase->cupo;
}
*/
eLectura ArchivoClases(eClases* clases,ifstream& archivo){
    if(!archivo.is_open())
        return eLectura::Errornoabrio;
    archivo.clear();
    archivo.seekg(0);

    str encabezado;

    getline(archivo, encabezado);
    eClases* aux = clases;
    while (archivo.good()) {
        str linea;
        getline(archivo, linea);
        if(archivo.eof())
            break;
        char delim = ',';
        string idClase, NombreClase, horario;
        std::istringstream iss(linea);
        getline(iss, idClase, delim);
        getline(iss, NombreClase, delim);
        getline(iss, horario, delim);
        aux->idClase = idClase;
        aux->nombreclase  = NombreClase;
        aux->horario  =stoi(horario);
        /*aux->cupo=asignarcupos(aux);*/
        aux++;
    }

    return eLectura::exitoabrio;
}
