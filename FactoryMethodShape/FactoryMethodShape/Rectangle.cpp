#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>


#include "json.hpp"   // json manipulation
#include "shapeFactoryManager.h"
#include "RectangleFactory.h"
using json = nlohmann::json;  // for ease of use
RectangleFactory recFac;
const bool Rectangle::registered = ShapeFactoryManager::getInstance().RegisterShape(id, recFac);

void Rectangle::setRectangle(int specialId_, int x1_, int x2_, int y1_, int y2_)
{
	specialId = specialId_;
	x1 = x1_;
	x2 = x2_;
	y1 = y1_;
	y2 = y2_;
}

void Rectangle::doDraw() const
{
	std::cout << "      Rectangle     " << std::endl << std::endl;;
	std::cout << "Point one: (" << x1 << "," << y1 << ")" << std::endl;
	std::cout << "Point two: (" << x2 << "," << y2 << ")" << std::endl;
}

void Rectangle::doSave() const
{
	std::ofstream outputStreamToFile("Shapes.json");
	json jsonObject;
	jsonObject["Rectangle"]["specialId"] = specialId;
	jsonObject["Rectangle"]["x1"] = x1;
	jsonObject["Rectangle"]["x2"] = x2;
	jsonObject["Rectangle"]["y1"] = y1;
	jsonObject["Rectangle"]["y2"] = y2;
}

void Rectangle::doLoad()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject["Rectangle"]["specialId"].get<int>();
	x1 = jsonObject["Rectangle"]["x1"].get<int>();
	x2 = jsonObject["Rectangle"]["x2"].get<int>();
	y1 = jsonObject["Rectangle"]["y1"].get<int>();
	y2 = jsonObject["Rectangle"]["y2"].get<int>();
}
