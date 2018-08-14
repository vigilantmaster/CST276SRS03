#pragma once

#include "Shape.h"
#include "Line.h"

class circle : public Shape
{
private:
	static const UniqueID id = 456;

private:
	static const bool registered; 

private:
	int id_;
	int radius;
	int xcenter;
	int ycenter;
	int specialId{};
		
public:
	circle();
	~circle();
	void setCircle(int specialId_, int radius_, int xcenter_, int ycenter_);
	json to_json() override;

private:
	static std::string toString();
	void doDraw() const override;
	void doSave() const override;
	void doLoad() override;
	void doLoad(json object) override;


	Shape* toShape(json* rhs) override;
};

