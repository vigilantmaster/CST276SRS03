#pragma once

#include "ShapeFactory.h"
#include "Circle.h"

class CircleFactory: public ShapeFactory
{
public:
	CircleFactory();
	~CircleFactory();

private:
	Circle* doCreateShape() const override;
};

