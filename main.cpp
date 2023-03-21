#include <iostream>
#include "ArrayInt.h"
#include "BadLength.h"
int main()
{
	IntArray array(10);//�������� ������� 
	IntArray arrayCopy(15);//������ ��� ������������ �����
	try {
		array[5] = 15;//������������ �������  ������
		std::cout <<" array[5] = "<< array[5]<<std::endl;//����� ������� �������;
		arrayCopy = array;//����������� �������
	}
	catch (BadLength &exception) // ������� ����� ���������� ��������� ������ - ����������
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