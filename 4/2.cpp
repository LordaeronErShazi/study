#include  <iostream>
#include  <string>
using  namespace  std;

class  CStudent
{
public:
	CStudent(char ming[]="noname",int nian=0)
	{
		for(int i=0;ming[i]!='\0';i++)
		{
			this->name[i]=ming[i];
		}
		this->age=nian;
		count++;
		cout<<name<<" is contructing"<<endl;
	}
	~CStudent()
	{
		cout<<name<<" is destructing"<<endl;
		count--;
	}
	static int getcount()
	{
		return count;
	}
	void printname()
	{
		cout<<"name:"<<name<<endl;
	}
private:
	char name[10];
	int age;
	static int count;	
};
//���������ʼ��
	int CStudent::count=0;
int  main()
{
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuB[5];
                stuB[4].printname();
                cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)};
                for  (int  i  =  0;  i  <  2;  i++)
                {
                        stuA[i].printname();
                }
                cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;

        return  0;
}
