#include <iostream>
using namespace std;

#ifndef TIME
#define TIME

//重载友元函数要在类前声明类和友元函数！

class Time;
ostream& operator <<(ostream& out, Time& t);	//全是引用 &&&&&&&&&&&&&&&
Time operator + (int s, Time& t);

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	int getH(){ return hour; }
	int getM(){ return minute; }
	int getS(){ return second; }
	Time(int h = 0, int m = 0, int s = 0):hour(h), minute(m), second(s){  }
	~Time(){}
	friend ostream& operator <<(ostream& out, Time& t);
	friend Time operator + (int s, Time& t);
	//friend Time operator - (int s, Time& t);
	Time operator +(int s);
	Time operator -(int s);
	//前置++
	Time& operator ++();
	Time& operator --();
};

#endif