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

}

unsigned int MyArray::getSize()
{
	return arraySize;
}

int MyArray::at(unsigned int index)
{
	return arrayptr[index];
}

void MyArray::pushBack (int val)
{
	resize(arraySize + 1);
	arrayptr[arraySize - 1] = val;
}

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
		std::string exc = "Nieprawidlowa wartosc indeksu.\nNazlezy podac wartosc od 0 do aktualnego rozmiaru tablicy.";
		throw exc;
	}
}

//zamieniamy wartosc na danym indeksie na podana
void MyArray::insert(int val, unsigned int index)
{
	arrayptr[index] = val;
}

void MyArray::popFront()
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		arrayptr[i] = arrayptr[i + 1];
	}
	resize(arraySize - 1);
}

void MyArray::popBack()
{
	resize(arraySize - 1);
}

void MyArray::pop(unsigned int index)
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
		std::string exc = "Nieprawidlowa wartosc indeksu.\nNazlezy podac wartosc od 0 do aktualnie najwiekszego indeksu tablicy.";
		throw exc;
	}
}

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