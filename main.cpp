#include <iostream>
#include "ArrayInt.h"
#include "BadLength.h"
int main()
{
	IntArray array(10);//создание массива 
	IntArray arrayCopy(10);//массив для тестировании копии
	try {
		array[5] = 15;//присваивание массиву  данные
		std::cout <<" array[5] = "<< array[5]<<std::endl;//Вывод элемент массива;
		arrayCopy = array;//копирование массива
		array.insertBefore(13, 6);//вставка элемента массива
		array.show();
		array.remove(1);//Удаление элемента массива;
	}
	catch (BadLength &exception) // сначала ловим исключения дочернего класса - исключения
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