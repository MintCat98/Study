#include <iostream>

using namespace std;

class IArticlePub {
private:
	string pub_name;
	int pub_id;
	string recent_contents;
	IArticleSub* sub_list[5];
	int numOfSub = 0;
	static int static_pub_counter;

public:
	IArticlePub(const string name);
	IArticlePub(const string name, const string con);
	~IArticlePub();
	void NotifyAttach(IArticleSub* subscriber);
	void NotifyAttachResponse(IArticleSub* subscriber);
	void NotifyDetach(IArticleSub* subscriber);
	void NotifyDetachResponse(IArticleSub* subscriber);
	void updatePubContents(string c);
	void Notify();
	int getPubID();
	string getPubName();
	string getRecentContents();
	int getSubSize();
	void PrintAllSub();
};



class IArticleSub {
private:
	string sub_name;
	int sub_id;
	string recent_article_contents;
	IArticlePub* recent_article_pub;
	IArticlePub* pub_list[5];
	int numOfPub = 0;
	static int static_sub_counter;

public:
	IArticleSub(string name);
	IArticleSub(string name, IArticlePub* articlePub);
	~IArticleSub();
	void Attach(IArticlePub* publisher);
	void AttachResponse(IArticlePub* publisher);
	void Detach(IArticlePub* p_pub);
	void DetachResponse(IArticlePub* p_pub);
	void Update(IArticlePub* publisher, const string contents);
	void PrintContents();
	string getSubName();
	int getSubID();
	int getPubSize();
	void PrintAllPub();
};



IArticlePub::IArticlePub(const string name) : pub_name{ name } {
	IArticlePub::static_pub_counter++;
	pub_id = static_pub_counter;
	for (int i = 0; i < 5; i++) {
		sub_list[i] = nullptr;
	}
	cout << "[Constructor]New Pub Created: (" << this->pub_name << "," << this->pub_id << ")" << endl;
}

IArticlePub::IArticlePub(const string name, const string con) : pub_name{name}, recent_contents{con} {
	IArticlePub::static_pub_counter++;
	pub_id = static_pub_counter;
	for (int i = 0; i < 5; i++) {
		sub_list[i] = nullptr;
	}
	cout << "[Constructor]New Pub Created: (" << this->pub_name << "," << this->pub_id << ")" << endl;
}

IArticlePub::~IArticlePub() {
	// implement
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

}

void IArticlePub::NotifyDetachResponse(IArticleSub* subscriber) {

}

void IArticlePub::updatePubContents(string c) {
	// Update the value
	recent_contents = c;
	// Notice the new content to subs by using Notify()
	Notify();
}

void IArticlePub::Notify() {
	for (int i = 0; i < numOfSub; i++) {
		string sname = (*sub_list)->getSubName();
		int sid = (*sub_list)->getSubID();
		cout << "Sub (" << sname << "," << sid << ")'s latest subscribed news is ";
		cout << " by " << pub_id << endl;
	}
}

int IArticlePub::getPubID() { return pub_id; }

string IArticlePub::getPubName() { return pub_name; }

string IArticlePub::getRecentContents() { return recent_contents; }

int IArticlePub::getSubSize() { return numOfSub; }

void IArticlePub::PrintAllSub() {
	for (int i = 0; i < 5; i++) {
		if (sub_list[i] != nullptr) {
			string sname = sub_list[i]->getSubName();
			int sid = sub_list[i]->getSubID();
			cout << "[" << sname << "," << sid << "]";
		}
	}
}



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
	// implement
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
	int pid = publisher->getPubID();
	string pname = publisher->getPubName();
	pub_list[pid - 1] = publisher;
	cout << "[Attach] Sub (" << this->sub_name << "," << this->sub_id << ") is attached to Pub (" << pname << "," << pid << ")" << endl;
}

void IArticleSub::Detach(IArticlePub* p_pub) {
	if (numOfPub != 0) { numOfPub--; }

	// No such pub
	if (find(0, 4, p_pub) == 0) {
		cout << "KeyError: There is no such publisher." << endl;
	}

	// Delete

}

void IArticleSub::DetachResponse(IArticlePub* p_pub) {
	// Implement
}

void IArticleSub::Update(IArticlePub* publisher, const string contents) {
	recent_article_pub = publisher;
	recent_article_contents = contents;
	PrintContents();
}

void IArticleSub::PrintContents() {
	cout << "\"" << recent_article_contents << "\"";
}

string IArticleSub::getSubName() { return sub_name; }

int IArticleSub::getSubID() { return sub_id; }

int IArticleSub::getPubSize() { return numOfPub; }

void IArticleSub::PrintAllPub() {
	for (int i = 0; i < 5; i++) {
		if (pub_list[i] != nullptr) {
			string pname = pub_list[i]->getPubName();
			int pid = pub_list[i]->getPubID();
			cout << "[" << pname << "," << pid << "]";
		}
	}
}



int main() {
	IArticlePub* dgistPub = new IArticlePub("DGIST");
	IArticlePub* bbcPub = new IArticlePub("BBC");
	IArticlePub* cnnPub = new IArticlePub("CNN");
	cout << endl;

	//Jenny subscribe DGIST, BBC
	IArticleSub* jennySub = new IArticleSub("Jenny", dgistPub);
	bbcPub->NotifyAttach(jennySub);
	cout << endl;

	//Tom subscribe BBC, CNN
	IArticleSub* tomSub = new IArticleSub("Tom");
	bbcPub->NotifyAttach(tomSub);
	cnnPub->NotifyAttach(tomSub);
	cout << endl;

	//Kate subscribe DGIST, BBC, CNN
	IArticleSub* kateSub = new IArticleSub("Kate", dgistPub);
	bbcPub->NotifyAttach(kateSub);
	kateSub->Attach(cnnPub);
	cout << endl;


	cout << "All Sub of (" << dgistPub->getPubName() << "," << dgistPub->getPubID() << "): ";
	dgistPub->PrintAllSub();
	cout << "All Sub of (" << bbcPub->getPubName() << "," << bbcPub->getPubID() << "): ";
	bbcPub->PrintAllSub();
	cout << "All Sub of (" << cnnPub->getPubName() << "," << cnnPub->getPubID() << "): ";
	cnnPub->PrintAllSub();
	cout << endl;
	kateSub->Detach(bbcPub);
	cout << endl;

	cout << "All Pub of (" << jennySub->getSubName() << "," << jennySub->getSubID() << "): ";
	jennySub->PrintAllPub();
	cout << "All Pub of (" << tomSub->getSubName() << "," << tomSub->getSubID() << "): ";
	tomSub->PrintAllPub();
	cout << "All Pub of (" << kateSub->getSubName() << "," << kateSub->getSubID() << "): ";
	kateSub->PrintAllPub();
	cout << endl;


	cout << "=========DGIST Notify ===========" << endl;
	dgistPub->updatePubContents("Welcome New DGIST Students");
	cout << endl;

	cout << "=========BBC Notify ===========" << endl;
	bbcPub->updatePubContents("Mr. Son scored at Tottenham");
	cout << endl;

	cout << "=========CNN Notify ===========" << endl;
	cnnPub->updatePubContents("New York city celebrates Chirstmas");
	cout << endl;

	cout << "=========DELETING [tomSub]===========" << endl;
	delete tomSub;
	cout << endl;

	cout << "=========DGIST Notify ===========" << endl;
	dgistPub->updatePubContents("Welcome New DGIST students");
	cout << endl;

	cout << "=========BBC Notify ===========" << endl;
	bbcPub->updatePubContents("Mr. Son scored at Tottenham");
	cout << endl;

	cout << "=========CNN Notify ===========" << endl;
	cnnPub->updatePubContents("New York city celebrates Christmas");
	cout << endl;

	cout << "=========Delete all others ===========" << endl;
	delete dgistPub;
	delete bbcPub;
	delete cnnPub;
	delete jennySub;
	delete kateSub;

	return 0;
}