#include <iostream>
#include "Shape.h"
#include "TwoShape.h"

using namespace std;

#ifndef CIRCLE
#define CIRCLE

class Circle:public TwoShape
{
protected:
	double radius;
public:
	Circle();
	~Circle();
	double getArea();
};

Circle::Circle(){
	radius = 1.0;
}

Circle::~Circle(){
	cout<<"CircleÎö¹¹º¯ÊýÖ´ÐÐ\n";
}

double Circle::getArea(){
	return 3.14159*radius*radius;
}



#endif