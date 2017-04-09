#include "Shape.h"
#include <iostream>

#ifndef TWOSHAPE
#define TWOSHAPE

class TwoShape :public Shape
{
protected:
	int flag;
	double area;
public:
	TwoShape();
	virtual ~TwoShape();
	virtual double getArea();
	virtual int decideShape();
};

TwoShape::TwoShape(){
	flag = 2;
	area = 0.0;
}

TwoShape::~TwoShape(){

}

double TwoShape::getArea(){
	return 0;
}

int TwoShape::decideShape(){
	return flag;
}

#endif