#pragma once
#include "Pokemon.h"
#include "Nodo.h"

class orden
{
public:
	orden();


	void swap(Pokemon* a, Pokemon* b);
	void QuickSort(Pokemon d[], int menor, int mayor);
	int QuickSortPartition(Pokemon da[], int mayor, int menor);
	Pokemon* startQuickSort(Pokemon datos[], int menor, int mayor);
	void SeleccionSort(Pokemon[], int);
	void Shell(Pokemon valores[], int n);


};

