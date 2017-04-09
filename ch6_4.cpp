//ch6_4.cpp
# include <iostream>
using namespace std; 
class TwoDimensionalShape {                 //��άͼ����
public:
	TwoDimensionalShape();                  //���캯��
	virtual ~TwoDimensionalShape();         //����������
    //���麯��
	virtual double getArea()=0;             //�������
    virtual void show()=0;                  //�������
};
class Square:public TwoDimensionalShape{    //��������
private:
	double side;                            //�����α߳�
public:
	Square(double);                         //���캯��
	virtual ~Square();                      //����������
	double getArea();                       //�������������
	void show();                            //�����������Ϣ
};
class Circle:public TwoDimensionalShape {   //Բ����
private:
	double radius;                          //Բ�뾶
public:
	Circle(double);                         //���캯��
	~Circle();                              //��������  
    double getArea();                       //����Բ�����
	void show();                            //���Բ����Ϣ
};
// ��άͼ�ι��캯��
TwoDimensionalShape::TwoDimensionalShape(){    
	cout<<"��άͼ�ι��캯��"<<endl;  
}
//��άͼ����������
TwoDimensionalShape::~TwoDimensionalShape(){
	cout<<"��άͼ����������"<<endl;   
}
//���������ι��캯������ʼ���߳�
Square::Square(double side):side(side){    
	cout<<"�����ι��캯��"<<endl;  
}
//��������������
Square::~Square(){  
	cout<<"��������������"<<endl;  
}
//�������������
double Square::getArea(){  
	return side*side;  
}
//��������ε���Ϣ
void Square::show(){
	cout<<"���Ǳ߳�Ϊ"<<side<<"��������"<<endl;
}
//Բ�ι��캯������ʼ���뾶
Circle::Circle(double r):radius(r){
	cout<<"Բ�ι��캯��"<<endl; 
}
//Բ����������
Circle::~Circle(){  
	cout<<"Բ����������"<<endl;  
}
//����Բ�����
double Circle::getArea(){  
	return radius*radius*3.14;  
}
// ���Բ�ε���Ϣ
void Circle::show(){
	cout<<"���ǰ뾶Ϊ"<<radius<<"��Բ��"<<endl;
}
// ���Զ�άͼ�κ���
void test(TwoDimensionalShape & t){
	t.show();
	cout<<"���Ϊ"<<t.getArea()<<endl;
}
// ������
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
	cout<<"���Ϊ"<<t1->getArea()<<endl;
    TwoDimensionalShape * t2;
    t2 = & c;
    t2->show();
	cout<<"���Ϊ"<<t2->getArea()<<endl;
    return 0;
}
*/