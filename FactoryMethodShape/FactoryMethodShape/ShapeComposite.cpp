#include "stdafx.h"
#include "ShapeComposite.h"
#include <iostream>
#include "json.hpp"
#include "shapeFactoryManager.h"
#include "ShapeCompositeFactory.h"

using json = nlohmann::json;  // for ease of use with json

ShapeCompositeFactory shapecompfact;
const bool shape_composite::registered = ShapeFactoryManager::getInstance().RegisterShape(id, shapecompfact);

shape_composite::shape_composite() : canvasWidth{ 1024 }, canvasHeight{ 800 }
{
	canvasRectangle.setRectangle(specialId, 0, canvasWidth, 0, canvasHeight);
}


void shape_composite::AddChild(Shape* child)
{
	if (child != nullptr)
	{
		children.push_back(child);
		//cout << "Shape Added" << endl;
	}
	else
	{
		cerr << "No Shape Added" << endl;
		throw exception("invalid shape");
	}
}
void shape_composite::RemoveChild(Shape* child)
{
	auto itr = find(children.begin(), children.end(), child);
	if (itr != children.end())
	{
		children.erase(itr);
	}
}

void shape_composite::drawCanvas() const
{
	canvasRectangle.Draw();
}

void shape_composite::doDraw() const
{
	drawCanvas();
	for each(auto shape in children)
	{
		shape->Draw();
	}
}

void shape_composite::doSave() const
{
	for each (auto shape in children)
	{
		shape->Save();		
	}	
}

void shape_composite::doLoad()
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject = json::object();
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
				throw exception("Invalid shape.");
			}
		}
		else
		{
			
		}
		
	}
}
