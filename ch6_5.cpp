#include<iostream>
using namespace std;
class Person{                    //Person类定义
private:
	char name[16];               //姓名字符串
	int money;			         //持有钱数
protected:	
	int pay(int m);              //支付m钱 
public:	
	Person(char *n,int m);       //构造函数
	char * getName();            //返回name
	void receive(int m);         //接收m钱
	void print();                //输出函数
	virtual void spend(int m);   //消费函数
	virtual Person * getPayer()=0;       //返回付款者
};

class Son;                       //Son类声明

class Father:public Person{      //Father类定义
public:
	Father(char *n,int m);       //构造函数
	int manage(Person *role,int m); //授权管理
    void spend(int m);           //消费函数
    Person * getPayer();       //返回付款者
};

class Son:public Person{         //Son类定义
private:
	Father * father;             //父亲
public:
	Son(Father *p,char *n,int m);//构造函数
	Father * getFather();        //返回Father
    void spend(int m);           //消费函数
    Person * getPayer();       //返回付款者
};

class Mother:public Person{          //Mother类定义
private:
	Father * husband;               //丈夫
public:
	Mother(Father *p,char *n,int m);  //构造函数
	Father * getHusband();          //返回Father（丈夫）
    void spend(int m);            //消费函数
    Person * getPayer();       //返回付款者
};

//Person付钱函数
int Person::pay(int m){
	if(m<=0)		//支付金额小于等于0，支付0元
		return 0;
	if(money>=m){	//支付金额小于等于持有钱数，支付m元
		money=money-m;
		return m;
	}else return 0;	//支付金额大于持有钱数，支付0元
}
//返回name
char * Person::getName(){
	return name;
}
//Person类构造函数
Person::Person(char *n,int m){
	strcpy(name,n);
	money=m;
}
//Person类收钱函数
void Person::receive(int m){
	if(m>0)		     //接收金额小于0，放弃接收
		money=money+m;
}
//Person类输出函数
void Person::print(){
	cout<<"name:"<<name<<"  money:"<<money<<endl;
}
//Person类销费函数
void Person::spend(int m){
 	 cout<<getName()<<"某种花费：";
	 cout<<pay(m)<<endl;
}
//Son类构造函数
Son::Son(Father *p,char *n,int m):Person(n,m){
	father=p;
}
//返回Father
Father * Son::getFather(){
	return father;
}
//Son类销费函数
void Son::spend(int m){
 	 cout<<getName()<<"交学费：";
	 cout<<pay(m)<<endl;
}
//Son类返回付款者
Person* Son::getPayer(){
	return father;
}
//Father类构造函数
Father::Father(char *n,int m):Person(n,m){}
//授权管理函数
int Father::manage(Person *role,int m){ //role支付对象，m支付金额
	if(strcmp(role->getPayer()->getName(),getName())==0) //支付对象的父亲是自己
		return pay(m);
	else
		return 0;
}
//Father类销费函数
void Father::spend(int m){
 	 cout<<getName()<<"买车：";
	 cout<<pay(m)<<endl;
}
//Father类返回付款者
Person* Father::getPayer(){
	return this;
}
//Mother类构造函数
Mother::Mother(Father *p,char *n,int m):Person(n,m){
	husband=p;
}
//返回Father
Father * Mother::getHusband(){
	return husband;
}
//Mother类销费函数
void Mother::spend(int m){
 	 cout<<getName()<<"买菜：";
	 cout<<pay(m)<<endl;
}
//Mother类返回付款者
Person* Mother::getPayer(){
	return husband;
}


//主函数
int main(){
    Father f1("李四",10000);
	Son s1(&f1,"李小四",100);
	Mother m1(&f1,"李蕾",100);
	s1.receive(f1.manage(&s1,1000));
    m1.receive(f1.manage(&m1,1000));
	s1.print();
	m1.print();
	cout<<"-----------------------\n";
	//两个人消费，运行结果不同
	Person * p[2];
	p[0]=&f1;
	p[1]=&s1;
	p[0]->spend(8000);
	p[1]->spend(600);
	p[0]->print();
	p[1]->print();
	return 0;
}