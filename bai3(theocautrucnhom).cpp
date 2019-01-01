#include<string>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;
//khai bao cau truc cau hoi
struct cauhoidapan{
	string cauhoi;
	string A;
	string B;
	string C;
	string DA;
	
};
struct nguoichoi{
	string ten;
	int diem;
};
	ifstream f;
//khai bao vector
vector<cauhoidapan> ds;
vector<nguoichoi> nc;
fstream g;
//khai bao ham 
void chonde();
bool kiemtra(string A,string B);
void xuat(cauhoidapan ds);
void docde();
void xuat(cauhoidapan ds);
void Xuattendiem();
void GhiFile();
//doc file chon de
void chonde()
{
//	ifstream f("DE1.txt");
	int sl;
	cauhoidapan de;
	string s,ans;
	getline(f,s);
	//doi string sang int
	sl=atoi(s.c_str());
	for(int i=0;i<sl;i++)
	{
		getline(f,s) ;de.cauhoi=s;
		getline(f,s) ;de.A=s;
		getline(f,s) ;de.B=s;
		getline(f,s) ;de.C=s;
		getline(f,s) ;de.DA=s;
	 
		ds.push_back(de);
		
	}
	docde();
	

}
//ham kiem tra string
bool kiemtra(string A,string B)
{
	if(A.compare(B)==0)
			return true;
		else
			return false;
		
}

void xuat(cauhoidapan ds,int &diem)
{
	
	string dapan;
	cout<<ds.cauhoi<<endl;
	cout<<ds.A<<endl;
	cout<<ds.B<<endl;
	cout<<ds.C<<endl;
	cout<<"nhap dap an :";
	cin>>dapan;
	if(kiemtra(ds.DA,dapan))
		diem+=2;
	
	
}
void Xuattendiem()
{
//	cout<<NC.ten<<" diem so nguoi choi la :"<<NC.diem;
	g.open("C://Users/Admin/Desktop/Diem.txt",ios::out | ios::app);
	for(int i =0 ;i<nc.size();i++)
	{
		g << nc[i].ten << " diem dat duoc :" <<nc[i].diem<<endl ;
		cout<<nc[i].ten<<" : "<<nc[i].diem;
	}
	g.close();
}
void InDS()
{
	int in;
	string s;
	cout<<"\nnhap 1 neu muon in danh sach tat ca nguoi choi :";
	cin>>in;
	g.open("C://Users/Admin/Desktop/Diem.txt",ios::in);
	
	if(in == 1){
		getline(g,s);
	{
		do
			{
				cout<<s<<endl;
				getline(g,s);
			}
		while(s.compare("") != 0);
	}
	}
	else
		cout<<"ban la nguoi choi dau tien "<<"\nHen Gap Lai !!";
}
//void GhiFile()
//{
//	ifstream g("Diem.txt",ios::out | ios::app);
//	for(int i =0 ;i<nc.size();i++)
//		g << nc[i].ten << "diem dat duoc :" <<nc[i].diem ;
//	g.close();
//}

void docde()
{
	nguoichoi NC;
	int diemso=0;
	string ten;
	for(int i=0;i<ds.size();i++)
		xuat(ds[i],diemso);
	cout<<"\ndiem cua ban la: "<<diemso<<endl;
	cout<<"nhap ten de luu :";
	cin>>ten;
	cout<<endl;
	NC.ten=ten;
	NC.diem=diemso;
	nc.push_back(NC);
	Xuattendiem();
}

int main()
{
	int n;
	cout<<"nhap de muon chon 1(de 1) và 2(de 2)";
	cin>>n;
	if(n==1){
		 f.open("C://Users/Admin/Desktop/DE1.txt");
		chonde();
		InDS();
	}
	if(n==2)
	{
		f.open("C://Users/Admin/Desktop/DE2.txt");
		chonde();
		InDS();
	}
//	chonde();
////	GiFile();
//	InDS();
}

