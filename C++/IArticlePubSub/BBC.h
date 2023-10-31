#pragma once
#include "IArticlePub.h"

class BBC : public IArticlePub {
public:
	BBC();
	BBC(const string con);
	void Event();
	~BBC();
};