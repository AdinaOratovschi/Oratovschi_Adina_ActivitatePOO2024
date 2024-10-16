#include <iostream>
#include <string>
using namespace std;

struct Bloc
{
	string strada;
	int nr_Scari;
	int nr_Apartamente;
	int anul_Constructiei;
	float suprafata;
};

Bloc citireBloc()
{
	Bloc bloc;
	
	cout << "Strada: ";
	cin >> bloc.strada;
	/*getline(cin, bloc.strada);*/
	cout << "Nr de scari: ";
	cin >> bloc.nr_Scari;
	cout << "Nr apartamente: ";
	cin >> bloc.nr_Apartamente;
	cout << "Anul constructiei: ";
	cin >> bloc.anul_Constructiei;
	cout << "Suprafata: ";
	cin >> bloc.suprafata;
	
	return bloc;
}

void afisareBloc(Bloc bloc)
{
	cout << "Blocul construit in anul "<< bloc.anul_Constructiei <<" se afla pe strada " << bloc.strada << " si are " << bloc.nr_Scari << " scari si " << bloc.nr_Apartamente << " apartamente cu suprafata de " << bloc.suprafata << endl;
}

int main()
{
	Bloc* blocuri;
	int nrBlocuri = 10;
	blocuri = new Bloc[nrBlocuri];

	for (int i = 0; i < nrBlocuri; i++)
	{
		cout << "Blocul " << i << endl;
		blocuri[i] = citireBloc();
	}

	for (int i = 0; i < nrBlocuri; i++)
	{
		afisareBloc(blocuri[i]);
	}

	delete[] blocuri;
}