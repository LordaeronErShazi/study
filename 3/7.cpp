#include<iostream>
using namespace std;
class Boat;
class Car
{
	friend int totalweight(Boat &b,Car &c);
	public:
		Car(int zhong);
	private:
		int weight;	
};
Car::Car(int zhong)
{
	weight=zhong;
}
class Boat
{
	friend int totalweight(Boat &b,Car &c);
	public:
		Boat(int zhong);
	private:
		int weight;
};
Boat::Boat(int zhong)
{
	weight=zhong;
}
int  totalweight(Boat&  b,Car&  c)
{
        return  b.weight+c.weight;
}
int  main()
{
        Boat  b(100);
        Car  c(200);
        cout<<totalweight(  b,  c)<<endl;
        return  0;
}

