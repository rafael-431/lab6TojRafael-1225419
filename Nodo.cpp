#include "pch.h"
#include "Nodo.h"

Nodo::Nodo() {
}


void Nodo::insertarLista(Nodo* pokemonn) {
	Nodo* Nuevo = new Nodo();
	Nuevo->kdex = pokemonn->kdex;
	Nuevo->pokem = pokemonn->pokem;
	Nuevo->Ndex = pokemonn->Ndex;

	Nuevo->siguiente = cabeza;

	cabeza = Nuevo;
	tamaño++;
}