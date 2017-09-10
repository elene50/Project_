#ifndef Europe_Tour_h
#define Europe_Tour_h
#include "Combined.h"


class Europe_Tour: public Combined_Tour<int,char>
{ 
	char countries[10][255];//
public:
	Europe_Tour(): Combined_Tour(){}
	~Europe_Tour(){};
	Europe_Tour(const Europe_Tour &);
	Europe_Tour(int,int*,int*,int*,int *,char *,int,int,int ,int ,int,char[][255],char[][255]);
	void red(Tour *[],int){};
    void header(){};
	void set_one_country(int i,char *country)
	{
		strcpy(countries[i],country);
	}
	char * get_one_country(int i)
	{
		return countries[i];
	}
};
	
Europe_Tour::Europe_Tour(int nn,int*D,int *M,int *Y,int *Kol,char *kod,int length,int transport_cost,int cost_of_living,int comission,int Gid_costs,char Cities[][255],char Countries [][255]):Combined_Tour(nn,D,M,Y,Kol,kod, length, transport_cost, cost_of_living, comission,Gid_costs,Cities)
{
for(int i=0;i<10;i++)
		strcpy(countries[i],Countries[i]);
}

Europe_Tour:: Europe_Tour(const Europe_Tour &obj)
{
	for(int i=0;i<10;i++)
		strcpy(countries[i],obj.countries[i]);

}

#endif