#ifndef Combined_Tour_h
#define Combined_Tour_h
#include "tour.h"
using namespace std;

template<class T1,class T2>
class Combined_Tour:public Tour<T1,T2>
{
protected:
	int gid_costs;
	char cities[10][255];
public:
	Combined_Tour():Tour(){gid_costs=0;}
	~Combined_Tour(){};
	Combined_Tour(T1,T1*,T1*,T1*,T1*,T2 *,T1,T1,T1 ,T1 ,T1,T2[][255]);
	Combined_Tour(const Combined_Tour &);
	void set_gid_costs(T1 costs)
	{
		gid_costs=costs;
	}
	T1 get_gid_costs()
	{
		return gid_costs;
	}
	void set_city(T1 i,T2 *city)
	{
		strcpy(cities[i],city);
	}
	T2* get_city(T1 i)
	{
		return cities[i];
	}



};

template<class T1,class T2>
Combined_Tour<T1,T2> :: Combined_Tour(T1 nn,T1*D,T1 *M,T1 *Y,T1 *Kol,T2 *kod,T1 length,T1 transport_cost,T1 cost_of_living,T1 comission,T1 Gid_costs,T2 Cities[][255]):Tour<T1,T2>(nn,D,M,Y,Kol,kod, length, transport_cost, cost_of_living,comission)
{
	set_gid_costs(Gid_costs);
	for(int i=0;i<10;i++)
		set_city(i,Cities[i]);
}

template<class T1,class T2>
Combined_Tour <T1,T2>::Combined_Tour(const Combined_Tour& obj):Tour<T1,T2>(obj)
{
	gid_costs=obj.gid_costs;
	for(int i=0;i<10;i++)
		strcpy(cities[i],obj.cities[i]);
}


#endif