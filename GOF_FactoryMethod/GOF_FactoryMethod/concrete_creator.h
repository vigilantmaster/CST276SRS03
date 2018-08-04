#pragma once
#include "Creator.h"
#include "IProduct.h"
class concrete_creator : public creator // overrides the factory method (create_product) to return an instance of ConcreteProduct.
{
public:
	concrete_creator();
	//TODO: create special memeber functions
	virtual ~concrete_creator();
protected:
	i_product* create_product() override;
};



