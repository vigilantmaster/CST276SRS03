#pragma once
/*
 * - declares the factory methods, which returns an object of type Product.
 *  Creator ma also define a default implementation of the factory method that returns a default ConcreteProduct object. 
 *  - may call the factory method to create a Product object
 */
#include "IProduct.h"
class creator
{
public:
	//TODO: create special memeber functions to shut the compiler up
	
public:
	i_product * get_product();
protected:
	virtual i_product * create_product() = 0;
private:
	i_product * _product{};
	creator();
	~creator();
};

