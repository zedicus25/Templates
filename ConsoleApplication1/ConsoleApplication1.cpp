#include <iostream>
#include "c_Calc.h"
int main()
{
	c_Calc<float,int> calc(5,5);
	//calc.load();
	calc.plus(4,5);
	std::cout << "\n";
	calc.minus(7,5);
	//calc.save();
}