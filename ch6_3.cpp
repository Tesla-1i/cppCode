//ch6_3.cpp
# include <iostream>
using namespace std; 
class TwoDimensionalShape{                         //��άͼ����
public:
    TwoDimensionalShape();                         //���캯��                        
	virtual ~TwoDimensionalShape();                        //��������
};
class Square : public TwoDimensionalShape{         //��������
protected:
	double side;                            //�����α߳�
public:
	Square();                               //Ĭ�Ϲ��캯��
	Square(double);                         //���캯��
	~Square();                              //��������
};
// ��άͼ�ι��캯��
TwoDimensionalShape::TwoDimensionalShape(){
	cout<<"��άͼ�ι��캯��"<<endl;
}
// ��άͼ����������
TwoDimensionalShape::~TwoDimensionalShape(){
	cout<<"��άͼ����������"<<endl;
}
// ������Ĭ�Ϲ��캯��
Square::Square():side(1){
	cout<<"�����ι��캯��"<<endl;
}
// �����ι��캯������ʼ���߳�
Square::Square(double side):side(side){
	cout<<"�����ι��캯��"<<endl;
}
// ��������������
Square::~Square(){
	cout<<"��������������"<<endl;
}
// ������
int main(){
	TwoDimensionalShape * t = new Square(9);
	delete t;
    return 0;
}
