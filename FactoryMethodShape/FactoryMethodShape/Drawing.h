#pragma once

#include <vector>
#include <functional>

#include "Shape.h"

class Drawing
{
private:
	std::vector<std::reference_wrapper<const Shape>/*C++98*/> shapeContainer_;

public:
	Drawing();
	~Drawing();

public:
	void Add(const Shape& shape);
	void Save() const;
	void Load();
	void Draw() const;
};
