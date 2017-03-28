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
void rewriteArrayInListAndHeap (MyArray *array, MyList *list, MyHeap *heap);
double averageOperationTime (const std::vector<double> vectorOfTimes);
void saveTimesToTextFile (double avgPushFront, double avgPushBack, double avgPush, double avgPopFront, double avgPopBack, double avgPop);

int main()
{

	//-----Czesc wlasciwa programu-------------------------------------

	long long int frequency, start, elapsed;
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
	string filepath = "";
	MyArray *arrayOfInts = new MyArray();
	MyList *listOfInts = new MyList();
	MyHeap *heapOfInts = new MyHeap();
	std::vector<double> arrayPushFrontTimes, arrayPushBackTimes, arrayPushTimes,
		arrayPopFrontTimes, arrayPopBackTimes, arrayPopTimes;
	std::vector<double> listPushFrontTimes, listPushBackTimes, listPushTimes,
		listPopFrontTimes, listPopBackTimes, listPopTimes;
	std::vector<double> heapPushTimes, heapPopTimes;
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
						<< "8. Zapisz wyniki do pliku.\n"
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
						arrayPushFrontTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
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
						arrayPushBackTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
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
						arrayPushTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '4':
						start = read_QPC();
						arrayOfInts->popFront();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						arrayPopFrontTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '5':
						start = read_QPC();
						arrayOfInts->popBack();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						arrayPopBackTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
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
						arrayPopTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '7':
						cout << "Zawartosc tablicy: \n";
						arrayOfInts->printArray();
						break;
					case '8':
						saveTimesToTextFile(averageOperationTime(arrayPushFrontTimes), averageOperationTime(arrayPushBackTimes), averageOperationTime(arrayPushTimes), averageOperationTime(arrayPopFrontTimes), averageOperationTime(arrayPopBackTimes), averageOperationTime(arrayPopTimes));
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
						<< "8. Zapisz wyniki do pliku.\n"
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
						listPushFrontTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
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
						listPushBackTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
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
						listPushTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '4':
						start = read_QPC();
						listOfInts->popFront();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						listPopFrontTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '5':
						start = read_QPC();
						listOfInts->popBack();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						listPopBackTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
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
						listPopTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '7':
						cout << "Zawartosc listy: \n";
						listOfInts->printList();
						break;
					case '8':
						saveTimesToTextFile(averageOperationTime(listPushFrontTimes), averageOperationTime(listPushBackTimes), averageOperationTime(listPushTimes), averageOperationTime(listPopFrontTimes), averageOperationTime(listPopBackTimes), averageOperationTime(listPopTimes));
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
						<< "4. Zapisz wyniki do pliku.\n"
						<< "9. Przejdz do glownego menu.\n";
					menuKey = _getch();
					switch (menuKey)
					{
					case '1':
						cout << "Wpisz liczbe: \n";
						cin >> cinValue;
						start = read_QPC();
						heapOfInts->heapPush(cinValue);
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						heapPushTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '2':
						start = read_QPC();
						heapOfInts->heapPop();
						elapsed = read_QPC() - start;
						cout << "\nCzas [ms] = " << std::setprecision(0)
							<< (1000.0 * elapsed) / frequency << "\n";
						cout << "\nCzas [us] = " << std::setprecision(3)
							<< (1000000.0 * elapsed) / frequency << "\n\n";
						heapPopTimes.push_back(static_cast<double>(elapsed) / static_cast<double>(frequency) * 1000000.0);
						break;
					case '3':
						cout << "Zawartosc kopca: \n";
						heapOfInts->printHeap(1, 1);
						break;
					case '4':
						saveTimesToTextFile(NULL, NULL, averageOperationTime(heapPushTimes), NULL, NULL, averageOperationTime(heapPopTimes));
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
		case '5':
			{
				cout << "Podaj zadany rozmiar tablicy: \n";
				cin >> cinValue;
				writeRandomToArray(arrayOfInts, cinValue);
				rewriteArrayInListAndHeap(arrayOfInts, listOfInts, heapOfInts);
				cout << "Zawartosc tablicy: \n";
				arrayOfInts->printArray();
				cout << "Zawartosc listy: \n";
				listOfInts->printList();
				cout << "Zawartosc kopca: \n";
				heapOfInts->printHeap(1, 1);
			}
			break;
		default:
			break;
		}
	} while (menuKey != '0');

	delete arrayOfInts, listOfInts, heapOfInts;
	return 0;
}
//odczyt danych z pliku tekstowego do tablicy klasy MyArray
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
//funkcja do pomiaru czasu, od podanej w materialach do projektu rozni sie
//tylko sposobem rzutowania (tu w stylu C++ zamiast C)
long long int read_QPC()
{
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return static_cast<long long int>(count.QuadPart);
}
//wypelnienie tablicy klasy MyArray pseudolosowymi wartosciami od 1 do miliona
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
//przepisanie elementow z tablicy klasy MyArray do listy klasy MyList
//i kopca klasy MyHeap
void rewriteArrayInListAndHeap (MyArray *array, MyList *list, MyHeap *heap)
{
	for (int i = 0; i < array->getSize(); i++)
	{
		list->pushBack(array->at(i));
		heap->heapPush(array->at(i));
	}
}
//zebranie zmierzonych czasow wykonania danej operacji i zwrocenie
//sredniej arytmetycznej
double averageOperationTime (const std::vector<double> vectorOfTimes)
{
	double averageTime = 0;
	for (int i = 0; i < vectorOfTimes.size(); i++)
	{
		averageTime += vectorOfTimes[i];
	}
	averageTime = averageTime / vectorOfTimes.size();

	return averageTime;
}
//zapis plikow tekstowych z wynikami na pulpicie
//sciezka pliku jest stala ze wzgledu na to ze funkcja zostala napisana
//z mysla o prywatnym uzytkowaniu jej do zebrania wynikow pomiarow czasowych
void saveTimesToTextFile (double avgPushFront, double avgPushBack, double avgPush, double avgPopFront, double avgPopBack, double avgPop)
{
	string structureNameAndSize;
	cout << "Podaj typ i rozmiar struktury jako nazwe pliku (na przyklad: tablica1000): \n";
	cin >> structureNameAndSize;
	
	std::ofstream file;
	file.open("c:\\users\\szatan\\desktop\\" + structureNameAndSize + ".txt", std::ios::out);

	if (file.is_open())
	{
		file << "PushFront, PushBack, Push, PopFront, PopBack, Pop\n";
		if (file.fail()) std::cerr << "Blad zapisu.\n";
		else
		{
			file << avgPushFront << ", " << avgPushBack << ", " << avgPush
				<< ", " << avgPopFront << ", " << avgPopBack << ", " << avgPop;
			if (file.fail()) std::cerr << "Blad zapisu.\n";
		}
		file.close();
	}
	else std::cerr << "Blad otwarcia pliku.\n";
}