#include "stdafx.h"
#include <iostream>
#include "shapeFactoryManager.h"
#include "Shape.h"
#include "Drawing.h"

Drawing::Drawing()
= default;

Drawing::~Drawing()
= default;

void Drawing::Add(const Shape& shape)
{
	shapeContainer_.emplace_back(shape);
}

void Drawing::Save() const
{
	for (const Shape& shape : shapeContainer_)
	{
		shape.Save();
	}
}

void Drawing::Load()
{
	
	while (std::cin.good())
	{
		auto tmp = -1;
		//load the JSON file here
		std::cin >> tmp; //instead of cin we will take outer while loop out and iterate through the json objects in the file
		// get rid of IF statement and load shapes and factories from JSON
		if (!std::cin.eof())
		{

// ShapeFactoryManager is a Singleton:

			const ShapeFactoryManager& shapeFactoryManager = ShapeFactoryManager::getInstance();
			const auto shape = static_cast<Shape::UniqueID>(tmp);
			const auto shapeFactory = shapeFactoryManager.createFactory(shape);
			const auto shapePtr = shapeFactory->CreateShape();

			// TODO:
			 if (shapePtr != nullptr)
			 {
			 	Add(*shapePtr);
			 }
			 else
			 {
			 	std::cout << "Invalid shape." << std::endl;
			 }
		}
	}
}

void Drawing::Draw() const
{
	for (const Shape& shape : shapeContainer_)
	{
		shape.Draw();
	}
}
