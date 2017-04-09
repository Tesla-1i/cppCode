//ch6_2.cpp
# include <iostream>
using namespace std; 
class TwoDimensionalShape{                         //��άͼ����
public:
    virtual void show();                    //�����άͼ����Ϣ
};
class Square : public TwoDimensionalShape{         //��������
protected:
	double side;                            //�����α߳�
public:
	Square();                               //Ĭ�Ϲ��캯��
	Square(double);                         //���캯��
	void setSide(double);                   //���ñ߳�
	double getArea();                       //�������������
	void show();                            //�����������Ϣ
};
// ��άͼ���������
void TwoDimensionalShape::show(){
	cout<<"����һ����άͼ��"<<endl;
}
// ������Ĭ�Ϲ��캯��
Square::Square():side(1){}
// �����ι��캯������ʼ���߳�
Square::Square(double side):side(side){}
// ���������α߳�
void Square::setSide(double side){
	this->side=side;  
}
// �������������
double Square::getArea(){  
	return side*side;  
}
// ��������ε���Ϣ
void Square::show(){
	cout<<"���Ǳ߳�Ϊ"<<side<<"�������Σ����Ϊ"
		<<getArea()<<endl;
}
// ������
int main(){
	TwoDimensionalShape t;             //������άͼ�ζ���t
    Square s1;                  //���������ζ���s1
    s1.setSide(8);
    Square s2(3);               //���������ζ���s2
    TwoDimensionalShape * members[3];  //��άͼ��ָ������
    members[0]=&t;
    members[1]=&s1;
    members[2]=&s2;
	for(int i=0;i<3;i++)
		members[i]->show();	
    return 0;
}