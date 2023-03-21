#include <iostream>
#include "ArrayInt.h"
#include "BadLength.h"
int main()
{
	IntArray array(100);//�������� ������� 
	try {
		array[105] = 15;//������������ �������  ������
	}
	catch (BadLength &exception) // ������� ����� ���������� ��������� ������ - ����������
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (std::exception &exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}

	return 0;
}