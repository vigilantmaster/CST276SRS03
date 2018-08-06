#pragma once
#include "Shape.h"

class polygon : public Shape
{
private:
	static const UniqueID id = 789;

private:
	static const bool registered; 



public:
	polygon();
	~polygon();
	void setPolygon(int specialId_, int xstart_, int x1_, int x2_, int ystart_, int y1_, int y2_);

private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;

};
