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
