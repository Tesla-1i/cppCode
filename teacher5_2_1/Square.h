#include <iostream>
#include "Shape.h"
#include "TwoShape.h"

using namespace std;

#ifndef SQUARE
#define SQUARE


class Square:public TwoShape
{
protected:
	double radius;
public:
	Square();
	~Square();
	double getArea();
};

Square::Square(){
	radius = 1.0;
}

Square::~Square(){
	cout<<"SquareÎö¹¹º¯ÊýÖ´ÐÐ\n";
}

double Square::getArea(){
	return radius*radius;
}

#endif