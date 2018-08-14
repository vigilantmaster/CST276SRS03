#include "stdafx.h"
#include <iostream>
#include "Circle.h"
#include "shapeFactoryManager.h"
#include "CircleFactory.h"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
circle_factory test;
const bool circle::registered = ShapeFactoryManager::getInstance().RegisterShape(id, test);

// Notes:
// You will need to register all shapes, not just Circle. 
// I have not tested the above technique, you may run into trouble.

circle::circle(): id_(0), radius(0), xcenter(0), ycenter(0)
{
}

circle::~circle()
= default;

void circle::setCircle(int specialId_, int radius_, int xcenter_, int ycenter_)
{
	specialId = specialId_;
	radius = radius_;
	xcenter = xcenter_;
	ycenter = ycenter_;
}

std::string circle::toString()
{
	return std::string();
}

void circle::doDraw() const
{
	std::cout << "    Circle   " << std::endl << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Center: (" << xcenter << "," << ycenter << ")\n" << std::endl;
}

void circle::doSave() const
{
	std::ofstream outpustStreamToFile("Shapes.Json");
	json toFile;
	const std::string stringid{ std::to_string(id) };
	toFile[stringid]["id"] = id;
	toFile[stringid]["specialId"] =  specialId ;
	toFile[stringid]["radius"] = radius ;
	toFile[stringid]["xcenter"] = xcenter;
	toFile[stringid]["ycenter"] = ycenter;
	toFile >> outpustStreamToFile;
	outpustStreamToFile.close();
}

void circle::doLoad()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	const std::string stringid{ std::to_string(id) };
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject[stringid]["specialId"].get<int>();
	radius = jsonObject[stringid]["radius"].get<int>();
	xcenter = jsonObject[stringid]["xcenter"].get<int>();
	ycenter = jsonObject[stringid]["ycenter"].get<int>();
	inputStreamFromFile.close();
}

void circle::doLoad(json object)
{
	*this->toShape(&object);
}

Shape* circle::toShape(json* rhs)
{
	const std::string stringid{ std::to_string(id) };
	specialId = (*rhs)[stringid]["specialId"].get<int>();
	radius = (*rhs)[stringid]["radius"].get<int>();
	xcenter = (*rhs)[stringid]["xcenter"].get<int>();
	ycenter = (*rhs)[stringid]["ycenter"].get<int>();
	return this;
}


json circle::to_json()
{
	const std::string stringid{ std::to_string(id) };
	json toFile;
	toFile[stringid]["specialId"] = specialId;
	toFile[stringid]["radius"] = radius;
	toFile[stringid]["xcenter"] = xcenter;
	toFile[stringid]["ycenter"] = ycenter;
	return toFile;
}


