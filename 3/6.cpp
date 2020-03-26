#include<iostream>
using namespace std;
class CPoint
{
	public:
		CPoint(int a,int b);
		CPoint(CPoint &p);
		int getx();
		int gety();
	private:
		int x,y;
};
CPoint::CPoint(int a=0,int b=0)
{
	x=a; y=b;
	cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(CPoint &p)
{
	x=p.x; y=p.y;
	cout<<"CPoint copy contstructor is called."<<endl;
}
int CPoint::getx()
{
	return x;
}
int CPoint::gety()
{
	return y;
}
class CRectangle
{
	public:
		CRectangle();
		CRectangle(CPoint xp1,CPoint xp2);
		CRectangle(int a,int b,int c,int d);
		CRectangle(CRectangle &p);
		int GetArea();
	private:
		int x1,y1,x2,y2;
		CPoint p1,p2;
};
CRectangle::CRectangle()
{
	x1=y1=x2=y2=0;
	cout<<"CRectangle default contstructor is called."<<endl;
}
CRectangle::CRectangle(CPoint xp1,CPoint xp2):p1(xp1),p2(xp2)
{
	x1=p1.getx(); y1=p1.gety();
	x2=p2.getx(); y2=p2.gety();
	cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}
CRectangle::CRectangle(int a,int b,int c,int d)
{
	x1=a; y1=b; x2=c; y2=d;
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle &p)
{
	x1=p.x1; y1=p.y1; x2=p.x2; y2=p.y2;
	//p1=p.p1; p2=p.p2;
	CPoint p1(p.p1); CPoint p2(p.p2);
	cout<<"CRectangle copy contstructor is called."<<endl;
}
int CRectangle::GetArea()
{
	return (x1-x2)*(y1-y2);
}
int  main()
{
    int  a=1,  b=1,  c=6,  d=11;
    cout<<"#  Define  p1  ######"<<endl;
    CPoint  p1;
    cout<<"#  Define  p2  ######"<<endl;
    CPoint  p2(10,20);
    cout<<"#  Define  rect1  ######"<<endl;
    CRectangle  rect1;
    cout<<"#  Define  rect2  ######"<<endl;
    CRectangle  rect2(p1,  p2);
    cout<<"#  Define  rect3  ######"<<endl;
    CRectangle  rect3(a,  b,  c,  d);
    cout<<"#  Define  rect4  ######"<<endl;
    CRectangle  rect4(rect2);
    cout<<"#  Calculate  area  ######"<<endl;
    cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl;
    cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl;
    cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl;
    cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl;
    system("pause");
    return  0;
}

