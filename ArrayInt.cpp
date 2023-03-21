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
   if (&a == this)//Проверка на самоназначначения адреса
     return *this;
   if (this->m_length != a.m_length)//проверка разности длин массивов для копирования
   {
	   throw BadLength("Different length arrays");
   }
   else {
	   for (int index{ 0 }; index < m_length; ++index)//Затем копируем элементы  
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