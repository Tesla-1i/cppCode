#include<iostream>
#include<cmath>
#include<ostream>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
#define pow(a) (a*a)
#define mem(arr,a) memset(arr,a,sizeof(arr))
#define N 100
#define LL long int//个别编译器可能不识别long long int,可改成long int
class String;
ostream& operator <<(ostream&, String&);
istream& operator >>(istream&in, String&a);
class String{
public:
    string s;
    int m;
public:
    String operator()(int,int);
    friend ostream&operator<<(ostream&, String&);
    friend istream&operator>>(istream&in, String&a);
    String operator+(String &);
    bool operator<(String &);
};
String String::operator()(int a, int b){
    String temp;
    temp.s.assign(s, a, b);
    return temp;
}
String String::operator+(String &a){
    String temp;
    temp.s = s + a.s;
    return temp;
}
istream&operator>>(istream&in, String&a){
    in >> a.s;
    return in;
}
bool String::operator<(String&a){
    return s < a.s;
}
ostream& operator<<(ostream&out, String &a){
    out << a.s << endl;
    return out;
}

int main(){
    String s1, s2;
    cin >> s1;
    cin >> s2;
    String s3 = s1 + s2;
    cout << s3;
    cout << s1(1, 3) << endl;
    if (s1 < s2)cout << "s2" << endl;
    else cout << "s1" << endl;
	return 0;
}
