#include<iostream.h>
#include<stdlib.h>
struct Node
{
	int val;
	Node *pNext;
};
class IntSet 
{
	Node * first;//指向链表的头结点
public:
	IntSet()
	{
		first=0;
	}
	IntSet(int count);
	IntSet(IntSet &old);
	~IntSet();
	bool add(int num);//增加元素
	bool del(int num);//删除元素
	bool search(int num);//查找元素
	void show();
	IntSet operator+(IntSet & other);//并
	IntSet operator-(IntSet & other);//差
	IntSet operator*(IntSet & other);//交
	IntSet & operator=(IntSet & other);//赋值,作为左值需要返回引用类型!
	IntSet operator-=(IntSet & other);
};

IntSet::IntSet(IntSet &old)
{
	Node *p=old.first,*tail;
	if(!p)	//p == 0;
	{
		first=0;
	}
	else
	{
		Node * now=new Node;
		now->val=p->val;
		first=now;
		tail=now;
		p=p->pNext;
		while(p)	//p指向的节点不为空
		{
			Node * now=new Node;
			now->val = p->val;
			tail->pNext=now;
			tail=now;
			p=p->pNext;
		}
		tail->pNext=0;
	}
}

IntSet::IntSet(int count)	//形参是节点数
{
	Node *head=0,*tail=0;
	cout<<"Set new Link with "<<count<<" note!"<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"Input the value of the node:";
		Node * now=new Node;
		if(now)
			cin>>now->val;
		if(!head) 		//head == 0时
			head=now;
		else
			tail->pNext=now;
		tail=now;
	}
	if(count!=0)		//count 不为0时
		tail->pNext=0;
	first=head;
}

IntSet::~IntSet()
{
	Node* p=first,*pre;
	while(p)
	{
		pre=p;
		p=p->pNext;
		delete pre;
	}
}

bool IntSet::add(int num)
{
    Node* tail=first;
	if(first)
	{ 
		while(tail)
		{
			if(tail->val==num)
			{
				cout<<"The num is in the set!"<<endl;
				return 0;
			}
			tail=tail->pNext;
		}
	}
	Node *now=new Node;
	now->val=num;
	if(!now)
	{	  
		cout<<"Error new node when add one!"<<endl;	
		return 0;
	}
	if(!first)   
		first=now;
	else
	{
		tail=first;
		while( tail->pNext)
			tail=tail->pNext;
		tail->pNext =now;
	} 
	tail=now;
	tail->pNext=0;
	return 1;
}

bool IntSet::search(int num)
{
	if(!first)
	{
		cout<<"Empty set,delete no node!"<<endl;
		return 0;
	}
    Node* p=first,*pre=first;
    while(num!=(p->val) && p->pNext  )
	{ 	
	    p=p->pNext;
	}
	if(num==(p->val)) return 1;
	else return 0;
}
bool IntSet::del(int num)
{
	if(!first)
	{
		cout<<"Empty set,delete no node!"<<endl;
		return 0;
	}
	Node* p=first,*pre=first;
    while(num!=(p->val) && p->pNext)
	{ 	pre=p;
	    p=p->pNext;
	}
    if(num==p->val)
	{
		if(p==first)	
			first=p->pNext ;
		else
			pre->pNext =p->pNext;
		cout<<"Delete "<<num<<"!"<<endl;
		return 1;
	}
	else 
		cout<<"the number to be delted is not in the set!";
	return 0;
}

void IntSet::show()
{
	cout<<"show all node in the link:"<<endl;
	int i=0;
	Node *tail=first;
	while(tail)
	{
		i++;
		cout<<i<<") "<<tail->val <<endl;
		tail=tail->pNext;
	}
}

IntSet IntSet::operator+(IntSet & other)
{
	IntSet temp(other);
	Node *p=first;
	while(p)
	{
		temp.add(p->val);
		p=p->pNext ;
	}
	return temp;
}

IntSet IntSet::operator-(IntSet & other)
{
	IntSet temp(*this);
	Node *q=other.first;
	while(q)
	{
		if(search(q->val ))
			temp.del(q->val);
		q=q->pNext;
	}
	if(!first) 
		cout<<"Empty!"<<endl;
	return temp;
}
IntSet IntSet::operator-=(IntSet & other)
{
	Node *q=other.first;
	while(q)
	{
		if(search(q->val ))
			del(q->val);
		q=q->pNext;
	}
	if(!first) 
		cout<<"Empty!"<<endl;
	return *this;
}

IntSet IntSet::operator* (IntSet & other)//交集
{ 
	IntSet temp(*this);
	Node *p=first, *q=other.first;
	while(p)
	{
		if(!other.search(p->val ))
			temp.del(p->val);
		p=p->pNext;
	}
	if(!temp.first) 
		cout<<"Empty!"<<endl;
	return temp;
}
IntSet & IntSet::operator = (IntSet &old) 
{
	Node *p1=first,*pre,*p2=old.first;
	while(p1 && p2)
	{
		p1->val=p2->val;
		pre=p1;
		p1=p1->pNext;
		p2=p2->pNext;
	}
	if(p2)//old链表比较长
	{
		while(p2)
		{
			add(p2->val);
			p2=p2->pNext;
		}
	}
	if(p1)//当前链表比较长
	{
		pre->pNext=0;
		//删除多余的链表
		Node *pre1;
		while(p1)
		{
			pre1=p1;
			p1=p1->pNext;
			delete pre1;
		}
	}
	return *this;
}
void main()
{   
	IntSet A;
    A.add(3);
	A.add(5);
	A.add(1);
	cout<<"Set A"<<endl;
	A.show();
    A.del(0);
	cout<<"Set A- "<<endl;
    A.show();
	IntSet B;
	B.add(5);
    B.add(4);
	cout<<"Set B"<<endl;
	B.show();
    cout<<"Set A+B"<<endl;//并
    (A+B).show();   
	cout<<"Set A-B"<<endl;//差
	(A-B).show();
	cout<<"Set A*B"<<endl;//交
	(A*B).show();
	IntSet C=A;
	cout<<"Set C"<<endl;
	C.show();
	A-=B;// -=
	A.show();
}