#include <iostream>
using namespace std;

class Magazin
{
public: //se recomanda sa fie atributele in private mereu
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	const int anDeschidere; //const -> nu se schimba valoarea pe toata durata de viata a obiectului
	static int impozitM2; //static -> se declara in zona de memorie a clasei

	Magazin():anDeschidere(2024),nrAngajati(0) //-> merge sa atribuim si pentru orice atribut, nu numai constante; lista de initializare a constructorului
	{
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL; //null alias pt 0
							//nullptr nu e alias; sa nu le alternam
	}
	//constructorul implicit nu are tip returnat deci numele este cel al clasei

	Magazin(string oras, int nrAngajati, float suprafata, int an): anDeschidere(an)
	{
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0;i < nrAngajati;i++)
		{
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& magazin):anDeschidere(magazin.anDeschidere)
	{
		this->oras = magazin.oras;
		this->nrAngajati = magazin.nrAngajati;
		this->salarii = new float[magazin.nrAngajati]; //nu dezalocam memorie pt ca cream ceva nou
		for (int i = 0; i < nrAngajati; i++)
		{
			this->salarii[i] = magazin.salarii[i];
		}
		this->suprafata = magazin.suprafata;
	}

	int gerNrAngajati()
	{
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float* salarii)
	{
		if (nrAngajati > 0)
		{
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL)
			{
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0;i < nrAngajati;i++)
			{
				this->salarii[i] = salarii[i];
			}
		}
	}

	~Magazin()
	{
		if (this->salarii)
		{
			delete[]this->salarii;
		}
	}//cand se termina durata de viata a obiectului se sterge; se termina unde se termina blocul obiectului respectiv (ex. in main)

	float getSuprafata()
	{
		return this->suprafata;
	}

	void setSuprafata(float suprafata)
	{
		if (suprafata > 0)
		{
			this->suprafata = suprafata;
		}
		
	}

	float* getSalarii()
	{
		return this->salarii;
	}

	float getSalariu(int index)
	{
		if (index >= 0 && index < this->nrAngajati)
		{
			return this->salarii[index];
		}
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
	cout << m1.gerNrAngajati() << endl;
	m1.setNrAngajati(6, new float[6]{2,5,6,1,7,9});//initializare inline
	cout << m1.gerNrAngajati() << endl;

	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2.getSalarii()[1] << endl;
	cout << m2.getSalariu(1) << endl;

	m2.setNrAngajati(5, new float[5]{9,6,4,2,7});
	cout << m2.getSalariu(4) << endl;

	Magazin m3(m2);//prima met de a apela const de copy
	Magazin m4 = m2;//a doua met de a apela const de copy
}