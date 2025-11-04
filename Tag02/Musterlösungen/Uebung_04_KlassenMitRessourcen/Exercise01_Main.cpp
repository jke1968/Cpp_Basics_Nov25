#include "String.h"
#include <stdio.h>
void f(String s) {
	s.modifyAt(0, 'X');
	s.print();
}
void testEmptyString() {
	String s3;
	printf("---");
	s3.print();
	s3.modifyAt(0, 'X');
	s3.print();
	printf("---");
}
int main() {
	String s1{ "ABC" };
	s1.print();
	// test copy ctor
	f(s1);
	s1.print();
	// test assignment operator
	String s2{ "DEFG" };
	s1 = s2;
	s2.modifyAt(0, 'Y');
	s1.print();
	s2.print();

	return 0;
}