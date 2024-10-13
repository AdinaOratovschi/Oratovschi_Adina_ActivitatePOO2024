#include <iostream>
using namespace std;

class Apartament
{
public:
	char* adresa;
	string proprietar;
	int nrCamere;
	float suprafata;

};

void afisareApartament(Apartament* ap)
{
	cout << "Adresa: " << ap->adresa << endl;
	cout << "Proprietar: " << ap->proprietar << endl;
	cout << "Nr. camere: " << ap->nrCamere << endl;
	cout << "Suprafata: " << ap->suprafata << endl;
}

Apartament citireApartament()
{
	Apartament ap;
	cout << "Adresa: ";
	char buffer[100];
	cin >> buffer;
	ap.adresa = new char[strlen(buffer) + 1];
	strcpy_s(ap.adresa, strlen(buffer) + 1, buffer);
	cout << "Proprietar: ";
	cin >> ap.proprietar;
	cout << "Nr. camere: ";
	cin >> ap.nrCamere;
	cout << "Suprafata: ";
	cin >> ap.suprafata;

	return ap;
}

int main()
{
	Apartament ap; //declarare
	ap.nrCamere = 3; //accesare

	Apartament* pointer; //pointer accesam cu -> ; obiect accesam cu .
	pointer = new Apartament();
	pointer->nrCamere = 5;
	pointer->proprietar = "Gigel";
	pointer->adresa = new char[strlen("Bucuresti") + 1];  //shallow copy -> se copiaza adresele, nu informatia
	strcpy_s(pointer->adresa, strlen("Bucuresti") + 1, "Bucuresti"); //strcpy nu merge; se pune strcpy_s ce are 3 parametrii (destinatia, size si sursa); _CTR_SECURE_NO_WARNINGS ar trb evitat
	pointer->suprafata = 120;

	afisareApartament(pointer);
	delete pointer;


	Apartament* apartamente;
	apartamente = new Apartament[2];

	/*Apartament** pointeri;
	pointeri = new Apartament * [3];*/

	int nrApartamente = 2;
	apartamente = new Apartament[nrApartamente];

	for (int i = 0; i < nrApartamente; i++)
	{
		apartamente[i] = citireApartament();
	}

	for (int i = 0; i < nrApartamente; i++)
	{
		afisareApartament(&(apartamente[i]));
	}

	for (int i = 0; i < nrApartamente; i++)
	{
		delete[] apartamente[i].adresa;
	}
	delete[] apartamente;
}