#pragma once
#include "Pokemon.h"

using namespace System;
class Nodo
{

public:

	Nodo* cabeza = nullptr;
	string  pokem;
	int kdex;
	int Ndex;
	Nodo* siguiente;
	int tamaño = 0;
	Nodo();
	void insertarLista(Nodo* p);



};

