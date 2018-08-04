#pragma once

#include "ShapeFactory.h"
#include "Polygon.h"

class polygon_factory: public ShapeFactory
{
public:
	polygon_factory();
	~polygon_factory();

private:
	polygon* doCreateShape() const override;
};

