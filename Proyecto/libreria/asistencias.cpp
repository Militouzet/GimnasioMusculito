#include "archivos.h"
//funcion para hacer resize a la asistencia si alguien mas se quiere unir a la clase
Asistencia* resizeAsistencia(eAsistencia* miLista, uint tam, uint nuevoTam) {
    Asistencia* aux = new Asistencia[nuevoTam];

    uint longitud = (tam <  nuevoTam) ? tam : nuevoTam;

    if(aux != nullptr) {

        for(uint i = 0; i < longitud; i++)
            aux[i] = miLista[i]; // *(miLista + i)

        delete[] miLista;
        return aux;
    }

    return nullptr;
}

eLectura ArchivoAsistencia(ifstream& ArchivoAsistencia,eAsistencia* asistencias){
    // SABIENDO QUE ESTA ORDENADO EL ARCHIVO CLASES
    if(!ArchivoAsistencia.is_open())
        return eLectura::Errornoabrio;
    //Setear inicio
    ArchivoAsistencia.clear();
    ArchivoAsistencia.seekg(0);


    Asistencia* aux = asistencias;

    while (!ArchivoAsistencia.eof())//mientras que no este en el ultimo
    {
        ArchivoAsistencia.read((char*)&aux->idCliente, sizeof(uint));
        ArchivoAsistencia.read((char*)&aux->cantInscriptos, sizeof(uint));

        eInscripcion* registrados = new eInscripcion[aux->cantInscriptos];
        eInscripcion* auxInscripciones = registrados;
        for(uint i=0;i<aux->cantInscriptos;i++)
        {
            ArchivoAsistencia.read((char*)auxInscripciones,sizeof(eInscripcion));
            auxInscripciones++;
        }
        aux->CursosInscriptos = registrados;

        aux++;
    }


    return eLectura::exitoabrio;
}

void ImprimirAsistencias(eAsistencia* asistencias,uint cant){
   eAsistencia *auxA = asistencias, *lastA = (asistencias) + (cant - 1);

    while (true) {
        cout << "id:" << auxA->idCliente << endl;
        eInscripcion *auxH = auxA->CursosInscriptos,
            *lastAux =
            (auxA->CursosInscriptos) + (auxA->cantInscriptos - 1);
        cout << "Incripciones:";
        while (true) {
            cout << auxH->idClase << ",";
            if (auxH == lastAux)
                break;
            auxH++;
        }
        cout << endl;
        if (auxA == lastA)
            break;
        auxA++;
    }
}


