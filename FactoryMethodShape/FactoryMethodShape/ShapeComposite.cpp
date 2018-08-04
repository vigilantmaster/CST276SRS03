#include "stdafx.h"
#include "ShapeComposite.h"
#include <iostream>
#include "json.hpp"
#include "shapeFactoryManager.h"
#include "ShapeCompositeFactory.h"

using json = nlohmann::json;  // for ease of use with json

ShapeCompositeFactory shapecompfact;
const bool ShapeComposite::registered = ShapeFactoryManager::getInstance().RegisterShape(id, shapecompfact);

ShapeComposite::ShapeComposite()
= default;

void ShapeComposite::AddChild(Shape* child)
{
	if (child != nullptr)
	{
		children.push_back(child);
		cout << "Shape Added" << endl;
	}
	else
	{
		cerr << "No Shape Added" << endl;
	}
}
void ShapeComposite::RemoveChild(Shape* child)
{
	auto itr = find(children.begin(), children.end(), child);
	if (itr != children.end())
	{
		children.erase(itr);
	}
}

void ShapeComposite::doDraw() const
{
	for each(auto shape in children)
	{
		shape->Draw();
	}
}

void ShapeComposite::doSave() const
{
	for each (auto shape in children)
	{
		shape->Save();		
	}	
}

void ShapeComposite::doLoad()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject;
	inputStreamFromFile >> jsonObject;
	

	// special iterator member functions for objects
	for (json::iterator it = jsonObject["ShapeComposite"].begin(); it != jsonObject["ShapeComposite"].end(); ++it)
	{
		// ShapeFactoryManager is a Singleton:
		//std::cout << it.key() << " : " << it.value() << "\n";
		const ShapeFactoryManager& shapeFactoryManager = ShapeFactoryManager::getInstance();
		
		const auto shape = static_cast<Shape::UniqueID>(it.value());
		const auto shapeFactory = shapeFactoryManager.createFactory(shape);
		if (shapeFactory != nullptr)
		{
			const auto shapePtr = shapeFactory->CreateShape();
			if (shapePtr != nullptr)
			{
				shapePtr->Load();
				children.push_back(shapePtr);
			}
			else
			{
				std::cout << "Invalid shape." << std::endl;
			}
		}
		
	}
}
