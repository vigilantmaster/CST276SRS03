#include "stdafx.h"

#include "ShapeFactory.h"

ShapeFactory::ShapeFactory()
= default;

ShapeFactory::~ShapeFactory()
= default;

Shape * ShapeFactory::CreateShape() const
{
	Shape* const result = doCreateShape();
	return result;
}

Shape * ShapeFactory::doCreateShape() const
{
	return nullptr;
}