#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Array {
	T* mas_;
	int count_;
	int cap_;
	int grow_;

public:
	Array();
	~Array();
	Array<T>(const Array& obj);
	Array<T>& operator=(const Array& obj);
	int GetSize();
	void SetSize(size_t size, int grow = 1);
	int GetUpperBound();
	bool IsEmpty();
	void FreeExtra();
	void RemoveAll();
	T GetAt(int index);
	void SetAt(int index, T val);
	T& operator[](int index);
	void Add(T val);
	Array<T>& Append(const Array& obj);
	T** GetData();
	void InsertAt(int pos, T val);
	void RemoveAt(int pos);

	template<class T>
	friend ostream& operator<<(ostream& out, const Array<T>& obj);
};