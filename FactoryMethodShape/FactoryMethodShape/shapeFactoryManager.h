#pragma once
#include "Shape.h"
#include "ShapeFactory.h"
#include <utility>
#include <vector>

class ShapeFactoryManager
{
private:
	ShapeFactoryManager();
	~ShapeFactoryManager();
	static ShapeFactoryManager* instance ;

protected:
	std::vector<std::pair<Shape::UniqueID,ShapeFactory&>> registrationTable;

public:	
	static ShapeFactoryManager& getInstance();
	bool RegisterShape(Shape::UniqueID, ShapeFactory&);
	ShapeFactory* createFactory(Shape::UniqueID UniqueIDin)const;
};

