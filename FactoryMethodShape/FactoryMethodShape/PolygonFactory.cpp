#include "stdafx.h"
#include "PolygonFactory.h"


polygon_factory::polygon_factory()
= default;

polygon_factory::~polygon_factory()
= default;

polygon* polygon_factory::doCreateShape() const
{
	auto* const result = new polygon();
	return result;
}
