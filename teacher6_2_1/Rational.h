#include<iostream>
using namespace std;

#ifndef RATIONAL
#define RATIONAL


class Rational;
ostream& operator <<(ostream& out, Rational &ra);

class Rational
{
private:
	int nu;
	int de;
public:
	int getNu(){return nu;}
	int getDe(){return de;}
	Rational(int n = 1, int d = 1){
		nu = n;
		de = d;
	}
	~Rational(){}
	//void simple();
	Rational operator +(Rational &ra);
	Rational operator -(Rational &ra);
	Rational operator *(Rational &ra);
	Rational operator /(Rational &ra);
	bool operator >(Rational &ra);
	bool operator <(Rational &ra);
	bool operator ==(Rational &ra);
	friend ostream& operator <<(ostream& out, Rational &ra);

};

#endif