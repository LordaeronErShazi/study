#include  <iostream>
using  namespace  std;
class Point
{
private:
	int m_x,m_y;
public:
	Point(int x,int y):m_x(x),m_y(y){
	}
	Point operator ++()
	{
		m_x++; m_y++;
		return Point(m_x,m_y);
	}
	Point operator ++(int)
	{
		m_x++; m_y++;
		return Point(m_x-1,m_y-1);
	}
//	Point operator <<()
//	{
//		return Point(m_x,m_y);
//	}
	friend ostream& operator <<(ostream &output,Point A);
};
ostream& operator <<(ostream &output,Point A)
{
	output<<"("<<A.m_x<<","<<A.m_y<<")"<<endl;
	return output;
}
int  main()
{
        Point  a(1,3);
        cout<<a;
        cout<<a++;
        cout<<++a;
        return  0;
}
