#include "BBC.h"

BBC::BBC() : IArticlePub("BBC") {
	cout << "BBC constructor1 is called" << endl;
}

BBC::BBC(const string con) : IArticlePub("BBC", con) {
	cout << "BBC constructor2 is called" << endl;
}

BBC::~BBC() {
	cout << "BBC is destructed" << endl;
}

void BBC::Advertisement() {
	cout << "BBC NEWS is coming soon!!" << endl;
}

void BBC::Event() {
	string sname;
	int sid;
	for (int i = 0; i < 5; i++) {
		if (sub_list[i] != nullptr) {
			sname = sub_list[i]->getSubName();
			sid = sub_list[i]->getSubID();
			break;
		}
	}
	cout << "The Event winnder is (" << sname << "," << sid << ")" << endl;
}