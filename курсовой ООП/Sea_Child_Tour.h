#ifndef Sea_Child_Tour_h
#define  Sea_Child_Tour_h
#include "Sea_Tour.h"
#include "Wellness_Tour.h"
#include <fstream>
#include <iostream>
using namespace std;

class Sea_Child_Tour:public Sea_Tour,public Child_Tour
{

	int cost_of_treatment;//стоимость лечения
public:
	Sea_Child_Tour(){cost_of_treatment=0;}
	~Sea_Child_Tour(){};
	Sea_Child_Tour(int,int*,int*,int*,int *,char*,int,int,int,int,char*,char*,char*,char*,int,int,int*,int);
	Sea_Child_Tour(const Sea_Child_Tour &obj):Sea_Tour(obj),Child_Tour(obj),Uncombined_Tour(obj)
	{
		cost_of_treatment=obj.cost_of_treatment;
	}
	Sea_Child_Tour operator=(const Sea_Child_Tour obj)
	{
		strcpy(kod,obj.kod);
    length=obj.length;
   cost_trans=obj.cost_trans;
	cost_of_living=obj.cost_of_living;
	comission=obj.comission;
	n=obj.n;
	for(int i=0;i<n;i++)
		{
			day[i]=obj.day[i];
			month[i]=obj.month[i];
			year[i]=obj.year[i];
		    kol[i]=obj.kol[i];
	     }
	strcpy(country,obj.country);
	strcpy(city,obj.city);
	strcpy(hotel,obj.hotel);
	strcpy(food_tip,obj.food_tip);
	cost_vosp=obj.cost_vosp;
	vosrast[0]=obj.vosrast[0];
	vosrast[1]=obj.vosrast[1];
	insurance=obj.insurance;
	cost_of_treatment=obj.cost_of_treatment;
		return *this;
	}
	int get_total_cost()
		{
			//int One_percent=(float)(cost_trans+cost_of_living+insurance+cost_vosp+cost_of_treatment)/(100-comission);
			return comission+cost_trans+cost_of_living+insurance+cost_vosp+cost_of_treatment;
		}
	void header();
	void print();
	int print(char*);
	void print_price();
	int print_com(char*);
	//void add(Tour*[],int,int);
	void add();
	void sort(){};
	int poisk(char *,int);
	int poisk(int* );
	int sravn(char*,int*);
	void red();
	int open_File(Sea_Child_Tour *);
	void  write_File(Sea_Child_Tour *,int);
	int enterFieldValue();
	int enterRecordNumber(int);
	char* enterFieldKod(Tour *[],int);
	void set_cost_of_treatment(int cost)
	{
		cost_of_treatment=cost;
	}
	int get_cost_of_treatment(){
		return cost_of_treatment;
	}
	friend ostream &operator<<(ostream &,Sea_Child_Tour &);
	friend istream &operator>>(istream &, Sea_Child_Tour &);

	friend fstream &operator<<(fstream &,Sea_Child_Tour &);
	friend fstream &operator>>(fstream &, Sea_Child_Tour &);

};

Sea_Child_Tour:: Sea_Child_Tour(int nn,int*D,int *M,int *Y,int *Kol,char *kod,int length,int transport_cost,int cost_of_living,int comission,char*country,char *city, char *hotel,char*food_t,int insurance,int cost_vosp,int *vosrast,int cost_treatment): 
	Sea_Tour(nn,D,M,Y,Kol,kod,length,transport_cost,cost_of_living,comission,country,city,hotel,food_t,insurance), Child_Tour(nn,D,M,Y,Kol,kod,length,transport_cost,cost_of_living, comission,country,city, hotel, cost_vosp, vosrast), Uncombined_Tour(nn,D,M,Y,Kol,kod,length,transport_cost,cost_of_living,comission,country,city,hotel)
{
	set_cost_of_treatment(cost_treatment);
}

void Sea_Child_Tour::  header()
{
cout << "\nДЕТСКИЕ САНАТОРИИ" << endl;
				cout << "================================================================================================================" << endl;
				cout << "  Код       Страна         Город       Санаторий  Тип      Дата        Колич.  Всего  Возраст  Общая      Валюта" << endl ;
				cout << "                                                  питания вылета       путёвок ночей           стоимость" << endl;
				cout << "================================================================================================================" << endl;
}

fstream &operator<<(fstream &out,Sea_Child_Tour &obj)
{
	out << obj.n << " " ;
	for(int i=0;i<obj.n;i++)
	{
out << obj.day[i]<< " " ;
out << obj.month[i] << " ";
out << obj.year[i] << " ";
out << obj.kol[i]<< " ";
	}
	out << obj.kod <<" " << obj.length << " " <<  obj.cost_trans << " " << obj.cost_of_living << " " << obj.comission << " " << obj.country << " " << obj.city << " " << obj.hotel << " " << obj.food_tip << " " << obj.cost_vosp << " " <<obj.vosrast[0] << " " << obj.vosrast[1] << " " << obj.insurance << " " << obj.cost_of_treatment << endl;
	return out;
}

fstream &operator>>(fstream &in, Sea_Child_Tour &obj)
{
	in >> obj.n;
	for(int i=0;i<obj.n;i++)
	{
in >> obj.day[i];
in >> obj.month[i];
in >> obj.year[i];
in >> obj.kol[i];
	}
	in >> obj.kod;
	in >> obj.length;
	in >> obj.cost_trans;
	in >> obj.cost_of_living;
	in >> obj.comission;
	in >> obj.country;
	in >> obj.city;
	in >> obj.hotel;
	in >> obj.food_tip;
	in >> obj.cost_vosp;
	in >> obj.vosrast[0];
	in >> obj.vosrast[1];
	in >> obj.insurance;
	in >> obj.cost_of_treatment;
	return in;
}

istream &operator>>(istream &in, Sea_Child_Tour &obj)
{
	obj.Uncombined_Tour:: Input();
	cout << "Введите название санатория: ";
	fflush stdin;
	gets(obj.hotel);
	obj.Sea_Tour::Input();
	obj.Child_Tour::Input();
	cout << "Введите стоимость лечения:           BR\b\b\b\b\b\b\b\b\b\b";
	obj.cost_of_treatment=obj.Tour::enterFieldValue();
	return in;
}

void Sea_Child_Tour :: print()
{
	cout << setw(3) << kod; 
	cout  << setw(13) <<country;
	cout << setw(16) << city;
	cout << setw(14) <<  hotel;
	cout << setw(7) <<  food_tip;
		int i=0;
		cout <<setw(5) <<  day[i] <<"." << setw(2) <<month[i] <<"." <<year[i]; 
		cout << setw(7) << kol[i];
	cout << setw(8)  << length;
	cout << setw(7)  << vosrast[0] << "-" << vosrast[1] ;
	cout << setw(12)  <<get_total_cost();
	cout <<  setw(5)  << val <<endl;
	i++;
	for(;i<n;i++)
		{
			cout << setw(54) << day[i] <<"." << setw(2) <<month[i] <<"." <<year[i] << setw(7) << kol[i] << endl; 
	}
}

int Sea_Child_Tour:: print(char *kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(17) << get_total_cost() ;
		return get_total_cost();
	}
	return 0;
}

int Sea_Child_Tour:: print_com(char*kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(15) << comission << setw(7) << "BR" << endl;
		return comission;
	}
	return 0;

}

void Sea_Child_Tour ::print_price()
{
	cout << setw(3) << kod; 
	cout << setw(11) << cost_trans;
	cout << setw(17) << cost_of_living; 
	cout << setw(18) << comission;
	cout << setw(9) << insurance; 
	cout << setw(13) << cost_vosp; 
	cout << setw(14) << cost_of_treatment; 
	cout << setw(15) << get_total_cost(); 
	cout <<  setw(8)  << val << endl;
}


//void Sea_Child_Tour::add()
//{
//	cout << "ДОБАВЛЕНИЕ НОВОЙ ЗАПИСИ" << endl; cout << endl;
//	cout << "Введите код тура: ";
//	/*int x=0;
//	int fl=0;
//	while(!x)
//	{
//	*/	fflush stdin;
//		gets(kod);
//	//	x=1;
//	//	for(int i=0;i<count;i++)
//	//	{
//	//		if(!strcmp(t[i]->get_kod(),kod))
//	//		{
//	//			cout << endl; cout << "Тур с таким кодом уже есть" << endl;
//	//			cout << "Повторите ввод, пожалуйста: " << endl;
//	//			cin.clear();
//	//			x=0;
//	//			break;
//	//		}
//	//	}
//	//	//fl++;
//	//}
//	cout << "Введите страну: ";
//	fflush stdin;
//	gets(country);
//	cout << "Введите город: ";
//	fflush stdin;
//	gets(city);
//	cout << "Введите название санатория: ";
//	fflush stdin;
//	gets(hotel);
//	cout << "Введите тип питания: ";
//	fflush stdin;
//	gets(food_tip);
//	cout << "Введите количество дат выезда: ";
//	cin >> n;
//			cout << "Введите :Дата - количество мест: ";
//			for(int j=0;j<n;j++)
//			{
//				cout << "ДАТА № " << j+1 <<endl;
//				cout << "день-> ";
//				cin >> day[j];
//				cout << "месяц->: ";
//				cin >> month[j];
//				cout << "год->:XXXX\b\b\b\b";
//				cin >> year[j];
//				cout << "количество мест на эту дату->: ";
//				cin >> kol[j];
//			}
//			cout << "Введите продолжительность:     ночей\b\b\b\b\b\b\b\b";
//			length=Tour::enterFieldValue();
//			cout << "Введите стоимость перелёта:           Br\b\b\b\b\b\b\b\b\b\b";
//			cost_trans=Tour::enterFieldValue();
//			cout << "Введите стоимость проживания в отеле:             Br\b\b\b\b\b\b\b\b\b\b\b";
//			cost_of_living=Tour::enterFieldValue();
//			cout << "Введите величину комиссии турагенству:            Br\b\b\b\b\b\b\b\b\b\b\b";
//			comission=Tour::enterFieldValue();
//			cout << "Введите допустимый возраст детей:" <<endl;
//			cout << "Введите начальный возраст->";
//			vosrast[0]=Tour::enterFieldValue();
//			cout << "Введите предельный возраст->";
//			vosrast[1]=Tour::enterFieldValue();
//			cout << "Введите стоимость услуг воспитателя:        Br\b\b\b\b\b\b";
//			cost_vosp=Tour::enterFieldValue();
//	cout << "Введите стоимость страховки:         Br\b\b\b\b\b\b\b\b\b\b";
//	insurance=Tour::enterFieldValue();
//	cout << "Введите стоимость лечения:         Br\b\b\b\b\b\b\b\b\b\b";
//	cost_of_treatment=Tour::enterFieldValue();
//	
//}

//int Sea_Child_Tour::enterFieldValue()
//{
//	int fl=0;
//	double x;
//	while(fl == 0)
//	{
//		cin >> x;
//		if(!cin || x!=int(x))
//		{
//			cout << endl; cout << "Ошибка ввода!" << endl;
//			cout << "Повторите ввод, пожалуйста: " << endl;
//			cin.clear();
//			while(cin.get()!='\n');
//			continue;
//		}
//		else fl++;
//	}
//	return x;
//}
//int Sea_Child_Tour::enterRecordNumber(int count)
//{
//	int fl = 0;
//	int x;
//	while (fl == 0)
//	{
//		cin >> x;
//		if (!cin || x != int(x) || x <= 0 || x >count)
//		{
//			cout << "Ошибка ввода! Попробуйте ещё раз" << endl;
//			cin.clear();
//			while (cin.get() != '\n');
//			continue;
//
//		}
//		else fl++;
//	}
//	return x;
//}
void Sea_Child_Tour::red()
{
	int k;
	cout << endl << endl << "**** ЧТО ВЫ ХОТИТЕ ИЗМЕНИТЬ? ****" << endl;
	cout << "===================" << endl << endl;
	//cout << "1.Код" << endl;
	cout << "1.Cтрана" << endl;
	cout << "2.Город" << endl;
	cout << "3.Санаторий" << endl;
	cout << "4.Продолжительность" << endl;
	cout << "5.Тип питания" << endl;
	cout << "6.Возраст" << endl;
	cout << "0.Назад" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	switch (k) {
	case 1:
		cout << "Введите новую страну: ";
		//char country[20];
		fflush stdin;
		gets(country);
		//set_country(country);
		break;
	case 2:
		cout << "Введите новый город: ";
		//char code[20];
		fflush stdin;
		gets(city);
		//set_kod(code);
		break;
	case 3:
		cout << "Введите новое название санатория: ";
		fflush stdin;
		gets(hotel);
		break;
	case 4:
		cout << "Введите новую продолжительность: ";
		length=Tour::enterFieldValue();
		break;

	case 5:
		cout << "Введите новый тип питания: ";
		//char code[20];
		fflush stdin;
		gets(food_tip);
		//set_kod(code);
		break;

	case 6:
		cout << "Введите новый возраст: ";
		//char code[20];
		cout << "Введите начальный возрвст-> ";
		vosrast[0]=Tour::enterFieldValue();
		cout << "Введите предельный возраст-> ";
		vosrast[1]=Tour::enterFieldValue();

	case 0: return;

	}
}
void  Sea_Child_Tour::write_File(Sea_Child_Tour *tr,int count)
{
				fstream out("SeaChildTour.txt", ios::out | ios::trunc );
		if (!out.is_open())
		cout << "Ошибка открытия файла!" << endl;
		for(int i=0;i<count;i++)
				out << tr[i];
		out.close();
}
int Sea_Child_Tour::open_File(Sea_Child_Tour *sch)
{
	fstream in("SeaChildTour.txt", ios::in );
	if (!in.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	return 0;
	}
	int i=0;
		Sea_Child_Tour tmp;
			while (in >> tmp)
			{
				sch[i]= tmp;
				i++;
			}
		in.close();
		return i;
}

int Sea_Child_Tour::poisk(char *Country,int Cost)
{
	if (!strcmp(country,Country)&&Cost>=get_total_cost())
	{
		cout<< "**";
		print();
	return 1;
	}
	return 0;
}

int Sea_Child_Tour::sravn(char *code,int *date_v)
{
	int x=0;
	if(!strcmp(kod,code))
	{
		for(int i=0;i<n;i++)
		{
			if(day[i]==date_v[0]&& month[i]==date_v[1]&&year[i]==date_v[2]&&kol[i]>0)
			{
				x++;
				kol[i]--;
			}
		}
	}
	return x;
}


int Sea_Child_Tour:: poisk(int* date)
{
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(year[i]==date[2])
		{
			if(month[i]==date[1])
			{
				if(day[i]-date[0]<=14&&day[i]-date[0]>0)
				{
					cout<< "**";
					print();
					cout << "ОСТАЛОСЬ " << day[i]-date[0] <<" ДНЕЙ !!!" << endl << endl;
					x++;
				}
			}
			else 
				if(month[i]-date[1]==1&&!x)
				{
					if(date[0]>day[i]&&date[0]>=10)
					{
						int d=date[0]/10;
						if((d+1)*10+day[i]-date[0]<=14)
						{
							cout<< "**";
							print();
							cout << "ОСТАЛОСЬ " << (d+1)*10+day[i]-date[0] <<" ДНЕЙ !!!" << endl << endl;
							x++;
						}
					}

				}
		}

	}
	return x;
}

#endif