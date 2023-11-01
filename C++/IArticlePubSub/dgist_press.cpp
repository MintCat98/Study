#include "dgist_press.h"

dgist_press::dgist_press() : IArticlePub("DGIST") {
	cout << "dgist press constructor1 is called" << endl;
}

dgist_press::dgist_press(const string con) : IArticlePub("DGIST", con) {
	cout << "dgist press constructor2 is called" << endl;
}

dgist_press::~dgist_press() {
	cout << "DGIST PRESS is destructed" << endl;
}

void dgist_press::Event() {
	cout << "The Event is totally swindle" << endl;
}

void dgist_press::CheerUp() {
	updatePubContents("I Love you guys");
}