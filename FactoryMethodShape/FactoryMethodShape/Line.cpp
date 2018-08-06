#include "stdafx.h"
#include <iostream>
#include "Line.h"
#include "shapeFactoryManager.h"
#include "LineFactory.h"
LineFactory linefactory;
const bool Line::registered = ShapeFactoryManager::getInstance().RegisterShape(id, linefactory);

Line::Line()
= default;

Line::~Line()
= default;

void Line::setLine(int specialId_, int xstart_, int xend_, int ystart_, int yend_)
{
	specialId = specialId_;
	xstart = xstart_;
	xend = xend_;
	ystart = ystart_;
	yend = yend_;
}

void Line::doDraw() const
{
	std::cout << "    Line  " << std::endl;
	std::cout << "\nLine Start: (" << xstart << "," << ystart << ")" << std::endl;
	std::cout << "Line End: (" << xend << ", " << yend << ")]\n" << std::endl;
}

void Line::doSave() const
{
	std::ofstream outputStreamToFile("Shapes.json");	
	json jsonObject;
	jsonObject["line"]["specialId"] = specialId;
	jsonObject["line"]["xstart"] = xstart;
	jsonObject["line"]["xend"] = xend;
	jsonObject["line"]["ystart"] = ystart;
	jsonObject["line"]["yend"] = yend;
}

void Line::doLoad()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject["line"]["specialId"].get<int>();
	xstart = jsonObject["line"]["xstart"].get<int>();
	xend = jsonObject["line"]["xend"].get<int>();
	ystart = jsonObject["line"]["ystart"].get<int>();
	yend = jsonObject["line"]["yend"].get<int>();
}
