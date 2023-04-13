#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Element
{
	T Data;
	Element* Prev, * Next;
};

template <typename T>
class Turn
{
	Element<T>* Head, * Tail;
	T Data;
	int count;

	void DelAll();
	void AddTail(T _data);
	void AddHead(T _data);
	void AddSomeWhere(int temp, T _data);
	void DelTail();

public:
	Turn();
	void Add(T _data);
	Element<T> Derive();
	bool Empty();
	void Print();
	~Turn();
};

