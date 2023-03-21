#include <iostream>
#include <string>
#include <exception>
using namespace std;
class BadLength : public exception
{
private:
	string m_error;
public:
	BadLength()=default;
	BadLength::BadLength(string error) : m_error(error)
	{
	}
	// ¬озвращаем std::string в качестве константной строки C-style
	 const char* what() const noexcept { return m_error.c_str(); } 
};
