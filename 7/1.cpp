#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void paixu(string s,int n)
{
	for(int i=0;i<n;i++)
	{
		int k,j;
		for(k=i,j=k+1;j<n;j++)
		{
			if(s[k]>s[j])
			{
				char tmp = s[k];
				s[k] = s[j];
				s[j] = tmp;
			}
		}
		if(k!=i)
		{
			char tmp=s[k];
			s[k]=s[i];
			s[i]=tmp;
		}
	}
}
int main()
{
	int i=0;
	ifstream infile("a.txt");
	ofstream outfile("b.txt");
	string temp;
	int length = temp.length();
	infile.read((char*)(&temp),length);
	paixu(temp,length);
	outfile.write((char*)(&temp),length);
	infile.close();
	outfile.close();
	return 0;
}


