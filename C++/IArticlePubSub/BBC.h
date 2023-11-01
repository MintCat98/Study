#pragma once
#include "IArticlePub.h"

class BBC : public IArticlePub {
public:
	BBC();
	BBC(const string con);
	void Advertisement();
	void Event();
	~BBC();
};