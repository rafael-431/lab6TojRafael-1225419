#include "pch.h"
#include"Pokemon.h"
#include"LeerArchivo.h"
#include"Nodo.h"
#include"orden.h" 
#include<string>
#include<iostream>

using namespace System;
using namespace std;
using namespace Diagnostics;

int main() {
    orden ordenar = orden();
    Nodo* ingresar = new Nodo();
    LeerArchivo archivos = LeerArchivo();
    Stopwatch^ watch = gcnew Stopwatch();

    cout << "Este es su archivo de texto" << "\n ";

    Pokemon* pdatos = archivos.LeerAr("LabPokemons.txt");
    for (size_t i = 0; i < archivos.TotaldeLineas - 1; i++)
    {
        string nombre = pdatos[i].Npokemon;
        int Kde = pdatos[i].kdex;
        int Nde = pdatos[i].ndex;
        ingresar->kdex = Kde;
        ingresar->pokem = nombre;
        ingresar->Ndex = Nde;


        cout << Nde << " " << nombre << " " << Kde << "\n ";
        ingresar->insertarLista(ingresar);
    }

    int selec = 0;
    cout << "\n";
    cout << "Eliga la forma en la que quiere ordenar los pokemons " << "\n";
    cout << "\n";
    cout << "por generacion (Selection Sort) (1)" << "\n";
    cout << "por National number ( Shell Sort) (2)" << "\n";
    cout << "por Nombrer (Quick Sort) (3)" << "\n";
    cin >> selec;

    switch (selec)
    {
    case 1:
        Console::Clear();
        watch->Start();
        cout << "Ordenamineto por generacion (Selection Sort)" << "\n";
        cout << "\n";
        ordenar.SeleccionSort(pdatos, ingresar->tamaño);
        watch->Stop();
        cout << "Tiempo empleado:  " << watch->ElapsedMilliseconds << "ms";
        cout << "\n";
        cout << "\n";


        break;
    case 2:
        Console::Clear();
        cout << "\n";
        watch->Start();
        cout << "Ordenamineto por National number (Shell Sort) " << "\n";
        cout << "\n";
        ordenar.Shell(pdatos, ingresar->tamaño);
        watch->Stop();
        cout << "Tiempo empleado:  " << watch->ElapsedMilliseconds << "ms";
        cout << "\n";
        cout << "\n";

        break;
    case 3:
        Console::Clear();
        cout << "\n";
        cout << "Ordenamiento por Nombrer (Quick Sort)";
        cout << "\n";
        watch->Start();
        Pokemon* ordenarDatos = ordenar.startQuickSort(pdatos, 0, archivos.TotaldeLineas - 1);
        watch->Stop();
        for (size_t i = 0; i < archivos.TotaldeLineas; i++)
        {
            cout << ordenarDatos[i].ndex << " " << ordenarDatos[i].Npokemon << " " << ordenarDatos[i].kdex << "\n";

        }
        cout << "Tiempo empleado:  " << watch->ElapsedMilliseconds << "ms";
        cout << "\n";
        cout << "\n";
        break;

    }


	return 0;
}

