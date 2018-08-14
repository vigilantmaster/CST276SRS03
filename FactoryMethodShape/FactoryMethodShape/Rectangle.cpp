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
	const std::string stringid{ std::to_string(id) };
	std::ofstream outputStreamToFile("Shapes.json");
	json jsonObject;
	jsonObject[stringid]["id"] = id;
	jsonObject[stringid]["specialId"] = specialId;
	jsonObject[stringid]["x1"] = x1;
	jsonObject[stringid]["x2"] = x2;
	jsonObject[stringid]["y1"] = y1;
	jsonObject[stringid]["y2"] = y2;
	jsonObject >> outputStreamToFile;
}

void Rectangle::doLoad()
{
	const std::string stringid{ std::to_string(id) };
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject[id]["specialId"].get<int>();
	x1 = jsonObject[stringid]["x1"].get<int>();
	x2 = jsonObject[stringid]["x2"].get<int>();
	y1 = jsonObject[stringid]["y1"].get<int>();
	y2 = jsonObject[stringid]["y2"].get<int>();
}

void Rectangle::doLoad(int specialId)
{

	// not implemented
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject[id]["specialId"].get<int>();
	x1 = jsonObject[id]["x1"].get<int>();
	x2 = jsonObject[id]["x2"].get<int>();
	y1 = jsonObject[id]["y1"].get<int>();
	y2 = jsonObject[id]["y2"].get<int>();

}

Shape* Rectangle::toShape(json* rhs)
{
	const std::string stringid{ std::to_string(id) };
	specialId = (*rhs)[id]["specialId"].get<int>();
	x1 = (*rhs)[stringid]["x1"].get<int>();
	x2 = (*rhs)[stringid]["x2"].get<int>();
	y1 = (*rhs)[stringid]["y1"].get<int>();
	y2 = (*rhs)[stringid]["y2"].get<int>();
	return this;
}

void Rectangle::doLoad(json object)
{
	*this->toShape(&object);
}

json Rectangle::to_json()
{
	json jsonObject;
	const std::string stringid{ std::to_string(id) };
	jsonObject[stringid]["specialId"] = specialId;
	jsonObject[stringid]["x1"] = x1;
	jsonObject[stringid]["x2"] = x2;
	jsonObject[stringid]["y1"] = y1;
	jsonObject[stringid]["y2"] = y2;
	return jsonObject;
}
