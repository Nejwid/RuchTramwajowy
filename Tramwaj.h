#pragma once
#include <string>
#include <memory>
#include <thread>
#include <chrono> // biblioteka dla sleep for
#include <queue>

class Przystanek;

using namespace::std;

class Tramwaj {

protected:
	
	int numerBoczny;  // id tramwaju
	
	int czasObs³ugiPrzystanku; // rózne tramwaje maj¹ ró¿ne czasy
	
	chrono::steady_clock::time_point pocz¹tek, koniec; // sk³adowe do mierzenia czasu przejazdu

	queue<pair<shared_ptr<Przystanek>, int>> pozosta³ePrzystanki;

	bool czyJestNaTrasie;

public:

	Tramwaj(int nr);

	void UstawKurs(queue<pair<shared_ptr<Przystanek>, int>> rozk³ad);

	bool Obs³u¿Pasa¿erów();

	void RealizujPrzystanek();

	void JedŸDalej();

	void OpóŸnienie(int opó¿nienie);

	chrono::milliseconds CzasPrzejazdu();

	virtual string ModelTramwaju() = 0;
}; 
