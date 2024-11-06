#include <iostream>
using namespace std;

//domeniu: Vehicule

class Masina
{
private:

	char* marca;
	float capacitateMotor;
	int anFabricatie;
	static int nrTotalMasini;
	const string tip;

public:

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
		this->capacitateMotor = 1000;
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

	Masina(const Masina& masina) :tip(masina.tip)
	{
		this->marca = new char[strlen(masina.marca) + 1];
		strcpy_s(this->marca, strlen(masina.marca) + 1, masina.marca);
		this->capacitateMotor = masina.capacitateMotor;
		this->anFabricatie = masina.anFabricatie;
		nrTotalMasini++;
	}

	~Masina()
	{
		if (this->marca)
		{
			delete[]this->marca;
		}
		nrTotalMasini--;
	}

	static void modificaNrTotalMasini(int nrTotalMasini)
	{
		Masina::nrTotalMasini = nrTotalMasini;
	}

	void afisare()
	{
		cout << "Masina are marca " << marca << " cu capacitate motor de " << capacitateMotor << " anul fabricatiei este " << anFabricatie << " , iar nr total de masini este " << nrTotalMasini << " de tipul " << tip << endl;
	}


	float getCapacitateMotor()
	{
		return this->capacitateMotor;
	}

	void setCapacitateMotor(float capacitateMotor)
	{
		this->capacitateMotor = capacitateMotor;
	}


	int getAnFabricatie()
	{
		return this->anFabricatie;
	}

	void setAnFabricatie(int anFabricatie)
	{
		this->anFabricatie = anFabricatie;
	}


	const char* getMarca()
	{
		return this->marca;
	}

	void setMarca(const char* marca)
	{
		if (this->marca != NULL)
		{
			delete[]this->marca;
		}
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
	}


	static int getNrTotalMasini()
	{
		return nrTotalMasini;
	}

	static void setNrTotalMasini(int nrTotalMasini)
	{
		Masina::nrTotalMasini = nrTotalMasini;
	}


	const string getTip()
	{
		return this->tip;
	}

	friend void imbunatatireMasina(Masina& m);
	
	Masina& operator=(const Masina& masina)
	{
		if (marca != NULL)
		{
			delete[]marca;
		}
		marca = new char[strlen(masina.marca) + 1];
		strcpy_s(marca, strlen(masina.marca) + 1, masina.marca);
		capacitateMotor = masina.capacitateMotor;
		anFabricatie = masina.anFabricatie;
		//nrTotalMasini = masina.nrTotalMasini;
		return *this;
	}

	friend ostream& operator<<(ostream& consola, Masina& masina);
	friend istream& operator>>(istream& consola, Masina& masina);

	Masina operator+(float capacitate)
	{
		Masina aux = *this;
		aux.capacitateMotor = aux.capacitateMotor + capacitate;
		return aux;
	}
};
int Masina::nrTotalMasini = 0;

void imbunatatireMasina(Masina& m)
{
	m.capacitateMotor = m.capacitateMotor + 1000;
}

ostream& operator<<(ostream& consola, Masina& masina)
{
	consola<< "Masina are marca " << masina.marca << " cu capacitate motor de " << masina.capacitateMotor << " anul fabricatiei este " << masina.anFabricatie << " , iar nr total de masini este " << masina.nrTotalMasini << " de tipul " << masina.tip << endl;
	return consola;
}

istream& operator>>(istream& consola, Masina& masina)
{
	cout << "Masina are marca: ";
	char buffer[100];
	consola >> buffer;
	if (masina.marca != NULL)
	{
		delete[]masina.marca;
	}
	masina.marca = new char[strlen(buffer) + 1];
	strcpy_s(masina.marca, strlen(buffer) + 1, buffer);
	cout << "Capacitate motor: ";
	consola >> masina.capacitateMotor;
	cout << "Anul fabricatiei: ";
	consola >> masina.anFabricatie;
	return consola;
}

class Motocicleta
{
private:

	char* marca;
	float capacitateCilindrica;
	int putereMotor;
	static int nrTotalMotociclete;
	const string tip;

public:

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
		this->capacitateCilindrica = 300;
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

	Motocicleta(const Motocicleta& motocicleta) :tip(motocicleta.tip)
	{
		this->marca = new char[strlen(motocicleta.marca) + 1];
		strcpy_s(this->marca, strlen(motocicleta.marca) + 1, motocicleta.marca);
		this->capacitateCilindrica = motocicleta.capacitateCilindrica;
		this->putereMotor = motocicleta.putereMotor;
		nrTotalMotociclete++;
	}

	~Motocicleta()
	{
		if (this->marca)
		{
			delete[]this->marca;
		}
		nrTotalMotociclete--;
	}

	static void modificaNrTotalMotociclete(int nrTotalMotociclete)
	{
		Motocicleta::nrTotalMotociclete = nrTotalMotociclete;
	}

	void afisare()
	{
		cout << "Motocicleta are marca " << marca << " cu capacitate cilindrica de " << capacitateCilindrica << " putere motor este " << putereMotor << " , iar nr total de motociclete este " << nrTotalMotociclete << " de tipul " << tip << endl;
	}


	float getCapacitateCilindrica()
	{
		return this->capacitateCilindrica;
	}

	void setCapacitateCilindrica(float capacitateCilindrica)
	{
		this->capacitateCilindrica = capacitateCilindrica;
	}


	int getPutereMotor()
	{
		return this->putereMotor;
	}

	void setPutereMotor(int putereMotor)
	{
		this->putereMotor = putereMotor;
	}


	char* getMarca()
	{
		return this->marca;
	}

	void setMarca(char* marca)
	{
		if (this->marca != NULL)
		{
			delete[]this->marca;
		}
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
	}


	static int getNrTotalMotociclete()
	{
		return nrTotalMotociclete;
	}

	static void setNrTotalMasini(int nrTotalMotociclete)
	{
		Motocicleta::nrTotalMotociclete = nrTotalMotociclete;
	}


	const string getTip()
	{
		return this->tip;
	}

	Motocicleta& operator=(const Motocicleta& motocicleta)
	{
		if (marca != NULL)
		{
			delete[]marca;
		}
		marca = new char[strlen(motocicleta.marca) + 1];
		strcpy_s(marca, strlen(motocicleta.marca) + 1, motocicleta.marca);
		capacitateCilindrica = motocicleta.capacitateCilindrica;
		putereMotor = motocicleta.putereMotor;
		nrTotalMotociclete = motocicleta.nrTotalMotociclete;
		return *this;
	}

	friend ostream& operator<<(ostream& consola, Motocicleta& motocicleta);
	friend istream& operator>>(istream& consola, Motocicleta& motocicleta);

	Motocicleta operator+(float capacitate)
	{
		Motocicleta aux = *this;
		aux.capacitateCilindrica = aux.capacitateCilindrica + capacitate;
		return aux;
	}
};
int Motocicleta::nrTotalMotociclete = 0;

ostream& operator<<(ostream& consola, Motocicleta& motocicleta)
{
	consola << "Motocicleta are marca " << motocicleta.marca << " cu capacitate cilindrica de " << motocicleta.capacitateCilindrica << " puterea motorului este " << motocicleta.putereMotor << " , iar nr total de motociclete este " << motocicleta.nrTotalMotociclete << " de tipul " << motocicleta.tip << endl;
	return consola;
}

istream& operator>>(istream& consola, Motocicleta& motocicleta)
{
	cout << "Motocicleta are marca: ";
	char buffer[100];
	consola >> buffer;
	if (motocicleta.marca != NULL)
	{
		delete[]motocicleta.marca;
	}
	motocicleta.marca = new char[strlen(buffer) + 1];
	strcpy_s(motocicleta.marca, strlen(buffer) + 1, buffer);
	cout << "Capacitate cilindrica: ";
	consola >> motocicleta.capacitateCilindrica;
	cout << "Putere motor: ";
	consola >> motocicleta.putereMotor;
	return consola;
}

class Bicicleta
{
private:

	char* marca;
	float greutate;
	int nrViteze;
	string culoare;
	static int nrTotalBiciclete;
	const string tip;

public:

	Bicicleta() : tip("Vehicul")
	{
		this->marca = new char[strlen("Trek") + 1];
		strcpy_s(this->marca, strlen("Trek") + 1, "Trek");
		this->greutate = 2.3;
		this->nrViteze = 3;
		this->culoare = "albastru";
		nrTotalBiciclete++;
	}

	Bicicleta(const char* marca, int nrViteze, string tipBici) : tip(tipBici)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->greutate = 3;
		this->nrViteze = nrViteze;
		this->culoare = "albastru";
		nrTotalBiciclete++;
	}

	Bicicleta(const char* marca, float greutate, int nrViteze, string tipBici) : tip(tipBici)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->greutate = greutate;
		this->nrViteze = nrViteze;
		this->culoare = "albastru";
		nrTotalBiciclete++;
	}

	Bicicleta(const Bicicleta& bicicleta) :tip(bicicleta.tip)
	{
		this->marca = new char[strlen(bicicleta.marca) + 1];
		strcpy_s(this->marca, strlen(bicicleta.marca) + 1, bicicleta.marca);
		this->greutate = bicicleta.greutate;
		this->nrViteze = bicicleta.nrViteze;
		this->culoare = bicicleta.culoare;
		nrTotalBiciclete++;
	}

	~Bicicleta()
	{
		if (this->marca)
		{
			delete[]this->marca;
		}
		nrTotalBiciclete--;
	}

	static void modificaNrTotalBicicleta(int nrTotalBiciclete)
	{
		Bicicleta::nrTotalBiciclete = nrTotalBiciclete;
	}

	void afisare()
	{
		cout << "Bicicleta are marca " << marca << " cu o greutate de " << greutate << " si nr de viteze de " << nrViteze << " si culoarea " << culoare << ", iar nr total de biciclete este " << nrTotalBiciclete << " de tipul " << tip << endl;
	}


	float getGreutate()
	{
		return this->greutate;
	}

	void setGreutate(float greutate)
	{
		this->greutate = greutate;
	}


	int getNrViteze()
	{
		return this->nrViteze;
	}

	void setNrViteze(int nrViteze)
	{
		this->nrViteze = nrViteze;
	}


	char* getMarca()
	{
		return this->marca;
	}

	void setMarca(char* marca)
	{
		if (this->marca != NULL)
		{
			delete[]this->marca;
		}
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
	}

	string getCuloare()
	{
		return this->culoare;
	}

	void setCuloare(string culoare)
	{
		this->culoare = culoare;
	}


	static int getNrTotalBiciclete()
	{
		return nrTotalBiciclete;
	}

	static void setNrTotalBiciclete(int nrTotalBiciclete)
	{
		Bicicleta::nrTotalBiciclete = nrTotalBiciclete;
	}


	const string getTip()
	{
		return this->tip;
	}

	friend void vopsesteBicicleta(Bicicleta& b, string culoareNoua);

	Bicicleta& operator=(const Bicicleta& bicicleta)
	{
		if (marca != NULL)
		{
			delete[]marca;
		}
		marca = new char[strlen(bicicleta.marca) + 1];
		strcpy_s(marca, strlen(bicicleta.marca) + 1, bicicleta.marca);
		greutate = bicicleta.greutate;
		nrViteze = bicicleta.nrViteze;
		culoare = bicicleta.culoare;
		nrTotalBiciclete = bicicleta.nrTotalBiciclete;
		return *this;
	}

	friend ostream& operator<<(ostream& consola, Bicicleta& bicicleta);
	friend istream& operator>>(istream& consola, Bicicleta& bicicleta);

	Bicicleta operator+(int pinion)
	{
		Bicicleta aux = *this;
		aux.nrViteze = aux.nrViteze + pinion;
		return aux;
	}
};
int Bicicleta::nrTotalBiciclete = 0;

void vopsesteBicicleta(Bicicleta& b, string culoareNoua)
{
	b.culoare = culoareNoua;
}

ostream& operator<<(ostream& consola, Bicicleta& bicicleta)
{
	consola << "Bicicleta are marca " << bicicleta.marca << " cu greutatea de " << bicicleta.greutate << " nr de viteze este " << bicicleta.nrViteze << " si culoarea " << bicicleta.culoare << " , iar nr total de biciclete este " << bicicleta.nrTotalBiciclete << " de tipul " << bicicleta.tip << endl;
	return consola;
}

istream& operator>>(istream& consola, Bicicleta& bicicleta)
{
	cout << "Bicicleta are marca: ";
	char buffer[100];
	consola >> buffer;
	if (bicicleta.marca != NULL)
	{
		delete[]bicicleta.marca;
	}
	bicicleta.marca = new char[strlen(buffer) + 1];
	strcpy_s(bicicleta.marca, strlen(buffer) + 1, buffer);
	cout << "Greutate: ";
	consola >> bicicleta.greutate;
	cout << "Nr viteze: ";
	consola >> bicicleta.nrViteze;
	cout << "Culoarea: ";
	consola >> bicicleta.culoare;
	return consola;
}

int main()
{
	Masina m1;
	m1.afisare();
	Masina m2("Mercedes", 2001, "Vehicul");
	m2.afisare();
	Masina m3("Dacia", 4.7, 2015, "Vehicul");
	m3.afisare();

	cout << "Masina are marca " << m1.getMarca() << " cu capacitate motor de " << m1.getCapacitateMotor() << " anul fabricatiei este " << m1.getAnFabricatie() << " , iar nr total de masini este " << m1.getNrTotalMasini() << " de tipul " << m1.getTip() << endl;
	m1.setMarca("BMW");
	m1.setCapacitateMotor(1800);
	m1.setAnFabricatie(2020);
	//m1.setNrTotalMasini(5);
	cout << "Masina are marca " << m1.getMarca() << " cu capacitate motor de " << m1.getCapacitateMotor() << " anul fabricatiei este " << m1.getAnFabricatie() << " , iar nr total de masini este " << m1.getNrTotalMasini() << " de tipul " << m1.getTip() << endl;

	imbunatatireMasina(m1);
	cout << "Masina imbunatatita are acum capacitatea de " << m1.getCapacitateMotor() << endl;

	Masina m4;
	m4.afisare();
	m4 = m2;
	m4.afisare();
	
	m4 = m2 + 17.4;
	cout << m4;

	Masina m5;
	cin >> m5;
	cout << m5;

	Motocicleta moto1;
	moto1.afisare();
	Motocicleta moto2("Kawasaki", 3, "Vehicul");
	moto2.afisare();
	Motocicleta moto3("Harley-Davidson", 3.9, 4, "Vehicul");
	moto3.afisare();

	cout << "Motocicleta are marca " << moto1.getMarca() << " cu capacitate cilindrica de " << moto1.getCapacitateCilindrica() << " putere motor este " << moto1.getPutereMotor() << " , iar nr total de motociclete este " << moto1.getNrTotalMotociclete() << " de tipul " << moto1.getTip() << endl;

	Motocicleta moto4;
	moto4.afisare();
	moto4 = moto3;
	moto4.afisare();

	moto4 = moto2 + 22.3;
	cout << moto4;

	Motocicleta moto5;
	cin >> moto5;
	cout << moto5;

	Bicicleta b1;
	b1.afisare();
	Bicicleta b2("Specialized", 2, "Vehicul");
	b2.afisare();
	Bicicleta b3("Giant", 3.1, 4, "Vehicul");
	b3.afisare();

	cout << "Bicicleta are marca " << b1.getMarca() << " cu o greutate de " << b1.getGreutate() << " si nr de viteze de " << b1.getNrViteze() << " si culoarea " << b1.getCuloare() << " , iar nr total de biciclete este " << b1.getNrTotalBiciclete() << " de tipul " << b1.getTip() << endl;

	vopsesteBicicleta(b1, "Roz");
	cout << "Bicicleta are acum culoarea " << b1.getCuloare() << endl;

	Bicicleta b4;
	b4.afisare();
	b4 = b2;
	b4.afisare();

	b4 = b2 + 1;
	cout << b4;
	
	Bicicleta b5;
	cin >> b5;
	cout << b5;
}