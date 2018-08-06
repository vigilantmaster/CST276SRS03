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

circle::circle()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject["Circle"]["specialId"].get<int>();
	radius = jsonObject["Circle"]["radius"].get<int>();
	xcenter = jsonObject["Circle"]["xcenter"].get<int>();
	ycenter = jsonObject["Circle"]["ycenter"].get<int>();
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
	toFile["Circle"]["specialId"] =  specialId ;
	toFile["Circle"]["radius"] = radius ;
	toFile["Circle"]["xcenter"] = xcenter;
	toFile["Circle"]["ycenter"] = ycenter;
	toFile >> outpustStreamToFile;
	outpustStreamToFile.close();
}

void circle::doLoad()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	specialId = jsonObject["Circle"]["specialId"].get<int>();
	radius = jsonObject["Circle"]["radius"].get<int>();
	xcenter = jsonObject["Circle"]["xcenter"].get<int>();
	ycenter = jsonObject["Circle"]["ycenter"].get<int>();
	inputStreamFromFile.close();
}


