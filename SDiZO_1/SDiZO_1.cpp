// SDiZO_1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <iomanip>
#include <random>
#include "MyList.h"
#include "MyArray.h"
#include "MyHeap.h"

using std::cout;
using std::cin;
using std::string;

void readTextFile (string filepath, MyArray *array);
long long int read_QPC();
void writeRandomToArray (MyArray *array, int arraySize);
void rewriteArrayInList (MyArray *array, MyList *list);

int main()
{
	/*MyList lista;
	lista.pushFront(1);
	lista.pushFront(2);
	lista.pushFront(3);
	lista.pushFront(4);
	lista.push(5, 2);
	lista.popBack();
	lista.printList();

	MyArray *tablica = new MyArray(3);
	tablica->pushBack(9);
	tablica->insert(1, 0);
	tablica->insert(2, 1);
	tablica->insert(3, 2);
	tablica->pushFront(10);
	tablica->swap(0, 1);
	tablica->printArray();

	MyArray tablica2;
	tablica2.pushBack(5);
	tablica2.printArray();
	
	MyHeap kopiec;
	kopiec.addToTail(1);
	kopiec.addToTail(4);
	kopiec.addToTail(3);
	//kopiec.printHeap(1);
	cout << kopiec.at(0) << " " << kopiec.at(1) << " " << kopiec.at(2);
	_getch();*/
	//-----Czesc wlasciwa programu-------------------------------------

	long long int frequency, start, elapsed;
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
	string filepath = "";
	MyArray *arrayOfInts = new MyArray();
	MyList *listOfInts = new MyList();
	MyHeap *heapOfInts = new MyHeap();
	char menuKey = 0;
	int cinValue = 0, cinIndex = 0;

	do
	{
		cout << "\n1. Wczytaj dane z pliku.\n"
			<< "2. Wykonaj operacje na tablicy.\n"
			<< "3. Wykonaj operacje na liscie.\n"
			<< "4. Wykonaj operacje na kopcu.\n"
			<< "5. Wypelnij tablice losowymi liczbami.\n"
			<< "0. Wyjdz z programu.\n"
			<< "Wcisnij przycisk...\n";
		menuKey = _getch();
		switch (menuKey)
		{
		case '1':
			cout << "Podaj sciezke wczytywanego pliku\n"
				<< "Na przyklad: C:\\Users\\User\\Documents\\textfile.txt\n"
				<< "Pamietaj o podwojnych backslashach!\n";
			cin >> filepath;
			readTextFile(filepath, arrayOfInts);
		case '2':
			{
				do
				{
					cout << "\n1. Dodaj element z przodu.\n"
						<< "2. Dodaj element z tylu.\n"
						<< "3. Dodaj na wybranej pozycji.\n"
						<< "4. Usun z przodu.\n"
						<< "5. Usun z tylu.\n"
						<< "6. Usun z wybranej pozycji.\n"
						<< "7. Wyswietl zawartosc tablicy.\n"
						<< "9. Przejdz do glownego menu.\n";
					menuKey = _getch();
					switch (menuKey)
					{
					case '1':
						cout << "Wpisz liczbe: \n";
						cin >> cinValue;
						start = read_QPC();
						arrayOfInts->pushFront(cinValue);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '2':
						cout << "Wpisz liczbe: \n";
						cin >> cinValue;
						start = read_QPC();
						arrayOfInts->pushBack(cinValue);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '3':
						cout << "Wpisz liczbe: \n";
						cin >> cinValue;
						cout << "Wpisz indeks: \n";
						cin >> cinIndex;
						start = read_QPC();
						arrayOfInts->push(cinValue, cinIndex);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '4':
						start = read_QPC();
						arrayOfInts->popFront();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '5':
						start = read_QPC();
						arrayOfInts->popBack();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '6':
						cout << "Wpisz indeks: \n";
						cin >> cinIndex;
						start = read_QPC();
						arrayOfInts->pop(cinIndex);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '7':
						cout << "Zawartosc tablicy: \n";
						arrayOfInts->printArray();
						break;
					case '0':
						menuKey = '9';
						break;
					default:
						break;
					}
				} while (menuKey != '9');
			}
			break;
		case '3':
			{
				do
				{
					cout << "\n1. Dodaj element z przodu.\n"
						<< "2. Dodaj element z tylu.\n"
						<< "3. Dodaj na wybranej pozycji.\n"
						<< "4. Usun z przodu.\n"
						<< "5. Usun z tylu.\n"
						<< "6. Usun z wybranej pozycji.\n"
						<< "7. Wyswietl zawartosc listy.\n"
						<< "9. Przejdz do glownego menu.\n";
					menuKey = _getch();
					switch (menuKey)
					{
					case '1':
						cout << "Wpisz liczbe: \n";
						cin >> cinValue;
						start = read_QPC();
						listOfInts->pushFront(cinValue);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '2':
						cout << "Wpisz liczbe: \n";
						cin >> cinValue;
						start = read_QPC();
						listOfInts->pushBack(cinValue);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '3':
						cout << "Wpisz liczbe: \n";
						cin >> cinValue;
						cout << "Wpisz pozycje: \n";
						cin >> cinIndex;
						start = read_QPC();
						listOfInts->push(cinValue, cinIndex);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '4':
						start = read_QPC();
						listOfInts->popFront();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '5':
						start = read_QPC();
						listOfInts->popBack();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '6':
						cout << "Wpisz pozycje: \n";
						cin >> cinIndex;
						start = read_QPC();
						listOfInts->pop(cinIndex);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						break;
					case '7':
						cout << "Zawartosc listy: \n";
						listOfInts->printList();
						break;
					case '0':
						menuKey = '9';
						break;
					default:
						break;
					}
				}
				while (menuKey != '9');
			}
			break;
		case '4':
			{
				do
				{
					cout << "\n1. Dodaj element do kopca.\n"
						<< "2. Usun korzen.\n"
						<< "3. Wyswietl zawartosc kopca.\n"
						<< "9. Przejdz do glownego menu.\n";
					menuKey = _getch();
					switch (menuKey)
					{
					case '1':

					case '2':

					case '3':

					case '0':
						menuKey = '9';
						break;
					default:
						break;
					}
				}
				while (menuKey != '9');
			}
			break;
		case '5':
			{
				cout << "Podaj zadany rozmiar tablicy: \n";
				cin >> cinValue;
				writeRandomToArray(arrayOfInts, cinValue);
				rewriteArrayInList(arrayOfInts, listOfInts);
				cout << "Zawartosc tablicy: \n";
				arrayOfInts->printArray();
				cout << "Zawartosc listy: \n";
				listOfInts->printList();
			}
			break;
		default:
			break;
		}
	} while (menuKey != '0');
	return 0;
}

void readTextFile (string filepath, MyArray *array)
{
	std::ifstream file;
	file.open(filepath, std::ios::in);
	if (file.is_open())
	{
		unsigned short numberOfElements = 0;
		int value;
		file >> numberOfElements;
		array->resize(numberOfElements);

		if (file.fail()) std::cerr << "Blad wczytania rozmiaru.\n";
		else
		{
			for (int i = 0; i < numberOfElements; i++)
			{
				file >> value;
				if (file.fail())
				{
					std::cerr << "Blad wczytywania danych.\n";
					break;
				}
				else array->insert(value, i);
			}
			file.close();
		}
	}
	else std::cerr << "Blad otwarcia pliku.\n";
}

long long int read_QPC()
{
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return static_cast<long long int>(count.QuadPart);
}

void writeRandomToArray (MyArray *array, int arraySize)
{
	int value;
	std::random_device rng;
	std::mt19937 eng(rng());
	std::uniform_int_distribution<> distribution(1, 1000000);
	array->resize(arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		value = distribution(eng);
		array->insert(value, i);
	}
}

void rewriteArrayInList (MyArray *array, MyList *list)
{
	for (int i = 0; i < array->getSize(); i++)
	{
		list->pushBack(array->at(i));
	}
}