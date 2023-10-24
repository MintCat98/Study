#include "IArticleSub.h"

int IArticleSub::static_sub_counter = 0;

IArticleSub::IArticleSub(string name) : sub_name{ name } {
	IArticleSub::static_sub_counter++;
	sub_id = static_sub_counter;
	for (int i = 0; i < 5; i++) {
		pub_list[i] = nullptr;
	}
	cout << "[Constructor]New Sub Created: (" << this->sub_name << "," << this->sub_id << ")" << endl;
}

IArticleSub::IArticleSub(string name, IArticlePub* articlePub) : sub_name{ name } {
	IArticleSub::static_sub_counter++;
	sub_id = static_sub_counter;
	for (int i = 0; i < 5; i++) {
		pub_list[i] = nullptr;
	}
	cout << "[Constructor]New Sub Created: (" << this->sub_name << "," << this->sub_id << ")" << endl;
	Attach(articlePub);
}

IArticleSub::~IArticleSub() {
	cout << "IAtricleSub Destructor called" << endl;
	for (IArticlePub* target : pub_list) {
		if (target != nullptr) {
			target->NotifyDetachResponse(this);
		}
	}
}

void IArticleSub::Attach(IArticlePub* publisher) {
	numOfPub++;

	// index == pubID - 1
	int pid = publisher->getPubID();
	string pname = publisher->getPubName();
	pub_list[pid - 1] = publisher;
	publisher->NotifyAttachResponse(this);
	cout << "[Attach] Sub (" << this->sub_name << "," << this->sub_id << ") is attached to Pub (" << pname << "," << pid << ")" << endl;
}

void IArticleSub::AttachResponse(IArticlePub* publisher) {
	numOfPub++;

	// index == pubID - 1
	string pname = publisher->getPubName();
	int pid = publisher->getPubID();
	pub_list[pid - 1] = publisher;
	cout << "[Attach] Sub (" << this->sub_name << "," << this->sub_id << ") is attached to Pub (" << pname << "," << pid << ")" << endl;
}

void IArticleSub::Detach(IArticlePub* p_pub) {
	// Check whether the list is empty
	if (numOfPub != 0) { numOfPub--; }
	else {
		cout << "KeyError: The pub list is empty." << endl;
		return;
	}
	// Find and delete
	string pname = p_pub->getPubName();
	int pid = p_pub->getPubID();
	//IArticlePub* find = pub_list[pid - 1];
	if (pub_list[pid - 1] == p_pub) { pub_list[pid - 1] = nullptr; }
	else {
		cout << "KeyError: There is no such publisher." << endl;
		return;
	}
	cout << "[Sub] (" << this->sub_name << "," << this->sub_id << ") unsubscribes [Pub] (" << pname << "," << pid << ")" << endl;
	p_pub->NotifyDetachResponse(this);
}

void IArticleSub::DetachResponse(IArticlePub* p_pub) {
	// Check whether the list is empty
	if (numOfPub != 0) { numOfPub--; }
	else {
		cout << "KeyError: The pub list is empty." << endl;
		return;
	}
	// Find and delete
	int pid = p_pub->getPubID();
	string pname = p_pub->getPubName();
	//IArticlePub* find = pub_list[pid - 1];
	if (pub_list[pid - 1] == p_pub) { pub_list[pid - 1] = nullptr; }
	else {
		cout << "KeyError: There is no such publisher." << endl;
		return;
	}
	cout << "[Sub] (" << this->sub_name << "," << this->sub_id << ") unsubscribes [Pub] (" << pname << "," << pid << ")" << endl;
}

void IArticleSub::Update(IArticlePub* publisher, const string contents) {
	recent_article_pub = publisher;
	recent_article_contents = contents;
	PrintContents();
}

void IArticleSub::PrintContents() { cout << "\"" << recent_article_contents << "\""; }

string IArticleSub::getSubName() { return sub_name; }

int IArticleSub::getSubID() { return sub_id; }

int IArticleSub::getPubSize() { return numOfPub; }

void IArticleSub::PrintAllPub() {
	for (IArticlePub* target : pub_list) {
		if (target != nullptr) {
			string pname = target->getPubName();
			int pid = target->getPubID();
			cout << "[" << pname << "," << pid << "]";
		}
	}
	cout << endl;
}