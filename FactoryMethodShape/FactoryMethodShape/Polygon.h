#pragma once
#include "Shape.h"

class polygon : public Shape
{
private:
	static const UniqueID id = 789;

private:
	static const bool registered; // TODO: initialize

private:
	int xstart{}, x1{}, x2{}, ystart{}, y1{}, y2{};

public:
	polygon();
	~polygon();

private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;

};
