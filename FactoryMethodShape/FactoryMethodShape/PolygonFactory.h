#pragma once

#include "ShapeFactory.h"
#include "Polygon.h"

class PolygonFactory: public ShapeFactory
{
public:
	PolygonFactory();
	~PolygonFactory();

private:
	Polygon* doCreateShape() const override;
};

