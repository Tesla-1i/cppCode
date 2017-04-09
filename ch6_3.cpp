//ch6_3.cpp
# include <iostream>
using namespace std; 
class TwoDimensionalShape{                         //二维图形类
public:
    TwoDimensionalShape();                         //构造函数                        
	virtual ~TwoDimensionalShape();                        //析构函数
};
class Square : public TwoDimensionalShape{         //正方形类
protected:
	double side;                            //正方形边长
public:
	Square();                               //默认构造函数
	Square(double);                         //构造函数
	~Square();                              //析构函数
};
// 二维图形构造函数
TwoDimensionalShape::TwoDimensionalShape(){
	cout<<"二维图形构造函数"<<endl;
}
// 二维图形析构函数
TwoDimensionalShape::~TwoDimensionalShape(){
	cout<<"二维图形析构函数"<<endl;
}
// 正方形默认构造函数
Square::Square():side(1){
	cout<<"正方形构造函数"<<endl;
}
// 正方形构造函数，初始化边长
Square::Square(double side):side(side){
	cout<<"正方形构造函数"<<endl;
}
// 正方形析构函数
Square::~Square(){
	cout<<"正方形析构函数"<<endl;
}
// 主函数
int main(){
	TwoDimensionalShape * t = new Square(9);
	delete t;
    return 0;
}
