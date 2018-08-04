#include "stdafx.h"
#include <iostream>
#include "Circle.h"
#include "ShapeFactoryManager.h"
#include "CircleFactory.h"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
circle_factory test;
const bool Circle::registered = ShapeFactoryManager::getInstance().RegisterShape(id, test);

// TODO: Notes:
// You will need to register all shapes, not just Circle. 
// I have not tested the above technique, you may run into trouble.

Circle::Circle()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	radius = jsonObject["circle"]["radius"].get<int>();
	xcenter = jsonObject["circle"]["xcenter"].get<int>();
	ycenter = jsonObject["circle"]["ycenter"].get<int>();
}

Circle::~Circle()
= default;

void Circle::doDraw() const
{
	std::cout << "    Circle   " << std::endl << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Center: (" << xcenter << "," << ycenter << ")\n" << std::endl;
}

void Circle::doSave() const
{
	std::cout << id << std::endl; // TODO: and circle data
}

void Circle::doLoad()
{
	// std::cin >> data; // TODO: Load the circle data from json file
}


