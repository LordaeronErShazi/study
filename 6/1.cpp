#include  <iostream>
using  namespace  std;
class Complex
{
private:
	float real,vir;
public:
	Complex(float r=0,float v=0):real(r),vir(v){
	}
	Complex operator +(Complex &c)
	{
		return Complex(real+c.real,vir+c.vir);
	}
	Complex operator -(Complex &c)
	{
		return Complex(real-c.real,vir-c.vir);
	}
	Complex operator +(int c)
	{
		return Complex(real+c,vir);
	}
	Complex operator -(double c)
	{
		return Complex(real-c,vir);
	}
	void print()
	{
		if(vir>=0)
		cout<<real<<"+"<<vir<<"i"<<endl;
		else
		cout<<real<<vir<<"i"<<endl;
	}
};
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

        return  0;
}
