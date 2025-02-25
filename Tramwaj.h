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
	
	int czasObs�ugiPrzystanku; // r�zne tramwaje maj� r�ne czasy
	
	chrono::steady_clock::time_point pocz�tek, koniec; // sk�adowe do mierzenia czasu przejazdu

	queue<pair<shared_ptr<Przystanek>, int>> pozosta�ePrzystanki;

	bool czyJestNaTrasie;

public:

	Tramwaj(int nr);

	void UstawKurs(queue<pair<shared_ptr<Przystanek>, int>> rozk�ad);

	bool Obs�u�Pasa�er�w();

	void RealizujPrzystanek();

	void Jed�Dalej();

	void Op�nienie(int op�nienie);

	chrono::milliseconds CzasPrzejazdu();

	virtual string ModelTramwaju() = 0;
}; 
