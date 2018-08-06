#pragma once
#include "ShapeFactory.h"
class RectangleFactory :
	public ShapeFactory
{
public:
	RectangleFactory();
	~RectangleFactory();
private:
	Shape* doCreateShape() const override;
};

