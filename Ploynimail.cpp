#include<iostream>
#include<cmath>
#include<ostream>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
//#define pow(a) (a*a)
#define mem(arr,a) memset(arr,a,sizeof(arr))
#define N 100
#define LL long int//个别编译器可能不识别long long int,可改成long int
class node{
public:
    int n, a;
};

class pol{
    node*s;
public:
    void set(int a, int n);
    pol();
    ~pol();
    LL get(int x);
    void show();
    pol operator+(pol&);
    pol operator-(pol&);
    pol operator*(pol&);
    pol&operator=(pol&);
};
pol::pol(){
    s = new node[N];
    for (int i = 0; i < N; i++)s[i].a = 0, s[i].n = 0;
}
pol::~pol(){
    cout << "delete" << endl;
}
void pol::set(int a, int n){
    s[n].a = a;
    s[n].n = n;
}
void pol::show(){
    bool flag = false;
    for (int i = 0; i < N; i++){
        if (s[i].a != 0){
            if (!flag)
                cout << s[i].a << "x^" << s[i].n, flag = true;
            else{
                cout << "+" << s[i].a << "x^" << s[i].n;
            }
        }
    }
    cout << endl;
}
pol pol::operator+(pol&a){
    pol temp;
    for (int i = 0; i < N; i++){
        if (a.s[i].a){
            temp.s[i].a = a.s[i].a + s[i].a;
            temp.s[i].n = a.s[i].n;
        }
    }
    return temp;
}
pol pol::operator-(pol&a){
    pol temp;
    for (int i = 0; i < N; i++){
        if (a.s[i].a){
            temp.s[i].a = s[i].a - a.s[i].a;
        }
    }
    return temp;
}
pol pol::operator*(pol&a){
    pol temp;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (s[i].a&&a.s[j].a){
                temp.s[i + j].a += s[i].a*a.s[j].a;
                temp.s[i + j].n = i + j;
            }
        }
    }
    return temp;
}
pol&pol::operator=(pol&a){
    for (int i = 0; i < N; i++){
        s[i].a = a.s[i].a;
        s[i].n = a.s[i].n;
    }
    return *this;
}
LL pol::get(int x){
    LL sum = 0;
    for (int i = 0; i < N; i++){
        sum += s[i].a*pow(x, s[i].n);
    }
    return sum;
}
int main(){
    pol s1, s2;
    for (int i = 0; i < 3; i++){
        s1.set(i, i);
        s2.set(i, 3 - i);
    }
    s1.show();
    s2.show();
    pol s = s1 + s2;
    s.show();
    s = s1*s2;
    s.show();
	return 0;
}