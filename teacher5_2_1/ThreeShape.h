#include "Shape.h"
#include <iostream>

#ifndef THREESHAPE
#define THREESHAPE

class ThreeShape:public Shape
{
protected:
	int flag;
	double area;
	double volume;
public:
	ThreeShape();
	virtual ~ThreeShape();
	virtual double getArea();
	virtual double getVolume();
	virtual int decideShape();
};

ThreeShape::ThreeShape(){
	flag = 3;
	area = 0.0;
	volume = 0.0;
}
ThreeShape::~ThreeShape(){}

double ThreeShape::getArea(){
	return 0;
}
double ThreeShape::getVolume(){
	return 0;
}
int ThreeShape::decideShape(){
	return flag;
//	flag = 3;
}

#endif 