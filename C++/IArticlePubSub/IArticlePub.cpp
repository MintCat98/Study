#include "IArticlePub.h"

int IArticlePub::static_pub_counter = 0;

IArticlePub::IArticlePub(const string name) : pub_name{ name } {
	IArticlePub::static_pub_counter++;
	pub_id = static_pub_counter;
	for (IArticleSub* elem : sub_list) {
		elem = nullptr;
	}
	cout << "[Constructor]New Pub Created: (" << this->pub_name << "," << this->pub_id << ")" << endl;
}

IArticlePub::IArticlePub(const string name, const string con) : pub_name{ name }, recent_contents{ con } {
	IArticlePub::static_pub_counter++;
	pub_id = static_pub_counter;
	for (IArticleSub* elem : sub_list) {
		elem = nullptr;
	}
	cout << "[Constructor]New Pub Created: (" << this->pub_name << "," << this->pub_id << ")" << endl;
}

IArticlePub::~IArticlePub() {
	cout << "IAtriclePub Destructor called" << endl;
	for (IArticleSub* target : sub_list) {
		if (target != nullptr) {
			target->DetachResponse(this);
		}
	}
}

void IArticlePub::NotifyAttach(IArticleSub* subscriber) {
	numOfSub++;

	// index == subID - 1
	int sid = subscriber->getSubID();
	string sname = subscriber->getSubName();
	sub_list[sid - 1] = subscriber;
	subscriber->AttachResponse(this);
	cout << "[Attach] Pub (" << this->pub_name << "," << this->pub_id << ") is attached to Sub (" << sname << "," << sid << ")" << endl;
}

void IArticlePub::NotifyAttachResponse(IArticleSub* subscriber) {
	numOfSub++;

	// index == subID - 1
	int sid = subscriber->getSubID();
	string sname = subscriber->getSubName();
	sub_list[sid - 1] = subscriber;
	cout << "[Attach] Pub (" << this->pub_name << "," << this->pub_id << ") is attached to Sub (" << sname << "," << sid << ")" << endl;
}

void IArticlePub::NotifyDetach(IArticleSub* subscriber) {
	// Check whether the list is empty
	if (numOfSub != 0) { numOfSub--; }
	else {
		cout << "KeyError: The sub list is empty." << endl;
		return;
	}
	// Find and delete
	int sid = subscriber->getSubID();
	string sname = subscriber->getSubName();
	IArticleSub* find = sub_list[sid - 1];
	if (find == subscriber) { find = nullptr; }
	else {
		cout << "KeyError: There is no such subscriber." << endl;
		return;
	}
	subscriber->DetachResponse(this);
	cout << "[Pub] (" << this->pub_name << "," << this->pub_id << ") detach [Sub] (" << sname << "," << sid << ")" << endl;
}

void IArticlePub::NotifyDetachResponse(IArticleSub* subscriber) {
	// Check whether the list is empty
	if (numOfSub != 0) { numOfSub--; }
	else {
		cout << "KeyError: The sub list is empty." << endl;
		return;
	}
	// Find and delete
	int sid = subscriber->getSubID();
	string sname = subscriber->getSubName();
	IArticleSub* find = sub_list[sid - 1];
	if (find == subscriber) { find = nullptr; }
	else {
		cout << "KeyError: There is no such subscriber." << endl;
		return;
	}
	cout << "[Pub] (" << this->pub_name << "," << this->pub_id << ") detach [Sub] (" << sname << "," << sid << ")" << endl;
}

void IArticlePub::updatePubContents(string c) {
	// Update the value
	recent_contents = c;
	// Notice the new content to subs
	Notify();
}

void IArticlePub::Notify() {
	for (IArticleSub* sub : sub_list) {
		if (sub != nullptr) {
			string sname = sub->getSubName();
			int sid = sub->getSubID();
			cout << "Sub (" << sname << "," << sid << ")'s latest subscribed news is ";
			sub->Update(this, recent_contents);
			cout << " by " << pub_name << endl;
		}
	}
}

int IArticlePub::getPubID() { return pub_id; }

string IArticlePub::getPubName() { return pub_name; }

string IArticlePub::getRecentContents() { return recent_contents; }

int IArticlePub::getSubSize() { return numOfSub; }

void IArticlePub::PrintAllSub() {
	for (IArticleSub* target : sub_list) {
		if (target != nullptr) {
			string sname = target->getSubName();
			int sid = target->getSubID();
			cout << "[" << sname << "," << sid << "]";
		}
	}
}