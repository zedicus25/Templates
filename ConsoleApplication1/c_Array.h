#pragma once
#include <iostream>
#include <ctime>
template <typename T>
class c_Array
{
private:
	int size;
	T* arr;
	void addElemet2D(T element, T**& res, int& n,  int count);
public:
	c_Array();

	void create(int size);
	void randArr();
	void print();
	void sortArr();
	bool findArr(T num);
	void addElement(T element);
	T** findRepeatElement();

	void save();
	void load();
	
	~c_Array()
	{
		delete[] arr;
	}
};



template<typename T>
inline void c_Array<T>::addElemet2D(T element, T**& res, int& n, int count)
{
	int m = 2;
	T** tmp = new T * [n];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = new T[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[i][j] = res[i][j];
		}
	}

	res = nullptr;
	res = new T * [n + 1];
	for (int i = 0; i < n+1; i++)
	{
		res[i] = new T[m];
	}
	n++;

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res[i][j] = tmp[i][j];
		}
	}

	res[n-1][0] = element;
	res[n-1][1] = count;

	delete[] tmp;
}

template<typename T>
inline c_Array<T>::c_Array()
{
	this->size = 0;
	this->arr = new T[0];
}

template<typename T>
inline void c_Array<T>::create(int size)
{
	this->arr = new T[size];
	this->size = size;
}

template<typename T>
inline void c_Array<T>::randArr()
{
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = 1 + rand() % 10;
	}
}

template<typename T>
inline void c_Array<T>::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << "\n";
	}
}

template<typename T>
inline void c_Array<T>::sortArr()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j =this->size-1; j > 0; j--)
		{
			if (this->arr[j] < arr[j - 1]) {
				T tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

template<typename T>
inline bool c_Array<T>::findArr(T num)
{
	for (int i = 0; i < this->size; i++)
	{
		if (num == arr[i]) {
			return true;
		}
	}
	return false;
}

template<typename T>
inline void c_Array<T>::addElement(T element)
{
	T* tmp = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i];
	}
	this->arr = nullptr;
	this->arr = new T[this->size + 1];

	for (int i = 0; i < this->size; i++)
	{
		arr[i] = tmp[i];
	}
	this->size++;
	this->arr[size-1] = element;
	delete[] tmp;
}

template<typename T>
inline T** c_Array<T>::findRepeatElement()
{
	int n = 0;
	int m = 2;
	T** res = new T * [n];
	res[0] = new T[m];
	int count = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = i; j < this->size; j++)
		{
			if (this->arr[i] == this->arr[j]) {
				count++;
			}
		}

		if (count > 1) {
			if (n != 0) {
				bool f = true;
				for (int k = 0; k < n; k++)
				{
					if (res[k][0] == this->arr[i]) {
						f = false;
						break;
					}
				}
				if (f) {
					this->addElemet2D(this->arr[i], res, n, count);
				}
			}
			else{
				this->addElemet2D(this->arr[i], res, n, count);
			}
		}
		count = 0;
	}

	return res;
}

template<typename T>
inline void c_Array<T>::save()
{
	FILE* file;
	fopen_s(&file, "fileArr.txt", "wb");
	if (file) {
		fwrite(&this->size, sizeof(int), 1, file);
		fwrite(this->arr, sizeof(this->arr[0]), this->size, file);
		fclose(file);
	}
}

template<typename T>
inline void c_Array<T>::load()
{
	FILE* file;
	fopen_s(&file, "fileArr.txt", "rb");
	if (file) {
		fread(&this->size, sizeof(int), 1, file);
		this->arr = new T[this->size];
		fread(this->arr, sizeof(arr[0]), this->size, file);
		fclose(file);
	}
}

