#include <iostream>
#include "Rational.h"
using namespace std;

int main(){
	int n1, d1;
	while(1){
		cout<<"请输入第一个数的分子和分母\n";
		cin>>n1>>d1;
		if(d1 != 0){
			//Rational ra1(n1, d1);
			break;
		}
		else
			cout<<"分母不为零\n";
	}
	Rational ra1(n1, d1);
	int n2, d2;
	while(1){
		cout<<"请输入第二个数的分子和分母\n";
		cin>>n2>>d2;
		if(d2 != 0){
			//Rational ra2(n2, d2);
			break;
		}
		else
			cout<<"分母不为零\n";
	}
	Rational ra2(n2, d2);
	//cout<<"ra2 "<<ra2<<" ra1 "<<ra1<<endl;
	cout<<"两者相加得: \n";
	Rational ra3;
	ra3 = ra1 + ra2;
	cout<<ra3<<endl;
	cout<<"两者相减得：\n";
	Rational ra4;
	ra4 = ra1 - ra2;
	cout<<ra4<<endl;
	cout<<"两者相乘得：\n";
	Rational ra5;
	ra5 = ra1 * ra2;
	cout<<ra5<<endl;
	cout<<"两者相除：\n";
	//ra6 = ra1 / ra2;
	Rational ra6;
	ra6 = ra1 / ra2;
	cout<<ra6<<endl;
	cout<<"比较两数大小\n";
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