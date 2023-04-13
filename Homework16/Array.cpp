#include "Array.h"

template <typename T>
Array<T>::Array()
{
	mas_ = 0;
	count_ = 0;
	cap_ = 0;
	grow_ = 1;
}

template <typename T>
Array<T>::~Array()
{
	if (mas_)
		delete[]mas_;
	mas_ = 0;
}

template<typename T>
Array<T>::Array(const Array& obj)
{
	count_ = obj.count_;
	cap_ = obj.cap_;
	grow_ = obj.grow_;
	mas_ = new int[cap_];
	memcpy(mas_, obj.mas_, sizeof(T) * cap_);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this != &obj) {
		delete[] mas_;
		count_ = obj.count_;
		cap_ = obj.cap_;
		grow_ = obj.grow_;
		mas_ = new int[obj.cap_];
		memcpy(mas_, obj.mas_, sizeof(T) * cap_);
	}
	return *this;
}

template <typename T>
int Array<T>::GetSize()
{
	return cap_;
}

template <typename T>
void Array<T>::SetSize(size_t size, int grow)
{
	grow_ = grow;
	if (size <= cap_) {
		mas_ = (T*)realloc(mas_, sizeof(T) * size);
		cap_ = size;
		if (count_ > cap_)
			count_ = cap_;
		return;
	}
	else {
		if (size % grow != 0)
			size = size + (grow - (size % grow));
		mas_ = (T*)realloc(mas_, sizeof(T) * size);
		cap_ = size;
	}
}

template <typename T>
int Array<T>::GetUpperBound()
{
	return count_ - 1;
}

template <typename T>
bool Array<T>::IsEmpty()
{
	return count_ == 0;
}

template <typename T>
void Array<T>::FreeExtra()
{
	if (cap_ % grow_ != 0) {
		mas_ = (T*)realloc(mas_, sizeof(T) * (count_ + (grow_ - count_ % grow_)));;
		cap_ = count_ + (grow_ - count_ % grow_);
	}
	else if (cap_ % grow_ == 0) {
		mas_ = (T*)realloc(mas_, sizeof(T) * count_);
		cap_ = count_;
	}
}

template <typename T>
void Array<T>::RemoveAll()
{
	delete[]mas_;;
	mas_ = 0;
	cap_ = 0;
	count_ = 0;
}

template <typename T>
T Array<T>::GetAt(int index)
{
	if (index >= 0 && index < count_) return mas_[index];
	else throw index;
}

template <typename T>
void Array<T>::SetAt(int index, T val)
{
	if (index >= 0 && index <= count_ && index < cap_) {
		mas_[index] = val;
		if (index == count_)
			count_++;
	}
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index == count_ && index < cap_) {
		count_++;
		return mas_[index];
	}
	if (index >= 0 && index < count_) return mas_[index];
	else throw index;
}

template <typename T>
void Array<T>::Add(T val)
{
	if (count_ < cap_)
		mas_[count_++] = val;
	else if (count_ >= cap_) {
		SetSize(cap_ + grow_, grow_);
		mas_[count_++] = val;
	}
}

template <typename T>
Array<T>& Array<T>::Append(const Array& obj)
{
	SetSize(count_ + obj.count_, grow_);
	memcpy(mas_ + count_, obj.mas_, sizeof(T) * obj.count_);
	count_ = count_ + obj.count_;
	return *this;
}

template <typename T>
T** Array<T>::GetData()
{
	return &mas_;
}

template <typename T>
void Array<T>::InsertAt(int pos, T val)
{
	if (0 <= pos && pos <= count_) {
		if (cap_ < count_ + 1)
			SetSize(cap_ + 1, grow_);
		if (pos > count_)
			mas_[pos] = val;
		else {
			for (int i = count_; i >= pos; i--) {
				mas_[i] = mas_[i - 1];
			}
			mas_[pos] = val;
		}
		count_++;
	}
	else
		return;
}

template <typename T>
void Array<T>::RemoveAt(int pos)
{
	if (pos < 0 || pos >= count_)
		return;
	for (int i = pos; i < count_; i++)
		mas_[i] = mas_[i + 1];
	count_--;
}

template<class T>
ostream& operator<<(ostream& out, const Array<T>& obj)
{
	for (int i = 0; i < obj.count_; i++) {
		out << obj.mas_[i] << " ";
	}
	return out;
}