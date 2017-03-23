#pragma once
class MyList
{
private:
	struct Element
	{
		Element *next, *previous;
		int value;
		Element (int value)
		{
			this->value = value;
			this->next = nullptr;
			this->previous = nullptr;
		}
	};

	int listSize;
public:
	MyList();
	~MyList();
	Element *front, *back;
	void pushFront (int val);
	void pushBack (int val);
	void push (int val, unsigned int position);
	void popFront ();
	void popBack ();
	void pop (unsigned int position);
	Element* findPosition (unsigned int position);
	void printList();
};