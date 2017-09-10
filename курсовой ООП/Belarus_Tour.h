#ifndef Belarus_Tour_h
#define Belarus_Tour_h
#include "Combined.h"
using namespace std;

class Belarus_Tour: public Combined_Tour<int,char>
{
	char places[10][255];//
public:
	Belarus_Tour():Combined_Tour(){}
	~Belarus_Tour();
	Belarus_Tour(const Belarus_Tour &) ;
	Belarus_Tour(int,int*,int*,int*,int *,char *,int,int,int ,int ,int,char[][255],char[][255]);
	void set_places(int i,char* one_place)
	{
		strcpy(places[i],one_place);
	}
	char * get_one_place(int i)
	{
		return places[i];
	}
	void print(){};
	void red(Tour *[],int){};
	void add(Tour*[],int,int){};
	void sort(){};
    void header(){};
	//int open_File(Sea_Tour *[]){return 0;};
	void  write_File(Tour *[],int,int){};
};

 Belarus_Tour:: Belarus_Tour(int nn,int*D,int *M,int *Y,int *Kol,char *kod,int length,int transport_cost,int cost_of_living,int comission,int Gid_costs,char Cities[][255],char Places [][255]):Combined_Tour(nn,D,M,Y,Kol,kod, length, transport_cost, cost_of_living, comission,Gid_costs,Cities)
 {
	 for(int i=0;i<10;i++)
		strcpy(places[i],Places[i]);
 }
 
 Belarus_Tour::Belarus_Tour(const Belarus_Tour &obj)
 {
	 for(int i=0;i<10;i++)
		strcpy(places[i],obj.places[i]);
 }


#endif