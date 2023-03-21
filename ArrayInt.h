#pragma once
#include <iostream>
using namespace std;
class IntArray
{
private:
	int m_length;
	int* m_data;

public:
	IntArray() = default;
	IntArray(int length);
	int getLength();
	int& operator[](const int index);
	IntArray&  operator=(const IntArray& a);
	void show();
};
