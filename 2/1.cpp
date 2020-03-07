#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	char a[10],b[10];
	int i,j,k,min=26;
	cin>>a>>b;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		a[i]=a[i]+32;
	}
	for(i=0;b[i]!='\0';i++)
	{
		if(b[i]>='A'&&b[i]<='Z')
		b[i]=b[i]+32;
	}
	for(i=0;a[i]!='\0';i++)
	{
		for(j=0;b[j]!='\0';j++)
		{
			k=abs(a[i]-b[j]);
			if(k<min) min=k;
		}
	}
	cout<<min;
	return 0;
}
