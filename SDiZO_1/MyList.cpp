#include "stdafx.h"
#include "MyList.h"
#include <iostream>
#include <string>

MyList::MyList()
{
	front = nullptr;
	back = nullptr;
	listSize = 0;
}

MyList::~MyList()
{

}
//metoda przeszukujaca liste od poczatku w poszukiwaniu elementu na danej pozycji
//po znalezieniu elementu zwraca wskaznik na niego, a gdy podana jest pozycja spoza
//zakresu - zglasza wyjatek
MyList::Element* MyList::findPosition(unsigned int position)
{
	if (position < listSize)
	{
		auto elementToReturn = front;

		for (int p = 0; p < position; p++)
		{
			elementToReturn = elementToReturn->next;
		}
		return elementToReturn;
	}
	else
	{
		std::string exc = "Pozycja spoza zakresu listy.";
		throw exc;
	}
}

void MyList::pushFront(int val)
{
	if (!listSize)
	{
		try
		{
			Element *element = new Element (val);
			front = element;
			back = element;
		}
		catch(std::bad_alloc)
		{
			std::cerr << "Nie powiodlo sie zaalokowanie pamieci.\n";
		}
	}
	else
	{
		try
		{
			Element *element = new Element (val);
			front->previous = element;
			element->next = front;
			front = element;
		}
		catch(std::bad_alloc)
		{
			std::cerr << "Nie powiodlo sie zaalokowanie pamieci.\n";
		}
	}
	listSize++;
}

void MyList::pushBack(int val)
{
	if (!listSize)
	{
		try
		{
			Element *element = new Element (val);
			front = element;
			back = element;
		}
		catch (std::bad_alloc)
		{
			std::cerr << "Nie powiodlo sie zaalokowanie pamieci.\n";
		}
	}
	else
	{
		try
		{
			Element *element = new Element (val);
			back->next = element;
			element->previous = back;
			back = element;
		}
		catch (std::bad_alloc)
		{
			std::cerr << "Nie powiodlo sie zaalokowanie pamieci.\n";
		}
	}
	listSize++;
}
//metoda dodajaca element do listy na wybranej pozycji
//w przypadku pozycji pierwszej albo ostatniej wywoluje odpowiednio
//metodu pushFront i pushBack - w takim wypadku lepiej uzyc tych funkcji zamiast push
void MyList::push(int val, unsigned int position)
{
	if (position > 0 && position < listSize - 1)
	{
		try
		{
			Element *element1 = findPosition(position - 1), *element2 = element1->next;
			Element *newElement = new Element(val);

			newElement->next = element2;
			newElement->previous = element1;
			element1->next = newElement;
			element2->previous = newElement;
			listSize++;
		}
		catch (std::bad_alloc)
		{
			std::cerr << "Nie powiodlo sie zaalokowanie pamieci.\n";
		}
	}
	else if (position == 0) pushFront(val);
	else if (position == listSize - 1) pushBack(val);
	else if (position >= listSize || position < 0)
	{
		std::string exc = "Pozycja spoza zakresu listy.";
		throw exc;
	}
}

void MyList::popFront()
{
	Element *elementToDelete = front;
	if (listSize == 1)
	{
		delete elementToDelete;
		front = back = nullptr;
		listSize--;
	}
	else if (listSize > 1)
	{
		Element *newFront = front->next;
		front = newFront;
		newFront->previous = nullptr;
		delete elementToDelete;
		listSize--;
	}
	else if (!listSize)
	{
		std::cout << "Lista jest pusta. Nie ma czego usunac.";
	}
}

void MyList::popBack()
{
	Element *elementToDelete = back;
	if (listSize == 1)
	{
		delete elementToDelete;
		front = back = nullptr;
		listSize--;
	}
	else if (listSize > 1)
	{
		Element *newBack = back->previous;
		back = newBack;
		newBack->next = nullptr;
		delete elementToDelete;
		listSize--;
	}
	else if (!listSize)
	{
		std::cout << "Lista jest pusta. Nie ma czego usunac.";
	}
}

void MyList::pop(unsigned int position)
{
	if (position > 0 && position < listSize - 1)
	{
		Element *elementToDelete = findPosition(position);
		Element *element1 = elementToDelete->previous, *element2 = elementToDelete->next;
		element1->next = element2;
		element2->previous = element1;
		delete elementToDelete;
		listSize--;
	}
	else if (position == 0) popFront();
	else if (position == listSize - 1) popBack();
	else if (position >= listSize || position < 0)
	{
		std::string exc = "Pozycja spoza zakresu listy.";
		throw exc;
	}
}
//wypisanie zawartosci calej listy na ekran
void MyList::printList()
{
	Element *element = front;
	for (int i = 0; i < listSize; i++, element = element->next)
	{
		std::cout << element->value << "\t";
	}
}