#include <iostream>
#include <ctime>
#include "c_Calc.h"
#include "c_Array.h"
int main()
{
	srand(time(0));
	/*c_Calc<float,int> calc(5,5);
	calc.load();
	std::cout << calc.plus();
	std::cout << "\n";
	std::cout << calc.minus();
	calc.save();*/

	c_Array<int> arr;
	int** arr1 = new int*[0];
	arr1[0] = new int[0];
	//arr.load();
	arr.create(10);
    arr.randArr();
	arr.sortArr();
	arr.print();
	std::cout << "\n";
	//arr.addElement(1555);
	//arr.print();
	//arr.save();
	arr1 = arr.findRepeatElement();
	std::cout << "\n";
	for (int i = 0; i < _msize(arr1)/sizeof(int); i++)
	{
		for (int j = 0; j <2; j++)
		{
			std::cout << arr1[i][j] << " ";
		}
		std::cout << "\n";
	}

}