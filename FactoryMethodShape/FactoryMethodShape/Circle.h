#pragma once

#include "Shape.h"

class circle : public Shape
{
private:
	static const UniqueID id = 456;

private:
	static const bool registered; // TODO: initialize

private:
	int radius;
	int xcenter;
	int ycenter;
		
public:
	circle();
	~circle();

private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;
};

