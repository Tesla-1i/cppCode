#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class PDRule  
{
public:
	const int R;  //ͬʱ�����Ľ���R
	const int S;  //�����ѵ���ʧS
	const int T;  //���ѵ�����T
	const int P;  //ͬʱ���ѵĳͷ�P
	PDRule(int R,int S,int T,int P):R(R),S(S),T(T),P(P){}
	virtual ~PDRule(){}
	int calculatePayoff(int stra1,int stra2);//�����������벩���ߵĲ��ԣ������һ�������ߵ�����
};

int PDRule::calculatePayoff(int stra1,int stra2)
{  //��������Ϊ1�����Ѳ���Ϊ0
   if( stra1==1 && stra2==1 ) return R;       
   else if ( stra1==1 && stra2==0 ) return S;
   else if ( stra1==0 && stra2==1 ) return T;
   else return P;
}

class Player  
{
protected:
	int oppStra;              // ������һ�ֲ���
	int id;                   // ѧ�ź�4λ 
public:
	Player(){
		id = 1;               // ѧ�ź�4λ 
		oppStra=-1;           // ��ʼû�ж��ֲ��ԣ�����Ϊ-1 
	}     
	virtual ~Player(){}
	virtual int nextStra();   // ���ֲ��õĲ���
	virtual void setOppStra(int oppS);// ���ö�����һ�ֲ���
	virtual void reset(){oppStra=-1;} // �ָ�����ʼ����
	virtual int getID() {return id;} 
};

void Player::setOppStra(int oppS)
{
	oppStra = oppS;
}

int Player::nextStra()
{
    return 1;   // ���ǲ��ú������� 
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

class Player2326: public Player    //��ѧ�ź���λΪ���������������PlayXXXX
{
private:
  
    /*�ڴ˴��Զ���ע�͵���ʽ˵������ӵ����ݵ���;
	* oppHistory���ڱ����ȥ2�β��Ķ��ֵĲ���
	*/
	//int oppHistory[2];
	int oppHistory[20];
public :
	//�����ṩ�޲ι��캯��
    Player2326()
	{   
		id = 2326;            //����id
		for(int i = 0; i < 20; i++){
			oppHistory[i] = -1;
		} 
		//oppHistory[0]=-1;     //��ʼ�����ֲ�����ʷ
		//oppHistory[1]=-1;
	}   
	
	/*�ڴ˴��Զ���ע�͵���ʽ˵�����ĵ��߼�
	* ��ȥ2�ζ��ֲ���������Ϊ���ѣ�0,0��,���ֱ��Ѷ��֣��������
	*/
	int nextStra()    //���¶���ú����������Player��������߼�����
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
    
	/*���±���Ĳ�����Ϣ
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

	void reset()   // �ָ�����ʼ����
	{
		Player::reset();
		for(int i = 0; i < 20; i++){
			oppHistory[i] = -1;
		}
        //oppHistory[0]=-1;     
		//oppHistory[1]=-1;       //������ӵ����ݽ���reset
	} 
}; 

class Player5678: public Player    //��ѧ�ź���λΪ5678
{

    //����������
    int oppHistory[100];
public :
	//�����ṩ�޲ι��캯��
    Player5678()
	{   
		id = 5678;            //����id
		for(int i = 0; i < 5; i++){
			oppHistory[i] = -1;
		} 
	}
	/*
	* //ÿ�ֶ����Ѷ���
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
		//���
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


	void reset()   // �ָ�����ʼ����
	{
		Player::reset();
		for(int i = 0; i < 5; i++){
			oppHistory[i] = -1;
		}
        //oppHistory[0]=-1;     
		//oppHistory[1]=-1;       //������ӵ����ݽ���reset
	} 
}; 

int main()
{
	Player2326 player2326;   //���������1 
	Player5678 player5678;   //���������2 
	Player * players [2] ;   //�����в������ռ����������飨�����ռ��� 
	players [0] = & player2326 ;
	players [1] = & player5678 ;
	int payoffs[2]={0,0};
	
	PDRule pdr(3,0,5,1);  //int R,int S,int T,int P
	
	int maxTurn = 100;  //��ֵ�������ʱ������100-1000�е�����ֵ 
	
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

