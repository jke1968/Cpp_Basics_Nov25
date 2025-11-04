#include "Container.h"
#include <iostream>
Container::Container(size_t size)
	: size{ size }, elements{new int[size]} // alloziere ein Array auf dem Heap
{
	std::cout << "ctor called" << std::endl;
	for (int i = 0; i < size; i++) {
		elements[i] = 100 + i;
	}
}

Container::Container(const Container& original)
{
	std::cout << "copy ctor called" << std::endl;
	// 1. kopiere die "einfachen" Member vom original in die Kopie
	this->size = original.size;
	// 2. alloziere ein neues heap array für die Kopie
	//    in der passenden Größe
	this->elements = new int[this->size];
	// 3. kopiere die Elemente des Arrays von der Kopie ins Original
	for (size_t i = 0; i < size; i++) {
		this->elements[i] = original.elements[i];
	}
}
Container& Container::operator=(const Container& rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	// 1. kopiere die einfachen Member von der rechten auf die linke Seite
	this->size = rhs.size;
	// 2. gib das heap memory segment der linken Seite frei
	delete[] this->elements;
	// 3. alloziere ein neues heap memory Segment in der passenden Größe
	//    für die linke Seite
	this->elements = new int[this->size];
	// 4. kopiere von der rechten in die linke Seite
	for (size_t i = 0; i < size; i++) {
		this->elements[i] = rhs.elements[i];
	}
	// 5. gib den linken Operanden als Referenz zurück:
	return *this;

}

void Container::printElements() const
{
	for (size_t i = 0; i < size; i++) {
		std::cout << elements[i] << " ";
	}
	std::cout << std::endl;
}

void Container::modify(int i)
{
	if (size >= 1) {
		elements[0] = i;
	}
}


Container::~Container()
{
	std::cout << "dtor called" << std::endl;
	// gib das allozierte Array wieder frei
	delete[] elements;
}
