#include "stdafx.h"
#include "MyArray.h"
#include <iostream>
#include <string>

MyArray::MyArray()
{
	arraySize = 0;
	arrayptr = nullptr;
}

MyArray::MyArray(unsigned int size)
{
	try
	{
		arraySize = size;
		arrayptr = new int[arraySize];
	}
	catch(std::bad_alloc)
	{
		std::cerr << "Nie udalo sie poprawnie zaalokowac tablicy.\n";
	}
}

MyArray::~MyArray()
{
	delete arrayptr;
}

unsigned int MyArray::getSize()
{
	return arraySize;
}

int MyArray::at(unsigned int index)
{
	return arrayptr[index];
}
//zwiekszamy tablice o 1 i wrzucamy na ostatnia pozycje nowy element
void MyArray::pushBack (int val)
{
	resize(arraySize + 1);
	arrayptr[arraySize - 1] = val;
}
//zwiekszamy tablice o 1, po czym przesuwamy wszystko w prawo i na zerowy indeks
//zapisujemy nowa wartosc
void MyArray::pushFront(int val)
{
	resize(arraySize + 1);
	for (int i = arraySize - 1; i > 0; i--)
	{
		arrayptr[i] = arrayptr[i - 1];
	}
	arrayptr[0] = val;
}
//dodajemy element o danej wartosci na podanym indeksie, a elementy z tego indeksu
//i wyzszych przesuwamy w prawo
//gdy wiemy ze dodamy element na poczatek lub koniec, lepiej jest uzyc pushFront
//albo pushBack - oszczedzamy na sprawdzeniu indeksu
void MyArray::push(int val, unsigned int index)
{
	if (index > 0 && index < arraySize)
	{
		resize(arraySize + 1);
		for (int i = arraySize - 1; i > index; i--)
		{
			arrayptr[i] = arrayptr[i - 1];
		}
		arrayptr[index] = val;
	}
	else if (index == 0) pushFront(val);
	else if (index == arraySize) pushBack(val);
	else
	{
		std::cerr << "Nieprawidlowa wartosc indeksu.\nNalezy podac wartosc od 0 do aktualnego rozmiaru tablicy.";
	}
}
//zamieniamy wartosc na danym indeksie na podana
void MyArray::insert(int val, unsigned int index)
{
	arrayptr[index] = val;
}
//zsuniecie elementow po pierwszym (po indeksie 0) w lewo i uciecie ostatniego
//elementu zmniejszajac tablice o 1
void MyArray::popFront()
{
	if (arraySize > 0)
	{
		for (int i = 0; i < arraySize - 1; i++)
		{
			arrayptr[i] = arrayptr[i + 1];
		}
		resize(arraySize - 1);
	}
	else
	{
		std::cout << "Nie mozna usunac elementu. Tablica jest pusta.\n";
	}
}
//usuniecie z konca tablicy poprzez uciecie jej
void MyArray::popBack()
{
	if (arraySize > 0)
	{
		resize(arraySize - 1);
	}
	else
	{
		std::cout << "Nie mozna usunac elementu. Tablica jest pusta.\n";
	}
}
//usun z wybranego indeksu i zsun w lewo elementy dalsze po czym zmniejsz
//rozmiar tablicy o 1
void MyArray::pop(unsigned int index)
{
	if (arraySize > 0)
	{
		if (index > 0 && index < arraySize - 1)
		{
			for (int i = index; i < arraySize - 1; i++)
			{
				arrayptr[i] = arrayptr[i + 1];
			}
			resize(arraySize - 1);
		}
		else if (index == 0) popFront();
		else if (index == arraySize - 1) popBack();
		else
		{
			std::cerr << "Nieprawidlowa wartosc indeksu.\nNalezy podac wartosc od 0 do aktualnego rozmiaru tablicy.";
		}
	}
	else
	{
		std::cout << "Nie mozna usunac elementu. Tablica jest pusta.\n";
	}
}
//zmienia rozmiar tablicy
void MyArray::resize(unsigned int newSize)
{
	try
	{
		int *temp = new int[newSize];
		//przepisanie calej tablicy i zostawienie pol dodanych niezainicjalizowanych (moga tam byc smieci)
		if (newSize > arraySize)
		{
			for (int i = 0; i < arraySize; i++)
			{
				temp[i] = arrayptr[i];
			}
		}
		//przepisanie tablicy az do osiagniecia nowego rozmiaru (ostatnie elementy tracimy)
		else if (newSize < arraySize)
		{
			for (int i = 0; i < newSize; i++)
			{
				temp[i] = arrayptr[i];
			}
		}
		delete[] arrayptr;
		arrayptr = temp;
		arraySize = newSize;
	}
	catch (std::bad_alloc)
	{
		std::cerr << "Nie udalo sie poprawnie zaalokowac tablicy.\n";
	}
}
//zamienia elementy o podanych indeksach miejscami
void MyArray::swap(unsigned int element1, unsigned int element2)
{
	int temp = arrayptr[element1];
	arrayptr[element1] = arrayptr[element2];
	arrayptr[element2] = temp;
}
//wypisanie zawartosci calej tablicy na ekran
void MyArray::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << arrayptr[i] << "\t";
	}
	std::cout << "\nIlosc elementow w tablicy: " << arraySize << "\n";
}

//przeciazenie operatora indeksu, z jakiegos powodu wydaje sie nie dzialac przy ustawianiu
//elementu na danym indeksie, wiec trzeba uzyc metody insert
int& MyArray::operator[] (size_t index)
{
	return arrayptr[index];
}

const int& MyArray::operator[](size_t index) const
{
	return arrayptr[index];
}