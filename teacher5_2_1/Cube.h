#include <iostream>
#include "Shape.h"
#include "ThreeShape.h"

using namespace std;

#ifndef CUBE
#define CUBE

class Cube:public ThreeShape
{
protected:
	double radius;
public:
	Cube();
	~Cube();
	double getArea();
	double getVolume();
};

Cube::Cube(){
	radius = 1.0;
}

Cube::~Cube(){
	cout<<"Cube��������ִ��\n";
}

double Cube::getArea(){
	return 6*radius*radius;
}

double Cube::getVolume(){
	return radius*radius*radius;
}

#endif