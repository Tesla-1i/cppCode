#include <iostream>
#include "Rational.h"
using namespace std;

int main(){
	int n1, d1;
	while(1){
		cout<<"�������һ�����ķ��Ӻͷ�ĸ\n";
		cin>>n1>>d1;
		if(d1 != 0){
			//Rational ra1(n1, d1);
			break;
		}
		else
			cout<<"��ĸ��Ϊ��\n";
	}
	Rational ra1(n1, d1);
	int n2, d2;
	while(1){
		cout<<"������ڶ������ķ��Ӻͷ�ĸ\n";
		cin>>n2>>d2;
		if(d2 != 0){
			//Rational ra2(n2, d2);
			break;
		}
		else
			cout<<"��ĸ��Ϊ��\n";
	}
	Rational ra2(n2, d2);
	//cout<<"ra2 "<<ra2<<" ra1 "<<ra1<<endl;
	cout<<"������ӵ�: \n";
	Rational ra3;
	ra3 = ra1 + ra2;
	cout<<ra3<<endl;
	cout<<"��������ã�\n";
	Rational ra4;
	ra4 = ra1 - ra2;
	cout<<ra4<<endl;
	cout<<"������˵ã�\n";
	Rational ra5;
	ra5 = ra1 * ra2;
	cout<<ra5<<endl;
	cout<<"���������\n";
	//ra6 = ra1 / ra2;
	Rational ra6;
	ra6 = ra1 / ra2;
	cout<<ra6<<endl;
	cout<<"�Ƚ�������С\n";
	if(ra1 > ra2)
		cout<<ra1<<" > "<<ra2<<endl;
	else if(ra1 < ra2)
		cout<<ra1<<" < "<<ra2<<endl;
	else if(ra1 == ra2)
		cout<<ra1<<" == "<<ra2<<endl;
	else
		cout<<"error\n";

	return 0;

}