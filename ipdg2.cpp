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
