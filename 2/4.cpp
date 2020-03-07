#include  <iostream>
#include  <cmath>
using  namespace  std;

//判断是否为素数
int  isPrime(long  num)
{
	int i,prime=1;
	for(i=2;i<num;i++)
	if(num%i==0)
	{
		prime=0;
		break;
	}
	return prime;
}

//计算质因素分解，
void  factorization(long &n,long factor[],int &numofFactor)
{
	int i=0,j;
	for(j=2;!isPrime(n);)
	{
		if(n%j==0&&isPrime(j))
		{
			n=n/j; factor[i++]=j; numofFactor++;
			j=2; continue;
		}
		else j++;
	}
	numofFactor++;
	factor[i]=n;
        return;
}

int  main()
{
        long  n;
        long  factor[100];
        int  numofFactor  =  0;
        cin  >>  n;
        factorization(n,  factor,  numofFactor);
        for  (int  i  =  0;  i  <  numofFactor;  i++)
        {
                cout  <<  factor[i]  <<  "  ";
        }
        cout  <<  endl;
        return  0;
}
