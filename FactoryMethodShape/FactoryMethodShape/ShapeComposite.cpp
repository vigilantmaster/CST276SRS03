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
	children.push_back(&canvasRectangle);
}


void shape_composite::AddChild(Shape* child)
{
	if (child != nullptr)
	{
		children.push_back(child);
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


shape_composite::~shape_composite()
= default;

void shape_composite::drawCanvas() const
{
	canvasRectangle.Draw();
}

void shape_composite::doDraw() const
{
	
	for each(auto shape in children)
	{
		shape->Draw();
	}
}

void shape_composite::doSave() const
{
	std::ofstream outputStreamToFile("TestComposite.json");
	const json jsonobject{ this->to_jsonList() };
	jsonobject >> outputStreamToFile;
}

void shape_composite::doLoad()
{
	std::ifstream inStreamFromFile("TestComposite.json");
	json jsonobject;
	jsonobject << inStreamFromFile;
	for (json::iterator it = jsonobject.begin(); it != jsonobject.end(); ++it)
	{
		// ShapeFactoryManager is a Singleton:
		const ShapeFactoryManager& shapeFactoryManager = ShapeFactoryManager::getInstance();
		int thisID = (*it)["id"].get<int>();
		const auto shape = static_cast<Shape::UniqueID>(thisID);
		const auto shapeFactory = shapeFactoryManager.createFactory(shape);
		if (shapeFactory != nullptr)
		{

			const auto shapePtr = shapeFactory->CreateShape();
			if (shapePtr != nullptr)
			{
				shapePtr->Load(*it);
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

json shape_composite::to_json()
{
	return json();
}

Shape* shape_composite::toShape(json* rhs)
{
	
	for (json::iterator it = (*rhs).begin(); it != (*rhs).end(); ++it)
	{
		
		// ShapeFactoryManager is a Singleton:
		const ShapeFactoryManager& shapeFactoryManager = ShapeFactoryManager::getInstance();
		auto myINT = (*it)["id"].get<int>();
		const auto shape = static_cast<Shape::UniqueID>(myINT);
		const auto shapeFactory = shapeFactoryManager.createFactory(shape);
		if (shapeFactory != nullptr)
		{

			const auto shapePtr = shapeFactory->CreateShape();
			if (shapePtr != nullptr)
			{
				shapePtr->Load(*it);
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

	return this;
}

void shape_composite::doLoad(json object)
{
	toShape(&object);
}

list<json> shape_composite::to_jsonList() const
{
	list<json> jsonOjectList;
	for each(auto shape in children)
	{
		jsonOjectList.push_back(shape->toJson());		
	}
	return jsonOjectList;
}


/*

void shape_composite::doLoad("this is the old one")
{
	std::ifstream inputStreamFromFile("Shapes.json");
	json jsonObject = json::object();
	inputStreamFromFile >> jsonObject;
	

	// special iterator member functions for objects
	for (json::iterator it = jsonObject["ShapeComposite"].begin(); it != jsonObject["ShapeComposite"].end(); ++it)
	{
		// ShapeFactoryManager is a Singleton:
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
}*/
