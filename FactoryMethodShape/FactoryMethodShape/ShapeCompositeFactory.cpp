#include "stdafx.h"
#include "ShapeCompositeFactory.h"


ShapeCompositeFactory::ShapeCompositeFactory()
= default;


ShapeCompositeFactory::~ShapeCompositeFactory()
= default;

shape_composite* ShapeCompositeFactory::doCreateShape() const
{
	auto* const result = new shape_composite();
	return result;
}
