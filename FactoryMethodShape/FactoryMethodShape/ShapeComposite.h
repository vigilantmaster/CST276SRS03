#pragma once
#include <vector>
#include "Shape.h"


// Composite Pattern Taken from GROUP OF FOUR Design Patterns


using namespace std;
class shape_composite : public Shape
{
private:
	static const UniqueID id = 987;
private:
	static const bool registered;
	

public:
	shape_composite();
	
protected:
	vector<Shape*> children; //Child components list.
public:
	/*
	* Add a Component to the child list.
	* Check to avoid duplication of same child in the list.
	*/
	void AddChild(Shape* child);

	/*
	* Remove a component from the child list if it exist there.
	*/
	void RemoveChild(Shape* child);
	/*
	* Remove all children from the list.
	*/
	void Clear()
	{
		children.clear();
	}
	virtual ~shape_composite()
	= default;

private:
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;

private:
	/*
	* An iterator type is defined which can be used from Composite class
	* To perform extensive operations on the Children list like Insert, Search etc.
	* This is provided just for Ease of use for Composite class developers.
	*/
	typedef	vector<shape_composite*>::iterator ChildIterator;
};



