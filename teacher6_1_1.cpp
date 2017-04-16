#include <iostream>
#include <cmath>

using namespace std;
class Point;
ostream& operator <<(ostream &out, Point &p);
//不提前声明以上两句，在VC6上会报错 C++ 'operator <<' is ambiguous 

class Point
{
public:
	double x, y;
public:
	Point(double a = 0, double b = 0):x(a),y(b){

	}
	~Point(){}
	void setPoint(int a, int b){
		x = a; y = b;
	}
	double operator - (Point &p2);
	friend ostream& operator <<(ostream& out, Point &p);
};
double Point::operator -(Point &p2){
	return sqrt((x - p2.x)*(x - p2.x) + (y - p2.y)*(y - p2.y));
}

ostream& operator <<(ostream &out, Point &p){
	out<<"["<<p.x<<","<<p.y<<"]";
	return out;
	//返回out!!!!!!!!
}

int main(){
	Point p1(2, 1), p2;
	cout<<"请输入p2的坐标\n";
	double x, y;
	cin>>x>>y;
	p2.setPoint(x, y);
	double d = p1 - p2;
	cout<<"距离结果是:\n";
	cout<<p1<<"->"<<p2<<" = "<<d<<endl;
	return 0;
}