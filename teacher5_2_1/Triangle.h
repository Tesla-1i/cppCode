#include <iostream>
#include "Shape.h"
#include "TwoShape.h"

using namespace std;

#ifndef TRIANGLE
#define TRIANGLE

class Triangle:public TwoShape
{
protected:
	double di;
	double height;
public:
	Triangle();
	~Triangle();
	double getArea();
};

Triangle::Triangle(){
	di = 1.0;
	height = 1.0;
}

Triangle::~Triangle(){
	cout<<"TriangleÎö¹¹º¯ÊýÖ´ÐÐ\n";
}

double Triangle::getArea(){
	return 0.5*di*height;
}

#endif