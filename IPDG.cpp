#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class PDRule  
{
public:
	const int R;  //同时合作的奖励R
	const int S;  //被背叛的损失S
	const int T;  //背叛的收益T
	const int P;  //同时背叛的惩罚P
	PDRule(int R,int S,int T,int P):R(R),S(S),T(T),P(P){}
	virtual ~PDRule(){}
	int calculatePayoff(int stra1,int stra2);//根据两个参与博弈者的策略，计算第一个博弈者的收益
};

int PDRule::calculatePayoff(int stra1,int stra2)
{  //合作策略为1，背叛策略为0
   if( stra1==1 && stra2==1 ) return R;       
   else if ( stra1==1 && stra2==0 ) return S;
   else if ( stra1==0 && stra2==1 ) return T;
   else return P;
}

class Player  
{
protected:
	int oppStra;              // 对手上一轮策略
	int id;                   // 学号后4位 
public:
	Player(){
		id = 1;               // 学号后4位 
		oppStra=-1;           // 初始没有对手策略，设置为-1 
	}     
	virtual ~Player(){}
	virtual int nextStra();   // 本轮采用的策略
	virtual void setOppStra(int oppS);// 设置对手上一轮策略
	virtual void reset(){oppStra=-1;} // 恢复到初始设置
	virtual int getID() {return id;} 
};

void Player::setOppStra(int oppS)
{
	oppStra = oppS;
}

int Player::nextStra()
{
    return 1;   // 总是采用合作策略 
}

class IterationPDG  
{
private:
	Player * player1;
	Player * player2;
	int maxTurn;
	int payoff1;
	int payoff2;
	PDRule pdr;
public:
	IterationPDG(int maxTurn, Player * p1,Player * p2, PDRule & pdr): maxTurn(maxTurn),pdr(pdr),player1(p1),player2(p2)
	  { 
		  payoff1 = 0;
          payoff2 = 0;	  
	  }
	  virtual ~IterationPDG(){}
	void start();
	int getPayoff1(){return payoff1;}
    int getPayoff2(){return payoff2;}
};

void IterationPDG::start()
{
    player1->reset();
	player2->reset();
  for(int i=0;i<maxTurn;i++){
	  int s1 = player1->nextStra();
      int s2 = player2->nextStra();
      payoff1 += pdr.calculatePayoff(s1,s2);
	  payoff2 += pdr.calculatePayoff(s2,s1);
	  player1->setOppStra(s2);
	  player2->setOppStra(s1);
  }
}

class Player2326: public Player    //用学号后四位为你的类命名，形如PlayXXXX
{
private:
  
    /*在此处以多行注释的形式说明你添加的数据的用途
	* oppHistory用于保存过去2次博弈对手的策略
	*/
	//int oppHistory[2];
	int oppHistory[20];
public :
	//必须提供无参构造函数
    Player2326()
	{   
		id = 2326;            //命名id
		for(int i = 0; i < 20; i++){
			oppHistory[i] = -1;
		} 
		//oppHistory[0]=-1;     //初始化对手策略历史
		//oppHistory[1]=-1;
	}   
	
	/*在此处以多行注释的形式说明博弈的逻辑
	* 过去2次对手策略如连续为背叛（0,0）,则本轮背叛对手，否则合作
	*/
	int nextStra()    //重新定义该函数，让你的Player按照你的逻辑博弈
	{ 

		int i, sum = 0;
		for(i = 0; i < 5; i++){
			if(oppHistory[i] == 0)
				sum++;
		}
		if(sum >= 3 || sum == 0)
			return 0;
		else{
			for(i = 5; i < 10; i++){
				if(oppHistory[i] == 0)
					sum++;
			}
			if(sum >= 4 || sum<= 1)
				return 0;
			else{
				for(i = 10; i < 20; i++){
					if(oppHistory[i] == 0)
						sum++;
				}
				if(sum >= 6 || sum <= 2)
					return 0;
				else 
					return 1;
			}
		}
	  //if ( oppHistory[0] == 0 && oppHistory[1] == 0 ) return 0 ;
	  //else return 1 ;
	}
    
	/*更新保存的博弈信息
	*/
	void setOppStra(int oppS)
	{
		Player::setOppStra(oppS);

		for(int i = 18; i >= 0; i--){
			oppHistory[i+1] = oppHistory[i];
		}
		oppHistory[0] = oppS;
		//oppHistory[0] = oppHistory[1];
		//oppHistory[1] = oppS;

	}

	void reset()   // 恢复到初始设置
	{
		Player::reset();
		for(int i = 0; i < 20; i++){
			oppHistory[i] = -1;
		}
        //oppHistory[0]=-1;     
		//oppHistory[1]=-1;       //对新添加的数据进行reset
	} 
}; 

class Player5678: public Player    //用学号后四位为5678
{

    //无新增数据
    int oppHistory[100];
public :
	//必须提供无参构造函数
    Player5678()
	{   
		id = 5678;            //命名id
		for(int i = 0; i < 5; i++){
			oppHistory[i] = -1;
		} 
	}
	/*
	* //每轮都背叛对手
	*/
	int nextStra()    
	{ 

		int i, sum = 0;
		for(i = 0; i < 5; i++){
			if(oppHistory[i] == 0)
				sum++;
		}
		if(sum >= 2)
			return 0;
		else{
				return 1;
			}
		//return 0;
		//随机
	   //srand((int)time(NULL));
	   //cout<<rand()*2/RAND_MAX<<"\n";
	   //return rand()*2/RAND_MAX;
	}
	void setOppStra(int oppS)
	{
		Player::setOppStra(oppS);

		for(int i = 3; i >= 0; i--){
			oppHistory[i+1] = oppHistory[i];
		}
		oppHistory[0] = oppS;
		//oppHistory[0] = oppHistory[1];
		//oppHistory[1] = oppS;

	}


	void reset()   // 恢复到初始设置
	{
		Player::reset();
		for(int i = 0; i < 5; i++){
			oppHistory[i] = -1;
		}
        //oppHistory[0]=-1;     
		//oppHistory[1]=-1;       //对新添加的数据进行reset
	} 
}; 

int main()
{
	Player2326 player2326;   //派生类对象1 
	Player5678 player5678;   //派生类对象2 
	Player * players [2] ;   //将所有博弈者收集到基类数组（异类收集） 
	players [0] = & player2326 ;
	players [1] = & player5678 ;
	int payoffs[2]={0,0};
	
	PDRule pdr(3,0,5,1);  //int R,int S,int T,int P
	
	int maxTurn = 100;  //该值在最后博弈时可能是100-1000中的任意值 
	
	for( int i = 0 ; i < 2 ; i++) {
		for( int j = 0 ; j < 2 ; j++){
			if ( i<j ){
			IterationPDG ipdg( maxTurn, players[i], players[j], pdr);
			ipdg.start();
			payoffs[i] += ipdg.getPayoff1();
			payoffs[j] += ipdg.getPayoff2();
			}
		}
	}
	
	for( int j = 0 ; j < 2 ; j++) {
	cout<<players[j]->getID()<<" : "<<payoffs[j]<<endl;
	}
	return 0;
}

