#pragma once
#include <iostream>
#include <string>
#include "IArticleSub.h"

class IArticleSub;
using namespace std;

class IArticlePub {
private:
	string pub_name;
	int pub_id;
	string recent_contents;
	static int static_pub_counter;

protected:
	IArticleSub* sub_list[5];
	int numOfSub = 0;

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
	virtual void Event() = 0;
};