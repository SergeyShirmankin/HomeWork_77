#include "ArrayInt.h"
#include "BadLength.h"
IntArray::IntArray(int length) : m_length(length)//конструктор массива
{
	try
	{
		m_data = new int[length] {}; // проверка правильности индекса и размера выделения памяти
	}
	catch (bad_alloc& ba)
	{
		cout << "bad_alloc caught!" << endl; //при неудаче выдавать ошибку
		cout << ba.what() << endl;
	}
}

int IntArray::getLength() { return m_length; } //геттер

int& IntArray::operator[](const int index)//оператор присваивания и отображении значения массива (переопределенный)
{
		if (index < 0 || index >= getLength())
			throw BadLength("Invalid index");//выбрасывают аварию
		return m_data[index];	
}


IntArray& IntArray:: operator=(const IntArray& a)//оператор копирования (переопределеннная)
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

void IntArray::show()//отобразить элементы массива на экране
{
	for (int i = 0; i < m_length; ++i)
	{
		std::cout << "m_data[" << i << "] = " << m_data[i]<<"  adress = "<< &m_data[i] << endl;
	}
}

void IntArray::insertBefore(int value, int index)//Вставить элемент массива по индексу и по значению
{
	// Проверяем правильность нашего значения индекса
	if (index >= 0 && index <= m_length)
	 {
		int* data{ new int[m_length + 1] };// Сначала создаем новый массив на один элемент больше, чем старый массив
		for (int before{ 0 }; before < index; ++before)// Копируем все элементы до индекса
			data[before] = m_data[before];
		data[index] = value;// Вставляем наш новый элемент в новый массив
		for (int after{ index }; after < m_length; ++after)// Копируем все значения после вставленного элемента
			data[after + 1] = m_data[after];
		delete[] m_data;// Наконец, удаляем старый массив и используем вместо него новый массив
		m_data = data;
		++m_length;
	}
	else
	{
		throw BadLength("Index not border");//если не входим в диапазон то запускаем аварию
	}
}
void IntArray::remove(int index)//Удаление одного элемента массива по индексу 
{
	if (index >= 0 && index <= m_length)
	{
		int* data{ new int[m_length - 1] };// Сначала создаем новый массив на один элемент меньше, чем старый массив
		// Копируем все элементы до индекса
		for (int before{ 0 }; before < index; ++before)	// Копируем все элементы до индекса
			data[before] = m_data[before];
		for (int after{ index + 1 }; after < m_length; ++after)// Копируем все значения после удаленного элемента
			data[after - 1] = m_data[after];
		// Наконец, удаляем старый массив и используем вместо него новый массив
		delete[] m_data;
		m_data = data;
		--m_length;
	}
	else
	{
		throw BadLength("Index not border");//если не входим в диапазон то запускаем аварию
	}
}
void IntArray::find(int value)//поиск в массиве данных
{
	for (int i = 0; i < m_length; ++i)
	{
		if (m_data[i] == value)
		{
			std::cout<<std::endl;
			std::cout << "Finded  m_data[" << i << "] = " << m_data[i] << "  adress = " << &m_data[i] << endl;
			std::cout << std::endl;
		}
	}
}
