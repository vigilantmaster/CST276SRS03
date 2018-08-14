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
	const std::string stringid{ std::to_string(id) };
	std::ofstream outputStreamToFile("Shapes.json");	
	json jsonObject;
	jsonObject[stringid]["id"] = id;
	jsonObject[stringid]["specialId"] = specialId;
	jsonObject[stringid]["xstart"] = xstart;
	jsonObject[stringid]["xend"] = xend;
	jsonObject[stringid]["ystart"] = ystart;
	jsonObject[stringid]["yend"] = yend;
	jsonObject >> outputStreamToFile;
}

void Line::doLoad()
{
	const std::string stringid{ std::to_string(id) };
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject[stringid]["specialId"].get<int>();
	xstart = jsonObject[stringid]["xstart"].get<int>();
	xend = jsonObject[stringid]["xend"].get<int>();
	ystart = jsonObject[stringid]["ystart"].get<int>();
	yend = jsonObject[stringid]["yend"].get<int>();
}

Shape* Line::toShape(json* rhs)
{
	const std::string stringid{ std::to_string(id) };
	specialId = (*rhs)[stringid]["specialId"].get<int>();
	xstart = (*rhs)[stringid]["xstart"].get<int>();
	xend = (*rhs)[stringid]["xend"].get<int>();
	ystart = (*rhs)[stringid]["ystart"].get<int>();
	yend = (*rhs)[stringid]["yend"].get<int>();
	return this;
}

void Line::doLoad(json object)
{
	*this->toShape(&object);
}


json Line::to_json()
{
	const std::string stringid{ std::to_string(id) };
	json jsonObject;
	jsonObject[stringid]["specialId"] = specialId;
	jsonObject[stringid]["xstart"] = xstart;
	jsonObject[stringid]["xend"] = xend;
	jsonObject[stringid]["ystart"] = ystart;
	jsonObject[stringid]["yend"] = yend;
	return jsonObject;
}
