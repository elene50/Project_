#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

class User
{

	char login[80];
	char parol[80];
public:
	User()
	{
		//login=new char[255];
		////NULL;
		//parol=new char[255];
		//NULL;
	}

	User(char *lg,char *pr)
	{
		setLogin(lg,pr);

		/*login=new char[strlen( lg)+1];
		strcpy(login, lg);
		parol=new char[strlen( pr)+1];
		strcpy(parol, pr);*/
	}
	User(const User &obj)
	{

		//login=new char[strlen(obj.login)+1];
		strcpy(login, obj.login);
		//parol=new char[strlen(obj.parol)+1];
		strcpy(parol, obj.parol);
		//	cout<<"Rabotaet KK"<<endl;
	}

	~User()
	{
		/*delete [] login;
		delete [] parol;*/
	}
	int	open_File(User *ob)
	{
		ifstream in("user.txt", ios::in );
		int i=0;
		User tmp;
		if (!in.is_open())
		{
			//cout << "Ошибка открытия файла!" << endl;
			ofstream out("user.txt",ios::out);
			out.close();
		}
		else
		{
			while (in >>tmp)
			{
				//ob[i].setLogin(tmp.login,tmp.parol);
				//strcpy(ob[i].login,tmp.login);
				ob[i]= tmp;
				//strcpy(ob[i].parol,tmp.parol);
				i++;
			}
		}

		in.close();
		return i;
	}
	User operator = (const User ob)
	{
		//if(this!=&ob)
		//{
			/*delete login;
			delete  parol;*/
			//login[80],parol[80];
			//login=new char[strlen(ob.login)+1];
			strcpy(login,ob.login);
			//parol=new char[strlen(ob.parol)+1];
			strcpy(parol,ob.parol);
			//cout<<"Rabotaet peregruska"<<endl;
		//}
		return *this;
	}

	int write_File(User *obj,int count,User *ob)
	{
		for(int i=0;i<count;i++)
		{
			if(strcmp(ob[i].login,obj[0].login)==0)
				return 0;
		}
		ofstream out("user.txt", ios::out | ios::app);
		out << obj[0];
		out.close();
		return 1;
	}
	void setLogin(char*lg,char *pr)
	{
		//login=new char[strlen( lg)+1];
		strcpy(login, lg);
		//parol=new char[strlen( pr)+1];
		strcpy(parol, pr);
	}

	const char *getLogin() 
	{
		return login;
	}
	char *getParol()
	{
		return parol;
	}

	friend ostream &operator<<(ostream &, User &);
	friend istream &operator>>(istream &, User &);
};


ostream &operator<<(ostream &out, User &obj)
{
	out  << obj.login<< " " << obj.parol << endl;
	return out;
}
istream &operator>>(istream &in, User &obj)
{
	in >> obj.login;
	in >>obj.parol  ;
	return in;
}