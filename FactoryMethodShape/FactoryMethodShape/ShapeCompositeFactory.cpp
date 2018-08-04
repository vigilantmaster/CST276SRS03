#include "stdafx.h"
#include "ShapeCompositeFactory.h"


ShapeCompositeFactory::ShapeCompositeFactory()
= default;


ShapeCompositeFactory::~ShapeCompositeFactory()
= default;

ShapeComposite* ShapeCompositeFactory::doCreateShape() const
{
	auto* const result = new ShapeComposite();
	return result;
}
