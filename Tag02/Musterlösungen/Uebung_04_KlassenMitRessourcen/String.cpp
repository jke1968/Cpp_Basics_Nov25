#include "String.h"
#include <iostream>

String::String() : String("") {
}

String::String(const char* initChars) {
	length = strlen(initChars);
	characters = new char[length+1];
	strcpy(characters, initChars);
}

String::String(const String& original) : length{original.length} {
	characters = new char[length+1];
	strcpy(characters, original.characters);
}

String& String::operator=(const String& rhs)
{
	length = rhs.length;
	delete[] characters;
	characters = new char[length+1];
	strcpy(characters, rhs.characters);
	return *this;
}

void String::print() const
{
	std::cout << characters << std::endl;
}

void String::modifyAt(int index, char c)
{
	if (index < length) {
		characters[index] = c;
	}
}

String::~String()
{
	delete[] characters;
}
