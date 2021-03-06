// FactoryMethodShape.cpp : Defines the entry point for the console application.
//
// INITIAL code TAKEN FROM Mitch Besser at OIT.  10/28/2017 
//EDITED BY Tanel Helmik 8/6/2018 with a composite. 
//Drawing was left alone although it isn't needed anymore.
#include "stdafx.h"
#include "FactoryMethodShape.h"
#include "ShapeComposite.h"
#include "Circle.h"
#include <iostream>
#include "shapeFactoryManager.h"
#include "RectangleFactory.h"


int main()
{
	shape_composite test;
	//load from Shapes.json
	//test.Load();
	//create circle
	circle testCircle;
	testCircle.setCircle(111111, 9, 4, 3);
	testCircle.Save();
	//add circle to compsite
	test.AddChild(&testCircle);
	//show the circle is there with previously loaded
	test.Draw();
	//removing circle
	test.RemoveChild(&testCircle);
	std::cout << "---------------------Test without added circle" << std::endl;
	test.Draw();
	//get a polygon from the singleton
	ShapeFactory * polygon_factory_ = ShapeFactoryManager::getInstance().createFactory(789) ;
	auto polygon = polygon_factory_->CreateShape();
	// probably make polygon different I will just load one from the json document
	polygon->Save();
	polygon->Load();
	test.AddChild(polygon);
	std::cout << "---------------------Test with polygon added from json" << std::endl;
	test.Draw();

	test.Save();

	shape_composite test2;
	//test2.Load();
	test2.Draw();
	test2.RemoveChild(polygon);
	test2.Save();
	


    return 0;
}

