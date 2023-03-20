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

};
