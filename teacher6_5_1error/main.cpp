#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

int main(){
	String s1, s2, s3;
	cout<<"请输入字符串s2\n";
	cin>>s2;
	cout<<"请输入字符串s3\n";
	cin>>s3;
	s1 = s2 + s3;
	cout<<"s1 = s2 + s3 = "<<s1<<endl;
	if(s1 < s3){
		cout<<s1<<" < "<<s3<<endl;
	}
	else{
		cout<<s1<<" > "<<s3<<endl;
	}
	cout<<"请输入s1中的两个索引\n";
	int i1, i2, l = strlen(s1.getS());
	while(1){
		cin>>i1>>i2;
		if((i1 >= 0 && i1 < i2)&& i2 <= (l-1))
			break;
		cout<<"请重新输入\n";
	}
	String s4;
	s4 = s1(i1, i2);
	cout<<"子串是："<<s4<<endl;
	return 0;
}