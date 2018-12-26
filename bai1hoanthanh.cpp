#include<iostream>
#include<vector>
#include<iostream>
#include <string.h>
using namespace std;
typedef struct Contact{

	char ten[20];
	char sdt[11];
	char gmail[20];
	char diachi[50];
	bool gioitinh;
}Contact;
vector <Contact> db;

//thêm moi 1 danh ba(contact) vào danh ba
void ThemMoi(Contact C);
//them vao db
//ghi db vao file(danhba.dat)

void LietKe();// in cac phan tu cua db ra man hinh
void CapNhat(Contact c);
//tim contact m co sdt c.sdt
//cap nhat c vao m
//ghi db vao file
void XoaContact(char*sdt);
// tim contact m co sdt trong db
//xoa contact m
//ghi db vao file
vector<Contact>
	TimTheoten(char*ten);
// tim contact m co theo ten ten
//them m vao bien vector
//tra ve bien vector
void GhiVaodb();
void DocVaodb();
void ChinhSuaTheoSDT(char sdt[]);
void Xoa(char xoa[]);
void TimKiem(char ten[],char sdt[]);
int main(){

	DocVaodb();
	LietKe();
	Contact c;
	strcpy(c.ten,"thanh cuteo");
	strcpy(c.sdt,"123");
	strcpy(c.gmail,"nnguyenvanthanh113@");
	strcpy(c.diachi,"doan tran nghiep");
	c.gioitinh=1;
	ThemMoi(c);
	Contact c1;
	strcpy(c1.ten,"nguyen thi a");
	strcpy(c1.sdt,"321");
	strcpy(c1.gmail,"nguyethia@gmail.com");
	strcpy(c1.diachi,"nha trang");
	c1.gioitinh=1;
	ThemMoi(c1);
	cout<<endl;
	cout<<" danh ba moi "<<endl<<endl;
	LietKe();
	cout<<"\ndanh ba sau khi cap nhat\n"<<endl;
	Contact cmoi;
	strcpy(cmoi.ten,"uyen phuong");
	strcpy(cmoi.sdt,"0168435210");
	strcpy(cmoi.gmail,"uyenphuong@gmail");
	strcpy(cmoi.diachi,"quang nam");
	cmoi.gioitinh=0;
	CapNhat(cmoi);//doc va in ra sau khi cap nhat
	cout<<"\nsau khi chinh sua la :\n";
	ChinhSuaTheoSDT("123");
//	LietKe();
	cout<<"sau khi xoa la :";
	Xoa("nguyen thi a");
	LietKe();
	cout<<"\nsau khi tim kiem theo ten : \n";
	TimKiem("uyen phuong","0168435210");
}

void GhiVaodb( ){
	FILE*f=fopen("db.dat","wb");
	Contact c;
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
}
void DocVaodb(){
	db.clear();
	FILE*f =fopen("db.dat","rb");
	if( f != NULL)
	{
		while(!feof(f)){
			Contact c;
			fread(&c,sizeof(Contact),1,f);	
			db.push_back(c);
		}
			fclose(f);
			db.pop_back();
	}
}
void ThemMoi(Contact c)
{
	  db.push_back(c);
	  GhiVaodb();
}

void LietKe(){
	for(int i=0 ; i <db.size() ;i++){
		cout<<"ten la: "<<db[i].ten<<endl;
		cout<<"sdt la: "<<db[i].sdt<<endl;
		cout<<"gmail la: "<<db[i].gmail<<endl;
		cout<<"dia chi la: "<<db[i].diachi<<endl;	
		cout<<"gioi tinh la: "<<db[i].gioitinh<<endl;
	}

}
void CapNhat(Contact c)
{
//	FILE*f=fopen("db.dat","wb");
//	Contact cmoi;
	ThemMoi(c);
	LietKe();
//	for(int i = 0 ; i < db.size() ; i++)
//		fwrite(&db[i],sizeof(db),1,f);	
//		fclose(f);
	FILE*f=fopen("db.dat","wb");
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
}
///xoa 1 phan tu bat ky trong vector
//void XoaContact(char*sdt)
//// tim contact m co sdt trong db
////xoa contact m
////ghi db vao file
//	_vector.erase(db.begin() + _position);
//}
void ChinhSuaTheoSDT(char sdt[])
{
	for(int i=0;i<db.size();i++)
		if(strcmp(db[i].sdt,sdt)==0)
		{
			strcpy(db[i].ten,"thanh cute");
			strcpy(db[i].diachi,"42/23 Doan tran nghiep");
			strcpy(db[i].gmail,"thanhcute.com");
			for(int i=0 ; i <db.size() ;i++){
				cout<<"ten la: "<<db[i].ten<<endl;
				cout<<"sdt la: "<<db[i].sdt<<endl;
				cout<<"gmail la: "<<db[i].gmail<<endl;
				cout<<"dia chi la: "<<db[i].diachi<<endl;	
				cout<<"gioi tinh la: "<<db[i].gioitinh<<endl;
			}
		}
}
void Xoa(char xoa[])
{
	for(int i=0;i<db.size();i++)
		{
			if(strcmp(db[i].ten,xoa) == 0)
				db.erase(db.begin()+i);
		}
}
void TimKiem(char ten[],char sdt[])
{
	for(int i=0;i<db.size();i++)
			if(strcmp(db[i].ten,ten)==0 && strcmp(db[i].sdt,sdt)==0)
			{
				cout<<"la nguoi thu :"<<i<<endl;
				cout<<"ten la: "<<db[i].ten<<endl;
				cout<<"sdt la: "<<db[i].sdt<<endl;
				cout<<"gmail la: "<<db[i].gmail<<endl;
				cout<<"dia chi la: "<<db[i].diachi<<endl;	
				cout<<"gioi tinh la: "<<db[i].gioitinh<<endl;
			}
}
