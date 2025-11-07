#include <iostream>
class Shape {
public:
	virtual float calculateArea() const = 0;
	virtual float calculateCircumference() const = 0;
};
class GraphicalObject {
private:
	int x;
	int y;
public: 
	GraphicalObject(int x, int y)
		: x{ x }, y{ y } {

	}
	int getX() const {
		return x;
	}
	int getY() const {
		return x;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	// diese member-function hat keine 
	// Implementierung in dieser Klasse
	// also ist sie eine "pure virtual function"
	// Eine Klasse mit wenigstens einer "Pure virtual function"
	// heisst "Abstrakte Klasse" -> von ihr kann kein Objekt erzeugt werden
	virtual float calculateArea() const = 0;

};

class Circle : public GraphicalObject, public Shape {
private:
	size_t radius;
public:
	Circle(int x, int y, size_t radius) 
		: GraphicalObject{ x,y }, radius { radius } {}
	// hier kann calculateArea implementiert werden
	float calculateArea() const override {
		return 3.141f * radius * radius;
	}
	float calculateCircumference() const override {
		return 2 * 3.141f * radius;
	}

};

class Rectangle : public GraphicalObject, public Shape {
private:
	size_t width;
	size_t height;
public:
	Rectangle(int x, int y, size_t width, size_t height)
		: GraphicalObject{ x,y }, width{ width }, height{ height } {}
	// hier kann calculateArea implementiert werden
	float calculateArea() const override {
		return static_cast<float>(width * height);
	}
	float calculateCircumference() const override {
		return static_cast < float>(2 * width + 2*height);
	}

};

int main() {
	GraphicalObject* graphicalObjects[2];
	Shape* shapes[2];
	Circle* c = new Circle{ 100,100,1 };
	graphicalObjects[0] = c;
	shapes[0] = c;
	Rectangle* r = new Rectangle{ 120,120,10,20 };
	graphicalObjects[1] = r;
	shapes[1] = r;
	float sumAreas = 0;
	float sumCircumferences = 0;
	for (int i = 0; i < 2; i++) {
		sumAreas += shapes[i]->calculateArea();
		sumCircumferences += shapes[i]->calculateCircumference();
	}
	std::cout << "Sum of all areas: " << sumAreas << std::endl;
	std::cout << "Sum of all circumferences: " << sumCircumferences << std::endl;
	return 0;
}