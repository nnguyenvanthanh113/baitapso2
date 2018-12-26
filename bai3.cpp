#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

fstream f;
fstream g;

struct DE{
	string CH;
	string DAA;
	string DAB;
	string DAC;
	string DA;
};


bool KiemTraDA(string a, string b){
	if(a.compare(b) == 0)
		return true;
	else
		return false;
}
//int KiemTraDA(char a,char b)
//{
//	int kt =strcmp(a,b);
//	if(kt == 0)
//		return 1;
//	else
//		return 0;
//}
// --- ham yeu cau luu diem ---
void LuuDiem(int diem){
	int a;
	int k;
	do{
		cout << "chon 1 de luu diem / chon 2 de khong luu diem!!!" << endl;
		cin >> a;
		if(a < 0 || a > 2)
			cout << "chon lai!!!" << endl;
	}while(a < 0 || a > 2);
	if(a == 1){
		string s;
		cout << endl << "nhap ten de luu diem: ";
		fflush(stdin);
		getline(cin, s);
		g.open("C://Users/Admin/Desktop/xemdiem.txt", ios::out | ios::app);
		g << s << "\t\t" << diem << "\n";
		g.close();
		cout << "luu diem thanh cong" << endl << endl;
		cout<<" muon xem diem thi nhan 1 nguoc lai nhan 0 :";
		cin>>k;
		if(k == 1)
		{
			cout<<"diem so cua ban la :"<<diem;
		}
		if(k == 0)
		{
			cout<<"Hen gap lai !!";
		}
	}
}

// --- ham mo de thi trong thu muc BO_DE ---
void MoDe(){
	string s;
	string x;
	int diem = 0;
	
	getline(f, s);
	cout << s << endl;
	getline(f, s);
	for(int i = atoi(s.c_str()); i > 0; i--){
		getline(f, s);		// --- dong 1 / cau hoi ---
		cout << s << endl;
		getline(f, s);		// --- dong 2 / dap an A ---
		cout << s << endl;
		getline(f, s);		// --- dong 3 / dap an B ---
		cout << s << endl;
		getline(f, s);		// --- dong 4 / dap an C ---
		cout << s << endl;
		getline(f, s);		// --- dong 5 / dap an dung ---
		cout << "cau tra loi cua ban la: ";
		fflush(stdin);
		getline(cin, x);	// --- dap an nguoi thi ---
		cout << endl;
		// --- kiem tra dap an dung voi dap an nguoi thi va cong diem ---
		if(KiemTraDA(s, x) == 1)
			diem += 2;
	}
	cout << "da hoan thanh bai kiem tra!!!" << endl << endl;
	LuuDiem(diem);
	
}


// --- xem diem da luu trong LUU_DIEM.txt ---
void XemDiem(){
	string s;
	g.open("C://Users/Admin/Desktop/xemdiem.txt", ios::in);
	cout << "diem nguoi choi da luu la:" << endl;
	getline(g, s);
	do{
		cout << s << endl;
		getline(g, s);
	}while(s.compare("") != 0);
	g.close();
}

// --- ham chon 1 trong cac bo de ---
void ChonDe(){
	int a;
	
	do{
		cout << "nhap so 1, 2 hoac 3 chon bo de tuong ung / chon 4 de xem diem so da luu!!!" << endl;
		cout << "1. de 1" << endl << "2. de 2" << endl << "3. de 3" << endl << "4. xem diem da luu" << endl;
		cin >> a;
		if(a < 1 || a > 4)
			cout << "chon sai!!! vui long chon lai!!!";
	}while(a < 1 || a > 4);
	
	if(a == 1){
		f.open("C://Users/Admin/Desktop/DE_1.txt", ios::in);
		MoDe();
		f.close();
	}
//	else
//		if(a == 2){
//			f.open("BO_DE/DE_2.txt", ios::in);
//			MoDe();
//			f.close();
//		}
//		else
//			if(a == 3){
//				f.open("BO_DE/DE_3.txt", ios::in);
//				MoDe();
//				f.close();
//			}
			else
				XemDiem();
}


int main(){
	
	ChonDe();
}
