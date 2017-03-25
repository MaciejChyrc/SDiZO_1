#pragma once
class MyHeap
{
private:
	unsigned int arraySize;
	int* arrayptr;
public:
	MyHeap();
	MyHeap(unsigned int size);
	~MyHeap();
	unsigned int getSize();
	int at(unsigned int index);
	void pushBack(int val);
	void resize(unsigned int newSize);
	void swap(unsigned int element1, unsigned int element2);
	void deleteRoot();
	void addToTail(int val);
	int leftSon(unsigned int index);
	int rightSon(unsigned int index);
	int parent(unsigned int index);
	void printHeap(unsigned int index);
};