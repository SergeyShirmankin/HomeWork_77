#include "ArrayInt.h"
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