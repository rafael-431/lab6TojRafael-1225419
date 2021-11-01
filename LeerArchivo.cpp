#include "pch.h"
#include "LeerArchivo.h"
#include"Pokemon.h"
#include "Nodo.h"
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

Pokemon* LeerArchivo::LeerAr(std::string nombre) {

    std::fstream archivo;
    archivo.open(nombre, std::ios::in);
    std::string linea;
    char delimitador = ',';
    static Pokemon datos[100];
    while (archivo.good())  //
    {
        getline(archivo, linea);
        std::stringstream X(linea);
        int countT = 0;
        std::string lineaT = "";

        while (getline(X, lineaT, delimitador)) {
            if (countT == 0) {
                datos[TotaldeLineas].ndex = std::stoi(lineaT);
            }
            if (countT == 1) {
                datos[TotaldeLineas].Npokemon = lineaT;
            }
            if (countT == 2) {
                datos[TotaldeLineas].kdex = std::stoi(lineaT);
            }
            countT = countT + 1;
        }
        TotaldeLineas = TotaldeLineas + 1;
    }
    archivo.close();
    return datos;
}
