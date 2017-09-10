#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

class Worker
{
	char login[80];
	char parol[80];
public:
	Worker()
	{
		//login=new char[100];
		//NULL;
		//parol=new char[100];
		//NULL;
		//new char[100];
	}
~Worker()
	{
		//delete [] login;
		//delete [] parol;
	}
	Worker(char *lg,char *pr)
	{

		//login=new char[strlen( lg)+1];
		strcpy(login, lg);
		//parol=new char[strlen( pr)+1];
		strcpy(parol, pr);
	}
	Worker(const Worker &obj)
	{

		//login=new char[strlen(obj.login)+1];
		strcpy(login, obj.login);
		//parol=new char[strlen(obj.parol)+1];
		strcpy(parol, obj.parol);
		//cout<<"Rabotaet KK"<<endl;
	}
	int enter()
	{
		char log[30],par[30];
		cout<<"\nВведите логин: ";
			cin>>log;
			cout<<"\nВведите пароль: ";
			cin>>par;
			if(!strcmp(login,log)&&!strcmp(parol,par))
				return 1;
			else return 0;

	}
	int enter_pols(Worker *ob,int count)
	{
		char log[30],par[30];
		cout<<"\nВведите логин: ";
			cin>>log;
			cout<<"\nВведите пароль: ";
			cin>>par;
			for(int i=0;i<count;i++)
			{
			if(!strcmp(ob[i].login,log)&&!strcmp(ob[i].parol,par))
				return 1;
			}
			 return 0;

	}

	int reg()
	{
		system("cls");
		cout<<"Необходимо зарегистрироваться" << endl;
		cout<<"\nВведите логин: ";
			cin>>login;
			cout<<"\nВведите пароль: ";
			cin>>parol;
			
				for(int i=0;login[i]!='\0';i++)
			{
				login[i]=login[i]+11;
			}
			for(int i=0;parol[i]!='\0';i++)
			{
				parol[i]=parol[i]+11;
			}
			write_File_adm();
			cout<<"\nРегистрация прошла успешно " << endl;
			return 0;
	}

	int reg_pols(Worker *ob,int count)
	{
			SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
		int x;
		cout<<"\nВведите логин: ";
			cin>>login;
			cout<<"\nВведите пароль: ";
			cin>>parol;
			x=write_File(ob,count);
			if(!x)
			{
				cout<<"Пользователь с таким логином уже зарегистрирован\a"<<endl;
				return 0;
			}
			
			else
			return 1;
	}


		int	open_File(Worker *ob)
	{
		ifstream in("user.txt", ios::in );
		int i=0;
		Worker tmp;
		if (!in.is_open())
		{
			ofstream out("user.txt",ios::out);
			out.close();
		}
		else
		{
			while (in >>tmp)
			{
	
				ob[i]= tmp;
				for(int j=0;ob[i].login[j]!='\0';j++)
				{
					ob[i].login[j]=ob[i].login[j]-11;
				}
				for(int j=0;ob[i].parol[j]!='\0';j++)
				{
					ob[i].parol[j]=ob[i].parol[j]-11;
				}
				i++;
			}
		}

		in.close();
		return i;
	}

		int write_File(Worker *ob,int count)
	{
		for(int i=0;i<count;i++)
		{
			if(strcmp(ob[i].login,login)==0)
				return 0;
		}
		ofstream out("user.txt", ios::out | ios::app);
			cout<<"\n Пользователь " << login << " успешно зарегистрирован" << endl;
		for(int i=0;login[i]!='\0';i++)
			{
				login[i]=login[i]+11;
			}
			for(int i=0;parol[i]!='\0';i++)
			{
				parol[i]=parol[i]+11;
			}
		out << *this;
		out.close();
		return 1;
	}


	
int	open_File_adm(Worker *ob)
	{
		ifstream in("admin.txt", ios::in);
		int i=0;
		Worker tmp;
		if (!in.is_open())
		{
		ofstream out("admin.txt",ios::out);
		out.close();
		}
		else
		{
			while (in >>tmp)
			{
				ob[i]= tmp;
				for(int j=0;ob[i].login[j]!='\0';j++)
				{
					ob[i].login[j]=ob[i].login[j]-11;
				}
				for(int j=0;ob[i].parol[j]!='\0';j++)
				{
					ob[i].parol[j]=ob[i].parol[j]-11;
				}
				i++;
				
			}
		}

		in.close();
		
		return i;
	}
	Worker operator = (const Worker ob)
	{
		//if(this!=&ob)
		//{//
			//delete []login;
			//delete [] parol;
			//login=new char[strlen(ob.login)+1];
			strcpy(login,ob.login);
			//parol=new char[strlen(ob.parol)+1];
			strcpy(parol,ob.parol);
			//cout<<"Rabotaet Peregruska"<<endl;
		//}
		return *this;
	}

	void write_File_adm()
	{
		ofstream out("admin.txt", ios::out | ios::trunc );
		for(int i=0;i<1;i++)
		{
			out << *this;
		}
		out.close();
	}

	const char *getLogin() const
	{
		return login;
	}
	char *getParol()
	{
		return parol;
	}
	friend ostream &operator<<(ostream &, Worker &);
	friend istream &operator>>(istream &, Worker &);
};

ostream &operator<<(ostream &out, Worker &obj)
{
	out  << obj.login<< " " << obj.parol << endl;
	return out;
}
istream &operator>>(istream &in, Worker &obj)
{
	in >> obj.login;
	in >>obj.parol  ;
	return in;
}