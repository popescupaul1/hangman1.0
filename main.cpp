#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

void joc_spanzuratoare(int incercari, string cuvant_dorit) {
	cout << "\nSPANZURATOAREA\n";
	cout << "\nAi " << incercari << " incercari pentru a ghici cuvantul. Succes!\n";
	int lungime_cuvant = cuvant_dorit.length();
	string progres_cuvant;
	char litera_ghicita;
	char prima_litera = cuvant_dorit[0], ultima_litera = cuvant_dorit[lungime_cuvant - 1];
	cout << " -> Prima litera a cuvantului este: " << prima_litera << endl;
	cout << " -> Ultima litera a cuvantului este: " << ultima_litera << endl;
	cout << "Cuvantul are " << lungime_cuvant << " litere. Poti incepe sa ghicesti litere!\n";


	cout << "\nIntrodu litera ghicita: "; cin >> litera_ghicita;
	for (int lit = 0; lit < lungime_cuvant; lit++) {
		if (cuvant_dorit[lit] == litera_ghicita)
			progres_cuvant.push_back(litera_ghicita);
		else
			progres_cuvant.push_back('-');
	}
	progres_cuvant[0] = prima_litera, progres_cuvant[lungime_cuvant - 1] = ultima_litera;
	cout << "Stare cuvant ghicit: " << progres_cuvant << endl;
	if (cuvant_dorit.find(litera_ghicita) != string::npos)
		cout << "Litera corecta! ";
	else
		incercari--, cout << "Litera incorecta... ";
	cout << "Mai ai: " << incercari << " incercari.\n";


	while (incercari) {
		cout << "\nIntrodu litera ghicita: "; cin >> litera_ghicita;
		for (int lit = 0; lit < lungime_cuvant; lit++) {
			if (cuvant_dorit[lit] == litera_ghicita) {
				progres_cuvant[lit] = litera_ghicita;
			}
		}

		cout << "Stare cuvant ghicit: " << progres_cuvant << endl;
		if (cuvant_dorit.find(litera_ghicita) != string::npos)
			cout << "Litera corecta! ";
		else
			incercari--, cout << "Litera incorecta... ";
		cout << "Mai ai: " << incercari << " incercari.\n";

		int comp = cuvant_dorit.compare(progres_cuvant);
		if (comp == 0) {
			cout << "\n----------------------------------\n",
				cout << " Ai ghicit cuvantul! - Felicitari!",
				cout << "\n	    Exiting...",
				cout << "\n----------------------------------\n";
			return;
		}
	}

	if (incercari == 0)
		cout << "\n-----------------------------------------------\n",
		cout << "	Cuvantul era: " << cuvant_dorit << endl;
	cout << " Nu ai ghicit cuvantul. Good luck next time! :)",
		cout << " \n		Exiting...",
		cout << "\n-----------------------------------------------\n";
	return;
}

int main()
{
	srand(time(0));
	vector<string> cuvinte;  //vector cuvinte
	cuvinte.push_back("derivabilitate");  //lista cuvinte
	cuvinte.push_back("spanzuratoarea");  //should prob find a better way than this
	cuvinte.push_back("animale");
	cuvinte.push_back("brutarie");
	cuvinte.push_back("intelepciune");
	cuvinte.push_back("amfibian");
	cuvinte.push_back("craciun");
	cuvinte.push_back("sarbatori");

	random_shuffle(cuvinte.begin(), cuvinte.end());
	string cuvant_dorit = cuvinte[0];
	int incercari = 6;

	int alegere;
	cout << "Ce mini-game vrei sa joci? \n";
	cout << "1. Spanzuratoarea \n";
	cout << "2. Coming soon...\n";
	cout << "Alegere: ";  cin >> alegere;
	switch (alegere) {
	case 1:
		joc_spanzuratoare(incercari, cuvant_dorit);
		break;
	default:
		cout << "Indisponibil...";
	}
}