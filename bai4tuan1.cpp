#include<iostream>
#include <fstream>
#define vocung 9999
#define max 100
using namespace std;
fstream f;
void docfile(int a[100][100],int n)
{
for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				f>>a[i][j];
			}
	}
	f.close();
}
void xuatfile(int a[100][100],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			
				cout<<a[i][j]<<" ";
				
			
			cout<<endl;
			
	}
}
int taomatran (int a[100][100],int n)
{	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
			cout<<"nhap a"<<"["<<i<<"]"<<"["<<j<<"]";
			cin>>a[i][j];
			}
	}
}
void duongdingannhat (int a[max][max],int batdau,int n)
{
	int haophi[max][max], dadi[max], vet[max], duongdi[max];
	int dem,mini,toi; 
	//khoi tao ma tran goc neu = 0 thi bang vo cung
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				if(a[i][j]==0)
					haophi[i][j] = vocung;
				
				else
					haophi[i][j]=a[i][j];
			}
	}
	//khoi tao ma tran dadi[],vet[],int pt[]
	for(int i=0;i<n;i++)
	{
		vet[i]=batdau;
		dadi[i]=0;
		duongdi[i]=haophi[batdau][i];
	}
	dem=1;
	duongdi[batdau]=0;//tu mot diem di mot diem thi bang 0
	dadi[batdau]=1;//diem dau tien da di qua nen dat bang 1
	while(dem<n-1 )
	{
		mini=vocung;
		for(int i=0;i<n;i++/* tim diem ke tiep gan nhat */)
		{
			if(dadi[i]!=1&&duongdi[i]<mini)
			{
				mini=duongdi[i];
				toi=i;
				
			}
		}
		dadi[toi]=1;
		for(int i=0;i<n;i++)
		{
			if(dadi[i]!=1)
				if(mini+haophi[toi][i]<duongdi[i] /* neu tim duoc duong di tu dau den diem can tim ngan hon thi */)
					{
						duongdi[i]=mini+haophi[toi][i];
						vet[i]=toi;
					}
		} 
		dem++;
	}
	for(int i=0;i<n;i++)
	{
		if(i!=batdau)
		{
			cout<<endl;
			cout<<"Khoang cach  nut "<<batdau<<"->"<< i << ":" <<duongdi[i] <<"   ";
			cout<<"duong di  "<<i;
		int j=i;
		  do
		  {
		  	j=vet[j];
		  	cout<<"<-"<<j;
		  }
		  while(j!=batdau);
		}
		
	}
}
int main()
{
	int n,k;
	int bd;
	f.open("bai4.txt",ios::in);
	int a[100][100];
	int b[100][100];
	do
	{
		cout<<" nhap 1 de nhap file | 2 de nhap tu ban phim :";
		cin>>k;
	}
	while(k<1 | k>2);
	if(k == 1)
	{
		f>>n;
		f>>bd;
		docfile(a,n);
		xuatfile(a,n);
		duongdingannhat(a,bd,n);
	}
	if(k == 2)
	{
		cout<<"nhap so diem :";
		cin>>n;
		cout<<"nhap vao diem bat dau di :";
		cin>>bd;
		taomatran (a,n);
		duongdingannhat(a,bd,n);
	}
}
