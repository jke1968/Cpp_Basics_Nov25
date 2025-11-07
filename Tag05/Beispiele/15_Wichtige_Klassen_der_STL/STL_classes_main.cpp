#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void printElements(const std::vector<std::string> strings) {
	// "for-each" in C++
	for (std::string s : strings) {
		std::cout << s << std::endl;
	}
}

bool compare_strings_descending(const std::string& s1, const std::string& s2) {
	if (s1 > s2) {
		return true;
	}
	return false;
}
int main() {
	std::string s{ "Hello World!" };

	// Anstelle eines Array: ein std::vector für std::strings
	std::vector<std::string> strings{};
	strings.push_back("GAMMA");
	strings.push_back("BETA");
	strings.push_back("ALPHA");
	std::cout << "unsorted" << std::endl;
	printElements(strings);
	// sortiere den vector mit der Template function "std::sort"
	// std::sort macht hier Gebrauch vom < Operator (der existieren muss)
	std::sort(strings.begin(), strings.end());
	std::cout << "sorted in ascending order" << std::endl;
	printElements(strings);
	// std::sort macht hier Gebrauch von der übergebenen Funktion
	std::sort(strings.begin(), strings.end(),compare_strings_descending);
	std::cout << "sorted in descending order" << std::endl;
	// std::sort verwendet hier eine sog. "lambda expression" 
	// (-> ein anonymes Funktionsobjekt) 
	std::sort(strings.begin(), strings.end(), [](const std::string& s1, const std::string& s2)
		{
			return s1.size() < s2.size();
		}
	);
	std::cout << "sorted by length" << std::endl;
	printElements(strings);

	return 0;
}
