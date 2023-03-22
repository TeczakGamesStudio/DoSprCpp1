#include <iostream>

using namespace std;

class osoba1{
	
	public: 
		string imie;
	
};

class osoba2{
	
	public:
		string imie;
		// setter - metoda klasy (funkcja wewn¹trz klasy), która ustawia wartoœci na zmiennych 
		// cz³onkowskich(publicznych / prywatnych / chronionych) obiektów
		void UstawWiek(int wiekU){
			wiek=wiekU;
		}
		// getter - metoda klasy, która pozwala u¿yskaæ informacjê o zminennych cz³onkowskich
		// obiektów (publicznych / prywatnych / chronionych)
		void wypiszDane(){
			cout<< "Imiê: "<<imie<<" ,Wiek: "<<wiek<<endl;
		}
	private:
		int wiek;
	
};

class osoba3{
	
	public:
		string imie,nazwisko;
		// settery - prototypy metod
		int ustawDane(string, string, int, double);
		int ustawDane2();
		//getter - prototyp metody
		void wypiszDane();
	private:
		int wiek;
		double saldo;
	
};
// definicja gettera
void osoba3 :: wypiszDane(){
	cout<<endl<<"------------------"<<endl;
	cout<<"Imiê: "<<imie<<endl;
	cout<<"Nazwisko: "<<nazwisko<<endl;
	cout<<"Wiek: "<<wiek<<endl;
	cout<<"Saldo: "<<saldo<<endl;
	cout<<"------------------"<<endl;
}
// definicja setterów
int osoba3 :: ustawDane(string i, string n, int w, double s){
	imie=i;
	nazwisko=n;
	wiek=w;
	saldo=s;
}
int osoba3 :: ustawDane2(){
	cout<<"Podaj Imiê: ";
	cin>>imie;
	cout<<endl<<"Podaj nazwisko: ";
	cin>>nazwisko;
	cout<<endl<<"Podaj wiek: ";
	cin>>wiek;
	cout<<endl<<"Podaj saldo: ";
	cin>>saldo;
	cout<<endl;
}

int main(){

	setlocale(LC_ALL, "Polish");
	//Przyk³ad 1
	//osoba1 o1;
	//o1.imie="Janusz";
	//cout<<"Imiê: "<<o1.imie<<endl;
	
	// Przyk³ad 2
	//osoba2 o2;
	//o2.imie="Kacper";
	//o2.UstawWiek(17);
	//o2.wypiszDane();
	
	//Przyk³ad 3
//	osoba3 o3;
//	string imie2,nazwisko2;
//	int wiek2;
//	double saldo2;
//	cout<<"Podaj imiê: "<<endl;
//	cin>>imie2;
//	cout<<"Podaj nazwisko: "<<endl;
//	cin>>nazwisko2;
//	cout<<"Podaj wiek: "<<endl;
//	cin>>wiek2;
//	cout<<"Podaj saldo: "<<endl;
//	cin>>saldo2;
//	o3.ustawDane(imie2,nazwisko2,wiek2,saldo2);
//	o3.wypiszDane();
	
	//Przyk³ad 4
//	osoba3 o[2];
//	o[0].ustawDane2();
//	o[1].ustawDane2();
//	
//	o[0].wypiszDane();
//	o[1].wypiszDane();	

	//Przyk³ad 5
	osoba3 o[10];
	for(int i=0; i<=9; i++){
		o[i].ustawDane2();
	}
	for(int i=0; i<=9; i++){
		o[i].wypiszDane();
	}	
	return 0;

}
