#pragma once

#include "Shape.h"

class Circle : public Shape
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
	Circle();
	~Circle();

private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;
};

