#pragma once
#pragma warning(disable: 4996)
#include <string.h>
class String
{
private:
	char* characters = nullptr;
	size_t length = 0;
public:
	// default ctor
	String();
	// one argument ctor
	String(const char* initChars);
	// copy ctor
	String(const String& original);
	// assignment operator
	String& operator=(const String& rhs);
	void print() const;
	void modifyAt(int index, char c);
	// destructor
	~String();
};

