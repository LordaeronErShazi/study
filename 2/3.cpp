#include<iostream>  
using namespace std;  
int countwater()  
{  
    int sumprice=20;  
    int sumpz=0;  
    int sumpg=0;  
    int sum=0;  
    while((sumprice)||(sumpz>=2)||(sumpg>=3))  
    {  
        while(sumprice)  
        {  
            sumprice--;  
            sum++;  
            sumpz++;  
            sumpg++;  
        }  
        while((sumpz>=2))  
        {  
            int a=sumpz/2;  
            sumpz%=2;  
           
            sumprice+=a;  
        }  
        while((sumpg>=3))  
        {  
            int b=sumpg/3;  
            sumpg%=3;  
         
            sumprice+=b;  
        }  
    }
	  
    cout<<"ʣ�µ�ƿ������"<<sumpz<<endl;
	cout<<"ʣ�µ�ƿ������"<<sumpg<<endl;
    return sum;   
}  
int main()  
{  
    cout<<countwater();  
    return 0;  
}  
