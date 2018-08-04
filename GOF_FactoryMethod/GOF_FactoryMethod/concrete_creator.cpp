#include "stdafx.h"
#include "concrete_creator.h"
#include "concrete_product.h"


concrete_creator::concrete_creator(): creator()
{
}

concrete_creator::~concrete_creator()
= default;

i_product * concrete_creator::create_product()
{
	
	return new concrete_product;
}
