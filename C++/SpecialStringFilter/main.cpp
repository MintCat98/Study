#include <iostream>
#include <string.h>
using namespace std;

//#include "SpecialFilter.h"

char** special_filter(const char* sentences[], int filter_offset, int num_sentences) {
	// result container
	char** filtered = new char* [num_sentences];
	// divide sentences
	for (int i = 0; i < num_sentences; i++) {
		int len = strlen(sentences[i]);
		filtered[i] = new char[len + 1];
		// filter
		for (int j = 0; i < len; j++) {
			char select = sentences[i][j];
			int ascii = int(select);
			// whitespace or null
			if (ascii == 32) {
				filtered[i][j] = select;
				continue;
			}
			else if (ascii == 0) {
				filtered[i][j] = select;
				break;
			}
			// letters
			// cap or lower
			int os = filter_offset;
			int start = (ascii > 96) ? 97 : 65;
			// lower
			if (start > 96) {
				os += 97;
				filtered[i][j] = (ascii < os) ? select : char(35);
			}
			// cap
			else {
				os += 65;
				filtered[i][j] = (ascii < os) ? select : char(35);
			}
		}
	}
	return filtered;
}

int main() {
	const char* sentences[] = { "Hello bruhs", "I am ABCDEFGHIJKLMNOPQRSTUBWXYZ" };
	int num_sentences = 2;
	char** result = special_filter(sentences, 25, num_sentences);
	for (int i = 0; i < num_sentences; i++) {
		cout << result[i] << endl;
	}
}