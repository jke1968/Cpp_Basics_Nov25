#include <iostream>

void swap(int& number1, int& number2) {
	int tmp = number1;
	number1 = number2;
	number2 = tmp;
}

int main() {
	int number1 = 0;
	int number2 = 0;

	std::cout << "Number1 : ";
	std::cin >> number1;
	std::cout << "Number2 : ";
	std::cin >> number2;
	std::cout << "Before: number1= " << number1 << " number2= " << number2 << std::endl;
	swap(number1, number2);
	std::cout << "After:  number1 = " << number1 << " number2 = " << number2 << std::endl;

	return 0;
}