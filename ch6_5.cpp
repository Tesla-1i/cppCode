#include<iostream>
using namespace std;
class Person{                    //Person�ඨ��
private:
	char name[16];               //�����ַ���
	int money;			         //����Ǯ��
protected:	
	int pay(int m);              //֧��mǮ 
public:	
	Person(char *n,int m);       //���캯��
	char * getName();            //����name
	void receive(int m);         //����mǮ
	void print();                //�������
	virtual void spend(int m);   //���Ѻ���
	virtual Person * getPayer()=0;       //���ظ�����
};

class Son;                       //Son������

class Father:public Person{      //Father�ඨ��
public:
	Father(char *n,int m);       //���캯��
	int manage(Person *role,int m); //��Ȩ����
    void spend(int m);           //���Ѻ���
    Person * getPayer();       //���ظ�����
};

class Son:public Person{         //Son�ඨ��
private:
	Father * father;             //����
public:
	Son(Father *p,char *n,int m);//���캯��
	Father * getFather();        //����Father
    void spend(int m);           //���Ѻ���
    Person * getPayer();       //���ظ�����
};

class Mother:public Person{          //Mother�ඨ��
private:
	Father * husband;               //�ɷ�
public:
	Mother(Father *p,char *n,int m);  //���캯��
	Father * getHusband();          //����Father���ɷ�
    void spend(int m);            //���Ѻ���
    Person * getPayer();       //���ظ�����
};

//Person��Ǯ����
int Person::pay(int m){
	if(m<=0)		//֧�����С�ڵ���0��֧��0Ԫ
		return 0;
	if(money>=m){	//֧�����С�ڵ��ڳ���Ǯ����֧��mԪ
		money=money-m;
		return m;
	}else return 0;	//֧�������ڳ���Ǯ����֧��0Ԫ
}
//����name
char * Person::getName(){
	return name;
}
//Person�๹�캯��
Person::Person(char *n,int m){
	strcpy(name,n);
	money=m;
}
//Person����Ǯ����
void Person::receive(int m){
	if(m>0)		     //���ս��С��0����������
		money=money+m;
}
//Person���������
void Person::print(){
	cout<<"name:"<<name<<"  money:"<<money<<endl;
}
//Person�����Ѻ���
void Person::spend(int m){
 	 cout<<getName()<<"ĳ�ֻ��ѣ�";
	 cout<<pay(m)<<endl;
}
//Son�๹�캯��
Son::Son(Father *p,char *n,int m):Person(n,m){
	father=p;
}
//����Father
Father * Son::getFather(){
	return father;
}
//Son�����Ѻ���
void Son::spend(int m){
 	 cout<<getName()<<"��ѧ�ѣ�";
	 cout<<pay(m)<<endl;
}
//Son�෵�ظ�����
Person* Son::getPayer(){
	return father;
}
//Father�๹�캯��
Father::Father(char *n,int m):Person(n,m){}
//��Ȩ������
int Father::manage(Person *role,int m){ //role֧������m֧�����
	if(strcmp(role->getPayer()->getName(),getName())==0) //֧������ĸ������Լ�
		return pay(m);
	else
		return 0;
}
//Father�����Ѻ���
void Father::spend(int m){
 	 cout<<getName()<<"�򳵣�";
	 cout<<pay(m)<<endl;
}
//Father�෵�ظ�����
Person* Father::getPayer(){
	return this;
}
//Mother�๹�캯��
Mother::Mother(Father *p,char *n,int m):Person(n,m){
	husband=p;
}
//����Father
Father * Mother::getHusband(){
	return husband;
}
//Mother�����Ѻ���
void Mother::spend(int m){
 	 cout<<getName()<<"��ˣ�";
	 cout<<pay(m)<<endl;
}
//Mother�෵�ظ�����
Person* Mother::getPayer(){
	return husband;
}


//������
int main(){
    Father f1("����",10000);
	Son s1(&f1,"��С��",100);
	Mother m1(&f1,"����",100);
	s1.receive(f1.manage(&s1,1000));
    m1.receive(f1.manage(&m1,1000));
	s1.print();
	m1.print();
	cout<<"-----------------------\n";
	//���������ѣ����н����ͬ
	Person * p[2];
	p[0]=&f1;
	p[1]=&s1;
	p[0]->spend(8000);
	p[1]->spend(600);
	p[0]->print();
	p[1]->print();
	return 0;
}