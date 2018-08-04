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

void Shape::Save() const
{
	doSave();
}

void Shape::Load()
{
	doLoad();
}
