#ifndef SHAPE
#define SHAPE

class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual double getArea();
	virtual double getVolume();
	virtual int decideShape();
};

Shape::Shape(){}

Shape::~Shape(){}
double Shape::getArea(){
	return 0;
}
double Shape::getVolume(){
	return 0;
}
int Shape::decideShape(){
	return 0;
}
#endif