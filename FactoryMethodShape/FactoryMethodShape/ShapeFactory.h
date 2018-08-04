#pragma once

#include "Shape.h"

class ShapeFactory
{
public:
	ShapeFactory();
	virtual ~ShapeFactory();

public:
	Shape* CreateShape() const;

private:
	virtual Shape* doCreateShape() const = 0;
};

