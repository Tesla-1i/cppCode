/* ����һ��������Set�������100�����ظ���������ʵ�ּ��ϵ����²�����
1������ĳ������Ԫ��ʱ����֤������û���ظ�Ԫ�أ�
   ɾ��ָ����Ԫ�أ����Ҹ�Ԫ���ڼ�������Ӽ�����ɾ����Ԫ�أ�
2�������������+����ʵ���������϶���ĺϲ�������
   �����������*�������������϶���Ľ���������Set s, s1, s2; s = s1+s2; s = s1* s2;
 3�����ظ�ֵ�����=�͸��ϸ�ֵ�����-= �� ʵ���������϶���ĸ�ֵ������������
 	����Set s1��s2��s1 = s2;   s1-=s2; ����S1��ȥ��S2�д��ڵ�Ԫ�ء�
*/

    #include<iostream>  
    #include<cstring>  
    using namespace std;  

    class Set;
    ostream& operator << (ostream& x , Set& p_set);

    class Set  
    {  
    public:  
        Set(int p_size = 1);  
        Set(const Set& p_Set);  
        ~Set();  
        int getLength()  
        {  
            return length ;  
        }  
        int *getData(){
        	return data;
        }
        void addItem(int p_item);  
        void delItem(int p_item);  
        Set operator + (Set& p_set);  
        Set operator * (Set& p_set);  
        Set& operator = (const Set& p_set);  //������ֵ����������;
        Set& operator -= (Set& p_set);  
        friend ostream& operator << (ostream& x , Set& p_set);  
        int operator [](int index) const;  
    private:  
        int size;  
        int length;  //????
        int* data;  
    };  
    Set::Set(int p_size)  
    {  
        size = (p_size <= 0) ? 1 : ((p_size > 100) ? 100 : p_size);  
        data=new int[ size ];  
        length=0;  
        memset(data,0,sizeof(data));  //��0��ʼ��data�ڴ棬������1�� ��������0x0101(int ������) 
    }  
    Set::Set(const Set &p_Set)  
    { 

    	size = p_Set.size;  
    	length = p_Set.length;  
    	data = new int[size];  
    	for(int i = 0 ; i < length ; i ++)  
        data[i] = p_Set[i];  



/*   		int *pData = p_Set.getData();
        size = p_Set.size;  
        length = p_Set.length;  
        data = new int[size];  
        for(int i = 0 ; i < length ; i ++)  
            data[i] = pData[i];  */
    }  
    Set::~Set()  
    {  
        if(data)  
            delete []data;  
        size = 0;  
        length = 0;  
    }  
    int Set::operator [](int index) const  
    {  
        return data[(index < 0) ? 0 : ((index >= length) ? length - 1 : index) ];  
    }  

    //addItem ���Ԫ��ʱ����鼯��������Ԫ���Ƿ��غ�
    void Set::addItem(int p_item)  			//????
    {  
        if(size == 100)  
        {  
            cout << "����������" << endl;  
            return;  
        }  
        if(length == size && size < 100)  
        {  
            size = ((size + 20) > 100) ? 100 : (size + 20);  
            int* temp = new int[size];  
            for(int i = 0 ; i < length ; i ++)  
                temp[i] = data[i];  
            if(data)  
                delete []data;  
            data = temp;  
        }  
        for(int i = 0 ; i < length ; i ++)  
        {  
            if(p_item == data[i])  
            {  
                cout << "��Ԫ���Ѵ��ڣ�" << endl;  
                return;  
            }  
        }  
        data[ length ] = p_item;  
        length ++;  
    }  
    ;  
    void Set::delItem(int p_item)  
    {  
        for(int i = 0 ; i < length ; i ++)  
        {  
            if(p_item == data[i])  
            {  
                if(i < length - 1)  
                    for(int j = i ; j < length - 1 ; j ++)  
                        data[j] = data[j +1];  
                length --;  
            }  
        }  
    }  
    Set Set::operator +(Set &p_set)  	//����
    {  
        Set s(*this);  
        int flag ;  
        for(int i = 0 ; i < p_set.length ; i ++)  
        {  
            flag = 1;  
            for(int j = 0 ; j < s.length ; j ++)  
                if(s[j] == p_set[i])  
                {  
                    flag = 0;  
                    break;  
                }  
            if(flag)  
                s.addItem(p_set[i]);  
        }  
        return s;  
    }  
    Set Set::operator * (Set &p_set)  	//����
    {  
        Set s(50);  
        for(int i = 0 ; i < p_set.length ; i ++)  
        {  
            for(int j = 0 ; j < length ; j ++)  
                if(data[j] == p_set[i])  
                {  
                    s.addItem(data[j]);  
                }  
        }  
        return s;  
    }  
    Set& Set::operator = (const Set &p_set)  //����
    {  
        size = p_set.size;  
        length = p_set.length;  
        if(data)  
            delete []data;  
        data = new int[size];  
        for(int i = 0 ; i < length ; i ++)  
            data[i] = p_set[i];  
        return *this;  
    }  
    Set& Set::operator -=(Set &p_set)  	//��� ��delItemʵ��
    {  
        for(int i = 0 ; i < p_set.length ; i ++)  
        {  
            for(int j = 0 ; j < length ; j ++)  
                if(data[j] == p_set[i])  
                {  
                    this->delItem(data[j]);  
                }  
        }  
        return *this;  
    }  
    ostream& operator << (ostream& out , Set &p_set)  
    {  
        for(int i = 0 ; i < p_set.length ; i ++)  
            out << p_set[i] << ' ';  
        return out;  
    }  
      
    int main()  
    {  

    	int a, b;
    	cout<<"�������������ϵĴ�С\n";
    	cin>>a>>b;
    	while(1){
    		if((a > 0 && a <= 100) && (b > 0 && b <= 100))
    			break;
    		else{
    			cout<<"����������(a<101,b<101)\n";
    			cin>>a>>b;
    		}
    	}

    	Set s1(a), s2(b), s3;
    	int m, n;
    	cout<<"�������һ�������е�"<<a<<"��Ԫ��\n";
    	int k;
    	for( k = 0; k < a; k++){
    		cin>>m;
    		s1.addItem(m);
    	}
    	cout<<"������ڶ��������е�"<<b<<"��Ԫ��\n";
    	for(k = 0; k < b; k++ ){
    		cin>>n;
    		s2.addItem(n);
    	}

		cout<<"�������һ�������е���ɾ����Ԫ��\n";
		int c;
		cin>>c;
		s1.delItem(c);
		cout<<"s1 = "<<s1<<endl;
		Set s = s1 + s2;
		cout<<"s1 + s2 = "<<s<<endl;
		s = s1 * s2;
		cout<<"s1 * s2 = "<<s<<endl;   	
		s1 -= s2;
		cout<<"s1 -= s2 , s1 = "<<s1<<endl;
		s3 = s2;
		cout<<"s3 = s2 , s3 = "<<s3<<endl;


        /*Set s1(5),s2(4),s3;  
        for(int i = 0 ; i < 5 ; i ++)  
            s1.addItem(i + 1);  
        s1.addItem(5);  
        cout << s1 << endl;  
        for(int j = 1 ; j <= 4 ; j ++)  
            s2.addItem(j * 2);  
        cout<<s2<<endl;  
        Set s=s1+s2;  
        cout<<s<<endl;  
        s=s1*s2;  
        cout<<s<<endl;  
        s1 -= s2;  
        cout << s1 << endl;  
        s3 = s2;  
        cout << s3 << endl; */ 
        return 0;  
    }  