#ifndef Uncombined_h
#define Unccombined_h
#include <iostream>
#include <iomanip>
#include "tour.h"
using namespace std;

template<class T1,class T2>
class  Uncombined_Tour: public Tour<T1,T2>
{
protected:
	 T2 hotel[50];
	 T2 country[20];
	 T2 city[50];
public:
	Uncombined_Tour():Tour(){}
	~Uncombined_Tour(){};
	void Input();
	
		void set_country(T2 *country)
	{
		strcpy(this->country,country);
	}
	T2* get_country()
	{
		return country;
	}
	void set_city(T2 *city)
	{
		strcpy(this->city,city);
	}
	T2* get_city()
	{
		return city;
	}

	void set_hotel(T2 *hotel)
	{
		strcpy(this->hotel,hotel);
	}
	T2* get_hotel()
	{
		return hotel;
	}
	Uncombined_Tour(T1 nn,T1*D,T1 *M,T1 *Y,T1 *Kol,T2 *kod,T1 length,T1 transport_cost,T1 cost_of_living,T1 comission,T2*country,T2 *city, T2 *hotel):Tour(nn,D,M,Y,Kol,kod, length, transport_cost, cost_of_living,comission)
	{
		set_country(country);
		set_city(city);
		set_hotel(hotel);
	}

	Uncombined_Tour(const Uncombined_Tour & obj):Tour(obj)
	{
		strcpy	(country,obj.country);
	strcpy(city,obj.city);	strcpy(hotel,obj.hotel);
	}
};

template<class T1,class T2>
void Uncombined_Tour<T1,T2>::Input()
	{
		cout << "���������� ����� ������" << endl; cout << endl;
	cout << "������� ��� ����: ";

	int x=0;
	int fl=0;
	/*while(!x)
	{*/
	fflush stdin;
	gets(kod);
	/*x=1;
	for(int i=0;i<count;i++)
	{
	if(!strcmp(t[i]->get_kod(),kod))
	{
	cout << endl; cout << "��� � ����� ����� ��� ����" << endl;
	cout << "��������� ����, ����������: " << endl;
	cin.clear();
	x=0;
	break;
	}
	}*/
	//		//fl++;
	//}
	//strcpy(kodd,enterFieldKod(t,count));
	//t->set_kod(kod);
	cout << "������� ������: ";
	fflush stdin;
	gets(country);
	cout << "������� �����: ";
	fflush stdin;
	gets(city);
	cout << "������� ���������� ��� ������: ";
	 n=Tour<T1,T2>::enterFieldValue();
	cout << "������� :���� - ���������� ����: ";
	for(int j=0;j<n;j++)
	{
		cout << "���� � " << j+1 <<endl;
		cout << "����-> ";
		 day[j]=Tour<T1,T2>::enterFieldValue();
		cout << "�����->: ";
		month[j]=Tour<T1,T2>::enterFieldValue();
		cout << "���->:XX\b\b";
		year[j]=Tour<T1,T2>::enterFieldValue();
		cout << "���������� ���� �� ��� ����->: ";
		 kol[j]=Tour<T1,T2>::enterFieldValue();
	}
	cout << "������� �����������������:     �����\b\b\b\b\b\b\b\b";
	length=Tour<T1,T2>::enterFieldValue();
	cout << "������� ��������� �������:            BR\b\b\b\b\b\b\b\b\b\b";
	cost_trans=Tour<T1,T2>::enterFieldValue();
	cout << "������� ��������� ���������� � �������:             BR\b\b\b\b\b\b\b\b\b\b\b";
	cost_of_living=Tour<T1,T2>::enterFieldValue();
	cout << "������� �������� �������� �����������:            BR\b\b\b\b\b\b\b\b\b\b";
	comission=Tour<T1,T2>::enterFieldValue();
	}

#endif