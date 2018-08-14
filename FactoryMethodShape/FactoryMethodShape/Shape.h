#pragma once
// https://github.com/nlohmann/json  Json code and examples taken from here
#include "json.hpp"
// for convenience
using json = nlohmann::json;
class Shape
{
protected:
	int specialId{}, xstart{}, x1{}, x2{}, ystart{}, y1{}, y2{};
	
public:
	using UniqueID = unsigned long; // See: https://en.wikipedia.org/wiki/Universally_unique_identifier

public:
	Shape();
	virtual ~Shape();

private:
	virtual void doDraw() const = 0;
	virtual json to_json() = 0;
public:
	void Draw() const;
	json toJson();
	Shape * operator<<(json * rhs);
	json operator<<(const Shape & rhs);

private:
	virtual void doSave() const = 0;
	virtual void doLoad() = 0;
	virtual void doLoad(json object) = 0;
	virtual Shape* toShape(json * rhs) = 0;

public:
	void Save() const;
	void Load();
	void Load(json object);
};
