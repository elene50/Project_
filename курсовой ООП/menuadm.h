#include "tour.h"
#include "Sea_Tour.h"
#include "Sea_Child_Tour.h"
#include "Mounty_tour.h"
#include "Wellness_Tour.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdlib.h>

class MenuAdm
{
public:
	int Menu_operations_Pols();
	char MenuAdmin();
	//char MenuAuthorised();

	int Menu_operations_Admin();
	int Menu_for_Clients();
	int Menu_choice_tour();
	int MenuUser();
	int Menu_for_Clients_pols();
	int enterFieldValue();
	int MenuAdm::enterRecordNumber(int );
	void admin_Work();

	void user_Work();
};

//char MenuAuthorised()
//{ 
//	char u;
//	cout<<"\n\t** А В Т О Р И З А Ц И Я ** \n"<<endl;
//	cout<<"\t1.Администратор\n\t2.Пользователь\n\t0.Выход из программы\n";
//	cout<<"\tВаш выбор:";
//	cin>>u;
//	return u;
//}
char MenuAdm:: MenuAdmin()
{ 
	char k;
	cout << endl << endl << "**** МЕНЮ ****" << endl;
	cout << "===================" << endl << endl;
	cout << "1.Работа с данными <Клиенты>" << endl;
	cout << "2.Работа с данными <Туры>" << endl;
	cout << "3.Прайс лист" << endl;
	cout << "0.Выход" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	return k;
}
int MenuAdm::MenuUser()
{
	int k;
	cout << endl << endl << "**** МЕНЮ ****" << endl;
	cout << "===================" << endl << endl;
	cout << "1.Работа с данными <Клиенты>" << endl;
	cout << "2.Работа с данными <Туры>" << endl;
	cout << "0.Выход" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	return k;
}


int MenuAdm:: Menu_for_Clients()
{
	int k;
	cout << endl << endl << "**** МЕНЮ ****" << endl;
	cout << "===================" << endl << endl;
	cout << "1.Просмотр всех клиентов" << endl;
	cout << "2.Просмотреть путёвки, реализованные в текущем месяце" << endl;
	cout << "3.Статистика туров" << endl << endl;
	cout << "0.Вернуться в главное меню" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	return k;
}
int MenuAdm:: Menu_for_Clients_pols()
{
	int k;
	cout << endl << endl << "**** МЕНЮ ****" << endl;
	cout << "===================" << endl << endl;
	cout << "1.Оформить путёвку" << endl;
	cout << "2.Просмотр всех клиентов" << endl;
	cout << "3.Статистика туров" << endl;
	cout << "0.Вернуться в главное меню" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	return k;
}
int MenuAdm::Menu_operations_Pols()
{
	int k;
	cout << endl << endl << "**** МЕНЮ ****" << endl;
	cout << "===================" << endl << endl;
	cout << "1.Просмотр всех записей" << endl;
	cout << "2.Поиск туров по стране и стоимости" << endl;
	cout << "3.Поиск туров по отелю и типу питания" << endl;
	cout << "4.Поиск горящих туров" << endl;
	cout << "0.Вернуться в главное меню" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	return k;
}

int MenuAdm::Menu_operations_Admin()
{
	int k;
	cout << endl << endl << "**** МЕНЮ ****" << endl;
	cout << "===================" << endl << endl;
	cout << "1.Добавление новой записи" << endl;
	cout << "2.Просмотр всех записей" << endl;
	cout << "3.Редактирование записи" << endl;
	cout << "4.Удаление записи" << endl;
	cout << "5.Поиск туров по стране и стоимости" << endl;
	cout << "6.Поиск туров по отелю и типу питания" << endl;
	cout << "7.Вывод  горящих туров" << endl;
	cout << "0.Вернуться в главное меню" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	return k;
}
int MenuAdm::Menu_choice_tour()
{
	int k;
	cout << endl << endl << "**** ВЫБЕРИТЕ ТИП ТУРА ****" << endl;
	cout << "===================" << endl << endl;
	cout << "1.Морской тур" << endl;
	cout << "2.Горнолыжный тур" << endl;
	cout << "3.Детские лагеря" << endl;
	cout << "4.Детские санатории на море" << endl << endl;
	cout << "0.Выход" << endl << endl;
	cout << "===================" << endl;
	cout << "Ваш выбор:" << endl;
	cin >> k;
	return k;
}

int MenuAdm::enterFieldValue()
{
	int fl=0;
	double x;
	while(fl == 0)
	{
		cin >> x;
		if(!cin || x!=int(x))
		{
			cout << endl; cout << "Ошибка ввод!\a" << endl;
			cout << "Повторите ввод, пожалуйста: " << endl;
			cin.clear();
			while(cin.get()!='\n');
			continue;
		}
		else fl++;
	}
	return x;
}


int MenuAdm::enterRecordNumber(int count)
{
	int fl = 0;
	int x;
	while (fl == 0)
	{
		cin >> x;
		if (!cin || x != int(x) || x <= 0 || x >count)
		{
			cout << "Ошибка ввода! Попробуйте ещё раз\a" << endl;
			cin.clear();
			while (cin.get() != '\n');
			continue;

		}
		else fl++;
	}
	return x;
}
void MenuAdm::admin_Work()
{
	char country[30],hotel[20],Ftip[10],res_kod[20],buf_kod[30][20];
	int cost,k,mn,y,date[3];
	Tour<int,char> *t[50],*tm[50],*tw[50],*ts[50],*tr,*tr1,*tr2,*tr3;
	Sea_Tour s[20];
	Mounty_Tour m[20];
	Child_Tour w[20];
	Sea_Child_Tour sch[20];
	Client <int,char> *pl[20];
	Tour<int,char>::vvod("BR");
	//Client <int,char> cl[20];
	Sea_Tour ss;
	Mounty_Tour mm;
	Child_Tour ww;
	Sea_Child_Tour schh;
	tr=&ss;
	tr1=&mm;
	tr2=&ww;
	tr3=&schh;
	//system("pause");
	int number;
	int count_mounty=0;
	int count_wellness=0;
	int count_ch_sea=0;//Sea_Child_Tour
	int count=0;
	int count_cl=0;
	count=s->open_File(s);//////ЧТЕНИЕ ИЗ ФАЙЛА
	count_mounty =m->open_File(m);
	count_wellness=w->open_File(w);
	count_ch_sea=sch->open_File(sch);
	//count_cl=cl->open_File(cl);
	//pl[0]=new Client<int,char>;
	count_cl=pl[0]->open_File(pl);
	/////////////////////////////////////////////////////////////////////////////////////

	int i,x,com,percent,ii;
	while(1){
		system("cls");
		int Cl=0,Tr=0,Pr=0;
		switch(MenuAdmin())
		{
		case '0': return;
			///////////////////////////////////////////////РАБОТА С КЛИЕНТАМИ////////////////////////////////////
		case '1':
			while (!Cl) {
				system("cls");
				switch (Menu_for_Clients()) {				
				case 1:
					i=count_cl;
					cout << "==============================================================================================" << endl;
					cout << " ФИО клиента     Телефон     Номер       Код тура    Дата       ФИО           Дата" << endl ;
					cout << "                             паспорта                выезда     регистратора  регистрации" << endl;
					cout << "==============================================================================================" << endl;
					for( i=0;i<count_cl;i++)
					{
						cout <<  i+1 <<".";
						pl[i]->see();
						//cl[i].see();
					}
					if(!i) 
					{
						cout << "Нет данных о клиентах" << endl;
					}
					system("pause");
					break;
					////////////////////////////////////ОТЧЁТ ПО МЕСЯЦУ///////////////////////////////////////////////////////////////////////////////////
				case 2:
					cout << "Введите текущий месяц: " ;
					cin >> mn;
					cout << "Введите текущий год:XXXX\b\b\b\b" ;
					cin >> y;
					x=0,com=0;
					cout << " =======================================================================================================" <<endl;
					cout << "     Клиент     №Телефона      Код     Сотрудник-        Дата           Общая         Стоимость   Валюта" << endl;
					cout << "                               тура    регистратор       регистрации    стоимость     тур услуги"<< endl;
					cout << " =======================================================================================================" <<endl;
					for( i=0;i<count_cl;i++)
					{
						if(pl[i]->see_date(mn,y))
						{
							pl[i]->see1();
							strcpy(res_kod,pl[i]->see_date(mn,y));
							for(int j=0;j<count;j++)
							{
								x+=s[j].print(res_kod);
								com+=s[j].print_com(res_kod);
							}
							for(int j=0;j<count_mounty;j++)
							{
								x+=m[j].print(res_kod);
								com+=m[j].print_com(res_kod);
							}
							for(int j=0;j<count_wellness;j++)
							{
								x+=w[j].print(res_kod);
								com+=w[j].print_com(res_kod);
							}
							for(int j=0;j<count_ch_sea;j++)
							{
								x+=sch[j].print(res_kod);
								com+=sch[j].print_com(res_kod);
							}
						}
					}
					if(x){
						cout << endl;
						cout << "Были реализованы путёки на сумму " << x << " BR" << endl;
						cout << "Прибыль тур агенства за счёт стоимости туристической услуги: " << com << " BR," << endl;
						x=(double)x;
						com=(double)com;
						cout << "что составляет " << (double)com/x*100 << " % от общей суммы"<<endl << endl;

						cout << "Отделу по работе с клиентами: " << endl;
						cout << "----------------------------------------------------" << endl;
						com=0;

						com=pl[0]->poisk_sotr(pl,count_cl);
						cout << "----------------------------------------------------" << endl;
						cout << "начислить премию к заработной плате в размере 3%" <<endl; 
						cout << "от общей стоимости реализованных путёвок, что составит ";
						percent=(double)x*0.03;
						cout << percent<< " BR" << endl;
						cout << "----------------------------------------------------" << endl << endl;
						cout << "Размер премии на одно человека составит: " << (double)percent/com << " BR" << endl;
						system("pause");
					}
					else{ 
						cout << endl;
						cout <<"По Вашему запросу ничего не найдено" << endl;
						system("pause");
					}
					break;
				case 3:ii=0;
					/////////////////////////////////////////////////СТаТИСТИКА///////////////////////////////////////
					for(i=0;i<count;i++)
						strcpy(buf_kod[ii++],s[i].get_kod());
					for(i=0;i<count_mounty;i++)
						strcpy(buf_kod[ii++],m[i].get_kod());
					for(i=0;i<count_wellness;i++)
						strcpy(buf_kod[ii++],w[i].get_kod());
					for(i=0;i<count_ch_sea;i++)
						strcpy(buf_kod[ii++],sch[i].get_kod());
					pl[0]->statistic(pl,buf_kod,ii,count_cl);
					system("pause");
					break;
				case 0:Cl=1;
					break;
				}
				//break;
			}
			break;
			///////////////////////////////////////////////РАБОТА С ТУРАМИ////////////////////////////////////////////////
		case '2': 

			while (!Tr) {
				system("cls");
				switch (Menu_operations_Admin()) {
				case 1: 
					switch (Menu_choice_tour())
					{
						//system("cls");
					case 1: 
						i=count;
						//t[i]=new Sea_Tour;////////////////////с полиморф.
						//t[i]->add(t,i,count);
						cin >> s[i];                                //перегрузка ввода для экрана
						count++;
						/*	for(int k=0;k<count;k++)
						t[k]->write_File(t,k,count);*/
						//for(int k=0;k<count;k++)
						s->write_File(s,i,count);
						cout<< count<<endl;
						system("pause");
						break;

					case 2:
						i=count_mounty;
						//tm[i]=new Mounty_Tour;
						//tm[i]->add(tm,i,count_mounty);
						cin >> m[i];                             //перегрузка ввода для экрана
						count_mounty++;
						m->write_File(m,count_mounty);
						////tr1->write_File(tm,count_mounty);
						system("pause");
						break;

					case 3:
						i=count_wellness;
						//tw[i]=new Child_Tour;
						//tw[i]->add(tw,i,count_wellness);
						cin >> w[i];                               //перегрузка ввода для экрана
						count_wellness++;
						////tr2->write_File(tw,count_wellness);
						w->write_File(w,count_wellness);
						system("pause");
						break;

					case 4:
						i=count_ch_sea;
						//ts[i]=new Sea_Child_Tour;
						//ts[i]->add(ts,i,count_ch_sea);
						cin >> sch[i];
						count_ch_sea++;
						sch->write_File(sch,count_ch_sea);
						////tr2->write_File(tw,count_wellness);
						system("pause");
						break;
					}
					break;
					////////////////////////////////////////////ПРОСМОТР/////////////////////////////////////////////////////////////////////////////
				case 2:
					cout << "\nДОСТУПНЫЕ ТУРЫ" << endl << endl;
					tr->header();
					//cout<< s.get_currency() << endl;
					for(int j=0;j<count;j++)
						t[j]=&s[j];
					for(i=0; i<count; i++)
					{
						cout <<  i+1 <<".";
						t[i]->print();

					}
					cout << "\n================================================================================================" << endl;
					tr1->header();
					for(i=0; i<count_mounty; i++)
					{
						tm[i]=&m[i];
					}
					for(i=0; i<count_mounty; i++)
					{
						cout <<  i+1 <<".";
						tm[i]->print();
					}
					cout << "\n==============================================================================================" << endl;
					tr2->header();
					for(i=0; i<count_wellness; i++)
					{
						tw[i]=&w[i];
					}
					for(i=0; i<count_wellness; i++)
					{
						cout <<  i+1 <<".";
						tw[i]->print();
					}
					cout << "\n==============================================================================================" << endl;

					cout << "\n==============================================================================================" << endl;
					tr3->header();
					for(i=0; i<count_ch_sea; i++)
					{
						ts[i]=&sch[i];
					}
					for(i=0; i<count_ch_sea; i++)
					{
						cout <<  i+1 <<".";
						ts[i]->print();
					}
					cout << "\n==============================================================================================" << endl;

					system("pause");
					break;
					///////////////////////////////////////////////РЕДАКТИРОВАНИЕ///////////////////////////////////////////////////////////////////////////
				case 3:
					switch (Menu_choice_tour())
					{
					case 1:
						s->header();
						//cout<< s.get_currency() << endl;
						for(int j=0;j<count;j++)
							t[j]=&s[j];
						for(i=0; i<count; i++)
						{
							cout <<  i+1 <<".";
							t[i]->print();
						}
						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{
							cout << endl; cout << "Введите номер тура для изменения" << endl;
							number=enterRecordNumber(count);
							s[number-1].red();
							s->write_File(s,i,count);
							system("pause");
						}
						break;

					case 2:
						cout << "\n================================================================================================" << endl;
						m->header();
						for(i=0; i<count_mounty; i++)
							tm[i]=&m[i];
						for(i=0; i<count_mounty; i++)
						{
							cout <<  i+1 <<".";
							tm[i]->print();
						}

						cout << "\n==============================================================================================" << endl;
						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{
							cout << endl; cout << "Введите номер тура для изменения" << endl;
							number=enterRecordNumber(count_mounty);
							m[number-1].red();
							m->write_File(m,count_mounty);
							system("pause");
						}
						break;

					case 3:
						cout << "\n===========================================================================================================" << endl;
						w->header();
						for(i=0; i<count_wellness; i++)
							tw[i]=&w[i];
						for(i=0; i<count_wellness; i++)
						{
							cout <<  i+1 <<".";
							tw[i]->print();
						}
						cout << "\n===========================================================================================================" << endl;

						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{
							cout << endl; cout << "Введите номер тура для изменения" << endl;
							number=enterRecordNumber(count_wellness);
							w[number-1].red();
							w->write_File(w,count_wellness);
							system("pause");
						}

						break;

					case 4:
						cout << "\n==============================================================================================================" << endl;

						cout << "\n==============================================================================================================" << endl;
						sch->header();
						for(i=0; i<count_ch_sea; i++)
							ts[i]=&sch[i];
						for(i=0; i<count_ch_sea; i++)
						{
							cout <<  i+1 <<".";
							ts[i]->print();
						}
						cout << "\n===============================================================================================================" << endl;
						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{
							cout << endl; cout << "Введите номер тура для изменения" << endl;
							number=enterRecordNumber(count_ch_sea);
							sch[number-1].red();
							sch->write_File(sch,count_ch_sea);
							system("pause");
						}
					}

					break;
					///////////////////////////////////////////////УДАЛЕНИЕ/////////////////////////////////////////////////////////////////////
				case 4:
					switch (Menu_choice_tour())
					{
					case 1:

						s->header();
						//cout<< s.get_currency() << endl;

						for(i=0; i<count; i++)
							t[i]=&s[i];
						for(i=0; i<count; i++)
						{
							cout <<  i+1 <<".";
							t[i]->print();
						}
						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{
							cout << endl; cout << "Введите номер для удаления" << endl;
							number=enterRecordNumber(count);
							for(i=number-1;i<count;i++)
								s[i]=s[i+1];
							count --;
							s->write_File(s,i,count);
							system("pause");
						}
						break;

					case 2:
						cout << "\n================================================================================================" << endl;
						m->header();
						for(i=0; i<count_mounty; i++)
							tm[i]=&m[i];
						for(i=0; i<count_mounty; i++)
						{
							cout <<  i+1 <<".";
							tm[i]->print();
						}
						cout << "\n===============================================================================================" << endl;
						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{
							cout << endl; cout << "Введите номер для удаления" << endl;
							number=enterRecordNumber(count_mounty);
							for(i=number-1;i<count_mounty;i++)
								m[i]=m[i+1];
							count_mounty --;
							m->write_File(m,count_mounty);
							system("pause");
						}
						break;


					case 3:
						cout << "\n===========================================================================================================" << endl;
						w->header();
						for(i=0; i<count_wellness; i++)
							tw[i]=&w[i];
						for(i=0; i<count_wellness; i++)
						{
							cout <<  i+1 <<".";
							tw[i]->print();
						}
						cout << "\n===========================================================================================================" << endl;

						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{
							cout << endl; cout << "Введите номер для удаления" << endl;
							number=enterRecordNumber(count_wellness);
							for(i=number-1;i<count_wellness;i++)
								w[i]=w[i+1];
							count_wellness --;
							w->write_File(w,count_wellness);
							system("pause");
						}
						break;

					case 4:

						cout << "\n==============================================================================================================" << endl;
						sch->header();
						for(i=0; i<count_ch_sea; i++)
							ts[i]=&sch[i];
						for(i=0; i<count_ch_sea; i++)
						{
							cout <<  i+1 <<".";
							ts[i]->print();
						}
						cout << "\n===============================================================================================================" << endl;
						if(!i)
						{
							cout << "Нет записей" <<endl;
							system("pause");
						}
						else{cout << endl; cout << "Введите номер для удаления" << endl;
						number=enterRecordNumber(count_ch_sea);
						for(i=number-1;i<count_ch_sea;i++)
							sch[i]=sch[i+1];
						count_ch_sea --;	
						sch->write_File(sch,count_ch_sea);
						system("pause");
						}
						break;
						//					fflush stdin;
						//			        gets(city);
						//					for(i=0; i<count; i++)
					}

					break;
					////////////////////////////////////////////ПОИСК/////////////////////////////////////////////
				case 5:
					k=0;
					cout << "Введите страну для поиска: ";
					fflush stdin;
					gets(country);
					cout << "Введите максимальную стоимость для поиска:                  " <<  Tour<int,char>::val <<"\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cin >> cost;
					s->header();

					for(int i=0;i<count;i++)
					{
						x=s[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					m->header();
					for(int i=0;i<count_mounty;i++)
					{
						x=m[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					w->header();
					for(int i=0;i<count_wellness;i++)
					{
						x=w[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					sch->header();
					for(int i=0;i<count_ch_sea;i++)
					{
						x=sch[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					system("pause");
					break;
					//////////////////////////////////////////////ПОИСК/////////////////////////////////////////////////////////////////
				case 6:
					k=0;
					cout << "Введите количество звёзд отеля: ";
					fflush stdin;
					gets(hotel);
					cout << "Введите тип питания (AL,BB,HB): ";
					fflush stdin;
					gets(Ftip);
					s->header();
					for(int i=0;i<count;i++)
					{
						x=s[i].poisk(hotel,Ftip);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					m->header();
					for(int i=0;i<count_mounty;i++)
					{
						x=m[i].poisk(hotel,Ftip);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					system("pause");
					break;
					///////////////////////////////////////////////////////////////////////////////////
				case 7:
					k=0;
					cout << " Введите Сегодняшнюю ДАТУ" << endl;
					cout << "Введите день: " ;
					cin >> date[0];
					cout << "Введите  месяц: " ;
					cin >> date[1];
					cout << "Введите год: " ;
					cin >>  date[2];
					s->header();
					for(int i=0;i<count;i++)
					{
						x=s[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout  << setw(98) <<"Не найдено туров" << endl;
					k=0;
					m->header();
					for(int i=0;i<count_mounty;i++)
					{
						x=m[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout << setw(98) <<"Не найдено туров" << endl;
					k=0;
					w->header();
					for(int i=0;i<count_wellness;i++)
					{
						x=w[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout  << setw(98) <<"Не найдено туров" << endl;
					k=0;
					sch->header();
					for(int i=0;i<count_ch_sea;i++)
					{
						x=sch[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout << setw(98) << "Не найдено туров" << endl;
					system("pause");
					break;
				case 0: Tr=1;
					break;
				}
			}

			break;



			////////////////////////////////////////////////ПРАЙС ЛИСТ/////////////////////////////////////////////
		case '3':
			cout << "\nМОРСКИЕ ТУРЫ" << endl;
			cout << "==============================================================================================" << endl;
			cout << "Код    Стоимость    Стоимость проживания       Стоимость      Страховка    Общая      Валюта  " << endl;
			cout << "        проезда          и питания            тур. услуги                  стоимость          " << endl;
			cout << "==============================================================================================" << endl;
			for(int i=0;i<count;i++)
			{
				s[i].print_price();
			}

			cout << "\nГОРНОЛЫЖНЫЕ ТУРЫ" << endl;
			cout << "=========================================================================================================" << endl;
			cout << "Код    Стоимость    Стоимость проживания    Стоимость       Страховка  Стоимость       Общая       Валюта" << endl;
			cout << "        проезда          и питания          тур. услуги                горнолыжного    стоимость  " << endl;
			cout << "                                                                       инвентаря " << endl;  
			cout << "=========================================================================================================" << endl;
			for(int i=0;i<count_mounty;i++)
			{
				m[i].print_price();
			}
			cout << "\nДЕТСКИЕ ЛАГЕРЯ" << endl;
			cout << "===============================================================================================" << endl;
			cout << "Код    Стоимость    Стоимость проживания    Стоимость     Стоимость услуг    Общая       Валюта" << endl;
			cout << "        проезда          и питания          тур. услуги   воспитателя        стоимость                   " << endl;
			cout << "===============================================================================================" << endl;
			for(int i=0;i<count_wellness;i++)
			{
				w[i].print_price();
			}
			cout << "\nДЕТСКИЕ САНАТОРИИ" << endl;
			cout << "==============================================================================================================" << endl;
			cout << "Код   Стоимость    Стоим.проживания   Стоимость    Страховка   Стоим. услуг   Стоимость     Общая       Валюта" << endl;
			cout << "       проезда         и питания      тур. услуги              воспитателя    мед.процедур  стоимость" << endl;
			cout << "==============================================================================================================" << endl;
			for(int i=0;i<count_ch_sea;i++)
			{
				sch[i].print_price();
			}
			system("pause");
			break;

		}
	}
}
void MenuAdm:: user_Work()

{

	char country[30],hotel[20],Ftip[10],Name[30],kod_tour[10],passport[20],Name_sotr[30],res_kod[20],buf_kod[30][20];
	int cost,k,tel_number,date_viezd[3],date_reg[3],d,mn,y,date[3];
	Tour <int,char> *t[50],*tm[50],*tw[50],*ts[50];//*tr,*tr1,*tr2,*tr3;
	Sea_Tour s[20];
	Mounty_Tour m[20];
	Child_Tour w[20];
	Sea_Child_Tour sch[20];
	Client <int,char> *pl[20];
	Tour<int,char>::vvod("BR");
	//Client <int,char> cl[20];
	//Sea_Tour s;
	//Mounty_Tour m;
	//Child_Tour w;
	//Sea_Child_Tour sch;
	//tr=&s;
	//tr1=&m;
	//tr2=&w;
	//tr3=&sch;
	//system("pause");
	int number;
	int count_mounty=0;
	int count_wellness=0;
	int count_ch_sea=0;//Sea_Child_Tour
	int count=0;
	int count_cl=0;
	count=s->open_File(s);//////ЧТЕНИЕ ИЗ ФАЙЛА
	count_mounty =m->open_File(m);
	count_wellness=w->open_File(w);
	count_ch_sea=sch->open_File(sch);
	//count_cl=cl->open_File(cl);
	//pl[0]=new Client<int,char>;
	count_cl=pl[0]->open_File(pl);
	/////////////////////////////////////////////////////////////////////////////////////

	int i,x,ii;
	while(1){
		system("cls");
		int Cl=0,Tr=0,Pr=0;
		switch(MenuAdmin())
		{
		case '0': return;
			///////////////////////////////////////////////РАБОТА С КЛИЕНТАМИ////////////////////////////////////
		case '1':
			while (!Cl) {
				system("cls");
				switch (Menu_for_Clients_pols()) {
				case 1:
					if(!count&&!count_wellness&&!count_mounty&&!count_ch_sea)
					{
						cout<< "Нет данных о турах"<<endl;
						system("pause");
					}
					else{
						cout << "\nДОСТУПНЫЕ ТУРЫ" << endl << endl;
						s->header();
						//cout<< s.get_currency() << endl;
						for(int j=0;j<count;j++)
							t[j]=&s[j];
						for(i=0; i<count; i++)
						{
							cout <<  i+1 <<".";
							t[i]->print();
							//s[i].print();

						}
						cout << "\n===============================================================================================" << endl;
						m->header();
						for(i=0; i<count_mounty; i++)
						{
							tm[i]=&m[i];
						}
						for(i=0; i<count_mounty; i++)
						{
							cout <<  i+1 <<".";
							tm[i]->print();
						}
						cout << "\n===========================================================================================================" << endl;
						w->header();
						for(i=0; i<count_wellness; i++)
						{
							tw[i]=&w[i];
						}
						for(i=0; i<count_wellness; i++)
						{
							cout <<  i+1 <<".";
							tw[i]->print();
						}
						cout << "\n=============================================================================================================" << endl;

						cout << "\n=============================================================================================================" << endl;
						sch->header();
						for(i=0; i<count_ch_sea; i++)
						{
							ts[i]=&sch[i];
						}
						for(i=0; i<count_ch_sea; i++)
						{
							cout <<  i+1 <<".";
							ts[i]->print();
						}
						x=0;
						cout << "\n==============================================================================================" << endl;
						cout << "Введите сегодняшнюю дату: ";
						cout << "Введите день: ";
						cin >> date[0];
						cout << "Введите месяц: ";
						cin >> date[1];
						cout << "Введите год: ";
						cin >> date[2];
						cout << "Введите фамилию клиента: ";
						fflush stdin;
						gets( Name);
						cout << "Введите номер телефона: ";
						cin >> tel_number;
						cout << "Введите номер  паспорта: ";
						fflush stdin;
						gets(passport);
						cout << "Введите код выбранного тура: ";
						do{
							fflush stdin;
							gets(kod_tour);
							for( i=0;i<count;i++)
							{
								if(!strcmp(kod_tour,s[i].get_kod()))
									x++;
							}
							for( i=0;i<count_mounty&&!x;i++)
							{
								if(!strcmp(kod_tour,m[i].get_kod()))
									x++;
							}
							for( i=0;i<count_wellness&&!x;i++)
							{
								if(!strcmp(kod_tour,w[i].get_kod()))
									x++;
							}
							for( i=0;i<count_ch_sea&&!x;i++)
							{
								if(!strcmp(kod_tour,sch[i].get_kod()))
									x++;
							}
							if(!x)
							{
								cout << endl;
								cout << "Не существует тура с введённым кодом!Попробуйте ещё раз\a" << endl;
							}
						}while(!x);

						cout << "Введите Дату выезда" << endl;
						do
						{
							x=0;
							cout << "Введите день: ";
							cin >> date_viezd[0];
							cout << "Введите месяц: ";
							cin >> date_viezd[1];
							cout << "Введите год: ";
							cin >> date_viezd[2];

							for( i=0;i<count&&!x;i++)
							{
								if(!strcmp(kod_tour,s[i].get_kod()))
								{
									for(int j=0;j<s[i].get_n();j++)
									{
										if(date_viezd[0]==s[i].get_day(j)&&date_viezd[1]==s[i].get_month(j)&&date_viezd[2]==s[i].get_year(j))
										{
											if(date_viezd[2]<date[2] || (date_viezd[2]==date[2] && date_viezd[1]<date[1]) || (date_viezd[2]==date[2] && date_viezd[1]==date[1] && date_viezd[0]<date[0]))
												x=-2;
											else{
												if(s[i].get_kol(j)>0)
												{
													ii=s[i].get_kol(j);
													s[i].set_kol(--ii,j);
													x++;
												}
												else x=-1;
											}
										}
									}

								}
							}
							for( i=0;i<count_mounty&&!x;i++)
							{
								if(!strcmp(kod_tour,m[i].get_kod()))
								{
									for(int j=0;j<m[i].get_n();j++)
									{

										if(date_viezd[0]==m[i].get_day(j)&&date_viezd[1]==m[i].get_month(j)&&date_viezd[2]==m[i].get_year(j))
										{
											if(date_viezd[2]<date[2] || (date_viezd[2]==date[2] && date_viezd[1]<date[1]) || (date_viezd[2]==date[2] && date_viezd[1]==date[1] && date_viezd[0]<date[0]))
												x=-2;
											else{
												if(m[i].get_kol(j)>0)
												{
													ii=m[i].get_kol(j);
													m[i].set_kol(--ii,j);
													x++;
												}
												else x=-1;
											}
										}
									}
								}

							}
							for( i=0;i<count_wellness&&!x;i++)
							{
								if(!strcmp(kod_tour,w[i].get_kod()))
								{
									for (int j=0;j<w[i].get_n();j++)
									{

										if(date_viezd[0]==w[i].get_day(j)&&date_viezd[1]==w[i].get_month(j)&&date_viezd[2]==w[i].get_year(j))
										{
											if(date_viezd[2]<date[2] || (date_viezd[2]==date[2] && date_viezd[1]<date[1]) || (date_viezd[2]==date[2] && date_viezd[1]==date[1] && date_viezd[0]<date[0]))
												x=-2;
											else{
												if(w[i].get_kol(j)>0)
												{
													ii=w[i].get_kol(j);
													w[i].set_kol(--ii,j);
													x++;
												}
												else x=-1;
											}
										}
									}
								}

							}

							for( i=0;i<count_ch_sea&&!x;i++)
							{
								if(!strcmp(kod_tour,sch[i].get_kod()))
								{
									for(int j=0;j<sch[i].get_n();j++)
									{

										if(date_viezd[0]==sch[i].get_day(j)&&date_viezd[1]==sch[i].get_month(j)&&date_viezd[2]==sch[i].get_year(j))
										{
											if(date_viezd[2]<date[2] || (date_viezd[2]==date[2] && date_viezd[1]<date[1]) || (date_viezd[2]==date[2] && date_viezd[1]==date[1] && date_viezd[0]<date[0]))
												x=-2;
											else{
												if(sch[i].get_kol(j)>0)
												{
													ii=sch[i].get_kol(j);
													sch[i].set_kol(--ii,j);
													x++;
												}
												else x=-1;
											}
										}
									}
								}

							}
							if(!x)
							{
								cout << endl;
								cout << "Вы ввели неверную дату для тура " << kod_tour << "! Попробуйте ещё раз\a" << endl;
							}
							if (x==-1)
							{
								cout << endl;
								cout << "Ошибка!Для данной даты отсутствуют места.Пожалуйста, пройдите регистрацию заново \a " << endl;
								system("pause");
							}
							if (x==-2)
							{
								cout << endl;
								cout << "Ошибка!Введённая дата уже прошла.Пожалуйста, пройдите регистрацию заново \a " << endl;
								system("pause");
							}
						}while(!x);
						if(x!=-1&&x!=-2)
						{
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
							//for( i=0;i<count;i++)
							//{
							//	x=s[i].sravn(kod_tour,date_viezd);
							//	//cout<< x<< endl;
							//	if(x)break;
							//}
							//for( i=0;i<count_mounty&&!x;i++)
							//{
							//	x=m[i].sravn(kod_tour,date_viezd);
							//	//cout<< x<< endl;
							//	if(x)break;
							//}
							//for( i=0;i<count_wellness&&!x;i++)
							//{
							//	x=w[i].sravn(kod_tour,date_viezd);
							//	//cout<< x<< endl;
							//	if(x)break;
							//}
							//for(i=0;i<count_ch_sea&&!x;i++)
							//{
							//	x=sch[i].sravn(kod_tour,date_viezd);
							//	//cout<< x<< endl;
							//	if(x)break;
							//}
							//if(!x) {
							//	cout << endl;
							//	cout <<"НЕКОРРЕКТНЫЙ ВВОД!\a" <<endl;
							//	cout <<"Несоответствие кода и/или даты либо отсутствуют места" <<endl;
							//system("pause");
							//}
							//else{
							i=count_cl;
							pl[i]= new Client<int,char>;
							pl[i]->set_name_kl(Name);
							pl[i]->set_tel_numder(tel_number);
							pl[i]->set_passport(passport);
							pl[i]->set_kod_tour(kod_tour);
							pl[i]->set_date_viezd(date_viezd);
							pl[i]->set_sotr(Name_sotr);
							pl[i]->set_date_reg(date_reg);
							//pl[i]= new Client<int,char>;
							//pl[i]->add();
							////cl[i].add();
							count_cl++;
							pl[0]->write_File(pl,count_cl);
							s->write_File(s,i,count);
							m->write_File(m,count_mounty);
							w->write_File(w,count_wellness);
							sch->write_File(sch,count_ch_sea);
							system("pause");
						}
					}
					//cl->write_File(cl,count_cl);
					break;
				case 2:
					i=count_cl;
					cout << "==============================================================================================" << endl;
					cout << " ФИО клиента     Телефон     Номер       Код тура    Дата       ФИО           Дата" << endl ;
					cout << "                             паспорта                выезда     регистратора  регистрации" << endl;
					cout << "==============================================================================================" << endl;
					for( i=0;i<count_cl;i++)
					{
						cout <<  i+1 <<".";
						pl[i]->see();
						//cl[i].see();
					}
					if(!i) 
					{
						cout << "Нет данных о клиентах" << endl;
					}
					system("pause");
					break;
				case 3: 
					system("cls");
					cout << "Введите год: " ;
					cin >> date[0];
					cout << "\nСтатистика проданных туров за " << date[0] << " год " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << " Тур                            |   Количество      |" << endl;
	cout << "----------------------------------------------------" << endl;
					/////////////////////////////////////////////////СТаТИСТИКА///////////////////////////////////////
					for( i=0;i<count;i++)
					{
						ii=0;
						cout << setw(4) << s[i].get_kod() << "|" << setw(14) << s[i].get_country() << "|"  << setw(12) << s[i].get_city() << "|" ;
						
							for(int j=0; j<count_cl;j++)
							{
								if(!strcmp(s[i].get_kod(),pl[j]->get_kod_tour())&&date[0]==pl[j]->get_date_reg_year())
									ii++;
							}
							cout << setw(4) << ii <<  "               |" << endl; 
						}
					for( i=0;i<count_mounty;i++)
					{
						ii=0;
						cout << setw(4) << m[i].get_kod() << "|" << setw(14) << m[i].get_country() << "|"  << setw(12) << m[i].get_city() << "|" ;
						
							for(int j=0; j<count_cl;j++)
							{
								if(!strcmp(m[i].get_kod(),pl[j]->get_kod_tour())&&date[0]==pl[j]->get_date_reg_year())
									ii++;
							}
							cout << setw(4) << ii <<  "               |" << endl; 
						}
					for( i=0;i<count_wellness;i++)
					{
						ii=0;
						cout << setw(4) << w[i].get_kod() << "|" << setw(14) << w[i].get_country() << "|"  << setw(12) <<w[i].get_city() << "|" ;
						
							for(int j=0; j<count_cl;j++)
							{
								if(!strcmp(w[i].get_kod(),pl[j]->get_kod_tour())&&date[0]==pl[j]->get_date_reg_year())
									ii++;
							}
							cout << setw(4) << ii <<  "               |" << endl; 
						}
					for( i=0;i<count_ch_sea;i++)
					{
						ii=0;
						cout << setw(4) << sch[i].get_kod() << "|" << setw(14) << sch[i].get_country() << "|"  << setw(12) << sch[i].get_city() << "|" ;
						
							for(int j=0; j<count_cl;j++)
							{
								if(!strcmp(s[i].get_kod(),pl[j]->get_kod_tour())&&date[0]==pl[j]->get_date_reg_year())
									ii++;
							}
							cout << setw(4) << ii <<  "               |" << endl; 
						}
					cout << "----------------------------------------------------" << endl << endl;
					system("pause");

					/*for(i=0;i<count;i++)
						strcpy(buf_kod[ii++],s[i].get_kod());
					for(i=0;i<count_mounty;i++)
						strcpy(buf_kod[ii++],m[i].get_kod());
					for(i=0;i<count_wellness;i++)
						strcpy(buf_kod[ii++],w[i].get_kod());
					for(i=0;i<count_ch_sea;i++)
						strcpy(buf_kod[ii++],sch[i].get_kod());
					pl[0]->statistic(pl,buf_kod,ii,count_cl);
					system("pause");*/
					break;

				case 0:Cl=1;
					break;
				}

			}
			break;
			///////////////////////////////////////////////РАБОТА С ТУРАМИ////////////////////////////////////////////////
		case '2': 

			while (!Tr) {
				system("cls");
				switch (Menu_operations_Pols()) {


					////////////////////////////////////////////ПРОСМОТР/////////////////////////////////////////////////////////////////////////////
				case 1:
					cout << "\nДОСТУПНЫЕ ТУРЫ" << endl << endl;
					s->header();
					//cout<< s.get_currency() << endl;
					for(int j=0;j<count;j++)
						t[j]=&s[j];
					for(i=0; i<count; i++)
					{
						cout <<  i+1 <<".";
						t[i]->print();
						//s[i].print();

					}
					cout << "\n================================================================================================" << endl;
					m->header();
					for(i=0; i<count_mounty; i++)
					{
						tm[i]=&m[i];
					}
					for(i=0; i<count_mounty; i++)
					{
						cout <<  i+1 <<".";
						tm[i]->print();
					}
					cout << "\n==============================================================================================" << endl;
					w->header();
					for(i=0; i<count_wellness; i++)
					{
						tw[i]=&w[i];
					}
					for(i=0; i<count_wellness; i++)
					{
						cout <<  i+1 <<".";
						tw[i]->print();
					}
					cout << "\n==============================================================================================" << endl;

					cout << "\n==============================================================================================" << endl;
					sch->header();
					for(i=0; i<count_ch_sea; i++)
					{
						ts[i]=&sch[i];
					}
					for(i=0; i<count_ch_sea; i++)
					{
						cout <<  i+1 <<".";
						ts[i]->print();
					}
					cout << "\n==============================================================================================" << endl;

					system("pause");
					break;

				case 2:
					k=0;
					cout << "Введите страну для поиска: ";
					fflush stdin;
					gets(country);
					cout << "Введите максимальную стоимость для поиска:                   " << Tour<int,char>:: val <<" \b\b\b\b\b\b\b\b\b\b\b\b\b";
					cin >> cost;
					s->header();
					for( i=0;i<count;i++)
					{
						x=s[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					m->header();
					for( i=0;i<count_mounty;i++)
					{
						x=m[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					w->header();
					for( i=0;i<count_wellness;i++)
					{
						x=w[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					sch->header();
					for( i=0;i<count_ch_sea;i++)
					{
						x=sch[i].poisk(country,cost);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					system("pause");
					break;
					//////////////////////////////////////////////ПОИСК/////////////////////////////////////////////////////////////////
				case 3:
					k=0;
					cout << "Введите количество звёзд отеля: ";
					fflush stdin;
					gets(hotel);
					cout << "Введите тип питания (AL,BB,HB): ";
					fflush stdin;
					gets(Ftip);
					s->header();
					for( i=0;i<count;i++)
					{
						x=s[i].poisk(hotel,Ftip);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					k=0;
					m->header();
					for( i=0;i<count_mounty;i++)
					{
						x=m[i].poisk(hotel,Ftip);
						if(x) k++;
					}
					if(!k) cout << "Не найдено туров" << endl;
					system("pause");
					break;
					///////////////////////////////////////////////////////////////////////////////////
				case 4:
					k=0;
					cout << "Сегодняшняя ДАТА" << endl;
					cout << "Введите день: " ;
					cin >> date[0];
					cout << "Введите  месяц: " ;
					cin >> date[1];
					cout << "Введите год: " ;
					cin >>  date[2];
					s->header();
					for( i=0;i<count;i++)
					{
						x=s[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout  << setw(98) <<"Не найдено туров" << endl;
					k=0;
					m->header();
					for( i=0;i<count_mounty;i++)
					{
						x=m[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout << setw(98) <<"Не найдено туров" << endl;
					k=0;
					w->header();
					for( i=0;i<count_wellness;i++)
					{
						x=w[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout  << setw(98) <<"Не найдено туров" << endl;
					k=0;
					sch->header();
					for( i=0;i<count_ch_sea;i++)
					{
						x=sch[i].poisk(date);
						if(x) k++;
					}
					if(!k) cout << setw(98) << "Не найдено туров" << endl;
					system("pause");
					break;
				case 0: Tr=1;
					break;
				}
			}

			break;



			////////////////////////////////////////////////ПРАЙС ЛИСТ/////////////////////////////////////////////
		case '3':
			cout << "\nМОРСКИЕ ТУРЫ" << endl;
			cout << "==============================================================================================" << endl;
			cout << "Код    Стоимость    Стоимость проживания       Стоимость      Страховка    Общая      Валюта  " << endl;
			cout << "        проезда          и питания            тур. услуги                  стоимость          " << endl;
			cout << "==============================================================================================" << endl;
			for(int i=0;i<count;i++)
			{
				s[i].print_price();
			}

			cout << "\nГОРНОЛЫЖНЫЕ ТУРЫ" << endl;
			cout << "=========================================================================================================" << endl;
			cout << "Код    Стоимость    Стоимость проживания    Стоимость       Страховка  Стоимость       Общая       Валюта" << endl;
			cout << "        проезда          и питания          тур. услуги                горнолыжного    стоимость  " << endl;
			cout << "                                                                       инвентаря " << endl;  
			cout << "=========================================================================================================" << endl;
			for(int i=0;i<count_mounty;i++)
			{
				m[i].print_price();
			}
			cout << "\nДЕТСКИЕ ЛАГЕРЯ" << endl;
			cout << "===============================================================================================" << endl;
			cout << "Код    Стоимость    Стоимость проживания    Стоимость     Стоимость услуг    Общая       Валюта" << endl;
			cout << "        проезда          и питания          тур. услуги   воспитателя        стоимость                   " << endl;
			cout << "===============================================================================================" << endl;
			for(int i=0;i<count_wellness;i++)
			{
				w[i].print_price();
			}
			cout << "\nДЕТСКИЕ САНАТОРИИ" << endl;
			cout << "==============================================================================================================" << endl;
			cout << "Код   Стоимость    Стоим.проживания   Стоимость    Страховка   Стоим. услуг   Стоимость     Общая       Валюта" << endl;
			cout << "       проезда         и питания      тур. услуги              воспитателя    мед.процедур  стоимость" << endl;
			cout << "==============================================================================================================" << endl;
			for(int i=0;i<count_ch_sea;i++)
			{
				sch[i].print_price();
			}
			system("pause");
			break;

		}
	}
}	


//void MenuAdm::WorkDateTours()
//{
//	char kod[10],country[80],city[20],hotel[20],type_of_room[20],food_tip[20];
//	int date[3],length,total_cost,visa,insurance,kol,cost_of_living,comission;
//	int nn,day[5],month[5],year[5],koll[5],cost_trans;
//	Tour *t[50],*tm[50],*tw[50],*ts[50],*tr,*tr1,*tr2,*tr3;
//	Sea_Tour s[20];
//	Mounty_Tour m[20];
//	Child_Tour w[20];
//	Sea_Child_Tour sch[20];
//	//Sea_Tour s;
//	//Mounty_Tour m;
//	//Child_Tour w;
//	//Sea_Child_Tour sch;
//	//tr=&s;
//	//tr1=&m;
//	//tr2=&w;
//	//tr3=&sch;
//	system("pause");
//	int number;
//	int count_mounty=0;
//	int count_wellness=0;
//	int count_ch_sea=0;//Sea_Child_Tour
//	int count=0;
//
//	//t[count]=new Sea_Tour;
//				count=s->open_File(s);//////ЧТЕНИЕ ИЗ ФАЙЛА
//			 count_mounty =m->open_File(m);
//			 count_wellness=w->open_File(w);
//			 count_ch_sea=sch->open_File(sch);
//							//cout<<count_wellness<<endl;
//	/*			for(j=0;j<count;j++)
//t[j]=&s[j];*/
//	
//	/////////////////////////////////////////////////////////////////////////////////////
//		
//
//	//cout <<count<< endl;
//	system("pause");
//	int i,x;
//	while (1) {
//		system("cls");
//		switch (Menu_operations_Admin()) {
//		case 1: 
//			switch (Menu_choice_tour())
//			{
//				//system("cls");
//			case 1: 
//				i=count;
//				//t[i]=new Sea_Tour;////////////////////с полиморф.
//				//t[i]->add(t,i,count);
//				s[i].add(t,i,count);
//				count++;
//		
//			/*	for(int k=0;k<count;k++)
//				t[k]->write_File(t,k,count);*/
//				//for(int k=0;k<count;k++)
//				s->write_File(s,i,count);
//				cout<< count<<endl;
//				system("pause");
//				break;
//
//			case 2:
//				i=count_mounty;
//				//tm[i]=new Mounty_Tour;
//				//tm[i]->add(tm,i,count_mounty);
//				m[i].add();
//				count_mounty++;
//				m->write_File(m,count_mounty);
//				////tr1->write_File(tm,count_mounty);
//				system("pause");
//				break;
//
//			case 3:
//				i=count_wellness;
//				//tw[i]=new Child_Tour;
//				//tw[i]->add(tw,i,count_wellness);
//				w[i].add();
//				count_wellness++;
//				////tr2->write_File(tw,count_wellness);
//				w->write_File(w,count_wellness);
//				system("pause");
//				break;
//
//			case 4:
//				i=count_ch_sea;
//				//ts[i]=new Sea_Child_Tour;
//				//ts[i]->add(ts,i,count_ch_sea);
//				sch[i].add();
//				count_ch_sea++;
//				sch->write_File(sch,count_ch_sea);
//				////tr2->write_File(tw,count_wellness);
//				system("pause");
//				break;
//			}
//			break;
//////////////////////////////////////////////ПРОСМОТР/////////////////////////////////////////////////////////////////////////////
//		case 2:
//			cout << "\nДОСТУПНЫЕ ТУРЫ" << endl << endl;
//			cout << "\nМОРСКИЕ ТУРЫ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна        Курорт    Отель  Тип      Дата        Колич.  Всего    Общая      Валюта" << endl ;
//			cout << "                                           питания  вылета      путёвок  ночей    стоимость" << endl;
//			//cout<< s.get_currency() << endl;
//					for(int j=0;j<count;j++)
//t[j]=&s[j];
//			for(i=0; i<count; i++)
//			{
//				cout <<  i+1 <<".";
//				t[i]->print();
//				//s[i].print();
//
//			}
//			cout << "\n==============================================================================================" << endl;
//			cout << "\nГОРНОЛЫЖНЫЕ ТУРЫ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна        Курорт    Отель  Тип      Дата        Колич.  Всего    Общая      Валюта" << endl ;
//			cout << "                                           питания  вылета      путёвок  ночей    стоимость" << endl;
//			for(i=0; i<count_mounty; i++)
//			{
//				tm[i]=&m[i];
//			}
//			for(i=0; i<count_mounty; i++)
//			{
//				cout <<  i+1 <<".";
//				tm[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//			cout << "\nДЕТСКИЕ ЛАГЕРЯ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна         Город       Лагерь        Дата        Колич.   Всего    Возраст  Общая      Валюта" << endl ;
//			cout << "                                                    вылета       путёвок  ночей             стоимость" << endl;
//			for(i=0; i<count_wellness; i++)
//			{
//				tw[i]=&w[i];
//			}
//			for(i=0; i<count_wellness; i++)
//			{
//				cout <<  i+1 <<".";
//				tw[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//
//				cout << "\n==============================================================================================" << endl;
//			cout << "\nДЕТСКИЕ САНАТОРИИ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна         Город       Санаторий  Тип      Дата        Колич.  Всего  Возраст  Общая      Валюта" << endl ;
//			cout << "                                                  питания вылета       путёвок ночей           стоимость" << endl;
//			for(i=0; i<count_ch_sea; i++)
//			{
//				ts[i]=&sch[i];
//			}
//			for(i=0; i<count_ch_sea; i++)
//			{
//				cout <<  i+1 <<".";
//				ts[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//
//			system("pause");
//			break;
//	///////////////////////////////////////////////РЕДАКТИРОВАНИЕ///////////////////////////////////////////////////////////////////////////
//		case 3:
//			switch (Menu_choice_tour())
//			{
//			case 1:
//			cout << "\nМОРСКИЕ ТУРЫ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна        Курорт    Отель  Тип      Дата        Колич.  Всего    Общая      Валюта" << endl ;
//			cout << "                                           питания  вылета      путёвок  ночей    стоимость" << endl;
//				//cout<< s.get_currency() << endl;
//				for(int j=0;j<count;j++)
//t[j]=&s[j];
//				for(i=0; i<count; i++)
//				{
//					cout <<  i+1 <<".";
//					t[i]->print();
//				}
//				
//				cout << endl; cout << "Введите номер тура для изменения" << endl;
//				number=s->enterRecordNumber(count);
//				s[number-1].red();
//				s->write_File(s,i,count);
//				system("pause");
//				break;
//
//			case 2:
//				cout << "\n==============================================================================================" << endl;
//			cout << "\nГОРНОЛЫЖНЫЕ ТУРЫ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна        Курорт    Отель  Тип      Дата        Колич.  Всего    Общая      Валюта" << endl ;
//			cout << "                                           питания  вылета      путёвок  ночей    стоимость" << endl;
//			for(i=0; i<count_mounty; i++)
//				tm[i]=&m[i];
//			for(i=0; i<count_mounty; i++)
//			{
//				cout <<  i+1 <<".";
//				tm[i]->print();
//			}
//			
//			cout << "\n==============================================================================================" << endl;
//			if(!i)
//			{
//				cout << "Нет записей" <<endl;
//			system("pause");
//			}
//			else{
//				cout << endl; cout << "Введите номер тура для изменения" << endl;
//				number=m->enterRecordNumber(count_mounty);
//				m[number-1].red();
//				m->write_File(m,count_mounty);
//				system("pause");
//			}
//			break;
//
//			case 3:
//				cout << "\n==============================================================================================" << endl;
//			cout << "\nДЕТСКИЕ ЛАГЕРЯ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна         Город       Лагерь        Дата        Колич.   Всего    Возраст  Общая      Валюта" << endl ;
//			cout << "                                                    вылета       путёвок  ночей             стоимость" << endl;
//			for(i=0; i<count_wellness; i++)
//				tw[i]=&w[i];
//			for(i=0; i<count_wellness; i++)
//			{
//				cout <<  i+1 <<".";
//				tw[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//		
//			if(!i)
//			{
//				cout << "Нет записей" <<endl;
//			system("pause");
//			}
//			else{
//				cout << endl; cout << "Введите номер тура для изменения" << endl;
//				number=w->enterRecordNumber(count_wellness);
//				w[number-1].red();
//				w->write_File(w,count_wellness);
//				system("pause");
//			}
//			
//			break;
//
//			case 4:
//				cout << "\n==============================================================================================" << endl;
//
//				cout << "\n==============================================================================================" << endl;
//			cout << "\nДЕТСКИЕ САНАТОРИИ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна         Город       Санаторий  Тип      Дата        Колич.  Всего  Возраст  Общая      Валюта" << endl ;
//			cout << "                                                  питания вылета       путёвок ночей           стоимость" << endl;
//			for(i=0; i<count_ch_sea; i++)
//				ts[i]=&sch[i];
//			for(i=0; i<count_ch_sea; i++)
//			{
//				cout <<  i+1 <<".";
//				ts[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//			if(!i)
//			{
//				cout << "Нет записей" <<endl;
//			system("pause");
//			}
//			else{
//				cout << endl; cout << "Введите номер тура для изменения" << endl;
//				number=sch->enterRecordNumber(count_ch_sea);
//				sch[number-1].red();
//				sch->write_File(sch,count_ch_sea);
//				system("pause");
//			}
//			}
//			
//			break;
//	///////////////////////////////////////////////УДАЛЕНИЕ/////////////////////////////////////////////////////////////////////
//		case 4:
//			switch (Menu_choice_tour())
//			{
//			case 1:
//
//				cout << "\nМОРСКИЕ ТУРЫ" << endl;
//				cout << "==============================================================================================" << endl;
//				cout << "  Код  Страна      Курорт      Отель         Колич.    Дата        Всего    Общая      Валюта"  ;
//				cout << "                                             путёвок   вылета      ночей    стоимость" << endl;
//				//cout<< s.get_currency() << endl;
//
//				for(i=0; i<count_mounty; i++)
//				t[i]=&s[i];
//				for(i=0; i<count; i++)
//				{
//					cout <<  i+1 <<".";
//					t[i]->print();
//				}
//				if(!i)
//			{
//				cout << "Нет записей" <<endl;
//			system("pause");
//			}
//			else{
//				cout << endl; cout << "Введите номер для удаления" << endl;
//				number=s->enterRecordNumber(count);
//				for(i=number-1;i<count;i++)
//					s[i]=s[i+1];
//				count --;
//				s->write_File(s,i,count);
//				system("pause");
//			}
//				break;
//
//			case 2:
//				cout << "\n==============================================================================================" << endl;
//			cout << "\nГОРНОЛЫЖНЫЕ ТУРЫ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна        Курорт    Отель  Тип      Дата        Колич.  Всего    Общая      Валюта" << endl ;
//			cout << "                                           питания  вылета      путёвок  ночей    стоимость" << endl;
//			for(i=0; i<count_mounty; i++)
//				tm[i]=&m[i];
//			for(i=0; i<count_mounty; i++)
//			{
//				cout <<  i+1 <<".";
//				tm[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//			if(!i)
//			{
//				cout << "Нет записей" <<endl;
//			system("pause");
//			}
//			else{
//				cout << endl; cout << "Введите номер для удаления" << endl;
//				number=m->enterRecordNumber(count_mounty);
//				for(i=number-1;i<count_mounty;i++)
//					m[i]=m[i+1];
//				count_mounty --;
//				m->write_File(m,count_mounty);
//				system("pause");
//			}
//			break;
//
//
//			case 3:
//				cout << "\n==============================================================================================" << endl;
//			cout << "\nДЕТСКИЕ ЛАГЕРЯ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна         Город       Лагерь        Дата        Колич.   Всего    Возраст  Общая      Валюта" << endl ;
//			cout << "                                                    вылета       путёвок  ночей             стоимость" << endl;
//			for(i=0; i<count_wellness; i++)
//				tw[i]=&w[i];
//			for(i=0; i<count_wellness; i++)
//			{
//				cout <<  i+1 <<".";
//				tw[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//		
//			if(!i)
//			{
//				cout << "Нет записей" <<endl;
//			system("pause");
//			}
//			else{
//				cout << endl; cout << "Введите номер для удаления" << endl;
//				number=w->enterRecordNumber(count_wellness);
//				for(i=number-1;i<count_wellness;i++)
//					w[i]=w[i+1];
//				count_wellness --;
//				w->write_File(w,count_wellness);
//				system("pause");
//			}
//			break;
//
//			case 4:
//				cout << "\n==============================================================================================" << endl;
//
//				cout << "\n==============================================================================================" << endl;
//			cout << "\nДЕТСКИЕ САНАТОРИИ" << endl;
//			cout << "==============================================================================================" << endl;
//			cout << "  Код       Страна         Город       Санаторий  Тип      Дата        Колич.  Всего  Возраст  Общая      Валюта" << endl ;
//			cout << "                                                  питания вылета       путёвок ночей           стоимость" << endl;
//			for(i=0; i<count_ch_sea; i++)
//				ts[i]=&sch[i];
//			for(i=0; i<count_ch_sea; i++)
//			{
//				cout <<  i+1 <<".";
//				ts[i]->print();
//			}
//			cout << "\n==============================================================================================" << endl;
//			if(!i)
//			{
//				cout << "Нет записей" <<endl;
//			system("pause");
//			}
//			else{cout << endl; cout << "Введите номер для удаления" << endl;
//				number=sch->enterRecordNumber(count_ch_sea);
//				for(i=number-1;i<count_ch_sea;i++)
//					sch[i]=sch[i+1];
//				count_ch_sea --;	
//					sch->write_File(sch,count_ch_sea);
//				system("pause");
//			}
//			break;
//				//					fflush stdin;
//				//			        gets(city);
//				//					for(i=0; i<count; i++)
//			}
//
//		
//
//			break;
//		case 0: return;
//		}
//	}
//	
//	//tr->write_File(t,count);
//	
//}
