#pragma once
class MyArray
{
protected:
	unsigned int arraySize;
	int* arrayptr;
public:
	MyArray();
	MyArray(unsigned int size);
	virtual ~MyArray();
	unsigned int getSize();
	int at(unsigned int index);
	void pushBack(int val);
	void pushFront(int val);
	void push(int val, unsigned int index);
	void insert(int val, unsigned int index);
	void popFront();
	void popBack();
	void pop(unsigned int index);
	void resize(unsigned int newSize);
	void swap(unsigned int element1, unsigned int element2);
	void printArray();
	int& operator[] (size_t index);
	const int& operator[] (size_t index) const;
};