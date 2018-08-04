#include "stdafx.h"
#include "shapeFactoryManager.h"
// Singleton Pattern taken from https://www.youtube.com/watch?v=hUE_j6q0LTQ this guy makes sense
ShapeFactoryManager* ShapeFactoryManager::instance = nullptr;
//std::vector<std::pair<Shape::UniqueID, ShapeFactory&>> ShapeFactoryManager::registrationTable;
ShapeFactoryManager::ShapeFactoryManager()
= default;

ShapeFactoryManager& ShapeFactoryManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ShapeFactoryManager;
	}
	return *instance;
}

bool ShapeFactoryManager::RegisterShape(Shape::UniqueID UniqueIDin, ShapeFactory& ShapeFactoryin)
{
	std::pair<Shape::UniqueID, ShapeFactory&> temp (UniqueIDin, ShapeFactoryin);
	temp.first = UniqueIDin;
	temp.second = ShapeFactoryin;
	registrationTable.push_back(temp);
	return true;
}

ShapeFactory* ShapeFactoryManager::createFactory(Shape::UniqueID UniqueIDin) const
{
	ShapeFactory* temp = nullptr;
	auto iterator = registrationTable.cbegin();
	for ( ; iterator != registrationTable.cend(); ++iterator)
	{
		if(iterator->first == UniqueIDin)
		{
			temp = &iterator->second;
		}
	}
	return temp;
}
ShapeFactoryManager::~ShapeFactoryManager() = default;
