/*（5）设计字符串类String，若有String类对象s1、s2和s3，重载运算符实现如下操作：
    1）重载“＋”实现字符串连接功能，使表达式s1= s2+s3成立；
    2）重载“<”判断两个字符串的大小，如 if(s1 < s2) cout<<s1<<”<”<<s2；
3）重载“<<”与“>>”，实现字符串的输入与输出操作，如cin>>s2; cout<<s2<<endl;
4）重载运算符“()”，从字符串对象中返回一个子串。如s1(2,4)表示返回从子串，即从s[2](s1第3个字符)开始的子串(包括s1[2]、s1[3]和s1[4]三个字符)。*/
# include <iostream>
# include <stdlib.h>
# include <cstring>
using namespace std;

class String;
//String operator + (String &str1,char *str2);
ostream& operator <<(ostream& out, String& string);
istream& operator >>(istream& in, String& string);

class String
{
public:
	String();
	//String(char *s);
	~String();
	//void show();	//显示str；
	//void set(char * newstr);
	char *get();
	String operator + (String &str2);
	//friend String operator + (String &str1,char *str2);
	bool operator < (String &str2);
	bool operator== (String &str2);
	//char & operator [] (int i);

	friend ostream& operator <<(ostream& out, String& string);
	friend istream& operator >>(istream& in, String& string);
	String operator () (int index1, int index2);

	char *str;
	int len;
};

char * String::get(){
	return str;
}

String::~String()
{
	if(!str)		
		delete [] str;
}
String::String()
{
	len=0;
}
/*String::String(char * s)
{
	len=strlen(s);
	str=new char[len+1];
	if(str!=0)
		strcpy(str,s);
	str[len]=0;
}

char & String::operator [](int i)
{
	if(str==0)
	{
		cout <<"error";
		exit(0);
	}
	else if ( i<0 ||  i>=len) 
	{
	   cout<<"out of range!";
	   exit(0);
	}
	else
		return str[i];
}*/


bool String::operator == (String & str2)
{
	if(strcmp(str,str2.str)==0)
		return true;
	else
		return false;
}


bool String::operator < (String &str2)
{
	if(strcmp(str,str2.str)<0)
		return true;
	else
		return false;
}/*
String operator+ (String &str1,char *str2)
{
	String ret;
	ret.len=str1.len+strlen(str2);
	ret.str=new char[ret.len+1];
	for(int i=0;i<str1.len;i++)
		ret.str[i]=str1.str[i];
	for(i=str1.len;i<ret.len;i++)
		ret.str[i]=str2[i-str1.len];
	ret.str[ret.len]=0;
	return ret;
}
void String::show()
{
	cout<<str<<endl;
}
void String::set(char * newstr)
{
	len=strlen(newstr);
	//if(str) 
	//	delete []str;
	str=new char[len+1];
	if(str!=0)
		strcpy(str,newstr);
	str[len]=0;
}*/
String String::operator + (String &str2)
{
	/*String ret;
	int i=0;
	int newlen=len+str2.len;
	char *strnew=new char[newlen+1];
	for(i=0;i<len;i++)
		strnew[i]=str[i];
	for(i=len;i<newlen;i++)
	{
		strnew[i]=str2.str[i-len];
	}
	strnew[newlen]=0;
	ret.str=strnew;
	return ret;*/

	int l1 = strlen(str);
	int l2 = strlen(str2.str);
	int l = l1+l2, i;
	//cout<<l1<<" "<<l2<<" "<<l<<endl;
	char *strnew = new char[ l1+l2+1];
	for(i = 0; i < l1; i++)
		{strnew[i] = str[i];}
	for(i = l1; i < l; i++)
		{strnew[i] = str2.str[i - l1];}
	strnew[l] = '\0';
	String ret;
	ret.str = strnew;
	//delete [] strnew;			//为神魔会出错
	//cout<<ret.str<<"123\n";
	return ret;	

}

ostream& operator <<(ostream& out, String& string){
	//char * str1 = string.get();
	out<<string.str;
	return out;
}
istream& operator >>(istream& in, String& string){
	char s[20];
	gets(s);
	int l = strlen(s);
	string.str = new char[l + 1];
	strcpy(string.str, s);
	string.str[l] = '\0';
	return in;
}


String String::operator () (int index1, int index2){
	//char s[index2 - index1 + 2];
	int i;
	const int j = index2 - index1 + 1;
	const int k = j + 1;
	char *s = new char[k];
	//char s[k];
	for(i = 0; i < j; i++){
		s[i] = str[i + index1];
	}
	s[j] = '\0';
	String tempStr;
	tempStr.str = s;
	//delete [] s;			//delete 会输出乱七八糟的东西，  为什么不能立即delete [], 
	return tempStr;


}

void main()
{
	String s1, s2,s3;
	cout<<"请输入s2: ";
	cin>>s2;
	cout<<"请输入s3: ";
	cin>>s3;
	//cout<<"s2: "<<s2<<"\n";
	s1 = s2 + s3;
	cout<<"s1 = s2 + s3, s1 = ";
	cout<<s1<<"\n";
	cout<<"比较s1 s3 的大小\n";
	if(s1 < s3){
		cout<<"s1 < s3\n";
	}else{
		cout<<"s1 > s3\n";
	}
	int a, b;
	cout<<"请输入s1中的两个索引\n";
	int l = strlen(s1.str);
	while(1){
		cin>>a>>b;
		if((a>=0) && (a<b) && (b<l-1))
			break;
		cout<<"重新输入\n";
	}
	String s4;
	s4 = s1(a, b);
	cout<<"子串："<<s4<<endl;

}