#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

istream& operator >>(istream& in, String& str){
	//s = new char[20];
	cin>>str.getS();
	return in;
}

ostream& operator <<(ostream& out, String& str){
	cout<<str.getS()<<endl;
	return out;
}

String String::operator +(String & str){
	char* strs = str.getS();
	strcat(s, strs);
	return String(s);
}

bool String::operator < (String &str){
	char * strs = str.getS();
	int i = strcmp(s, strs);
	if( i < 0)
		return true;
	else
		return false;
}

String String::operator ()(int index1, int index2){
	int l = strlen(s);
	if(index2 > l-1){
		cout<<"Ô½½ç";
		exit(1);
	}
	int length = index2-index1 + 2;
	char *pStr = new char[index2 - index1 + 2];
	for(int i = 0; i < length - 1;i++ ){
		pStr[i] = s[index1 + i];
	}
	pStr[i] = '\0';
	String tempStr(pStr);
	delete[] pStr;
	return tempStr;
}
