#include <iostream>
#include <string.h> // for strstr

bool isPalindrome(const std::string s) {
	int left = 0;
	int right = s.length() - 1;
	while (left < right) {
		if (s[left] != s[right]) {
			return false;
		}
		left++;
		right--;
	}
}
bool contains_anna(const std::string s) {
	if (strstr(s.c_str(), "anna") != NULL) {
		return true;
	} else {
		return false;
	}
}
int main() {
	std::string s;
	do {
		std::cout << "Enter word: ";
		std::cin >> s;
		std::cout 
			<< s << " is palindrome: " 
			<< std::boolalpha << isPalindrome(s);
		std::cout << std::endl;
		std::cout 
			<< s << " contains 'anna' " 
			<< std::boolalpha << contains_anna(s);
		std::cout << std::endl;
	} while (s != "EXIT");
	return 0;
}