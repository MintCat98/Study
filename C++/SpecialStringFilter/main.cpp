#include <iostream>
using namespace std;

#include "SpecialFilter.h"

int main() {
	const char* sentences[] = { "Hello bruhs", "I am ABCDEFGHIJKLMNOPQRSTUBWXYZ" };
	int num_sentences = 2;
	char** result = special_filter(sentences, 25, num_sentences);
	for (int i = 0; i < num_sentences; i++) {
		cout << result[i] << endl;
	}
}