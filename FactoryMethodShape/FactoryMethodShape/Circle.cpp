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

// TODO: Notes:
// You will need to register all shapes, not just Circle. 
// I have not tested the above technique, you may run into trouble.

circle::circle()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	radius = jsonObject["circle"]["radius"].get<int>();
	xcenter = jsonObject["circle"]["xcenter"].get<int>();
	ycenter = jsonObject["circle"]["ycenter"].get<int>();
}

circle::~circle()
= default;

void circle::doDraw() const
{
	std::cout << "    Circle   " << std::endl << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Center: (" << xcenter << "," << ycenter << ")\n" << std::endl;
}

void circle::doSave() const
{
	std::cout << id << std::endl; // TODO: and circle data
}

void circle::doLoad()
{
	// std::cin >> data; // TODO: Load the circle data from json file
}


