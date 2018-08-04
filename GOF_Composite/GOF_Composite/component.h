#pragma once
class component
{
public:
	virtual void operation();
	virtual void add(component* add) = 0;
	virtual void remove(component* remove) = 0;
	virtual component* get_child(int) = 0;
	component();
	virtual ~component();
};

