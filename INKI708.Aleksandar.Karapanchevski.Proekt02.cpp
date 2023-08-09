#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//definiranje na struktura
struct Vraboten
{
	char imeV[20];
	char prezimeV[30];
	float godiniStaz;
	int stepenObrazovanie;
	float bodovi;
	float plata;
};
//definiranje na funkcija za sortiranje na struktura po ime 
void sortiraj(struct Vraboten v[],int broj)
{
	int i,j;
	struct Vraboten pom;
	for(i=0;i<broj-1;i++)
	for(j=0;j<broj-1;j++)
		if(v[j].imeV[0]>v[j+1].imeV[0])
		{
			pom=v[j];
			v[j]=v[j+1];
			v[j+1]=pom;
		}
}
//definiranje na funkcija za vnesuvanje na podatoci
void vnesi(struct Vraboten v[],int broj)
{
	int i,iz;
	float izborO,izborR;
	for(i=0;i<broj;i++)
	{
		cout<<"\n Ime ->> ";
		cin>>v[i].imeV;
		cout<<"\n Prezime ->> ";
		cin>>v[i].prezimeV;
		cout<<"\n Godini na staz ->> ";
		cin>>v[i].godiniStaz;
		cout<<endl;
		//meni za izbor za obrazovanie so kontrola
		do
		{
		cout<<"\n ---------------------------";
		cout<<"\n Vidovi na obrazovanie  ";
		cout<<"\n 1. Sredno obrazovanie ";
		cout<<"\n 2. Viso obrazovanie ";
		cout<<"\n 3. Visoko obrazovanie ";
		cout<<"\n ---------------------------";
		cout<<"\n Izbor : ";
		cin>>iz;
		}while(iz!=1 && iz!=2 && iz!=3);
		if(iz==1)
			izborO=0.5;
		if(iz==2)
			izborO=1;
		if(iz==3)
			izborO=1.3;
		v[i].stepenObrazovanie=iz;
		//meni za izbor so kontrola za rabotno mesto
		do
		{
		cout<<"\n ---------------------------";
		cout<<"\n Vidovi na rabotni mesta  ";
		cout<<"\n 1. Rabotno mesto 1 - 300 boda";
		cout<<"\n 2. Rabotno mesto 2 - 350 boda";
		cout<<"\n 3. Rabotno mesto 3 - 370 boda";
		cout<<"\n 4. Rabotno mesto 4 - 400 boda";
		cout<<"\n 5. Rabotno mesto 5 - 500 boda";
		cout<<"\n ---------------------------";
		cout<<"\n Izbor : ";
		cin>>iz;
		}while(iz!=1 && iz!=2 && iz!=3 && iz!=4 && iz!=5 );
		if(iz==1)
			izborR=300;
		if(iz==2)
			izborR=350;
		if(iz==3)
			izborR=370;
		if(iz==4)
			izborR=400;
		if(iz==5)
			izborR=500;
		v[i].bodovi=izborR;
		
		//presmetka na plata.
		
		v[i].plata=(v[i].godiniStaz*0.7+izborO*izborR)*22;
	}
	sortiraj(v,broj);
}
//definicija na funkcija za pecatenje na pdoatocite
void pecati(struct Vraboten v[],int broj)
{
	//upis na podtaocite vo datoteka
	ofstream dat("Vraboteni.txt");
	cout<<"\n Spisok na vraboteni : ";
	cout<<"\n======================================================";
	for(int i=0;i<broj;i++)
	{
		dat<<"\n "<<v[i].imeV;
		dat<<"  "<<v[i].prezimeV;
		dat<<"  so godini na staz "<<v[i].godiniStaz<<" - ";
		cout<<"\n "<<i+1<<". "<<v[i].imeV<<" "<<v[i].prezimeV<<" ";
		if(v[i].stepenObrazovanie==1)
		{
			cout<<" Sredno obrazovanie ";
			dat<<" Sredno obrazovanie ";
		}
		if(v[i].stepenObrazovanie==2)
		{
			cout<<" Viso obrazovanie ";
			dat<<" Viso obrazovanie ";
		}
		if(v[i].stepenObrazovanie==3)
		{
			cout<<" Visoko obrazovanie ";
			dat<<" Visoko obrazovanie ";
		}
		cout<<" so rabotno mesto od "<<v[i].bodovi<<" bodovi i plata "<<v[i].plata;
		dat<<" so rabotno mesto od "<<v[i].bodovi<<" bodovi i plata "<<v[i].plata;
	}
}

int main()
{
	struct Vraboten v[100];
	int broj=0,izbor;
	//meni za izbor
	do
	{
	cout<<"\n -- Izbor od meni - - ";
	cout<<"\n 1. Vnes ";
	cout<<"\n 2. Ispis ";
	cout<<"\n 0. Izlez ";
	cout<<"\n Izbor od meni : ";
	cin>>izbor;
	switch(izbor)
	{
		case 1: {
				cout<<"\n Broj Vraboteni ->> ";
				cin>>broj;
				vnesi(v,broj);
				break;
			}
		case 2:{
			//kontrola ako korisnikot izbere prvo 2 od menito
				if(broj==0)
				cout<<"\n !!! Mora prvo da izberete 1 od menito za izbor "<<endl;
				else
				pecati(v,broj);
			
				break;
			}
		case 0:break;
		default:cout<<"\n Greska Greska "<<endl;
	}
	}while(izbor!=0);
	return 0;
}
