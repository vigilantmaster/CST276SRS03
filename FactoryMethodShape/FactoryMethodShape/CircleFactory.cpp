#include "stdafx.h"
#include "CircleFactory.h"


circle_factory::circle_factory()
= default;


circle_factory::~circle_factory()
= default;

circle * circle_factory::doCreateShape() const
{
	auto* const result = new circle();
	return result;
}
