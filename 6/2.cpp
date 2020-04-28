#include  <iostream>
using  namespace  std;
class Complex
{
private:
	float real,vir;
public:
	Complex(float r=0,float v=0):real(r),vir(v){
	}
	friend Complex operator +(const Complex &c1,const Complex &c2);
	friend Complex operator -(const Complex &c1,const Complex &c2);
	friend Complex operator +(const Complex &c1,int c2);
	friend Complex operator +(int c1,const Complex &c2);
	friend Complex operator -(float c1,const Complex &c2);
	friend Complex operator -(const Complex &c1,float c2);
	void print()
	{
		cout<<"("<<real<<")+("<<vir<<"i"<<")"<<endl;
	}
};
Complex operator +(const Complex &c1,const Complex &c2)
{
	return Complex(c1.real+c2.real,c1.vir+c2.vir);
}
Complex operator -(const Complex &c1,const Complex &c2)
{
	return Complex(c1.real-c2.real,c1.vir-c2.vir);
}
Complex operator +(const Complex &c1,int c2)
{
	return Complex(c1.real+c2,c1.vir);
}
Complex operator +(int c1,const Complex &c2)
{
	return Complex(c1+c2.real,c2.vir);
}
Complex operator -(float c1,const Complex &c2)
{
	return Complex(c1-c2.real,0-c2.vir);
}
Complex operator -(const Complex &c1,float c2)
{
	return Complex(c1.real-c2,c1.vir);
}

int  main()
{
        Complex  a(3,4),b(1,-1),c;
        c=a+b;
        cout<<"a+b=";
        c.print();
        cout<<endl;
        c=a-b;
        cout<<"a-b=";
        c.print();
        cout<<endl;
        c=a+100;
        cout<<"a+100=";
        c.print();
        cout<<endl;
        c=a-2.5;
        cout<<"a-2.5=";
        c.print();
        cout<<endl;
        c=100+a;
        cout<<"100+a=";
        c.print();
        cout<<endl;
        c=2.5-a;
        cout<<"2.5-a=";
        c.print();
        cout<<endl;
        return  0;
}
