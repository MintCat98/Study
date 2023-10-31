#pragma once
#include "IArticlePub.h"

class CNN : public IArticlePub {
public:
	CNN();
	CNN(const string con);
	void Event();
	~CNN();
};