#include<iostream>
#include <iomanip>
using namespace std;
float Plural(float a,float b)
{
	return (a-b);
}
int main()
{
	float a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<Plural(a,c)<<' '<<Plural(b,d);
	return 0;
}


