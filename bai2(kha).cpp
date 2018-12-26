#include<IOSTREAM>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
struct ngaythang
{
	int ngay;
	int thang;
	int nam;
} ;
int thang[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void nhap(string &s)
{
	cout<<"nhap ngay thang nam (dd/mm/yyyy) :";
	getline(cin,s);
	cout<<s;
	
}
int namnhuan(int nam)
{
	if((nam%4==0&&nam%100!=0)||nam%400==0)
			return 1;
	return 0;
		
}
int timstt(ngaythang n)
{
	int stt=0;
	if(namnhuan(n.nam) == 1)
	{
		for(int i = 0; i < n.thang;i++)
		{
			if(i == 2)
				thang[i] += 1;	
			stt+=thang[i];
			stt+=n.ngay;
			return stt;
		}
	}
	else
		{
		for(int i = 0; i < n.thang;i++)
		{	
			stt+=thang[i];
			stt+=n.ngay;
			return stt;
		}
	}

}
void NgayTruSTT(int stt, int nam)
{
	int k = 0;
	if(namnhuan(nam) == 1)
	{
			for(int i = 0; i < 13; i++)
			{
				if(i = 2)
					thang[i] += 1;
				k += thang[i];
				if(stt <= k)
				{
					cout<<"ngay :"<<stt-(k-thang[i])<<endl;
					cout<<"thang :"<<i<<endl;
					cout<<"nam :"<<nam<<endl;
					break;
				}
			}
		}
	else
	{
			for(int i = 0; i < 13; i++)
				{
					 k += thang[i];
					 cout<<"thang "<<i;
					 if(stt <= k)
						{
							cout<<"ngay :"<<stt-(k-thang[i])<<endl;
							cout<<"thang :"<<i<<endl;
							cout<<"nam :"<<nam<<endl;
							break;
						}
				}	
	}		
}
void NgaySTT(int stt, int nam)
{
	int k=0;
	int h=0;
	if(namnhuan(nam) == 1)
		{
				for(int i = 0; i < 13; i++)
					{
						if(i == 2)
							thang[2] += 1;
						k +=thang[i];
						 
						if(stt <= k)
							{
								cout<<"ngay :"<<stt-(k-thang[i])<<endl;
								cout<<"thang :"<<i<<endl;
								cout<<"nam :"<<nam<<endl;
								break;
							}
					}
			}
		
	else
	{
		for(int i = 0; i < 13; i++)
					{
						k += thang[i];					
						 if(stt <= k)
							{				
								cout<<"ngay :"<<stt-(k-thang[i])<<endl;
								h = 1;
								cout<<"hello";
								cout<<"thang :"<<i<<endl;
								cout<<"nam :"<<nam<<endl;
								break;
							}
							if(h==1)
							{
								cout<<"thang :"<<i<<endl;
								cout<<"nam :"<<nam<<endl;
							}
					}	
	}
}	
void CongNgayThang(ngaythang n, int x)
{
	int kq = x + timstt(n);
	int nam = n.nam;
	if(kq <= 365)
		 NgaySTT(kq, nam);///kiem tra nam nay la nhuan hay ko nhuan
	else
	{
		if(namnhuan(nam) == 1)
			if(kq == 366)
				 {	
				 	cout<<"ngay 31 "<<"thang 12 "<<"nam "<<nam;
				 }
			if(kq > 366)
				 NgayTruSTT(kq - 366, nam + 1);//nam sau
		else
			 NgayTruSTT(kq- 365, nam + 1);//nam sau
	}
}
//void TruNgayThang(ngaythang n, int x)
//{
//	int kq = timstt(n) - x;
//	int nam = n.nam;
//	if(kq >= 1)
//		 NgaySTT(kq, nam);///kiem tra nam nay la nhuan hay ko nhuan
//	else
//	{
//		if(namnhuan(nam) == 1)
//			if(kq == 366)
//				 {	
//				 	cout<<"ngay 31 "<<"thang 12 "<<"nam "<<nam;
//				 }
//			if(kq > 366)
//				 NgayTruSTT(kq - 366, nam + 1);//nam sau
//		else
//			 NgayTruSTT(kq- 365, nam + 1);//nam sau
//	}
//}
int main()
{	int n;
	char t[4];
	ngaythang x;
	string st;
	nhap(st);
	t[0]=st[0];
	t[1]=st[1];
	x.ngay=atoi(t);
	cout<<"\n ngay :"<<x.ngay;
	t[0]=st[3];
	t[1]=st[4];
	x.thang=atoi(t);
	cout<<"\n thang :"<<x.thang;
	t[0]=st[6];
	t[1]=st[7];
	t[2]=st[8];
	t[3]=st[9];
	x.nam=atoi(t);
	cout<<"\n nam :"<<x.nam;
	if(namnhuan(x.nam))
		cout<<"\n la nam nhuan";
	 else
	 	cout<<"\n khong phai nam nhuan";
	cout<<"\n so thu tu:"<<timstt(x)<<endl;
	cout<<"nhap so ngay muon cong x <= 365 :";
	cin>>n;
	cout<<endl;
	CongNgayThang(x,n);
}
