#include "stdafx.h"
#include "MyHeap.h"
#include <iostream>

//konstruktory jak i niektore metody identyczne z tymi z MyArray
//(roznia sie tylko kilkoma cout-ami)
//nie zastosowalem dziedziczenia od MyArray, poniewaz MyArray zostalo w pelni napisane zanim
//powstala taka idea, a wolalem uniknac ingerencji w strukture tamtej klasy
MyHeap::MyHeap()
{
	heapSize = 0;
	heapptr = nullptr;
}

MyHeap::MyHeap(unsigned int size)
{
	try
	{
		heapSize = size;
		heapptr = new int[heapSize];
	}
	catch (std::bad_alloc)
	{
		std::cerr << "Nie udalo sie poprawnie zaalokowac kopca.\n";
	}
}

MyHeap::~MyHeap()
{
	delete heapptr;
}

unsigned int MyHeap::getSize()
{
	return heapSize;
}

int MyHeap::at(unsigned int index)
{
	return heapptr[index];
}
//wpisuje nowy element jako ostatni element kopca, uprzednio zwiekszajac tablice
//nastepnie przywracana jest wlasnosc kopca idac od nowego elementu w gore
//UWAGA: algorytm przywracania wlasnosci kopca mocno zainspirowany
//       rozwiazaniem ze strony http://eduinf.waw.pl, z faktu, ze przy
//       implementacji tego algorytmu napotkalem problemy z indeksowaniem
//       przez ktore caly kopiec byl do niczego, bo przy jego budowaniu
//       wyrzucalo cala aplikacje
void MyHeap::heapPush(int v)
{
	int i, j;
	resize(heapSize + 1);
	i = heapSize - 1;
	j = parent(i);

	while (i > 0 && heapptr[j] < v)
	{
		heapptr[i] = heapptr[j];
		i = j;
		j = parent(i);
	}
	heapptr[i] = v;
}
//wpisuje wartosc ostatniego elementu kopca (liscia najbardziej z prawej)
//do korzenia, nastepnie zmniejsza kopiec i przywraca jego wlasnosc idac
//z gory do dolu
//UWAGA: algorytm przywracania wlasnosci kopca mocno zainspirowany
//       rozwiazaniem ze strony http://eduinf.waw.pl, z faktu, ze przy
//       implementacji tego algorytmu napotkalem problemy z indeksowaniem
//       przez ktore caly kopiec byl do niczego, bo przy jego budowaniu
//       wyrzucalo cala aplikacje
void MyHeap::heapPop()
{
	if (heapSize > 2)
	{
		int i, j, val;
		
		val = heapptr[heapSize - 1];

		i = 0;
		j = leftSon(i);

		while (j < heapSize - 1)
		{
			if (rightSon(i) < heapSize - 1 && heapptr[rightSon(i)] > heapptr[leftSon(i)]) j++;
			if (val >= heapptr[j]) break;
			heapptr[i] = heapptr[j];
			i = j;
			j = leftSon(i);
		}
		heapptr[i] = val;
		resize(heapSize - 1);
	}
	else if (heapSize == 2)
	{
		heapptr[0] = heapptr[1];
		resize(1);
	}
	else if (heapSize <= 1)
	{
		resize(0);
		std::cout << "Kopiec jest pusty. Nie ma czego usunac.\n";
	}
}
//zmienia rozmiar tablicy przechowujacej elementy kopca
//identyczna z ta z MyArray
void MyHeap::resize(unsigned int newSize)
{
	try
	{
		int *temp = new int[newSize];
		//przepisanie calej tablicy i zostawienie pol dodanych niezainicjalizowanych (moga tam byc smieci)
		if (newSize > heapSize)
		{
			for (int i = 0; i < heapSize; i++)
			{
				temp[i] = heapptr[i];
			}
		}
		//przepisanie tablicy az do osiagniecia nowego rozmiaru (ostatnie elementy tracimy)
		else if (newSize < heapSize)
		{
			for (int i = 0; i < newSize; i++)
			{
				temp[i] = heapptr[i];
			}
		}
		delete[] heapptr;
		heapptr = temp;
		heapSize = newSize;
	}
	catch (std::bad_alloc)
	{
		std::cerr << "Nie udalo sie poprawnie zaalokowac kopca.\n";
	}
}
//zwraca indeks lewego syna
int MyHeap::leftSon(unsigned int index)
{
	return index * 2 + 1;
}
//zwraca indeks prawego syna
int MyHeap::rightSon(unsigned int index)
{
	return index * 2 + 2;
}
//zwraca indeks ojca
int MyHeap::parent(unsigned int index)
{
	return (index - 1) / 2;
}
//wypisuje cala zawartosc kopca poziom po poziomie, wywolujac sie rekurencyjnie
//jako argument zawsze powinny byc podane dwie jedynki, sa one po to aby
//w rekurencji dobrze wyliczac indeksy i poziomy kopca
void MyHeap::printHeap(unsigned int index, unsigned int level)
{
	if (index <= heapSize)
	{
		std::cout << "\nPoziom " << level << ":\t";
		if (index * 2 <= heapSize)
		{
			for (int i = index - 1; i < index * 2 - 1; i++)
			{
				std::cout << heapptr[i] << "\t";
			}
			std::cout << "\n";
			printHeap(index * 2, ++level);
		}
		else
		{
			for (int i = index - 1; i < heapSize; i++)
			{
				std::cout << heapptr[i] << "\t";
			}
			std::cout << "\nIlosc elementow w kopcu: " << heapSize << "\n";
		}
	}
}

