#pragma once

#include "ShapeFactory.h"
#include "ShapeComposite.h"

class ShapeCompositeFactory: public ShapeFactory
{
public:
	ShapeCompositeFactory();
	~ShapeCompositeFactory();
private:
	shape_composite* doCreateShape() const override;
};

