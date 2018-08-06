#pragma once

#include "Shape.h"

class circle : public Shape
{
private:
	static const UniqueID id = 456;

private:
	static const bool registered; 

private:
	int id_;
	int radius;
	int xcenter;
	int ycenter;
	int specialId{};
		
public:
	circle();
	~circle();
	void setCircle(int specialId_, int radius_, int xcenter_, int ycenter_);

private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;
};

