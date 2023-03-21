#include "ArrayInt.h"
#include "BadLength.h"
IntArray::IntArray(int length) : m_length(length)
{
	try
	{
		m_data = new int[length] {};
	}
	catch (bad_alloc& ba)
	{
		cout << "bad_alloc caught!" << endl;
		cout << ba.what() << endl;
	}
}

int IntArray::getLength() { return m_length; }

int& IntArray::operator[](const int index)
{
		if (index < 0 || index >= getLength())
			throw BadLength("Invalid index");
		return m_data[index];	
}


IntArray& IntArray:: operator=(const IntArray& a)
{
   if (&a == this)//�������� �� ����������������� ������
     return *this;
   if (this->m_length != a.m_length)//�������� �������� ���� �������� ��� �����������
   {
	   throw BadLength("Different length arrays");
   }
   else {
	   for (int index{ 0 }; index < m_length; ++index)//����� �������� ��������  
		   m_data[index] = a.m_data[index];
   }
  return *this;
}

void IntArray::show()
{
	for (int i = 0; i < m_length; ++i)
	{
		std::cout << "m_data[" << i << "] = " << m_data[i]<<"  adress = "<< &m_data[i] << endl;
	}
}

void IntArray::insertBefore(int value, int index)
{
	// ��������� ������������ ������ �������� �������
	if (index >= 0 && index <= m_length)
	 {
		int* data{ new int[m_length + 1] };// ������� ������� ����� ������ �� ���� ������� ������, ��� ������ ������
		for (int before{ 0 }; before < index; ++before)// �������� ��� �������� �� �������
			data[before] = m_data[before];
		data[index] = value;// ��������� ��� ����� ������� � ����� ������
		for (int after{ index }; after < m_length; ++after)// �������� ��� �������� ����� ������������ ��������
			data[after + 1] = m_data[after];
		delete[] m_data;// �������, ������� ������ ������ � ���������� ������ ���� ����� ������
		m_data = data;
		++m_length;
	}
	else
	{
		throw BadLength("Index not border");
	}
}
//void IntArray::remove(int index)
//{
//	if (index >= 0 && index <= m_length)
//	{
//	int* data{ new int[m_length - 1] };// ������� ������� ����� ������ �� ���� ������� ������, ��� ������ ������
//	// �������� ��� �������� �� �������
//	for (int before{ 0 }; before < index; ++before)	// �������� ��� �������� �� �������
//		data[before] = m_data[before];	
//	for (int after{ index + 1 }; after < m_length; ++after)// �������� ��� �������� ����� ���������� ��������
//		data[after - 1] = m_data[after];
//	// �������, ������� ������ ������ � ���������� ������ ���� ����� ������
//	delete[] m_data;
//	m_data = data;
//	--m_length;
//   }
//	else
//	{
//	throw BadLength("Index not border");
//    }
//
//