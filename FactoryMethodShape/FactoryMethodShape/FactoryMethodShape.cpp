// FactoryMethodShape.cpp : Defines the entry point for the console application.
//
// INITIAL code TAKEN FROM Mitch Besser at OIT.  10/28/2017 
//FINALIZED BY Tanel Helmik 8/4/2018 with a composite. 
//Drawing was left alone although it isn't needed anymore.
#include "stdafx.h"
#include "FactoryMethodShape.h"
#include "ShapeComposite.h"

int main()
{
	shape_composite test;
	test.Load();
	test.Draw();
    return 0;
}

