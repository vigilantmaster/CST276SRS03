#include "stdafx.h"
#include "PolygonFactory.h"


PolygonFactory::PolygonFactory()
= default;

PolygonFactory::~PolygonFactory()
= default;

Polygon* PolygonFactory::doCreateShape() const
{
	auto* const result = new Polygon();
	return result;
}
