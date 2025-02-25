#include "Tramwaj.h"
#include "RodzajeTramwaj�w.h"
#include "Przystanek.h"

Tramwaj::Tramwaj(int nr) : czyJestNaTrasie(false), numerBoczny(nr) {}

void Tramwaj::UstawKurs(queue<pair<shared_ptr<Przystanek>, int>> rozk�ad) { // ustawienie linii i godziny odjazdu
	if (!czyJestNaTrasie) {	
		this->pozosta�ePrzystanki = rozk�ad;
		this->czyJestNaTrasie = true;
	} 
}

bool Tramwaj::Obs�u�Pasa�er�w() { // obs�ugujemy przystanek przez czas zale�ny od modelu tramwaju
	this_thread::sleep_for(chrono::milliseconds(this->czasObs�ugiPrzystanku*10)); 
	return true;
}

void Tramwaj::Jed�Dalej() { // jedziemy do nastepnego przystanku przez czas podany w rozk�adzie jazdy
	this_thread::sleep_for(chrono::milliseconds(this->pozosta�ePrzystanki.front().second*100));
}


void Tramwaj::RealizujPrzystanek() { // dojechali�my do nast�pnego przystanku
	
	pozosta�ePrzystanki.front().first->RealizujPrzystanek(this->czasObs�ugiPrzystanku);
	
	pozosta�ePrzystanki.pop();
}

chrono::milliseconds Tramwaj::CzasPrzejazdu() { // pomiar czasu przejazdu
	this->pocz�tek = chrono::steady_clock::now();

	while (!pozosta�ePrzystanki.empty()) {
		this->Jed�Dalej();
		this->RealizujPrzystanek();
	}

	this->koniec = chrono::steady_clock::now();

	auto ca�kowityCzas = chrono::duration_cast<chrono::milliseconds>(this->koniec - this->pocz�tek);

	return ca�kowityCzas;
}

void Tramwaj::Op�nienie(int op�nienie) { 
	this_thread::sleep_for(chrono::milliseconds(op�nienie*10));
}
