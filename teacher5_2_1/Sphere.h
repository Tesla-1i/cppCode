#include <iostream>
#include "Shape.h"
#include "ThreeShape.h"

using namespace std;

#ifndef SPHERE
#define SPHERE

class Sphere:public ThreeShape
{
protected:
	double radius;
public:
	Sphere();
	~Sphere();
	double getArea();
	double getVolume();
};

Sphere::Sphere(){
	radius = 1.0;
}

Sphere::~Sphere(){
	cout<<"SphereÎö¹¹º¯ÊýÖ´ÐÐ\n";
}

double Sphere::getArea(){
	return 4*3.14159*radius*radius;
}

double Sphere::getVolume(){
	return 3.14159*radius*radius*radius*4/3;
}

#endif