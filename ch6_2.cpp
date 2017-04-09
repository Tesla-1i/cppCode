//ch6_2.cpp
# include <iostream>
using namespace std; 
class TwoDimensionalShape{                         //二维图形类
public:
    virtual void show();                    //输出二维图形信息
};
class Square : public TwoDimensionalShape{         //正方形类
protected:
	double side;                            //正方形边长
public:
	Square();                               //默认构造函数
	Square(double);                         //构造函数
	void setSide(double);                   //设置边长
	double getArea();                       //计算正方形面积
	void show();                            //输出正方形信息
};
// 二维图形输出函数
void TwoDimensionalShape::show(){
	cout<<"这是一个二维图形"<<endl;
}
// 正方形默认构造函数
Square::Square():side(1){}
// 正方形构造函数，初始化边长
Square::Square(double side):side(side){}
// 设置正方形边长
void Square::setSide(double side){
	this->side=side;  
}
// 计算正方形面积
double Square::getArea(){  
	return side*side;  
}
// 输出正方形的信息
void Square::show(){
	cout<<"这是边长为"<<side<<"的正方形，面积为"
		<<getArea()<<endl;
}
// 主函数
int main(){
	TwoDimensionalShape t;             //创建二维图形对象t
    Square s1;                  //创建正方形对象s1
    s1.setSide(8);
    Square s2(3);               //创建正方形对象s2
    TwoDimensionalShape * members[3];  //二维图形指针数组
    members[0]=&t;
    members[1]=&s1;
    members[2]=&s2;
	for(int i=0;i<3;i++)
		members[i]->show();	
    return 0;
}