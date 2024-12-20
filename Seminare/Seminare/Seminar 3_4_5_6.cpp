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

	//tipReturnat nume (lista parametrii)
	//m4=m3=m2 apel in cascada

	Magazin operator=(const Magazin& m) //const punem referinta
	{
		if (&m != this) //verificare de autoasignare
		{
			oras = m.oras;
			nrAngajati = m.nrAngajati;
			if (salarii != NULL)
			{
				delete[]salarii;
			}
			salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++)
			{
				salarii[i] = m.salarii[i];
			}
			suprafata = m.suprafata;
		}
		return *this; //returnam obiectul de la adresa lui this
	}

	//polimorfism prin tipul parametrii si/sau nr de parametrii

	Magazin operator+(const Magazin& m)
	{
		Magazin aux = *this;
		aux.suprafata = aux.suprafata + m.suprafata;
		return aux;
	}

	Magazin operator+(const Magazin& m)const
	{
		Magazin temp = *this;
		temp.nrAngajati = nrAngajati + m.nrAngajati;
		float* aux = new float[m.nrAngajati];
		for (int i = 0; i < nrAngajati; i++)
		{
			aux[i] = salarii[i];
		}
		for (int i = 0; i < m.nrAngajati; i++) {
			aux[i + this->nrAngajati] = m.salarii[i];
		}
		if (temp.salarii != NULL)
		{
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Magazin operator+=(const Magazin& m) //diferenta dintr += si + : this se modifica la +=, la + this nu se modifica
	{
		nrAngajati = nrAngajati + m.nrAngajati;
		return *this;
	}

	Magazin operator+(float marireAngajati)const
	{
		Magazin aux = *this;
		aux.nrAngajati = this->nrAngajati + marireAngajati;
		return aux;
	}

	bool operator>(Magazin m)
	{
		return this->suprafata > m.suprafata && this->nrAngajati > m.nrAngajati;
	}

	bool operator==(Magazin m)
	{
		return this->suprafata == m.suprafata && this->nrAngajati == m.nrAngajati;
	}

	operator int()
	{
		return this->nrAngajati;
	}

	operator float()
	{
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++)
		{
			s += this->salarii[i];
		}
		return s;
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < nrAngajati)
		{
			return salarii[index];
		}
		else
		{
			//pt a lucra cu exceptii: throw, try si catch
			throw "Indexul este in afara limitelor";
		}
	}

	friend Magazin operator+(float marire, const Magazin& m); //fol get si set daca nu o declaram friend
	friend ostream& operator<<(ostream& consola, const Magazin& m);
	//friend istream& operator>>(istream& consola, const Magazin& m);
};
int Magazin::impozitM2 = 2; //:: operator de rezolutie -> acceseaza in clasa

//difernta dintre o metoda si o functie: metoda primeste pointerul this
//metoda in clasa, fct in afara

Magazin operator+(float marire, const Magazin& m) //este functie nu metoda
{
	Magazin aux = m;
	aux.nrAngajati = marire + m.nrAngajati;
	return aux;
}

ostream& operator<<(ostream& consola, const Magazin& m) //const pt ca e referinta
{
	consola << "Oras:" << m.oras << endl;
	consola << "Nr angajati:" << m.nrAngajati << endl;
	if (m.nrAngajati > 0)
	{
		for (int i = 0;i < m.nrAngajati;i++)
		{
			consola << "Salarii: "<< m.salarii[i] << endl;
		}
	}
	consola << "Suprafata:" << m.suprafata << endl;
	consola << "An deschidere:" << m.anDeschidere << endl;
	consola << "Impozit pe m2:" << m.impozitM2 << endl;
	return consola;
}

//istream& operator>>(istream& consola, const Magazin& m)
//{
//	cout << "Oras: ";
//	consola >> m.nrAngajati;
//}

int main()
{
	Magazin m1;
	cout << m1.gerNrAngajati() << endl;
	m1.setNrAngajati(6, new float[6]{2,5,6,1,7,9});//initializare inline
	cout << m1.gerNrAngajati() << endl;

	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2.getSalarii()[1] << endl;
	cout << m2.getSalariu(1) << endl;

	//m2.setNrAngajati(5, new float[5]{9,6,4,2,7});
	//cout << m2.getSalariu(4) << endl;

	Magazin m3(m2);//prima met de a apela const de copy
	Magazin m4 = m2;//a doua met de a apela const de copy

	m1.afisare();
	Magazin m5;
	m5 = m1;
	m5.afisare();

	//m2 + m3
	//m2.operator+(m3)

	if (m1 > m2) //m1.operator>(m2)
	{
		cout << "m1 e mai mare" << endl;
	}
	else
		cout << "m2 e mai mare" << endl;

	if (m1 == m2) //m1.operator>(m2)
	{
		cout << "m1 e egal cu m2" << endl;
	}
	else
		cout << "nu sunt egale" << endl;

	cout << m2;

	int nrAngajati = (int)m2; //transformare mod explicit
	
	float salariiTotale = m2;
	cout << "Salarii totale: " << salariiTotale<<endl;

	try {
		cout << m2[1] << endl;
		m2[1] = 200; //ca sa putem da valoare fol float& altfel se va face o copie locala care este const si nu poate fi modificata
		cout << m2[1] << endl;
		float salariuAngajati2 = m2[1]; //aici se incearca rularea acestui cod
		float s = m2[-9];
	} 
	catch (int exceptie)
	{

	}
	catch (float exceptie)
	{

	}
	catch (const char* exceptie)
	{
		cout << exceptie << endl;
	}
	catch (string exceptie)
	{

	}
	catch (...) //= orice tip de exceptie
	{

	}
	
	//alocare dinamica -> const de copiere, destructor, operator=
	//metode, fct statice, 1-2 constructori
}