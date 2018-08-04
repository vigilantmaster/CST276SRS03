#include "stdafx.h"
#include <iostream>
#include "Polygon.h"
#include "shapeFactoryManager.h"
#include "PolygonFactory.h"

#include "json.hpp"   // json manipulation
using json = nlohmann::json;  // for ease of use
PolygonFactory polygonfactory;
const bool Polygon::registered = ShapeFactoryManager::getInstance().RegisterShape(id, polygonfactory);
Polygon::Polygon()
= default;

Polygon::~Polygon()
= default;

void Polygon::doDraw() const
{
	std::cout << "      POLYGON     " << std::endl << std::endl;;
	std::cout << "Start Point: (" << xstart << ","  << ystart << ")" << std::endl;
	std::cout << "Point Two: (" << x1 << "," << y1 << ")" << std::endl;
	std::cout << "Point Three: (" << x2 << "," << y2 << ")" << std::endl;
	std::cout << "End Point: (" << xstart << "," << ystart << ")\n" << std::endl;
}
void Polygon::doSave() const
{
	std::ofstream outputStreamToFile("Shapes.json");
	json jsonObject;
	jsonObject["polygon"]["xstart"] = xstart;
	jsonObject["polygon"]["x1"] = x1;
	jsonObject["polygon"]["x2"] = x2;
	jsonObject["polygon"]["ystart"] = ystart;
	jsonObject["polygon"]["y1"] = y1;
	jsonObject["polygon"]["y2"] = y2;
}
void Polygon::doLoad()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	xstart = jsonObject["polygon"]["xstart"].get<int>();
	x1 = jsonObject["polygon"]["x1"].get<int>();
	x2 = jsonObject["polygon"]["x2"].get<int>();
	ystart = jsonObject["polygon"]["ystart"].get<int>();
	y1 = jsonObject["polygon"]["y1"].get<int>();
	y2 = jsonObject["polygon"]["y2"].get<int>();
}
