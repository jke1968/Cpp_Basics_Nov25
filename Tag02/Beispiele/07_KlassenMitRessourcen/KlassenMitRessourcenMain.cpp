#include <iostream>
#include "Container.h"

void f(Container copy) {
	std::cout << "enter f" << std::endl;
	copy.modify(1);
	copy.printElements();
	std::cout << "exit f" << std::endl;
}
void demoCopyCtor() {
	Container original{ 3 };
	original.printElements();
	f(original);
	original.printElements();
}
int main() {
	std::cout << "enter main" << std::endl;
	Container c1{ 3 };
	Container c2{ 3 };
	c1 = c2;
	c2.modify(1);
	c2.printElements();
	c1.printElements();
	std::cout << "exit main" << std::endl;
	return 0;
}