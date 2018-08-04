#include "stdafx.h"
#include "Creator.h"


i_product * creator::get_product()
{
	if(_product == 0)
	{
		_product = create_product();
	}
	return _product;
}


creator::creator()
= default;


creator::~creator()
= default;
