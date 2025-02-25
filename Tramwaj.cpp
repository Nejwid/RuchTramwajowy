#include "Tramwaj.h"
#include "RodzajeTramwajów.h"
#include "Przystanek.h"

Tramwaj::Tramwaj(int nr) : czyJestNaTrasie(false), numerBoczny(nr) {}

void Tramwaj::UstawKurs(queue<pair<shared_ptr<Przystanek>, int>> rozk³ad) { // ustawienie linii i godziny odjazdu
	if (!czyJestNaTrasie) {	
		this->pozosta³ePrzystanki = rozk³ad;
		this->czyJestNaTrasie = true;
	} 
}

bool Tramwaj::Obs³u¿Pasa¿erów() { // obs³ugujemy przystanek przez czas zale¿ny od modelu tramwaju
	this_thread::sleep_for(chrono::milliseconds(this->czasObs³ugiPrzystanku*10)); 
	return true;
}

void Tramwaj::JedŸDalej() { // jedziemy do nastepnego przystanku przez czas podany w rozk³adzie jazdy
	this_thread::sleep_for(chrono::milliseconds(this->pozosta³ePrzystanki.front().second*100));
}


void Tramwaj::RealizujPrzystanek() { // dojechaliœmy do nastêpnego przystanku
	
	pozosta³ePrzystanki.front().first->RealizujPrzystanek(this->czasObs³ugiPrzystanku);
	
	pozosta³ePrzystanki.pop();
}

chrono::milliseconds Tramwaj::CzasPrzejazdu() { // pomiar czasu przejazdu
	this->pocz¹tek = chrono::steady_clock::now();

	while (!pozosta³ePrzystanki.empty()) {
		this->JedŸDalej();
		this->RealizujPrzystanek();
	}

	this->koniec = chrono::steady_clock::now();

	auto ca³kowityCzas = chrono::duration_cast<chrono::milliseconds>(this->koniec - this->pocz¹tek);

	return ca³kowityCzas;
}

void Tramwaj::OpóŸnienie(int opóŸnienie) { 
	this_thread::sleep_for(chrono::milliseconds(opóŸnienie*10));
}
