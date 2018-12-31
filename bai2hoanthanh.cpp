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
	int stt = n.ngay;
	if(namnhuan(n.nam) == 1)
	{
		for(int i = 0; i < n.thang;i++)
		{
			if(i == 2)
				thang[i] += 1;	
			stt+=thang[i];
			
		}
		return stt;
	}
	else
		{
		for(int i = 0; i < n.thang;i++)
		{	
			stt+=thang[i];
		
		}
			return stt;
	}

}
void NgayTruSTT(int n, int nam)
{
	int i = 0;
	while(n > thang[i])
	{
		n = n - thang[i];
		i++;
	}
	cout<<"ngay :"<<n<< " thang "<<i<<" nam :"<<nam;
}	

int CongNgayThang(ngaythang n, int x)
{
	int kq = x + timstt(n);
	if(namnhuan(n.nam))
	{
		if(kq <= 366)
		{
			thang[2] = 29;
			  NgayTruSTT(kq, n.nam);
		}
		else
			NgayTruSTT(kq-366,n.nam+1);
	}
	else
	{
			if(kq <= 365)
				 	NgayTruSTT(kq,n.nam);				 
			else
				{
					n.nam++;
					if(namnhuan(n.nam))
						{
							thang[2] = 29;
							NgayTruSTT(kq-365,n.nam);
						}
					else
						NgayTruSTT(kq-365, n.nam);
				}
	}
}
int TruNgayThang(ngaythang n, int x)
{
	int kq = timstt(n);
	if(kq > x)
		{
			kq -= x;
			if(namnhuan(n.nam))
				{
					thang[2]=29;
					NgayTruSTT(kq,n.nam);
				}
			else
				{
					NgayTruSTT(kq,n.nam);	
				}
		}
	else
		{
			if(namnhuan(n.nam))
				{
					kq = kq - x + 366;
					n.nam--;
					NgayTruSTT(kq,n.nam);
				}
			else
				{
					kq = kq - x + 365;
					n.nam--;
					if(namnhuan(n.nam))
						{
							thang[2]=29;
							NgayTruSTT(kq,n.nam);
						}
					else
						{
							NgayTruSTT(kq,n.nam);
						}
				}
		}
}
int main()
{	int n,k;
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
	cout<<"nhap so ngay muon cong x <= 365 : ";
	cin>>n;
	cout<<endl;
	CongNgayThang(x,n);
	cout<<endl;
	cout<<"nhap ngay tru :";
	cin>>k;
	TruNgayThang(x,k);
//	cout<<"ngay"<<x.ngay<<"thang"<<x.thang<<"nam"<<x.nam;
}
