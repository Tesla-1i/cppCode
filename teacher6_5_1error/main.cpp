#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

int main(){
	String s1, s2, s3;
	cout<<"�������ַ���s2\n";
	cin>>s2;
	cout<<"�������ַ���s3\n";
	cin>>s3;
	s1 = s2 + s3;
	cout<<"s1 = s2 + s3 = "<<s1<<endl;
	if(s1 < s3){
		cout<<s1<<" < "<<s3<<endl;
	}
	else{
		cout<<s1<<" > "<<s3<<endl;
	}
	cout<<"������s1�е���������\n";
	int i1, i2, l = strlen(s1.getS());
	while(1){
		cin>>i1>>i2;
		if((i1 >= 0 && i1 < i2)&& i2 <= (l-1))
			break;
		cout<<"����������\n";
	}
	String s4;
	s4 = s1(i1, i2);
	cout<<"�Ӵ��ǣ�"<<s4<<endl;
	return 0;
}