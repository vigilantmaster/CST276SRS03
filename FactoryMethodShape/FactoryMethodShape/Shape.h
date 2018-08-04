#pragma once

class Shape
{
	
public:
	using UniqueID = unsigned long; // See: https://en.wikipedia.org/wiki/Universally_unique_identifier

public:
	Shape();
	virtual ~Shape();

private:
	virtual void doDraw() const = 0;

public:
	void Draw() const;

private:
	virtual void doSave() const = 0;
	virtual void doLoad() = 0;

public:
	void Save() const;
	void Load();
};
