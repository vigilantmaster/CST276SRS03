// FactoryMethodShape.cpp : Defines the entry point for the console application.
//
// INITIAL code TAKEN FROM Mitch Besser at OIT.  10/28/2017 
//FINALIZED BY Tanel Helmik 11/14/2017 with a composite. 
//Drawing was left alone although it isn't needed anymore.
#include "stdafx.h"
#include "Line.h"
#include "FactoryMethodShape.h"
#include "ShapeComposite.h"

int main()
{
	ShapeComposite test;
	test.Load();
	test.Draw();
	system("pause");
    return 0;
}

