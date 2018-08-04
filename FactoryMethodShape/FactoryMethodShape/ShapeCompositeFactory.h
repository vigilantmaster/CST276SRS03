#pragma once

#include "ShapeFactory.h"
#include "ShapeComposite.h"

class ShapeCompositeFactory: public ShapeFactory
{
public:
	ShapeCompositeFactory();
	~ShapeCompositeFactory();
private:
	ShapeComposite* doCreateShape() const override;
};

