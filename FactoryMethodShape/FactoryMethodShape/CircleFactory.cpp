#include "stdafx.h"
#include "CircleFactory.h"


circle_factory::circle_factory()
= default;


circle_factory::~circle_factory()
= default;

Circle * circle_factory::doCreateShape() const
{
	auto* const result = new Circle();
	return result;
}
