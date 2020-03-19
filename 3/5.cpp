#include<iostream>
#include<cmath>
using namespace std;
class CTime
{
public:
	CTime(int nian,int yue,int ri,int shi=0,int fen=0,int miao=0);
	CTime(CTime &p);
	~CTime();
	int dayDiff(CTime t);
	void showTime();
	int isvalid();
	int run(int nian);
private:
	int year,month,day,hour,minute,second;	
};
CTime::CTime(int nian,int yue,int ri,int shi,int fen,int miao)
{
	int ri1;
	switch(yue)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: ri1=31; break;
	case 2: ri1=28+run(nian);			
	default: ri1=30;			//�ж�ʱ���Ƿ�Ϸ� 
	}
	if((ri<=ri1)&&!((shi>=0&&shi<=23)&&(fen>=0&&fen<=59)&&(miao>=0&&miao<=59))) 
	{
	nian=yue=ri=shi=fen=miao=0; 
	cout<<"time error!"<<endl;}
	if(!(ri<=ri1)&&((shi>=0&&shi<=23)&&(fen>=0&&fen<=59)&&(miao>=0&&miao<=59))) 
	{
	nian=yue=ri=shi=fen=miao=0; 
	cout<<"data error!"<<endl;}
	if(!(ri<=ri1)&&!((shi>=0&&shi<=23)&&(fen>=0&&fen<=59)&&(miao>=0&&miao<=59))) 
	{
	nian=yue=ri=shi=fen=miao=0; 
	cout<<"data and time error!"<<endl;}
	year=nian; month=yue; day=ri;
	hour=shi; minute=fen; second=miao;
	cout<<"���캯��������"<<endl;		
}
CTime::CTime(CTime &p)
{
	year=p.year; month=p.month; day=p.day;
	hour=p.hour; minute=p.minute; second=p.second;				//ʵ�ֿ������캯�� 
	cout<<"�������캯��������"<<endl;
}
CTime::~CTime()
{
	cout<<"��������������"<<endl;
}
int CTime::dayDiff(CTime t)
{
    int nd, nm, ny; 
    int od, om, oy; 
    nm = (t.month + 9) % 12;
	ny = t.year - nm/10;
	nd = 365*ny + ny/4 - ny/100 + ny/400 + (nm*306 + 5)/10 + (t.day - 1);
	om = (month + 9) % 12;
	oy = year - om/10;
	od = 365*oy + oy/4 - oy/100 + oy/400 + (om*306 + 5)/10 + (day - 1);
    return abs(od - nd);															//���������� 
}
void CTime::showTime()
{
	cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}
int CTime::isvalid()
{
	int prime=1;
	if(year==0&&month==0&&day==0&&hour==0&&minute==0&&second==0)
		prime=0;
	return prime;															//�ж�ʱ�������Ƿ�Ϊ�� 
}
int CTime::run(int nian)
{
	if((nian%4==0) && (nian%100!=0)||nian%400==0) return 1;
	else return 0;																//�ж��Ƿ�Ϊ���� 
}
int  main()
{
        int  year,  month,  day,  hour,  minute,  second;
        cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second;
        CTime  t1(year,  month,  day,  hour,  minute,  second);
        t1.showTime();
        CTime  t2(2000,  1,  1);  //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00
        if  (t1.isvalid())          //������ں�ʱ��Ϸ������������
        {
                int  days=0;
                days=t1.dayDiff(t2);
                cout  <<  "������֮�������"  <<  days  <<  "��"  <<  endl;
                days=t2.dayDiff(t1);
                cout  <<  "������֮�������"  <<  days  <<  "��"  <<  endl;
        }
}
