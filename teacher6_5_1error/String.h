#include <iostream>
#include <cstring>
using namespace std;

#ifndef STRING
#define STRING

class String;
ostream& operator <<(ostream& out, String& str);
istream& operator >>(istream& in, String& str);

class String
{
private:
	char s[20];
public:
	char * getS(){return s; }
	String(char *str = NULL){
		//s = new char[20];
		strcpy(s, str);
	}
	String(String& str){
		char *strs = str.getS();
		//s = new char[20];
		strcpy(s, strs);
	}
	~String(){
		//delete [] s;
	}
	friend ostream& operator <<(ostream& out, String& str);
	friend istream& operator >>(istream& in, String& str);
	String operator +(String &str);
	bool operator <(String &str);
	String operator ()(int a, int b);
	
};

#endif