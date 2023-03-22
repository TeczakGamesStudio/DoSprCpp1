#include<iostream>
using namespace std;

class osoba{
	private:
		string imie, nazwisko;
		int wiek;
	public:
		osoba(){};//konstruktor
		~osoba();//destruktor
		int dodaj(string, string, int);
		void wypisz();
		osoba(string, string, int);
		osoba(string, string);
};
//konstruktor parametryczny z list� inicjalizator�w zmiennych cz�onkowskich
osoba::osoba(string i,string n):
	imie{i},nazwisko{n}
	{
		cout<<endl<<"Powr�ci�em i tworz�"<<endl;
	}
	
osoba::osoba(string i, string n, int w){
	imie=i,nazwisko=n,wiek=w;
}
int osoba::dodaj(string i, string n, int w){
	imie=i,nazwisko=n,wiek=w;
}
void osoba::wypisz(){
	cout<<endl<<"---------------------"<<"\nImie: "<<imie<<"\nNazwisko: "<<nazwisko<<"\nWiek: "<<wiek<<"\n---------------------"<<endl;
}
//osoba::osoba(){
//	cout<<endl<<"Jestem tu i dzia�am :)"<<endl;
//}
osoba::~osoba(){
	cout<<endl<<"Usuwam obiekt :("<<endl;
}
int main(){
	setlocale(LC_ALL,"Polish");
	/*osoba o0;
	o0.dodaj("Miko�aj","Sobczak",16);
	o0.wypisz();
	o0.~osoba();*/
	
	//jawne wyjawienie konstuktora
//	osoba o1=osoba("Miko�aj","Sobczak",16);
//	o1.wypisz();
	
	//ukryte wywo�anie konstruktora
//	osoba o2("Andrzej","Kmicic",30);
//	o2.wypisz();
	
	//osoba o3("Miko�aj","Sobczak");
	//o3.wypisz();
	
	osoba o[3]={
		{"A","B"},
		{"C","D"},
		{"E","F"}
	};
	for(int i=0;i<=2;i++){
		o[i].wypisz();
	}
	return 0;
}
