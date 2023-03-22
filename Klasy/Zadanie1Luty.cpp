#include<iostream>
using namespace std;

int id_zalogowanego=-1;


class osoba{// klasa osoba
	private:
		int id;
		string imie;
		string nazwisko;
		string login;
		string haslo;
		double saldo;
	public:
		osoba();
		void dodaj_dane(int,string,string,string,string,double);
		bool zaloguj(string,string);
		void zmien_saldo(double);
		void wypisz(string);
};
// konstruktor osoby
osoba::osoba(){
};
// funkcje klasy osoba
void osoba::dodaj_dane(int Uid, string Uimie, string Unazwisko, string Ulogin, string Uhaslo, double Usaldo){
	id=Uid;
	imie=Uimie;
	nazwisko=Unazwisko;
	login=Ulogin;
	haslo=Uhaslo;
	saldo=Usaldo;
};
bool osoba::zaloguj(string Ulog, string UPass){
	if(Ulog==login && UPass == haslo){
		id_zalogowanego=id;
		return 1;
	}
	else {
		return 0;
	}
};
void osoba::zmien_saldo(double koszt){
	if(saldo>=koszt){
		saldo-=koszt;
		cout<<"Gratuluje zakupu!Twoje saldo zostalo pomniejszone o kwote "<<koszt<<"PLN\n\n";
	}
	else{
		cout<<"Nie posiadasz wystarczajacej kwoty!!!\n";
	}
};
void osoba::wypisz(string co){
	if(co=="id"){
		cout<<id;
	}
	else if(co=="imie"){
		cout<<imie;
	}
	else if(co=="nazwisko"){
		cout<<nazwisko;
	}
	else if(co=="login"){
		cout<<login;
	}
	else if(co=="haslo"){
		cout<<haslo;
	}
	else if(co=="saldo"){
		cout<<saldo;
	}
};
//koniec osoby


class sklep{//klasa sklep
	private:
		int numer_artykulu;
		string nazwa;
		double cena;
	public:
		sklep();
		sklep(int, string, double);
		void wypisz();
		double zwroc_cene();
		void wypisz2();
};
sklep::sklep(){
};
sklep::sklep(int id, string name, double wartosc){
	numer_artykulu=id;
	nazwa=name;
	cena=wartosc;
}
void sklep::wypisz(){
	cout<<"- "<<numer_artykulu<<" - "<<nazwa<<" - cena: "<<cena<<"PLN"<<endl;
}
double sklep::zwroc_cene(){
	return cena;
}
void sklep::wypisz2(){
	cout<<nazwa<<" - cena: "<<cena<<"PLN"<<endl;
}
int main(){
	
	osoba o[3]={
		{},
		{},
		{}
	};
	o[0].dodaj_dane(0,"Mikolaj","Sobczak","mikso","haslo1234",100000.56);
	o[1].dodaj_dane(1,"Kacper","Nowak","kacno","haslo2334",107.87);
	o[2].dodaj_dane(2,"Szymon","Chmielorz","szych","haslo22",123.35);
	
	
	sklep towar[4]={
		{0,"Chleb",4.55},
		{1,"Kawa",15.25},
		{2,"Mleko",3.85},
		{3,"Makaron",4.55}
	};
	
	while(true){// system logowania
		string log;
		string pass;
		cout<<"Podaj login: ";
		cin>>log;
		cout<<endl<<"Podaj haslo: ";
		cin>>pass;
		if(o[0].zaloguj(log,pass)==1){
			break;
		}
		else if(o[1].zaloguj(log,pass)==1){
			break;
		}
		else if(o[2].zaloguj(log,pass)==1){
			break;
		}
		else{
			cout<<"\nBledny login lub haslo!\n";
		}
	}
	system("cls");
	int dec;
	string dalej;
	bool isShop=true;
	while(isShop){
		//Przywitanie
		cout<<"Witaj ";
		o[id_zalogowanego].wypisz("imie");
		cout<<" ";
		o[id_zalogowanego].wypisz("nazwisko");
		cout<<"!"<<endl;
		//pokaz salda
		cout<<"Twoje saldo wynosi: ";
		o[id_zalogowanego].wypisz("saldo");
		cout<<"PLN\n\n";
			
		cout<<"Witaj w sklepie Stonka\nObecnie na stanie mamy nastepujace artykuly w nieograniczonych ilosciach:\n\n";
		for(int i=0;i<4;i++){
			towar[i].wypisz();
		}
		cout<<endl<<"Ile chcesz zakupic towarow?: ";
		cin>>dec;
		if(dec<1){
			dec=1;
		}
		sklep Koszyk[dec];
		int dec2;
		system("cls");
		cout<<"zajeto 0/"<<dec<<" przedmiotow w koszyku\n";
		for(int i=0;i<dec;i++){
			
			cout<<"Podaj nr. artykulu ktory chcesz dodac do koszyka: \n";
			for(int j=0;j<4;j++){
				towar[j].wypisz();
			}
			cout<<":";
			cin>>dec2;
			if(dec2>3){
				system("cls");
				cout<<"Nie mamy takiego numeru artykulu\n";
				i--;
			}
			else if(dec2<0){
				system("cls");
				cout<<"Czemu podales/as wartosc ujemna?\n";
				i--;
			}
			else{
				Koszyk[i]=towar[dec2];
				system("cls");
				cout<<"Produkt zostal dodany do koszyka, zajeto "<<( i + 1 )<<"/"<<dec<<" przedmiotow w koszyku\n";
			}
		}
		cout<<"------------------\n";
		cout<<"Podsumowanie zakupow: \n";
		double suma=0;
		for(int i=0;i<dec;i++){
			cout<<( i + 1 )<<". ";
			Koszyk[i].wypisz2();
			suma+=Koszyk[i].zwroc_cene();
		}
		cout<<"------------------\nSuma: "<<suma<<"PLN\n...\nSprawdzanie czy mozliwy jest zakup!\n";
		o[id_zalogowanego].zmien_saldo(suma);
		cout<<"kontynuuj zakupy - napisz 'e' \nAby zakonczyc wcisznij dowolny klawisz poza 'e' :";
		string isend;
		cin>>isend;
		if(isend!="e"){
			isShop=false;
		}
		system("cls");
	}
	system("cls");
	cout<<"\nZapraszamy ponownie!!!";
	
	return 0;
}
