#pragma once
#include <iostream>
template <typename T, typename V>
class c_Calc
{
private:
	T val1;
	V val2;
public:
	c_Calc();
	c_Calc(T val1, V val2);
	
	T plus();
	T minus();

	void save();
	void load();
};

template<typename T, typename V>
inline c_Calc<T, V>::c_Calc()
{
	this->val1 = NULL;
	this->val2 = NULL;
}

template<typename T, typename V>
inline c_Calc<T, V>::c_Calc(T val1, V val2)
{
	this->val1 = val1;
	this->val2 = val2;
}

template<typename T, typename V>
inline T c_Calc<T, V>::plus()
{
	return (this->val1 + this->val2);
}

template<typename T, typename V>
inline T c_Calc<T, V>::minus()
{
	return (this->val1 - this->val2);
}

template<typename T, typename V>
inline void c_Calc<T, V>::save()
{
	FILE* file;
	fopen_s(&file, "file.txt", "wb");
	if (file) {
		fwrite(&this->val1, sizeof(val1), 1, file);
		fwrite(&this->val2, sizeof(val2), 1, file);
		fclose(file);
	}
}

template<typename T, typename V>
inline void c_Calc<T, V>::load()
{
	FILE* file;
	fopen_s(&file, "file.txt", "rb");
	if (file) {
		fread(&this->val1, sizeof(val1), 1, file);
		fread(&this->val2, sizeof(val2), 1, file);
		fclose(file);
	}
}





