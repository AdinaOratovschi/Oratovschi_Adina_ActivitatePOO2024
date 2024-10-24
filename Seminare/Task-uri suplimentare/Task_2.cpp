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

	}

	Masina(char* marca, int anFabricatie, string tipMasina) : tip(tipMasina)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->anFabricatie = anFabricatie;
	}

	Masina(char* marca, float capacitateMotor, int anFabricatie, string tipMasina) : tip(tipMasina)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->capacitateMotor = capacitateMotor;
		this->anFabricatie = anFabricatie;
	}
};
int Masina::nrTotalMasini = 1;

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

	}
	
	Motocicleta(char* marca, int putereMotor, string tipMotor) : tip(tipMotor)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->putereMotor = putereMotor;
	}

	Motocicleta(char* marca, float capacitateCilindrica, int putereMotor, string tipMotor) : tip(tipMotor)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->capacitateCilindrica = capacitateCilindrica;
		this->putereMotor = putereMotor;
	}
};
int Motocicleta::nrTotalMotociclete = 1;

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

	}
	
	Bicicleta(char* marca, int nrViteze, string tipBici) : tip(tipBici)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->nrViteze = nrViteze;
	}

	Bicicleta(char* marca, float greutate, int nrViteze, string tipBici) : tip(tipBici)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->greutate = greutate;
		this->nrTotalBiciclete = nrViteze;
	}
};
int Bicicleta::nrTotalBiciclete = 1;
