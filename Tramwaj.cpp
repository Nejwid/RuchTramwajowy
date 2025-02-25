#include "Tramwaj.h"
#include "RodzajeTramwajów.h"
#include "Przystanek.h"

Tramwaj::Tramwaj(int nr) : czyJestNaTrasie(false), numerBoczny(nr) {}

void Tramwaj::UstawKurs(queue<pair<shared_ptr<Przystanek>, int>> rozkład) { // ustawienie linii i godziny odjazdu
	if (!czyJestNaTrasie) {	
		this->pozostałePrzystanki = rozkład;
		this->czyJestNaTrasie = true;
	} 
}

bool Tramwaj::ObsłużPasażerów() { // obsługujemy przystanek przez czas zależny od modelu tramwaju
	this_thread::sleep_for(chrono::milliseconds(this->czasObsługiPrzystanku*10)); 
	return true;
}

void Tramwaj::JedźDalej() { // jedziemy do nastepnego przystanku przez czas podany w rozkładzie jazdy
	this_thread::sleep_for(chrono::milliseconds(this->pozostałePrzystanki.front().second*100));
}


void Tramwaj::RealizujPrzystanek() { // dojechaliśmy do następnego przystanku
	
	pozostałePrzystanki.front().first->RealizujPrzystanek(this->czasObsługiPrzystanku);
	
	pozostałePrzystanki.pop();
}

chrono::milliseconds Tramwaj::CzasPrzejazdu() { // pomiar czasu przejazdu
	this->początek = chrono::steady_clock::now();

	while (!pozostałePrzystanki.empty()) {
		this->JedźDalej();
		this->RealizujPrzystanek();
	}

	this->koniec = chrono::steady_clock::now();

	auto całkowityCzas = chrono::duration_cast<chrono::milliseconds>(this->koniec - this->początek);

	return całkowityCzas;
}

void Tramwaj::Opóźnienie(int opóźnienie) { 
	this_thread::sleep_for(chrono::milliseconds(opóźnienie*10));
}
