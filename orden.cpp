#include "pch.h"
#include "orden.h"
#include "Nodo.h"
#include "Pokemon.h"
#include<string>
#include<iostream>

using namespace System;
using namespace std;

orden::orden() {

}

void orden::SeleccionSort(Pokemon datos[], int tam) {

	for (int i = 0; i < tam; i++)
	{
		int min = i;
		for (int j = i + 1; j < tam; j++)
		{
			if (datos[min].kdex > datos[j].kdex) {
				min = j;
			}

			if (datos[min].ndex > datos[j].ndex) {
				min = j;
			}

		}

		int aux = datos[i].kdex;
		int auxx = datos[i].ndex;
		string auxi = datos[i].Npokemon;

		datos[i].kdex = datos[min].kdex;
		datos[i].ndex = datos[min].ndex;
		datos[i].Npokemon = datos[min].Npokemon;

		datos[min].kdex = aux;
		datos[min].ndex = auxx;
		datos[min].Npokemon = auxi;
	}

	Console::Write("\n");
	for (int i = 0; i < tam; i++)
	{

		cout << datos[i].ndex << " " << datos[i].Npokemon << " " << datos[i].kdex << "\n";
	}



}

void orden::Shell(Pokemon poke[], int tama) {

	for (int gap = tama / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < tama; i++)
		{
			Pokemon Temp = poke[i];
			int j;
			for (j = i; j >= gap && poke[j - gap].ndex > Temp.ndex; j -= gap)
				poke[j] = poke[j - gap];
			poke[j] = Temp;
		}
	}
	for (int i = 0; i < tama; i++)
	{
		cout << poke[i].ndex << " " << poke[i].Npokemon << " " << poke[i].kdex << "\n";
	}
}

void orden::swap(Pokemon* a, Pokemon* b)
{
	Pokemon t = *a;
	*a = *b;
	*b = t;
}

void orden::QuickSort(Pokemon datos[], int menor, int mayor)
{
	if (menor < mayor)
	{
		int pi = QuickSortPartition(datos, mayor, menor);

		QuickSort(datos, menor, pi - 1);
		QuickSort(datos, pi + 1, mayor);
	}
}

int orden::QuickSortPartition(Pokemon datos[], int mayor, int menor)
{
	Pokemon pivot = datos[mayor];
	int i = (menor - 1);

	for (int j = menor; j <= mayor - 1; j++)
	{

		if (datos[j].Npokemon <= pivot.Npokemon)
		{
			i++;
			swap(&datos[i], &datos[j]);
		}
	}


	swap(&datos[i + 1], &datos[mayor]);
	return (i + 1);
}

Pokemon* orden::startQuickSort(Pokemon datos[], int menor, int mayor)
{
	QuickSort(datos, menor, mayor);
	return datos;
}