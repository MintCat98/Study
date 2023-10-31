#pragma once
#include "IArticlePub.h"

class dgist_press : public IArticlePub {
public:
	dgist_press();
	dgist_press(const string con);
	void Event();
	void CheerUp();
	~dgist_press();
};