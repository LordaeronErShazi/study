#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	short stu_id;
	short score;	
};
int main()
{
	int num;
	cin>>num;
	student *a = new student[num];
	for(int i=0;i<=num-1;i++)
	{
		cin>>a[i].stu_id>>a[i].score;
	}
	ofstream ofile("out.txt");
	ifstream ifile("out.txt");
	ofile.write((char*)a,sizeof(a)*num);
	student *b = new student[num];
	for(int i=1;i<=num;i++)
	{
		ifile.read((char*)b,sizeof(a));
	}
	ofile.write((char*)b,sizeof(b)*num);
	ifile.close();
	ofile.close();
	return 0;
}
