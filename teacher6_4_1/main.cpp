#include <iostream>
#include "Time.h"
using namespace std;

int main(){
	/*Time t1(0, 0, 5);
	cout<<t1<<endl;
	Time t2;
	t2 = t1 - 130;
	cout<<t2<<endl;
	Time t3(23, 59, 59);
	++t3;
	cout<<t3<<endl;
	Time t4(1, 0, 0);
	--t4;
	cout<<t4<<endl;*/
	int h1, m1, s1;
	cout<<"请输入时间t1，格式: hour minute second\n";
	while(1){
		cin>>h1>>m1>>s1;
		if((h1 >= 0)&& (h1<=23) &&(m1 >= 0)&&(m1 <= 59) &&(s1 >= 0) &&(s1 <= 59))
			break;
		cout<<"error! 请重新输入\n";
	}
	Time t1(h1, m1, s1);
	cout<<"请输入秒数\n";
	int s2;
	cin>>s2;
	if(s2 > 3600){
		cout<<"error";
		return 1;
	}
	Time t2;
	t2 = s2 + t1;
	cout<<"秒数 + 时间类 ："<<t2<<endl;
	Time t3;
	t3 = t1 + s2;
	cout<<"时间类 + 秒数："<<t3<<endl;
	cout<<"t1 = "<<t1<<endl;
	cout<<"请输入秒数\n";
	int s3;
	cin>>s3;
	if(s3 > 3600){
		cout<<"error";
		return 1;
	}
	Time t4;
	t4 = t1 - s3;
	cout<<"时间类 - 秒数："<<t4<<endl;
	++t1;
	cout<<"++t1 = "<<t1<<endl;
	--t1;
	cout<<"--t1 = "<<t1<<endl;
	return 0;
}