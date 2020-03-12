#include<iostream>
#include<iomanip>
using  namespace  std;
//���ڴ˴�����Account��Ķ���



class Account
{
public:
	void init(char account[],char name[],char sex[],int age,double money);
	double printmoney();
	void deposit(double newmoney);
	void withdraw(double oldmoney);
private:
	char ac[30],na[30],se[30];
	int ag;
	double mo;
};
void Account::init(char account[],char name[],char sex[],int age,double money)
{
	for(int i=0;account[i]!='\0';i++)
		ac[i]=account[i];
	for(int i=0;name[i]!='\0';i++)
		na[i]=name[i];
	for(int i=0;sex[i]!='\0';i++)
		se[i]=sex[i];
	ag=age;
	if(int(money*1000)%10==0) mo=money;
	else 
	{
		mo=0;
		cout<<"������Ľ��Ϸ�"<<endl;
	}
}
double Account::printmoney()
{
	cout<<na<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<mo<<endl;
}
void Account::deposit(double newmoney)
{
	if(int(newmoney*1000)%10==0)
		mo+=newmoney;
	else
	{
		cout<<"������Ľ��Ϸ�"<<endl;
	} 	
}
void Account::withdraw(double oldmoney)
{
	if(int(oldmoney*1000)%10==0)
	{
		if(mo>=oldmoney)
			mo-=oldmoney;
		else
			cout<<"���Ĵ�����"<<endl;
	}
	else
	{
		cout<<"������Ľ��Ϸ�"<<endl;
	} 	
}



int  main()
{
        Account  tom;
        tom.init("32020320011001876X",  "Tom  Black",  "��",  19,  2000.89);
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
        tom.deposit(89.471);//�����������Ľ��Ϸ�
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
        tom.deposit(10000);
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89
        tom.withdraw(10001);
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
        tom.withdraw(10000.123);//�����������Ľ��Ϸ�
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
        tom.withdraw(10000.9);//��������Ĵ�����
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
        Account  jerry;
        jerry.init("320203200910116569",  "Jerry  Black",  "Ů",  11,  100.956);//�����������Ľ��Ϸ�
        jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00
}

