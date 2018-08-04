#pragma once

#include "ShapeFactory.h"
#include "Circle.h"

class circle_factory: public ShapeFactory
{
public:
	circle_factory();
	~circle_factory();

private:
	circle* doCreateShape() const override;
};

