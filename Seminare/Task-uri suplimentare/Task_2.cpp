#include <iostream>
using namespace std;

//domeniu: Vehicule

class Masina
{
public:

	char* marca;
	float capacitateMotor;
	int anFabricatie;
	static int nrTotalMasini;
	const string tip;

	Masina() : tip("Vehicul")
	{
		this->marca = new char[strlen("Audi") + 1];
		strcpy_s(this->marca, strlen("Audi") + 1, "Audi");
		this->capacitateMotor = 5.4;
		this->anFabricatie = 2014;
		nrTotalMasini++;
	}

	Masina(const char* marca, int anFabricatie, string tipMasina) : tip(tipMasina)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->anFabricatie = anFabricatie;
		nrTotalMasini++;
	}

	Masina(const char* marca, float capacitateMotor, int anFabricatie, string tipMasina) : tip(tipMasina)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->capacitateMotor = capacitateMotor;
		this->anFabricatie = anFabricatie;
		nrTotalMasini++;
	}

	~Masina()
	{
		if (this->marca)
		{
			delete[]this->marca;
		}
	}
	
	static void modificaNrTotalMasini(int nrTotalMasini)
	{
		Masina::nrTotalMasini=nrTotalMasini;
	}

	void afisare()
	{
		cout << "Masina are marca " << marca << " cu capacitate motor de " << capacitateMotor << " anul fabricatiei este " << anFabricatie << " , iar nr total de masini este " << nrTotalMasini << " de tipul " << tip<<endl;
	}
};
int Masina::nrTotalMasini = 0;

class Motocicleta
{
public:
	char* marca;
	float capacitateCilindrica;
	int putereMotor;
	static int nrTotalMotociclete;
	const string tip;

	Motocicleta() : tip("Vehicul")
	{
		this->marca = new char[strlen("Yamaha") + 1];
		strcpy_s(this->marca, strlen("Yamaha") + 1, "Yamaha");
		this->capacitateCilindrica = 3.8;
		this->putereMotor = 4;
		nrTotalMotociclete++;
	}
	
	Motocicleta(const char* marca, int putereMotor, string tipMotor) : tip(tipMotor)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->putereMotor = putereMotor;
		nrTotalMotociclete++;
	}

	Motocicleta(const char* marca, float capacitateCilindrica, int putereMotor, string tipMotor) : tip(tipMotor)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->capacitateCilindrica = capacitateCilindrica;
		this->putereMotor = putereMotor;
		nrTotalMotociclete++;
	}

	static void modificaNrTotalMotociclete(int nrTotalMotociclete)
	{
		Motocicleta::nrTotalMotociclete=nrTotalMotociclete;
	}

	void afisare()
	{
		cout << "Motocicleta are marca " << marca << " cu capacitate cilindrica de " << capacitateCilindrica << " putere motor este " << putereMotor << " , iar nr total de motociclete este " << nrTotalMotociclete << " de tipul " << tip << endl;
	}
};
int Motocicleta::nrTotalMotociclete = 0;

class Bicicleta
{
public:
	char* marca;
	float greutate;
	int nrViteze;
	static int nrTotalBiciclete;
	const string tip;

	Bicicleta() : tip("Vehicul")
	{
		this->marca = new char[strlen("Trek") + 1];
		strcpy_s(this->marca, strlen("Trek") + 1, "Trek");
		this->greutate = 40.3;
		this->nrViteze = 3;
		nrTotalBiciclete++;
	}
	
	Bicicleta(const char* marca, int nrViteze, string tipBici) : tip(tipBici)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->nrViteze = nrViteze;
		nrTotalBiciclete++;
	}

	Bicicleta(const char* marca, float greutate, int nrViteze, string tipBici) : tip(tipBici)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->greutate = greutate;
		this->nrViteze = nrViteze;
		nrTotalBiciclete++;
	}
	
	static void modificaNrTotalBicicleta(int nrTotalBiciclete)
	{
		Bicicleta::nrTotalBiciclete=nrTotalBiciclete;
	}

	void afisare()
	{
		cout << "Bicicleta are marca " << marca << " cu o greutate de " << greutate << " si nr de viteze de " << nrViteze << " , iar nr total de biciclete este " << nrTotalBiciclete << " de tipul " << tip << endl;
	}
};
int Bicicleta::nrTotalBiciclete = 0;

int main()
{
	Masina m1;
	m1.afisare();
	Masina m2("Mercedes",2001,"Vehicul");
	m2.afisare();
	Masina m3("Dacia", 4.7, 2015, "Vehicul");
	m3.afisare();

	Motocicleta moto1;
	moto1.afisare();
	Motocicleta moto2("Kawasaki", 3, "Vehicul");
	moto2.afisare();
	Motocicleta moto3("Harley-Davidson", 3.9, 4, "Vehicul");
	moto3.afisare();

	Bicicleta b1;
	b1.afisare();
	Bicicleta b2("Specialized", 2, "Vehicul");
	b2.afisare();
	Bicicleta b3("Giant", 54, 4, "Vehicul");
	b3.afisare();
}