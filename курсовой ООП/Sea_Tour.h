#ifndef Sea_Tour_h
#define Sea_Tour_h
//#define _CRT_NONSTDC_NO_DEPRECATE
//#include "tour.h"
#include "Uncombined_tour.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


class Sea_Tour:virtual public Uncombined_Tour<int,char>
{
protected:
	//static char val[4];//Валюта
	char food_tip[20]; //тип питания (HB,BB,AL)
	int insurance; // стоимость страховки
public:
	Sea_Tour():Uncombined_Tour(){insurance=0;}
	~Sea_Tour(){};
	Sea_Tour(int,int*,int*,int*,int *,char*,int,int,int,int,char*,char*,char*,char*,int);
	Sea_Tour (const Sea_Tour &);
	Sea_Tour operator=(const Sea_Tour obj)
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

		return *this;
	}
	static void vvod(char*);
	void header();
	void red();
	void print();
	int print(char*);
	int print_com(char*);
	void print_price();
	
	int poisk(char*,int);
	int poisk(char*,char*);
	int poisk(int*);
	void add(Tour*[],int,int);
	void sort(){};
	int open_File(Sea_Tour *);
	void  write_File(Sea_Tour *,int,int);
	int enterFieldValue();
	int enterRecordNumber(int);
	void Input();
	void set_kol(int Kol,int i)
	{kol[i]=Kol;}
	int get_day(int i)
	{return day[i];}
	int get_month(int i)
	{return month[i];}
	int get_year(int i)
	{return year[i];}
	int get_kol(int i)
	{
		return kol[i];
	}
	int get_n()
	{
		return n;
	}
	int get_total_cost()
	{
		//int One_percent=(float)((cost_trans+cost_of_living+insurance)/(100-comission));
		return comission+cost_trans+cost_of_living+insurance;
	}
	void set_food(char *Food)
	{
		strcpy(food_tip,Food);
	}
	char* get_food()
	{
		return food_tip;
	}

	void set_insurance(int insurance)
	{
		this->insurance=insurance;
	}
	int get_insurance()
	{
		return insurance;
	}
	friend fstream &operator<<(fstream &,Sea_Tour &);
	friend fstream &operator>>(fstream &, Sea_Tour &);

	friend ostream &operator<<(ostream &,Sea_Tour &);
	friend istream &operator>>(istream &, Sea_Tour &);
};

//////////////////////////Класс Sea_Tour//////////////////////////////////////////////


Sea_Tour :: Sea_Tour (int nn,int*D,int *M,int *Y,int *Kol,char *kod,int length,int transport_cost,int cost_of_living,int comission,char*country,char *city, char *hotel,char*food_t,int insurance): 
	Uncombined_Tour(nn,D,M,Y,Kol,kod,length,transport_cost,cost_of_living,comission,country,city,hotel)
{
	set_food(food_t);
	set_insurance(insurance);
}


Sea_Tour :: Sea_Tour (const Sea_Tour &obj): Uncombined_Tour (obj)
{
	strcpy(food_tip,obj.food_tip);
	insurance = obj.insurance;
}

void Sea_Tour :: header()
{
	cout << "\nМОРСКИЕ ТУРЫ" << endl;
				cout << "==================================================================================================" << endl;
				cout << "  Код       Страна        Курорт    Отель  Тип      Дата        Колич.  Всего    Общая      Валюта" << endl ;
				cout << "                                           питания  вылета      путёвок  ночей    стоимость" << endl;
				cout << "==================================================================================================" << endl;
}


void Sea_Tour :: print()
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
	cout << setw(13)  << get_total_cost();
	//cout << setw(14) << setiosflags(ios::right) << total_cost;
	cout <<  setw(5)  << val <<endl;
	//resetiosflags(ios::right);
	i++;
	for(;i<n;i++)
	{
		cout << setw(54) << day[i] <<"." << setw(2) <<month[i] <<"." <<year[i] << setw(7) << kol[i] << endl; 
	}
}

int Sea_Tour :: print(char *kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(17) << get_total_cost();
		return get_total_cost();
	}
	return 0;
}

int Sea_Tour ::print_com(char*kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(15) << comission << setw(7) << "BR" << endl;
		return comission;
	}
	return 0;

}

void Sea_Tour :: print_price()
{
	cout << setw(3) << kod; 
	cout << setw(13) << cost_trans;
	cout << setw(18) << cost_of_living; 

	cout << setw(22) << comission ;
	cout << setw(13) << insurance; 
	cout << setw(13) << get_total_cost(); 
	cout <<  setw(8)  << val <<endl;

}
void Sea_Tour ::Input()
{
	cout << "Введите тип питания(BB,HB,AL): ";
	fflush stdin;
	gets(food_tip);
	cout << "Введите стоимость страховки:         BR\b\b\b\b\b\b\b\b\b\b";
	insurance=Tour::enterFieldValue();
}


istream& operator >> (istream & in, Sea_Tour& obj)
{ 
	obj.Uncombined_Tour::Input();
	obj.Input();
	cout << "Введите количество звёзд отеля(3*,4*,5*): ";
	fflush stdin;
	gets(obj.hotel);
	return in;
}

fstream &operator<<(fstream &out, Sea_Tour &obj)
{
	out << obj.n << " " ;
	for(int i=0;i<obj.n;i++)
	{
		out << obj.day[i]<< " " ;
		out << obj.month[i] << " ";
		out << obj.year[i] << " ";
		out << obj.kol[i]<< " ";
	}
	out << obj.kod <<" " << obj.length << " " <<  obj.cost_trans << " " << obj.cost_of_living << " " << obj.comission << " " << obj.country << " " << obj.city << " " << obj.hotel << " "  <<obj.food_tip << " "  << obj.insurance << endl;
	return out;
}

fstream &operator>>(fstream &in, Sea_Tour &obj)
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
	/*in >> obj.get_total_cost();*/
	in >> obj.food_tip;
	in >> obj.insurance;

	return in;
}


//void Sea_Tour::add(Tour *t[],int u,int count)
//{
//	cout << "ДОБАВЛЕНИЕ НОВОЙ ЗАПИСИ" << endl; cout << endl;
//	cout << "Введите код тура: ";
//	fflush stdin;
//	gets(kod);
//	cout << "Введите страну: ";
//	fflush stdin;
//	gets(country);
//	cout << "Введите город: ";
//	fflush stdin;
//	gets(city);
//	cout << "Введите название отеля: ";
//	fflush stdin;
//	gets(hotel);
//	cout << "Введите количество дат выезда: ";
//	cin >> n;
//	cout << "Введите :Дата - количество мест: ";
//	for(int j=0;j<n;j++)
//	{
//		cout << "ДАТА № " << j+1 <<endl;
//		cout << "день-> ";
//		cin >> day[j];
//		cout << "месяц->: ";
//		cin >> month[j];
//		cout << "год->:XX\b\b";
//		cin >> year[j];
//		cout << "количество мест на эту дату->: ";
//		cin >> kol[j];
//	}
//	
//	cout << "Введите продолжительность:     ночей\b\b\b\b\b\b\b\b";
//	length=Tour::enterFieldValue();
//	cout << "Введите стоимость перелёта:           Br\b\b\b\b\b\b\b\b\b\b";
//	cost_trans=Tour::enterFieldValue();
//	cout << "Введите стоимость проживания в отеле:             Br\b\b\b\b\b\b\b\b\b\b\b";
//	cost_of_living=Tour::enterFieldValue();
//	cout << "Введите величину комиссии турагенству:        %\b\b\b\b\b\b";
//	comission=Tour::enterFieldValue();
//	cout << "Введите количество звёзд отеля(3*,4*,5*): ";
//	fflush stdin;
//	gets(hotel);
//	cout << "Введите тип питания(BB,HB,AL): ";
//	fflush stdin;
//	gets(food_tip);
//	cout << "Введите стоимость страховки:         Br\b\b\b\b\b\b\b\b\b\b";
//	insurance=Tour::enterFieldValue();
//	
//}


int Sea_Tour::open_File(Sea_Tour *s)
{
	fstream in("SeaTour.txt", ios::in );
	if (!in.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 0;
	}
	int i=0;
	Sea_Tour tmp;
	while (in >> tmp)
	{
		s[i]= tmp;
		i++;
	}

	in.close();
	return i;
}


void  Sea_Tour::write_File(Sea_Tour *tr,int o,int count)
{
	//cout << "Запись"<< endl;	
	fstream out("SeaTour.txt", ios::out | ios::trunc );
	if (!out.is_open())
		cout << "Ошибка открытия файла!" << endl;
	for(int i=0;i<count;i++)
		out << tr[i];
	out.close();
}

//int Sea_Tour::enterFieldValue()
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
//int Sea_Tour::enterRecordNumber(int count)
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

void Sea_Tour::red()
{
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
	//	gets(kod);
	//	set_kod(kod);
	//	break;
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
		//char code[20];
		fflush stdin;
		gets(food_tip);
		//set_kod(code);
		break;

	}
}

int Sea_Tour::poisk(char *Country,int Cost)
{
	if (!strcmp(country,Country)&&Cost>=get_total_cost())
	{
		cout<< "**";
		print();
		return 1;
	}
	return 0;
}

int Sea_Tour::poisk(char* Hotel,char* Ftip)
{
	if (!strcmp(hotel,Hotel)&&(!strcmp(food_tip,Ftip)))
	{
		cout<< "**";
		print();
		return 1;
	}
	return 0;
}



int Sea_Tour:: poisk(int* date)
{
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(year[i]==date[2])
		{
			if(month[i]==date[1])
			{
				if(day[i]-date[0]<=14&&day[i]-date[0]>0&&!x)
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