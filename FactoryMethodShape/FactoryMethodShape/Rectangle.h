#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
private:
	static const UniqueID id = 90209348;

private:
	static const bool registered;
public:
	void setRectangle(int specialId_, int x1_, int x2_, int y1_, int y2_);
private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;
};

