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
