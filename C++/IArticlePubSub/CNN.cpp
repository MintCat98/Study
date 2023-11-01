#include "CNN.h"

CNN::CNN() : IArticlePub("CNN") {
	cout << "CNN constructor1 is called" << endl;
}

CNN::CNN(const string con) : IArticlePub("CNN", con) {
	cout << "CNN constructor2 is called" << endl;
}

CNN::~CNN() {
	cout << "CNN is destructed" << endl;
}

void CNN::Event() {
	string sname;
	int sid;
	for (int i = 4; i > -1; i--) {
		if (sub_list[i] != nullptr) {
			sname = sub_list[i]->getSubName();
			sid = sub_list[i]->getSubID();
			break;
		}
	}
	cout << "The Event winnder is (" << sname << "," << sid << ")" << endl;
}