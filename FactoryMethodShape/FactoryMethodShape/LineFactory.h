#pragma once

#include "ShapeFactory.h"
#include "Line.h"

class LineFactory: public ShapeFactory
{
public:
	LineFactory();
	~LineFactory();

private:
	Line* doCreateShape() const override;
};

