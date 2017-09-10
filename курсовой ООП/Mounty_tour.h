#ifndef Mounty_tour_h
#define Mounty_tour_h
//#define _CRT_NONSTDC_NO_DEPRECATE
//#include "Uncombined_tour.h"
#include <iostream>
#include <fstream>
#include <iomanip>
//#include "tour.h"
using namespace std;

class  Mounty_Tour: public Uncombined_Tour<int,char>
{
	char food_tip[20]; //тип питания (HB,BB,AL)
	int insurance;// стоимость страховки
	int rent_ski;//аренда горнолыжного снаряжения
public:
	Mounty_Tour():Uncombined_Tour()
	{insurance=0;
	rent_ski=0;
	}
	~Mounty_Tour(){};
	Mounty_Tour(int,int*,int*,int*,int *,char*,int,int,int,int,char *,char *,char *,char *,int,int);
	Mounty_Tour (const Mounty_Tour &);
	Mounty_Tour operator=(const Mounty_Tour obj)
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
	insurance=obj.insurance;
	rent_ski=obj.rent_ski;

		return *this;
	}
	void header();
	void add();
	void print();
	int print(char*);
	int poisk(char*,int);
	int poisk(char*,char*);
	int poisk(int*);
	void print_price();
	int print_com(char*);
	int sravn(char*,int*);
	void sort(){};
	void red();
	int open_File(Mounty_Tour*);
	void  write_File(Mounty_Tour *,int);
	int enterFieldValue();
	int enterRecordNumber(int);
	//void WorkDateTours();
	int get_total_cost()
		{
			//int One_percent=(float)(cost_trans+cost_of_living+insurance+rent_ski)/(100-comission);
			return comission+cost_trans+cost_of_living+insurance+rent_ski;
		}
	void set_insurance(int insurance)
	{
		this->insurance=insurance;
	}
	int get_insurance()
	{
		return insurance;
	}

	void set_rent_ski( int  rent_ski)
	{
		this->rent_ski=rent_ski;
	}
	int get_rent_ski()
	{
		return  rent_ski;
	}
	void set_food(char *Food)
	{
		strcpy(food_tip,Food);
	}
	char* get_food()
	{
		return food_tip;
	}
	friend ostream &operator<<(ostream &,Mounty_Tour &);
	friend istream &operator>>(istream &, Mounty_Tour &);

	friend fstream &operator<<(fstream &,Mounty_Tour &);
	friend fstream &operator>>(fstream &, Mounty_Tour &);

};

////////////////////////////////Класс Mounty_Tour///////////////////////////////////////////////
Mounty_Tour :: Mounty_Tour (int nn,int*D,int *M,int *Y,int *Kol,char *kod,int length,int cost_transport,int cost_of_living,int comission,char *country,char* city,char *hotel,char *fd,int insurance,int rent_ski): 
	Uncombined_Tour(nn,D,M,Y,Kol,kod,length,cost_transport,cost_of_living,comission,country,city,hotel)
{
	set_insurance(insurance);
	set_rent_ski(rent_ski);
}

Mounty_Tour :: Mounty_Tour (const Mounty_Tour &obj): Uncombined_Tour (obj)
{
	strcpy(food_tip,obj.food_tip);
	insurance = obj.insurance;
	rent_ski=obj.rent_ski;
	//cout<<"Rabotaet kK"<<endl;
}


void Mounty_Tour :: header()
{
cout << "\nГОРНОЛЫЖНЫЕ ТУРЫ" << endl;
				cout << "==================================================================================================" << endl;
				cout << "  Код       Страна        Курорт    Отель  Тип      Дата        Колич.  Всего    Общая      Валюта" << endl ;
				cout << "                                           питания  вылета      путёвок  ночей    стоимость" << endl;
				cout << "==================================================================================================" << endl;
}


void Mounty_Tour :: print()
{
	
	cout << setw(3) << kod; 
	cout  << setw(13) <<country;
	cout << setw(16) << city;
	cout << setw(6) <<  hotel;
	cout << setw(9) <<  food_tip;
	//cout.width(3);
		int i=0;
		cout <<setw(5) <<  day[i] <<"." << setw(2) <<month[i] <<"." <<year[i]; 
		cout << setw(7) << kol[i];
	cout << setw(8)  << length;
	cout << setw(12)  << get_total_cost();
	//cout << setw(14) << setiosflags(ios::right) << total_cost;
	cout <<  setw(5)  << val <<endl;
	//resetiosflags(ios::right);
	i++;
	for(;i<n;i++)
		{
			cout << setw(54) << day[i] <<"." << setw(2) <<month[i] <<"." <<year[i] << setw(7) << kol[i] << endl; 
	}

}
int Mounty_Tour :: print(char *kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(17) << get_total_cost();
		return get_total_cost();
	}
	return 0;
}
int Mounty_Tour :: print_com(char*kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(15) << comission << setw(7) << "BR" << endl;
		return comission;
	}
	return 0;

}

void Mounty_Tour :: print_price()
{
	cout << setw(3) << kod; 
	cout << setw(13) << cost_trans;
	cout << setw(18) << cost_of_living; 
	cout << setw(21) << comission;
	cout << setw(12) << insurance; 
	cout << setw(12) << rent_ski; 
	cout << setw(16) << get_total_cost(); 
	cout <<  setw(8)  <<  val <<endl;
}

fstream &operator<<(fstream &out, Mounty_Tour &obj)
{
	out << obj.n << " " ;
	for(int i=0;i<obj.n;i++)
	{
out << obj.day[i]<< " " ;
out << obj.month[i] << " ";
out << obj.year[i] << " ";
out << obj.kol[i]<< " ";
	}
	out << obj.kod <<" " << obj.length << " " <<  obj.cost_trans << " " << obj.cost_of_living << " " << obj.comission << " " << obj.country << " " << obj.city << " " << obj.hotel << " "  <<obj.food_tip << " "  << obj.insurance << " " << obj.rent_ski << endl;
	return out;
}


fstream &operator>>(fstream &in, Mounty_Tour &obj)
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
	//in >> obj.type_of_room ;
	//in >> obj.get_total_cost();
	
	in >> obj.insurance;
	in >> obj.rent_ski;
	return in;
}

istream &operator>>(istream &in, Mounty_Tour &obj)
{
	obj.Uncombined_Tour::Input();
	cout << "Введите тип питания(BB,HB,AL): ";
			fflush stdin;
			gets(obj.food_tip);
			cout << "Введите количество звёзд отеля: ";
			fflush stdin;
			gets(obj.hotel);
	cout << "Введите стоимость страховки:         BR\b\b\b\b\b\b\b\b\b\b";
			obj.insurance=obj.Tour::enterFieldValue();
			cout << "Введите стоимость горнолыжного инвентаря:         BR\b\b\b\b\b\b\b\b\b\b";
		   obj. rent_ski =obj.Tour::enterFieldValue();
		   return in;
}


//void Mounty_Tour::add()
//{
//cout << "ДОБАВЛЕНИЕ НОВОЙ ЗАПИСИ" << endl; cout << endl;
//			cout << "Введите код тура: ";
//
//			int x=0;
//			int fl=0;
//	/*while(!x)
//	{*/
//		fflush stdin;
//			gets(kod);
//			 /*x=1;
//			for(int i=0;i<count;i++)
//			{
//		if(!strcmp(t[i]->get_kod(),kod))
//		{
//			cout << endl; cout << "Тур с таким кодом уже есть" << endl;
//			cout << "Повторите ввод, пожалуйста: " << endl;
//			cin.clear();
//			x=0;
//			break;
//		}
//		  }*/
//	//		//fl++;
//	//}
//			//strcpy(kodd,enterFieldKod(t,count));
//			//t->set_kod(kod);
//			cout << "Введите страну: ";
//			fflush stdin;
//			gets(country);
//			cout << "Введите город: ";
//			fflush stdin;
//			gets(city);
//			cout << "Введите название отеля: ";
//			fflush stdin;
//			gets(hotel);
//			cout << "Введите количество дат выезда: ";
//			cin >> n;
//			cout << "Введите :Дата - количество мест: ";
//			for(int j=0;j<n;j++)
//			{
//				cout << "ДАТА № " << j+1 <<endl;
//				cout << "день-> ";
//				cin >> day[j];
//				cout << "месяц->: ";
//				cin >> month[j];
//				cout << "год->:XX\b\b";
//				cin >> year[j];
//				cout << "количество мест на эту дату->: ";
//				cin >> kol[j];
//			}
//			cout << "Введите тип питания: ";
//			fflush stdin;
//			gets(food_tip);
//			cout << "Введите продолжительность:     ночей\b\b\b\b\b\b\b\b";
//			length=Tour::enterFieldValue();
//			cout << "Введите стоимость перелёта:           Br\b\b\b\b\b\b\b\b\b\b";
//			cost_trans=Tour::enterFieldValue();
//			cout << "Введите стоимость проживания в отеле:             Br\b\b\b\b\b\b\b\b\b\b\b";
//			cost_of_living=Tour::enterFieldValue();
//			cout << "Введите величину комиссии турагенству:        %\b\b\b\b\b\b";
//			comission=Tour::enterFieldValue();
//			cout << "Введите стоимость страховки:         Br\b\b\b\b\b\b\b\b\b\b";
//			insurance=Tour::enterFieldValue();
//			cout << "Введите стоимость горнолыжного инвентаря:         Br\b\b\b\b\b\b\b\b\b\b";
//		    rent_ski =Tour::enterFieldValue();
//			//t[n]->set_Viezd(nn,D,M,Y,koll);
//			//t[n]->set_insurance(insurance);
//			//t[n]=new Mounty_Tour(kod,country,city,hotel,kol,date,length,total_cost,airfare,visa,cost_of_living,comission,insurance,rent_ski);
//
//}

//int Mounty_Tour::enterFieldValue()
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
//
//int Mounty_Tour::enterRecordNumber(int count)
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

void Mounty_Tour::red()
{
	//system("cls");
			int k;
			cout << endl << endl << "**** ЧТО ВЫ ХОТИТЕ ИЗМЕНИТЬ? ****" << endl;
			cout << "===================" << endl << endl;
			cout << "1.Cтрана" << endl;
			cout << "2.Город" << endl;
			cout << "3.Отель" << endl;
			cout << "4.Продолжительность" << endl;
			cout << "5.Тип питания" << endl;
			/*cout << "7.Cтрана" << endl;*/
			cout << "0.Назад" << endl << endl;
			cout << "===================" << endl;
			cout << "Ваш выбор:" << endl;
			cin >> k;
			switch (k) {

			//case 1:
			//	cout << "Введите новый код: ";
			//	//char code[20];
			//	fflush stdin;
			//gets(kod);
			//set_kod(kod);
			//break;
			case 1:
				cout << "Введите новую страну: ";
				fflush stdin;
			gets(country);
			break;
			case 2:
				cout << "Введите новый город: ";
				fflush stdin;
			gets(city);
			break;
			case 3:
				cout << "Введите новое количество звёзд в отеле: ";
					fflush stdin;
			gets(hotel);
			break;
			case 4:
				cout << "Введите новую продолжительность: ";
				length=Tour::enterFieldValue();
			break;

			case 5:
				cout << "Введите новый тип питания: ";
				fflush stdin;
			gets(food_tip);
			break;

			case 0:return;

			}
}
void  Mounty_Tour::write_File(Mounty_Tour *tr,int count)
{
	
				fstream out("MountyTour.txt", ios::out | ios::trunc );
		if (!out.is_open())
		cout << "Ошибка открытия файла!" << endl;
		for(int i=0;i<count;i++)
				out << tr[i];
		out.close();
}

int Mounty_Tour::open_File(Mounty_Tour *m)
{
	fstream in("MountyTour.txt", ios::in );
	if (!in.is_open())
	{
	return 0;
	}

	int i=0;
		Mounty_Tour tmp;
			while (in >> tmp)
			{
				m[i]= tmp;
				i++;
			}

		in.close();
		return i;
}

int Mounty_Tour::poisk(char *Country, int Cost)
{
	if (!strcmp(country,Country)&&Cost>=get_total_cost())
	{
		cout<< "**";
		print();
	return 1;
	}
	return 0;
}

int Mounty_Tour::poisk(char* Hotel,char* Ftip)
{
if (!strcmp(hotel,Hotel)&&(!strcmp(food_tip,Ftip)))
	{
		cout<< "**";
		print();
	return 1;
	}
	return 0;
}

int Mounty_Tour::sravn(char *code,int *date_v)
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

int Mounty_Tour:: poisk(int* date)
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