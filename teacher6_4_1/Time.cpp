#include <iostream>
#include "Time.h"
using namespace std;

ostream& operator <<(ostream& out, Time& t){
	int h = t.getH();
	int m = t.getM();
	int s = t.getS();
	cout<<h<<" : "<<m<<" : "<<s<<endl;
	return out;
}

Time operator + (int s, Time& t){
	int h1 = t.getH();
	int m1 = t.getM();
	int s1 = t.getS();
	//加130s的情况
	int m2 = s / 60;
	m1 = m1 + m2;
	int s2 = s % 60;
	s1 = s1 + s2;
	//s1 += s;
	if(s1 > 59){
		s1 = s1 - 60;
		m1 = m1 + 1;
		if(m1 > 59){
			m1 = m1 - 60;
			h1 = h1 + 1;
			if(h1 > 23)
				h1 = 0;
		}
	} 
	return Time(h1, m1, s1);
}

Time Time::operator +(int s){
	//int h1 = t.getH();
	//int m1 = t.getM();
	//int s1 = t.getS();
	int h1 = hour, m1 = minute, s1 = second;
	
	//
	int m2 = s / 60;
	m1 = m1 + m2;
	int s2 = s % 60;
	s1 = s1 + s2;
	//s1 += s;
	if(s1 > 59){
		s1 = s1 - 60;
		m1 = m1 + 1;
		if(m1 > 59){
			m1 = m1 - 60;
			h1 = h1 + 1;
			if(h1 > 23)
				h1 = 0;
		}
	}
	return Time(h1, m1, s1); 
}

Time Time::operator -(int s){
	//int h1 = t.getH();
	//int m1 = t.getM();
	//int s1 = t.getS();
	//
	int h1 = hour, m1 = minute, s1 = second;
	int m2 = s / 60;
	int s2 = s % 60;
	//
	if(s1 < s2){
		if(m1 < (m2 + 1)){
			if(h1 < 1){
				h1 = 23;
				m1 = m1 + 60 - m2 - 1;
				s1 = s1 + 60 - s2;
				return Time(h1, m1, s1);
				//cout<<"error\n";
				//return Time(0, 0, 0);
			}
			else{
				h1 = h1 - 1;
				m1 = m1 + 60 - m2 - 1;
				s1 = s1 + 60 - s2;
				return Time(h1, m1, s1);
			}
		}
		else{
			s1 = s1 + 60 - s2;
			m1 = m1 - 1 - m2;
			return Time(h1, m1, s1);	
		}
	}
	else{
		if(m1 >= m2){
			s1 = s1 - s2;
			m1 = m1 - m2;
			return Time(h1, m1, s1);
		}
		else{
			if(hour > 0){
				h1--;
				m1 = m1 + 60 - m2;
				s1 = s1 - s2;
				return Time(h1, m1, s1); 
			}
			else{
				h1 = 23;
				m1 = m1 + 60 -m2;
				s1 = s1 - s2;
				return Time(h1, m1, s1);
			}
		}
	}
}

Time& Time::operator ++(){
	if(second < 59){
		second++;
	}
	else{
		if(minute < 59){
			second = 0;
			minute++;
		}
		else{
			if(hour < 23){
				hour++;
				minute = 0;
				second = 0;
			}
			else{
				hour=0;minute=0; second= 0;
			}
		}
	}
	return *this;
}

Time& Time::operator --(){
	if(second > 0){
		second--;
	}
	else{
		if(minute > 0){
			minute--;
			second = second + 60 -1;
		}
		else{
			if(hour > 0){
				hour--;
				second = 59;
				minute = 59;
			}
			else{
				hour = 23;
				second = 59;
				minute = 59;
				//cout<<"error\n";
			}
		}
	}
	return *this;
}