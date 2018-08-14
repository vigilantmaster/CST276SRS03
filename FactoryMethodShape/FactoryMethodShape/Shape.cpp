#include "stdafx.h"
#include <iostream>
#include "Shape.h"


Shape::Shape()
= default;


Shape::~Shape()
= default;

void Shape::Draw() const
{
	doDraw();
}

json Shape::toJson()
{
	return to_json();
}


Shape* Shape::operator<<(json * rhs)
{
	return toShape(rhs);
}


json Shape::operator<<(const Shape & rhs)
{
	return toJson();
}

void Shape::Save() const
{
	doSave();
}

void Shape::Load()
{
	doLoad();
}

void Shape::Load(json object)
{
	doLoad(object);
}
