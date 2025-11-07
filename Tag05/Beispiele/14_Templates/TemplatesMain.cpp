#include <iostream>
#include <string>
// um eine swap-Funktion zu erhalten,
// die alle möglichen Datentypen swapped
// wird aus der konkreten Funktion
// eine sog. "template function" oder auch ein "function template"
// diese Funktion heisst auch "template definition"
template<typename T>
void swap(T& i1, T& i2) {
	T tmp = i1;
	i1 = i2;
	i2 = tmp;
}

// Beispiel für ein class-Template / bzw. eine Template-Klasse 
// Eine Container-Klasse für beliebige Datentypen T
template<typename T>
class Container {
private:
	static constexpr size_t max_elements = 3;
	T elements[max_elements];
public:
	Container() {}
	void printElements() const {
		for (int i = 0; i < max_elements; i++) {
			// Annahme: es existiert ein << Operator für den Typ T
			std::cout << elements[i] << " ";
		}
		std::cout << std::endl;
	}
	void modifyAt(int index, T element) {
		if (index >= 0 && index < max_elements) {
			elements[index] = element;
		}
	}
	// liefert alle Elemente des internen Arrays als Strin zurück
	std::string getElements() const {
		std::string result{};
		for (int i = 0; i < max_elements; i++) {
			result = result + std::to_string(elements[i]) + " ";
		}
		return result;
	}
};
// Überlade den << Operator für die Datentypen 
// std::ostream (linke Seite) und
// Container (rechte Seite)
template <typename T>
std::ostream& operator<<(std::ostream& out, const Container<T>& rhs) {
	return out << rhs.getElements();
}

int main() {
	int i1 = 11;
	int i2 = 22;
	double d1 = 1.1;
	double d2 = 2.2;
	std::string s1 = { "Thales" };
	std::string s2 = { "Hitachi" };

	std::cout << "vorher  i1 = "  << i1 << " i2 = " << i2 << std::endl;
	// da swap eine template-function ist, 
	// ist dieser Funktionsaufruf eine sog. "template instantiation"
	// #1 Instanziierung für den Typ int
	swap(i1, i2);
	std::cout << "nachher i1 = " << i1 << " i2 = " << i2 << std::endl;

	std::cout << "vorher  d1 = " << d1 << " d2 = " << d2 << std::endl;
	// #2 Instanziierung für den Typ double
	swap(d1, d2);
	std::cout << "nachher d1 = " << d1 << " d2 = " << d2 << std::endl;

	std::cout << "vorher  s1 = " << s1 << " s2 = " << s2 << std::endl;
	// #3 Instanziierung für den Typ std::string
	swap(s1, s2);
	std::cout << "nachher s1 = " << s1 << " s2 = " << s2 << std::endl;

	// Instanziiere ein Objekt der Klasse "Container":
	// da Container eine Template-Klasse ist, muss
	// ein Datentyp zusätzlich angegeben werden: der Datentyp
	// für die Elemente des Arrays
	// #1 Instanziierung für den Typ int
	Container<int> intContainer{};
	intContainer.printElements();
	intContainer.modifyAt(0, 7);
	intContainer.printElements();
	// #2 Instanziierung für den Typ std::string
	Container<std::string> stringContainer{};
	stringContainer.printElements();
	stringContainer.modifyAt(0, "Bjarne");
	stringContainer.printElements();

	std::cout << "Alle Elemente des int-Containers" << std::endl;
	std::cout << intContainer << std::endl;

	return 0;
}