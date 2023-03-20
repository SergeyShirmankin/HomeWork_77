#include "ArrayInt.h"
IntArray::IntArray(int length) : m_length(length)
{
				m_data = new int[length] {};
}