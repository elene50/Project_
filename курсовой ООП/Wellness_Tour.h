#ifndef Wellness_Tour_h
#define Wellness_Tour_h
//#define _CRT_NONSTDC_NO_DEPRECATE
//#include "Uncombined_tour.h"
#include <iomanip>
#include <iostream>
#include <fstream>
//#include "tour.h"
using namespace std;

////////////////////////////////////Производный класс Child_Tour///////////////////////////////////
class  Child_Tour: virtual public Uncombined_Tour<int,char>
{
protected:
	int cost_vosp;//Стоимость услуг воспитателя
	int vosrast[2];//Возраст
public:
	Child_Tour():Uncombined_Tour(){
		cost_vosp=0;
		vosrast[0]=0;
		vosrast[1]=0;
	}
	~Child_Tour(){};
	Child_Tour(int,int*,int*,int*,int *,char*,int,int,int,int,char*,char*,char*,int,int*);
	Child_Tour (const Child_Tour &);
	Child_Tour operator=(const Child_Tour obj)
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
	cost_vosp=obj.cost_vosp;
	vosrast[0]=obj.vosrast[0];
	vosrast[1]=obj.vosrast[1];
		return *this;
	}
	int get_total_cost()
		{
			//int One_percent=(float)(cost_trans+cost_of_living+cost_vosp)/(100-comission);
			return comission+cost_trans+cost_of_living+cost_vosp;
		}
	void header();
	void print();
	int print(char*);
	int print_com(char*);
	void print_price();
	int poisk(char*,int);
	int poisk(int* );
	int sravn(char*,int*);
	void sort(){};
	void red();
	//void add(Tour*[],int,int);
	void add();
	int open_File(Child_Tour*);
	void  write_File(Child_Tour*,int);
	int enterFieldValue();
	int enterRecordNumber(int);
	void Input();
	
	void set_cost_vosp(int cost)
	{
		cost_vosp=cost;
	}
	int get_cost_vosp()
	{
		return cost_vosp;
	}
	void set_vosrast(int *vosr)
	{
		vosrast[0]=vosr[0];
		vosrast[1]=vosr[1];
	}
	int* get_vosrast()
	{
		return vosrast;
	}

	friend ostream &operator<<(ostream &,Child_Tour &);
	friend istream &operator>>(istream &, Child_Tour &);

	friend fstream &operator<<(fstream &,Child_Tour &);
	friend fstream &operator>>(fstream &, Child_Tour &);
};

////////////////////////////////Класс Child_Tour///////////////////////////////////////////////
Child_Tour :: Child_Tour (int nn,int*D,int *M,int *Y,int *Kol,char *kod,int length,int transport_cost,int cost_of_living,int comission,char*country,char *city, char *hotel,int Cost_vosp, int *vosr): 
	Uncombined_Tour(nn,D,M,Y,Kol,kod,length,transport_cost,cost_of_living,comission,country,city,hotel)
{
		 set_cost_vosp(Cost_vosp);
		 set_vosrast(vosr);
}

Child_Tour :: Child_Tour (const Child_Tour &obj): Uncombined_Tour (obj)
{
	 cost_vosp=obj.cost_vosp;
	 vosrast[0]=obj.vosrast[0];
	  vosrast[1]=obj.vosrast[1];
}

void Child_Tour ::  header()
{
cout << "\nДЕТСКИЕ ЛАГЕРЯ" << endl;
				cout << "=============================================================================================================" << endl;
				cout << "  Код       Страна         Город       Лагерь        Дата        Колич.   Всего    Возраст  Общая      Валюта" << endl ;
				cout << "                                                    вылета       путёвок  ночей             стоимость" << endl;
				cout << "=============================================================================================================" << endl;
}

void Child_Tour :: Input()
{
	cout << "Введите допустимый возраст детей:" <<endl;
			cout << "Введите начальный возраст->";
			vosrast[0]=Tour::enterFieldValue();
			cout << "Введите предельный возраст->";
			vosrast[1]=Tour::enterFieldValue();
			cout << "Введите стоимость услуг воспитателя:            BR\b\b\b\b\b\b\b\b\b\b\b";
			cost_vosp=Tour::enterFieldValue();
}


void Child_Tour :: print()
{
	cout << setw(3) << kod; 
	cout  << setw(13) <<country;
	cout << setw(16) << city;
	cout << setw(13) <<  hotel;
	//cout.width(3);
		int i=0;
		cout <<setw(7) <<  day[i] <<"." << setw(2) <<month[i] <<"." <<year[i]; 
		cout << setw(7) << kol[i];
	cout << setw(8)  << length;
	cout << setw(8)  << vosrast[0] << "-" << vosrast[1] ;
	cout << setw(12)  << get_total_cost();
	//cout << setw(14) << setiosflags(ios::right) << total_cost;
	cout <<  setw(5)  << val <<endl;
	//resetiosflags(ios::right);
	i++;
	for(;i<n;i++)
		{
			cout << setw(54) << day[i] <<"." << setw(2) <<month[i] <<"." <<year[i] << setw(7) << kol[i] << endl; 
	}

	//cout << setw(3) << kod; 
	//cout  << setw(13) <<country;
	//cout << setw(15) << city;
	//cout << setw(14) <<  hotel;
	////cout.width(3);
	//	int i=0;
	//	cout <<setw(8) <<  Viezd.day[i] <<"." << setw(2) <<Viezd.month[i] <<"." <<Viezd.year[i]; 
	//	cout << setw(7) << Viezd.kol[i];
	//cout << setw(8)  << length;
	////cout << setw(14) << setiosflags(ios::right) << total_cost;
	//cout << setw(8)  << vosrast[0] << "-" << vosrast[1] ;
	//cout <<  setw(4)  << "BR" <<endl;
	////resetiosflags(ios::right);
	//i++;
	//for(;i<Viezd.n;i++)
	//	{
	//		cout << setw(55) << Viezd.day[i] <<"." << setw(2) <<Viezd.month[i] <<"." <<Viezd.year[i] << setw(7) << Viezd.kol[i] << endl; 
	//}

	//resetiosflags(ios::right);
	//cout << setw(10) << setiosflags(ios::left) << airfare;
	//cout << setw(10) << setiosflags(ios::left) << visa;
	//cout << setw(10) << setiosflags(ios::left) << cost_of_living;
	//cout << setw(3) << setiosflags(ios::left) << comission;
		//cout << setw(10) << setiosflags(ios::left) << cost_of_treatment;

}

int Child_Tour:: print(char *kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(17) << get_total_cost();
		return get_total_cost();
	}
	return 0;
}

int Child_Tour:: print_com(char*kode)
{
	if(!strcmp(kod,kode))
	{
		cout << setw(15) << comission << setw(7) << "BR" << endl;
		return comission;
	}
	return 0;

}
void Child_Tour ::print_price()
{
	cout << setw(3) << kod; 
	cout << setw(13) << cost_trans;
	cout << setw(18) << cost_of_living; 
	cout << setw(20) << comission;
	cout << setw(12) << cost_vosp; 
	cout << setw(18) << get_total_cost(); 
	cout <<  setw(8)  <<  val <<endl;
}


fstream &operator<<(fstream &out, Child_Tour &obj)
{
	out << obj.n << " " ;
	for(int i=0;i<obj.n;i++)
	{
out << obj.day[i]<< " " ;
out << obj.month[i] << " ";
out << obj.year[i] << " ";
out << obj.kol[i]<< " ";
	}
	out << obj.kod <<" " << obj.length << " " <<  obj.cost_trans << " " << obj.cost_of_living << " " << obj.comission << " " << obj.country << " " << obj.city << " " << obj.hotel << " " << obj.cost_vosp << " " <<obj.vosrast[0] <<" " << obj.vosrast[1] << endl;
	return out;
}

fstream &operator>>(fstream &in, Child_Tour &obj)
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
	//in >> obj.type_of_room ;
	//in >> obj.total_cost;
	in >> obj.cost_vosp;
	in >> obj.vosrast[0];
	in >> obj.vosrast[1];
	return in;
}

istream &operator>>(istream &in, Child_Tour &obj)
{
	obj.Uncombined_Tour::Input();
		cout << "Введите название лагеря: ";
			fflush stdin;
			gets(obj.hotel);
	obj.Input();

			return in;
	
}


void Child_Tour::add()
{
			cout << "ДОБАВЛЕНИЕ НОВОЙ ЗАПИСИ" << endl; cout << endl;
			cout << "Введите код тура: ";
		fflush stdin;
			gets(kod);
			cout << "Введите страну: ";
			fflush stdin;
			gets(country);
			cout << "Введите город: ";
			fflush stdin;
			gets(city);
			cout << "Введите название лагеря: ";
			fflush stdin;
			gets(hotel);
			cout << "Введите количество дат выезда: ";
			cin >> n;
			cout << "Введите :Дата - количество мест: ";
			for(int j=0;j<n;j++)
			{
				cout << "ДАТА № " << j+1 <<endl;
				cout << "день-> ";
				cin >> day[j];
				cout << "месяц->: ";
				cin >> month[j];
				cout << "год->:XX\b\b";
				cin >> year[j];
				cout << "количество мест на эту дату->: ";
				cin >> kol[j];
			}
			cout << "Введите продолжительность:     ночей\b\b\b\b\b\b\b\b";
			length=Tour::enterFieldValue();
			cout << "Введите стоимость перелёта:           Br\b\b\b\b\b\b\b\b\b\b";
			cost_trans=Tour::enterFieldValue();
			cout << "Введите стоимость проживания в отеле:             Br\b\b\b\b\b\b\b\b\b\b\b";
			cost_of_living=Tour::enterFieldValue();
			cout << "Введите величину комиссии турагенству:             Br\b\b\b\b\b\b\b\b\b\b\b";
			comission=Tour::enterFieldValue();
			cout << "Введите допустимый возраст детей:" <<endl;
			cout << "Введите начальный возраст->";
			vosrast[0]=Tour::enterFieldValue();
			cout << "Введите предельный возраст->";
			vosrast[1]=Tour::enterFieldValue();
			cout << "Введите стоимость услуг воспитателя:        Br\b\b\b\b\b\b";
			cost_vosp=Tour::enterFieldValue();
}

void Child_Tour::red()
{
			int k;
			cout << endl << endl << "**** ЧТО ВЫ ХОТИТЕ ИЗМЕНИТЬ? ****" << endl;
			cout << "===================" << endl << endl;
			//cout << "1.Код" << endl;
			cout << "1.Cтрана" << endl;
			cout << "2.Город" << endl;
			cout << "3.Лагерь" << endl;
			cout << "4.Продолжительность" << endl;
			cout << "5.Возраст" << endl;
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
				cout << "Введите новое название лагеря: ";
					fflush stdin;
			gets(hotel);
			break;
			case 4:
				cout << "Введите новую продолжительность: ";
				length=Tour::enterFieldValue();
			break;

			case 5:
				cout << "Введите новый возраст: ";
			cout << "Введите начальный возрвст-> ";
			vosrast[0]=Tour::enterFieldValue();
			cout << "Введите предельный возраст-> ";
			vosrast[1]=Tour::enterFieldValue();
			//set_kod(code);
			break;

			}
}

//int Child_Tour::enterFieldValue()
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
//int Child_Tour::enterRecordNumber(int count)
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
void  Child_Tour::write_File(Child_Tour *tr,int count)
{			
		fstream out("ChildTour.txt", ios::out | ios::trunc );
		if (!out.is_open())
		cout << "Ошибка открытия файла!" << endl;
		for(int i=0;i<count;i++)
				out << tr[i];
		out.close();

}
int Child_Tour::open_File(Child_Tour *m)
{
	fstream in("ChildTour.txt", ios::in );
	if (!in.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	return 0;
	}
	int i=0;
		Child_Tour tmp;
			while (in >> tmp)
			{
				m[i]= tmp;
				i++;
			}

		in.close();
		return i;
}

int Child_Tour::poisk(char* Country, int Cost)
{
	if (!strcmp(country,Country)&&Cost>=get_total_cost())
	{
		cout<< "**";
		print();
	return 1;
	}
	return 0;
}

int Child_Tour::sravn(char *code,int *date_v)
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

int Child_Tour:: poisk(int* date)
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