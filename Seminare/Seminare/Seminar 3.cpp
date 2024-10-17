#include <iostream>
using namespace std;

class Magazin
{
public: //se recomanda sa fie atributele in private mereu
	string oras;
	int nrAngajati;
	float suprafata;
	const int anDeschidere; //const -> nu se schimba valoarea pe toata durata de viata a obiectului
	static int impozitM2; //static -> se declara in zona de memorie a clasei

	Magazin():anDeschidere(2024),nrAngajati(2) //-> merge sa atribuim si pentru orice atribut, nu numai constante
	{
		this->oras = "Bucuresti";
		this->suprafata = 50;

	}
	//constructorul implicit nu are tip returnat deci numele este cel al clasei

	Magazin(string oras, int nrAngajati, float suprafata, int an): anDeschidere(an)
	{
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;

	}

	void afisare() //functia nu primeste parametrii pt ca avem this, primeste Magazin (?)
	{
		cout << "Oras:" << this->oras << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe m2:" << this->impozitM2 << endl; //statica merge si cu this-> si fara
	}

	//metoda sa calculeze suprafata medie
	float calculeazaSuprafataMedie()
	{
		if (this->nrAngajati != 0)
		{
			return this->suprafata / this->nrAngajati;
		}
		else
			return 0;
	}

	static void modificaImpozit(int impozit) //fiind fct statica, apartine clasei (nu se fol this la fct statice)
	{
		if (impozit > 0)
		{
			Magazin::impozitM2 = impozit;
		}
		
	}

	//este bine ca o fct statica sa fie in interiorul clasei deoarece statica lucreaza cu atributele clasei (?)
	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine)
	{
		float suma = 0;
		for (int i = 0;i < nrMagazine;i++)
		{
			suma = suma + vector[i].suprafata;
		}
		return suma;
	}
};
int Magazin::impozitM2 = 2; //:: operator de rezolutie -> acceseaza in clasa

//difernta dintre o metoda si o functie: metoda primeste pointerul this

int main()
{
	Magazin m1;
	m1.afisare();

	Magazin m2("Iasi", 10, 200, 2019);
	m2.afisare();

	Magazin* pointer = new Magazin("Timisoara", 5, 250, 2018);
	pointer->afisare(); //-> face dereferentiere si accesare
	
	cout << "Suprafata medie pe angajat este: " << pointer->calculeazaSuprafataMedie()<<endl;

	int nrMagazine = 3;
	Magazin* vector = new Magazin[nrMagazine];
	//in cazul in care nu avem niciun constructor vine compilatorul si va face el un constructor implicit cu valori random
	//daca avem doar un constructor CU parametrii nu vom putea face un vector, pentru ca vectorul foloseste constructorul implicit
	for (int i = 0;i < nrMagazine;i++)
	{
		vector[i].afisare(); //indexul [] face dereferentiere si deplasare deci nu avem sageata
		//(*(vector+1)).afisare = deplasare - deferentiere - afisare
		
	}

	Magazin::modificaImpozit(3); //sau
	m1.modificaImpozit(4);

	cout << "Suprafata totala este: " << Magazin::calculeazaSuprafataTotala(vector, nrMagazine)<<endl;
	delete[] vector;
	delete[] pointer;
}