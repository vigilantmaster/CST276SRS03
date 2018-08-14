#include "stdafx.h"
#include <iostream>
#include "Polygon.h"
#include "shapeFactoryManager.h"
#include "PolygonFactory.h"

#include "json.hpp"   // json manipulation
using json = nlohmann::json;  // for ease of use
polygon_factory polygonfactory;
const bool polygon::registered = ShapeFactoryManager::getInstance().RegisterShape(id, polygonfactory);
polygon::polygon()
= default;

polygon::~polygon()
= default;

void polygon::setPolygon(int specialId_, int xstart_, int x1_, int x2_, int ystart_, int y1_, int y2_)
{
	specialId = specialId_;
	xstart = xstart_;
	x1 = x1_;
	x2 = x2_;
	ystart = ystart_;
	y1 = y1_;
	y2 = y2_;
}

void polygon::doDraw() const
{
	std::cout << "      POLYGON     " << std::endl << std::endl;;
	std::cout << "Start Point: (" << xstart << ","  << ystart << ")" << std::endl;
	std::cout << "Point Two: (" << x1 << "," << y1 << ")" << std::endl;
	std::cout << "Point Three: (" << x2 << "," << y2 << ")" << std::endl;
	std::cout << "End Point: (" << xstart << "," << ystart << ")\n" << std::endl;
}
void polygon::doSave() const
{
	const std::string stringid{ std::to_string(id) };
	std::ofstream outputStreamToFile("Shapes.json");
	json jsonObject;
	jsonObject[stringid]["id"] = id;
	jsonObject[stringid]["specialId"] = specialId;
	jsonObject[stringid]["xstart"] = xstart;
	jsonObject[stringid]["x1"] = x1;
	jsonObject[stringid]["x2"] = x2;
	jsonObject[stringid]["ystart"] = ystart;
	jsonObject[stringid]["y1"] = y1;
	jsonObject[stringid]["y2"] = y2;
	jsonObject >> outputStreamToFile;
}
void polygon::doLoad()
{
	const std::string stringid{ std::to_string(id) };
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject[stringid]["specialId"].get<int>();
	xstart = jsonObject[stringid]["xstart"].get<int>();
	x1 = jsonObject[stringid]["x1"].get<int>();
	x2 = jsonObject[stringid]["x2"].get<int>();
	ystart = jsonObject[stringid]["ystart"].get<int>();
	y1 = jsonObject[stringid]["y1"].get<int>();
	y2 = jsonObject[stringid]["y2"].get<int>();
}

Shape* polygon::toShape(json* rhs)
{
	const std::string stringid{ std::to_string(id) };
	specialId = (*rhs)[stringid]["specialId"].get<int>();
	xstart = (*rhs)[stringid]["xstart"].get<int>();
	x1 = (*rhs)[stringid]["x1"].get<int>();
	x2 = (*rhs)[stringid]["x2"].get<int>();
	ystart = (*rhs)[stringid]["ystart"].get<int>();
	y1 = (*rhs)[stringid]["y1"].get<int>();
	y2 = (*rhs)[stringid]["y2"].get<int>();
	return this;
}

void polygon::doLoad(json object)
{
	*this->toShape(&object);
}

json polygon::to_json()
{
	const std::string stringid{ std::to_string(id) };
	json jsonObject;
	jsonObject[stringid]["specialId"] = specialId;
	jsonObject[stringid]["xstart"] = xstart;
	jsonObject[stringid]["x1"] = x1;
	jsonObject[stringid]["x2"] = x2;
	jsonObject[stringid]["ystart"] = ystart;
	jsonObject[stringid]["y1"] = y1;
	jsonObject[stringid]["y2"] = y2;
	return jsonObject;
}
