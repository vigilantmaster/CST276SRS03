#pragma once
#include "component.h"
class leaf :
	public component
{
public:
	//TODO: special member functions
	void operation() override;

	leaf();
	~leaf();
};

