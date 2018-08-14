#pragma once

#include "Shape.h"

class Line : public Shape
{
private:
	static const UniqueID id = 123;

private:
	int xstart{};
	int xend{};
	int ystart{};
	int yend{};
	int specialId{};

private:
	static const bool registered; 

public:
	Line();
	~Line();

public:
	void setLine(int specialId_, int xstart_, int xend_, int ystart_, int yend_);
	json to_json() override;

private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;

	Shape* toShape(json* rhs) override;
	void doLoad(json object) override;
};

