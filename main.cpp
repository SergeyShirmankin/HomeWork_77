#include <iostream>
#include "ArrayInt.h"
#include "BadLength.h"
int main()
{
	IntArray array(10);//создание массива 
	IntArray arrayCopy(15);//массив дл€ тестировании копии
	try {
		array[5] = 15;//присваивание массиву  данные
		std::cout <<" array[5] = "<< array[5]<<std::endl;//¬ывод элемент массива;
		arrayCopy = array;//копирование массива
	}
	catch (BadLength &exception) // сначала ловим исключени€ дочернего класса - исключени€
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (std::exception &exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}
	array.show();
	std::cout << "arrayCopy" << endl;
	arrayCopy.show();
	return 0;
}