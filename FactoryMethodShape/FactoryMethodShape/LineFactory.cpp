#include "stdafx.h"
#include "LineFactory.h"


LineFactory::LineFactory()
= default;


LineFactory::~LineFactory()
= default;

Line * LineFactory::doCreateShape() const
{
	auto* const result = new Line();
	return result;
}
