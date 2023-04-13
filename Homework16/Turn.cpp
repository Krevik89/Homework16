#include "Turn.h"

template<typename T>
Turn<T>::Turn()
{
	Head = Tail = NULL;
	count = 0;
}

template<typename T>
Turn<T>::~Turn()
{
	DelAll();
}

template<typename T>
void Turn<T>::DelAll()
{
	Element<T>* ptr;
	while (count != 0)
	{
		ptr = Head;
		Head = Head->Next;
		delete ptr;
		count--;
	}
}

template<typename T>
void Turn<T>::AddTail(T data)
{
	Element<T>* ptr = new Element<T>;

	Tail->Next = ptr;
	ptr->Prev = Tail;
	ptr->Next = NULL;
	Tail = ptr;

	count++;
}

template<typename T>
void Turn<T>::AddHead(T _data)
{
	Element<T>* ptr = new Element<T>;

	if (count == 0)
	{
		Head = ptr;
		Tail = ptr;
		ptr->Data = _data;
		ptr->Next = NULL;
		ptr->Prev = NULL;
		count++;
	}
	else
	{
		Head->Prev = ptr;
		ptr->Next = Head;
		ptr->Data = _data;
		ptr->Prev = NULL;
		Head = ptr;
		count++;
	}
}

template<typename T>
void Turn<T>::AddSomeWhere(int position, T _data)
{

	if (position<0 || position>count)
	{
		cout << "\n\nError!\n\n";
		exit(1);
	}

	if (position == 0)
	{
		AddHead(_data);
	}

	else if (position == count - 1)
	{
		AddTail(_data);
	}

	else
	{
		Element<T>* ptr = Head;
		int i = 0;
		while (i < position)
		{
			ptr = ptr->Next;
			i++;
		}

		Element<T>* prev = ptr;
		Element<T>* next = ptr->Next;
		Element<T>* cur = new Element<T>();
		prev->Next = cur;
		cur->data = _data;
		cur->Prev = prev;
		cur->Next = next;
		next->Prev = cur;
	}
	count++;

}

template<typename T>
bool Turn<T>::Empty()
{
	if (count == 0)return true;
	else return false;
}

template<typename T>
void Turn<T>::Add(T _data)
{
	AddHead(_data);
}

template<typename T>
Element<T> Turn<T>::Derive()
{
	Element<T>tmp;

	if (!Empty())
	{
		tmp.Data = Tail->Data;
		tmp.Next = Tail->Next;
		tmp.Prev = Tail->Prev;

		DelTail();
		return tmp;
	}
	else
	{
		return tmp;
	}
}

template<typename T>
void Turn<T>::DelTail()
{

	if (count == 1)
	{
		delete Tail;
		Tail = NULL;
		Head = NULL;
	}
	else
	{
		Element<T>* ptr = Tail->Prev;
		ptr->Next = NULL;
		delete Tail;
		Tail = ptr;
	}

	count--;
}

template<typename T>
void Turn<T>::Print()
{
	Element<T>* ptr = Head;

	while (ptr != 0)
	{
		cout << ptr->Data;
		ptr = ptr->Next;
	}

	cout << "\n\n";
}
