//ch6_4.cpp
# include <iostream>
using namespace std; 
class TwoDimensionalShape {                 //二维图行类
public:
	TwoDimensionalShape();                  //构造函数
	virtual ~TwoDimensionalShape();         //虚析构函数
    //纯虚函数
	virtual double getArea()=0;             //计算面积
    virtual void show()=0;                  //输出函数
};
class Square:public TwoDimensionalShape{    //正方形类
private:
	double side;                            //正方形边长
public:
	Square(double);                         //构造函数
	virtual ~Square();                      //虚析构函数
	double getArea();                       //计算正方形面积
	void show();                            //输出正方形信息
};
class Circle:public TwoDimensionalShape {   //圆形类
private:
	double radius;                          //圆半径
public:
	Circle(double);                         //构造函数
	~Circle();                              //析构函数  
    double getArea();                       //计算圆形面积
	void show();                            //输出圆形信息
};
// 二维图形构造函数
TwoDimensionalShape::TwoDimensionalShape(){    
	cout<<"二维图形构造函数"<<endl;  
}
//二维图形析构函数
TwoDimensionalShape::~TwoDimensionalShape(){
	cout<<"二维图形析构函数"<<endl;   
}
//定义正方形构造函数，初始化边长
Square::Square(double side):side(side){    
	cout<<"正方形构造函数"<<endl;  
}
//正方形析构函数
Square::~Square(){  
	cout<<"正方形析构函数"<<endl;  
}
//计算正方形面积
double Square::getArea(){  
	return side*side;  
}
//输出正方形的信息
void Square::show(){
	cout<<"这是边长为"<<side<<"的正方形"<<endl;
}
//圆形构造函数，初始化半径
Circle::Circle(double r):radius(r){
	cout<<"圆形构造函数"<<endl; 
}
//圆形析构函数
Circle::~Circle(){  
	cout<<"圆形析构函数"<<endl;  
}
//计算圆形面积
double Circle::getArea(){  
	return radius*radius*3.14;  
}
// 输出圆形的信息
void Circle::show(){
	cout<<"这是半径为"<<radius<<"的圆形"<<endl;
}
// 测试二维图形函数
void test(TwoDimensionalShape & t){
	t.show();
	cout<<"面积为"<<t.getArea()<<endl;
}
// 主函数
int main(){
	Square s(10);
    Circle c(10);
    test(s);
    test(c);
    return 0;
}
/*
int main(){
	Square s(10);
	Circle c(5);
	TwoDimensionalShape * t1;
    t1 = & s;
    t1->show();
	cout<<"面积为"<<t1->getArea()<<endl;
    TwoDimensionalShape * t2;
    t2 = & c;
    t2->show();
	cout<<"面积为"<<t2->getArea()<<endl;
    return 0;
}
*/