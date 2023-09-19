#include <iostream>
using namespace std;

void reverse(const char* str);

int main() {
	const char* str = "DGIST";	// str -> address of "D"
	reverse(str);
	return 0;
}

void reverse(const char* str) {
	if (*str) {
		// Call `reverse` until it encounters "\0"
		reverse(str + 1);
		// Then print backward
		cout << *str;
	}
}