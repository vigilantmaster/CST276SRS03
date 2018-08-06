#include "stdafx.h"
#include "RectangleFactory.h"
#include "Rectangle.h"


RectangleFactory::RectangleFactory()
= default;


RectangleFactory::~RectangleFactory()
= default;

Shape* RectangleFactory::doCreateShape() const
{
	auto* const result = new Rectangle();
	return result;
}
