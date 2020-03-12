#include<iostream>
#include<iomanip>
using  namespace  std;
//请在此处补充Account类的定义



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
		cout<<"您输入的金额不合法"<<endl;
	}
}
double Account::printmoney()
{
	cout<<na<<"的存款为"<<fixed<<setprecision(2)<<mo<<endl;
}
void Account::deposit(double newmoney)
{
	if(int(newmoney*1000)%10==0)
		mo+=newmoney;
	else
	{
		cout<<"您输入的金额不合法"<<endl;
	} 	
}
void Account::withdraw(double oldmoney)
{
	if(int(oldmoney*1000)%10==0)
	{
		if(mo>=oldmoney)
			mo-=oldmoney;
		else
			cout<<"您的存款金额不足"<<endl;
	}
	else
	{
		cout<<"您输入的金额不合法"<<endl;
	} 	
}



int  main()
{
        Account  tom;
        tom.init("32020320011001876X",  "Tom  Black",  "男",  19,  2000.89);
        tom.printmoney();//输出：Tom  Black的存款为2000.89
        tom.deposit(89.471);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的存款为2000.89
        tom.deposit(10000);
        tom.printmoney();//输出：Tom  Black的存款为12000.89
        tom.withdraw(10001);
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        tom.withdraw(10000.123);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        tom.withdraw(10000.9);//输出：您的存款金额不足
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        Account  jerry;
        jerry.init("320203200910116569",  "Jerry  Black",  "女",  11,  100.956);//输出：您输入的金额不合法
        jerry.printmoney();//输出：Jerry  Black的存款为0.00
}

