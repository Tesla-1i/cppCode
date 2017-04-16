#include <iostream>
#include "Rational.h"
using namespace std;

ostream& operator <<(ostream& out, Rational &ra){
	int nu = ra.getNu();
	int de = ra.getDe();
	//cout<<nu<<" / "<<de<<endl;
	if(nu == 0){
		out<<0;	//? 0 ? "0"
		return out;
	}
	else if(nu == de){
		out<<1;
		return out;
	}
	else{
		int temp = de;
		int n1 = nu, m1 = de;
	//求最大公约数
		while(temp != 0){
			temp = nu % de;
			nu = de;
			de = temp;
		}
		int gcd = nu;
		de = m1 / gcd;
		nu = n1 / gcd;
		////
		out<<nu<<"/"<<de;
		return out;
	}
	//out<<nu<<"/"<<de;
	//return out;
}

/*void Rational::simple(){
	int temp = de;
	int n1 = nu, m1 = de;
	//求最大公约数
	while(temp != 0){
		temp = nu % de;
		nu = de;
		de = temp;
	}
	int gcd = n;
	de = m1 / gcd;
	nu = n1 / gcd;
	//cout<<n<<" "<<m<<"\n";
}
*/
Rational Rational::operator +(Rational &ra){
	int m1, n1, n2, m2;
	n2 = ra.getNu();
	m2 = ra.getDe();
	m1 = de * m2;
	n1 = nu * m2 + n2 * de;
	//cout<<n1<<"+"<<m1<<endl;
	//cout<<m1<<" "<<n1<<endl;
	Rational reational4(n1, m1);
	//cout<<reational4.getM<<endl;
	return reational4;
}

Rational Rational::operator -(Rational &ra){
	int m1, n1, n2, m2;
	n2 = ra.getNu();
	m2 = ra.getDe();
	m1 = de * m2;
	n1 = nu * m2 - n2 * de;
	Rational reational(n1, m1);
	return reational;
}

Rational Rational::operator /(Rational &ra){
	int nu1, de1, nu2, de2;
	nu1 = ra.getNu();
	de1 = ra.getDe();
	nu2 = nu * de1;
	de2 = de * nu1;
	return Rational(nu2, de2);
}

Rational Rational::operator *(Rational &ra){
	int nu1, de1, nu2, de2;
	nu1 = ra.getNu();
	de1 = ra.getDe();
	nu2 = nu1 * nu;
	de2 = de1 * de;
	return Rational(nu2, de2);
}

bool Rational::operator > (Rational &ra){
	int nu1 = ra.getNu();
	int de1 = ra.getDe();
	if(nu * de1 > nu1 * de)
		return true;
	else
		return false;
}

bool Rational::operator < (Rational &ra){
	int nu1 = ra.getNu();
	int de1 = ra.getDe();
	if(nu * de1 < nu1 * de)
		return true;
	else
		return false;
}

bool Rational::operator == (Rational &ra){
	int nu1 = ra.getNu();
	int de1 = ra.getDe();
	if(nu * de1 == nu1 * de)
		return true;
	else
		return false;
}

