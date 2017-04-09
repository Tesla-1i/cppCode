#include <iostream>
#include "Shape.h"
#include "TwoShape.h"
#include "ThreeShape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "Sphere.h"
#include "Cube.h"

using namespace std;

int main(){
	Shape *s[5];
	Circle ci;
	Triangle tr;
	Square sq;
	Sphere sp;
	Cube cu;
	s[0] = &ci;
	s[1] = &tr;
	s[2] = &sq;
	s[3] = &sp;
	s[4] = &cu;
	for(int i=0; i<5; i++){
		switch(s[i]->decideShape()){
			case 2:
				cout<<"这是一个二维图形; 面积是："<<s[i]->getArea()<<endl;
				break;
			case 3:
				cout<<"这是一个三维图形; 面积是："<<s[i]->getArea()<<"; 体积是："<<s[i]->getVolume()<<endl;
		}
	}
	return 0;
}