#include<iostream>
using namespace std;
int judge(char a[])
{
	return 1;
}
int main()
{
	char a[8];
	int b,c,i;
	cin>>a;
	for(i=0,b=0;i<=7;i++)
	{
		if(a[i]!='*')
			b=b+a[i]-48;
	}
	c=36-b;
	if(judge(a)) cout<<c;
	else cout<<"No Answer";
	return 0;
}
