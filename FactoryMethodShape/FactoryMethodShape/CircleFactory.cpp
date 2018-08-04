#include "stdafx.h"
#include "CircleFactory.h"


CircleFactory::CircleFactory()
= default;


CircleFactory::~CircleFactory()
= default;

Circle * CircleFactory::doCreateShape() const
{
	auto* const result = new Circle();
	return result;
}
