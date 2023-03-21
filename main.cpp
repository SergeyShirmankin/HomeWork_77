#include <iostream>
#include "ArrayInt.h"
#include "BadLength.h"
int main()
{
	IntArray array(100);//создание массива 
	try {
		array[105] = 15;//присваивание массиву  данные
	}
	catch (BadLength &exception) // сначала ловим исключения дочернего класса - исключения
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (std::exception &exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}

	return 0;
}