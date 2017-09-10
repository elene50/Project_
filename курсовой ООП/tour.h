#ifndef tour_h
#define tour_h
//#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <iomanip>
using namespace std;

////////////////////////АБСТРАКТНЫЙ КЛАСС TOUR////////////////////////////////////////////////////////////
template<class T1,class T2>
class Tour{
protected:
	
	T1 n;
	T1 day[10];
	T1 month[10];
	T1 year[10];
	T1 kol[10];
	T2 kod[20];  //код тура
	T1 length; //продолжительность пребывания
	T1 cost_trans; //стоимость транспорта
	T1 cost_of_living; //стоимость проживания в отеле
	T1 comission; //комиссия турагенству
public:
	Tour();
	Tour(T1,T1*,T1*,T1*,T1 *,T2*,T1,T1,T1,T1);
	Tour(const Tour &);
	virtual ~Tour(){};
	virtual void print()=0;
	virtual void sort()=0;
	virtual void red()=0;
	virtual void header()=0;
	T1 enterFieldValue();
	T1 enterRecordNumber(T1);
	//T1 sravn(T2*,T1*);

	
	T1 poisk(T1*);
	static void vvod(char*);
	static T2 val[4];//Валюта
	//virtual void add(Tour *[],int,int)=0;
	//virtual int open_File(Sea_Tour *[])=0;
	//virtual void write_File(Tour *[],int,int)=0;
	//virtual void cost_kalkulate();
	void set_kol(T1 Kol,T1 i)
	{kol[i]=Kol;}
	T1 get_day(T1 i)
	{return day[i];}
	T1 get_month(T1 i)
	{return month[i];}
	T1 get_year(T1 i)
	{return year[i];}
	T1 get_kol(T1 i)
	{
		return kol[i];
	}
	T1 get_n()
	{
		return n;
	}
	void set_kod(T2 *kod)
	{
		strcpy(this->kod,kod);
	}
	T2* get_kod()
	{
		return kod;
	}

	/*int get_day(int i)
	{
	return Viezd.day[i];
	}
	int get_month(int i)
	{
	return Viezd.month[i];
	}
	int get_year(int i)
	{
	return Viezd.year[i];
	}
	int get_kol(int i)
	{
	return Viezd.kol[i];
	}*/
	void set_length(T1 l)
	{
		length=l;
	}

	T1 get_length()
	{
		return length;
	}


	void set_cost_trans(T1 airfare)
	{
		this->cost_trans=cost_trans;
	}
	T1 get_trans()
	{
		return cost_trans;
	}

	void set_cost_of_living(T1 cost_of_living)
	{
		this->cost_of_living=cost_of_living;
	}
	T1 get_cost_of_living()
	{
		return cost_of_living;
	}
	void set_comission(T1 comission)
	{
		this->comission=comission;
	}
	T1 get_comission()
	{
		return comission;
	}
	/*virtual void  set_country(char *country)
	{
	;
	}
	virtual char* get_country()
	{
	;
	}
	void set_city(char *city)
	{
	strcpy(this->city,city);
	}
	char* get_city()
	{
	return city;
	}

	void set_hotel(char *hotel)
	{
	strcpy(this->hotel,hotel);
	}
	char* get_hotel()
	{
	return hotel;
	}*/

};

template<class T1,class T2>
char Tour<T1,T2>::val[4];//static - член валюта

template<class T1,class T2>
void Tour<T1,T2>:: vvod(char *Val)
{
	strcpy(val,Val);
}

///////////////////////////Класс Tour///////////////////////////////////////////
template<class T1,class T2>
Tour <T1,T2>:: Tour()
{
	length=0;
	cost_trans=0;
	cost_of_living=0;
	comission=0;
}

template<class T1,class T2>
Tour <T1,T2> :: Tour (T1 nn,T1*D,T1 *M,T1 *Y,T1 *Kol,T2 *kod,T1 length,T1 transport_cost,T1 cost_of_living,T1 comission)
{
	n=nn;
	for(int i=0;i<nn;i++)
	{
		day[i]=D[i];
		month[i]=M[i];
		year[i]=Y[i];
		kol[i]=Kol[i];
	}

	set_kod(kod);
	set_length(length);
	set_cost_trans(transport_cost);
	set_cost_of_living(cost_of_living);
	set_comission(comission);

}


template<class T1,class T2>
Tour <T1,T2>:: Tour (const Tour<T1,T2> & obj)
{

	n= obj.n ;
	for(int i=0;i<obj.n;i++)
	{
		day[i]=obj.day[i];
		month[i]=obj.month[i];
		year[i]= obj.year[i];
		kol[i]=obj.kol[i];
	}
	strcpy(kod,obj.kod);
	length=obj.length;
	cost_trans=obj.cost_trans;
	cost_of_living=obj.cost_of_living;
	comission=obj.comission;
}

template<class T1,class T2>
T1 Tour <T1,T2>::enterFieldValue()
{
	int fl=0;
	int x;
	while(fl == 0)
	{
		cin >> x;
		if(!cin || x!=int(x))
		{
			cout << endl; cout << "Ошибка ввода!\a" << endl;
			cout << "Повторите ввод, пожалуйста: " << endl;
			cin.clear();
			while(cin.get()!='\n');
			continue;
		}
		else fl++;
	}
	return x;
}


template<class T1,class T2>
T1 Tour <T1,T2>::enterRecordNumber(T1 count)
{
	int fl = 0;
	int x;
	while (fl == 0)
	{
		cin >> x;
		if (!cin || x != int(x) || x <= 0 || x >count)
		{
			cout << "Ошибка ввода! Попробуйте ещё раз" << endl;
			cin.clear();
			while (cin.get() != '\n');
			continue;

		}
		else fl++;
	}
	return x;
}






template<class T1,class T2>
T1 Tour <T1,T2>:: poisk(T1* date)
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

//////////////////////////////////Класс Client////////////////////////////////////////
template<class T1, class T2>
class Client
{
protected:
	//List <Client> cl  ;
	T2 Name[80]; //ФиО клиента
	T1 tel_number;// Номер телефона клиента
	T2 passport[20];// Паспортные данные
	T2 kod_tour[20];// Код выбранного тура
	T1 date_viezd[3];// Выбранная дата отправления
	T2 Name_sotr[20];// ФИО сотрудника, проводившего регистрацию
	T1 date_reg[3];//Дата регистрации путёвки
public:
	Client();
	~ Client(){};
	Client(T2 *,T1, T2 *,T2 *,T1 *,T2 *,T1*);
	Client (const Client &);
	/* Client operator=(const Client obj)
	{
	strcpy(Name,obj.Name);
	tel_number=obj.tel_number;
	strcpy(passport,obj.passport);
	strcpy(kod_tour,obj.kod_tour);
	date_viezd[0]=obj.date_viezd[0];
	date_viezd[1]=obj.date_viezd[1];
	date_viezd[2]=obj.date_viezd[2];
	strcpy(Name_sotr,obj.Name_sotr);
	date_reg[0]=obj.date_reg[0];
	date_reg[1]=obj.date_reg[1];
	date_reg[2]=obj.date_reg[2];

	return *this;
	}*/
	void add();
	void red();
	void Input();
	void see();
	void see1();
	void statistic(Client *[],T2[][20],T1,T1);
	char* see_date(T1,T1);
	void write_File(Client *[],T1);
	T1 open_File(Client *[]);
	T1 poisk_sotr(Client *[],T1);
	void set_name_kl( T2 *name)
	{
		strcpy(Name,name);
	}
	void set_tel_numder(T1 tel)
	{
		tel_number=tel;
	}
	void set_passport(T2 *Pasport)
	{
		strcpy(passport,Pasport);
	}
	void set_kod_tour(T2 *kod)
	{
		strcpy(kod_tour,kod);
	}
	void set_date_viezd(T1 *date)
	{
		date_viezd[0]=date[0];
		date_viezd[1]=date[1];
		date_viezd[2]=date[2];
	}
	void set_sotr(T2 *sotr)
	{
		strcpy(Name_sotr,sotr);
	}

	void set_date_reg(T1 *date)
	{
		date_reg[0]=date[0];
		date_reg[1]=date[1];
		date_reg[2]=date[2];
	}
	T1 get_date_reg_year()
	{
		return date_reg[2];
	}
	T2* get_kod_tour()
	{
		return kod_tour;
	}
	/*friend ostream &operator<<(ostream &, Client &);
	friend istream &operator>>(istream &,  Client &);*/

};

template<class T1, class T2>
Client <T1,T2>:: Client()
{
	tel_number=0;
	date_viezd[0]=0;
	date_viezd[1]=0;
	date_viezd[2]=0;
	date_reg[0]=0;
	date_reg[1]=0;
	date_reg[2]=0;
}

template<class T1, class T2>
Client <T1,T2>:: Client(T2* name,T1 num, T2 *passp,T2 *code,T1 *viesd,T2 *name_s,T1*reg)
{
	set_name_kl(name);
	set_tel_numder(num);
	set_passport(passp);
	set_kod_tour(code);
	set_date_viezd(viesd);
	set_sotr(name_s);
	set_date_reg(reg);
}

template<class T1, class T2>
Client <T1,T2>:: Client(const Client & obj)
{
	strcpy(Name,obj.Name);
	tel_number=obj.tel_number;
	strcpy(passport,obj.passport);
	strcpy(kod_tour,obj.kod_tour);
	date_viezd[0]=obj.date_viezd[0];
	date_viezd[1]=obj.date_viezd[1];
	date_viezd[2]=obj.date_viezd[2];
	strcpy(Name_sotr,obj.Name_sotr);
	date_reg[0]=obj.date_reg[0];
	date_reg[1]=obj.date_reg[1];
	date_reg[2]=obj.date_reg[2];
}

//template<class T1, class T2>
//ostream &operator<<(ostream &out, Client &obj)
//{
//	out << obj.Name <<" " << obj.tel_number << " " <<  obj.passport << " " << obj.kod_tour << " " << obj.date_viezd << " " << obj.Name_sotr << " " << obj.date_reg << endl;
//	return out;
//}
//template<class T1, class T2,class T3>
//istream &operator>>(istream &in, Client &obj)
//{ 
//	in >> obj.Name;
//	in >> obj.tel_number;
//	in >> obj.passport;
//	in >> obj.kod_tour;
//	in >> obj.date_viezd;
//	in >> obj.Name_sotr;
//	in >> obj.date_reg;
//	return in;
//}

template<class T1, class T2>
void Client <T1,T2>::add()
{

	cout << "ДОБАВЛЕНИЕ НОВОЙ ЗАПИСИ" << endl; cout << endl;
	cout << "Введите фамилию клиента: ";
	fflush stdin;
	gets( Name);
	cout << "Введите номер телефона: ";
	cin >> tel_number;
	cout << "Введите номер  паспорта: ";
	fflush stdin;
	gets(passport);
	cout << "Введите код выбранного тура: ";
	fflush stdin;
	gets(kod_tour);
	cout << "Введите Дату выезда" << endl;
	cout << "Введите день: ";
	cin >> date_viezd[0];
	cout << "Введите месяц: ";
	cin >> date_viezd[1];
	cout << "Введите год: ";
	cin >> date_viezd[2];
	cout << "Введите фамилию сотрудника-регистратора: ";
	fflush stdin;
	gets(Name_sotr);
	cout << "Введите Дату оформления путёвки" << endl;
	cout << "Введите день: ";
	cin >> date_reg[0];
	cout << "Введите месяц: ";
	cin >> date_reg[1];
	cout << "Введите год: ";
	cin >> date_reg[2];
}

template<class T1, class T2>
void Client <T1,T2>::see()
{
	cout << setw(11) << Name; 
	cout  << setw(12) << tel_number;
	cout << setw(13) << passport;
	cout << setw(7) <<  kod_tour;
	cout << setw(9) <<  date_viezd[0] << "." << setw(2) << date_viezd[1] << "." << date_viezd[2] ;
	cout << setw(14) << Name_sotr ;
	cout << setw(10) << date_reg[0] << "." << setw(2) << date_reg[1] << "." << date_reg[2] << endl;

}

template<class T1, class T2>
void Client <T1,T2>::see1()
{
	cout << setw(11) << Name; 
	cout  << setw(12) << tel_number;
	cout << setw(11) <<  kod_tour;
	cout << setw(16) << Name_sotr ;
	cout << setw(8) << date_reg[0] << "." << setw(2) << date_reg[1] << "." << date_reg[2];
}

template<class T1, class T2>
void Client <T1,T2>::write_File(Client *tr[],T1 count)
{

	//cout << "Запись"<< endl;	
	ofstream out("Client.txt", ios::out | ios::trunc );
	if (!out.is_open())
		cout << "Ошибка открытия файла!" << endl;
	for(int i=0;i<count;i++)
	{
		out.write((char*)(&tr[i]->Name), sizeof(tr[i]->Name));
		out.write((char*)(&tr[i]->tel_number), sizeof(tr[i]->tel_number));
		out.write((char*)(&tr[i]->passport), sizeof(tr[i]->passport));
		out.write((char*)(&tr[i]->kod_tour), sizeof(tr[i]->kod_tour));
		out.write((char*)(&tr[i]->date_viezd), sizeof(tr[i]->date_viezd));
		out.write((char*)(&tr[i]->Name_sotr), sizeof(tr[i]->Name_sotr));
		out.write((char*)(&tr[i]->date_reg), sizeof(tr[i]->date_reg));


	}

	out.close();

}

template<class T1, class T2>
T1 Client <T1,T2>::open_File(Client *s[])
{

	ifstream in("Client.txt", ios::in );
	if (!in.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 0;
	}

	int i=0;

	system("pause");
	//while (in >> tmp)
	s[i]=new Client;
	while((in.read((char*)&(s[i]->Name), sizeof(s[i]->Name)))&&(in.read((char*)&(s[i]->tel_number), sizeof(s[i]->tel_number)))&&
		(in.read((char*)&(s[i]->passport), sizeof(s[i]->passport)))&&(in.read((char*)&(s[i]->kod_tour), sizeof(s[i]->kod_tour)))&&
		(in.read((char*)&(s[i]->date_viezd), sizeof(s[i]->date_viezd)))&&(in.read((char*)&(s[i]->Name_sotr), sizeof(s[i]->Name_sotr)))&&
		(in.read((char*)&(s[i]->date_reg), sizeof(s[i]->date_reg))))
	{
		i++;
		s[i]=new Client;

	}		

	in.close();
	return i;
}

template<class T1, class T2>
char* Client <T1,T2>::see_date(T1 m,T1 y)
{
	if(m==date_reg[1]&&y==date_reg[2])
	{
		return kod_tour;
	}
	else return NULL;
}

template<class T1, class T2>
T1 Client <T1,T2>::poisk_sotr(Client *cl[],T1 count)
{
	char sotr[10][50];
	int x=0,c=0;
	for(int i=0;i<count;i++)
	{
		x=0;
		for(int j=0;j<c;j++)
		{
			if(!strcmp(sotr[j],cl[i]->Name_sotr))
				x++;
		}
		if(!x)
		{
			strcpy(sotr[c],cl[i]->Name_sotr);
			c++;
		}
	}
	for(int i=0;i<c;i++)
		cout<<sotr[i] << endl;
	return c;
}

template<class T1, class T2>
void Client <T1,T2>::statistic(Client *cl[],T2 str[][20], T1 ii,T1 count)
{
	system("cls");
	int Year,kol[50],x,y,koll,c=0;
	char buf[20][20];
	cout << "Введите год: ";
	cin >> Year;
	cout << endl;
	cout << "Статистика проданных туров за " << Year << " год " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Тур  Количество" << endl;
	cout << "------------------------------------------------" << endl;
	for(int i=0;i<ii;i++)
	{
		kol[i]=0;
		for(int j=0;j<count;j++)
		{
			if(!(strcmp(str[i],cl[j]->kod_tour))&& Year==cl[j]->date_reg[2])
				kol[i]++;
		}
		cout << setw(3) << str[i] << "|" << setw(4) << kol[i] <<  setw(8) << "|" << endl;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////
	for(int j=0;j<count;j++)
	{
		x=0;
		y=0;
		for(int i=0;i<ii;i++)
		{    
			if(!strcmp(cl[j]->kod_tour,str[i]))
				x++;
		}
		if(!x)
		{
	for(int k=0;k<c;k++)
			{
				if(!strcmp(buf[k],cl[j]->kod_tour))
					y++;
			}
			if(!y&&Year==cl[j]->date_reg[2])
			{
				strcpy(buf[c],cl[j]->kod_tour);
				c++;
			}
		}
	}
	for(int i=0;i<c;i++)
	{
		koll=0;
		for(int j=0;j<count;j++)
		{
			if(!strcmp(buf[i],cl[j]->kod_tour)&&Year==cl[j]->date_reg[2])
			{
				koll++;
			}
		}
		cout << setw(3) << buf[i] << "|" << setw(4) << koll <<  setw(8) << "|" << endl;
	}
	cout << "------------------------------------------------" << endl;

}
/////////////////////////////////////////////////////////////


#endif
