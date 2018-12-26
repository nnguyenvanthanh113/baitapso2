#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;
struct danhba{
	char ten[20];
	bool gt;
	char sdt[11];
	char email[20];
	char diachi[50];
};
typedef struct danhba Contact;
vector <Contact> db;
fstream f input("C://Users/Admin/Desktop/input.dat");
fstream g output("C://Users/Admin/Desktop/output.dat")
void DocFile(Contact)
void ThemMoi(Contact c)
void Ghidb()
void InDB()
int main()
{
	Contact c1;
	char st[50];
	strcpy(c1.ten,"nguyen van thanh");
	strcpy(c1.gt,"1");
	strcpy(c1.sdt,"016587");	
	Contact c2;
	char st[50];
	strcpy(c2.ten,"nguyen van A");
	strcpy(c2.gt,"0");
	strcpy(c2.sdt,"123");
	
}
void DocFile(ofstream f , vector<Contact> &db)
{
	FILE * f.open("C://Users/Admin/Desktop/input.dat")
	for(int i =0 ;i<db.size();i++)
			fread	(&db[i],sizeof(wb) 0,1)
}
void Xuat(Contact c)
{
	cout<<"ten :"<<c.ten<<endl;
	cout<<"gt :"<<c.gt<<endl;
	cout<<"sdt :"<<c.sdt<<endl;
}
void ThemMoi(Contact c)
{
	c.push_back(c);
	Ghidb()
}
void Ghidb()
{
		FILE * f.write("C://Users/Admin/Desktop/output.dat")
		for(int i =0 ;i<db.size();i++)
			f-->(&db[i],sizeof(rb) 0,1)
}


