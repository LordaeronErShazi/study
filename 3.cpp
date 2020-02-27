#include<iostream>
using namespace std;
int main()
{
	int a[3][3],b[3][3],c[3][3],i,j,k;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		cin>>a[i][j];
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		cin>>b[i][j];
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j];
		}
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			cout<<c[i][j];
			cout<<' ';
			if(j==2) cout<<'\n';
		}
	}
	return 0;
}
