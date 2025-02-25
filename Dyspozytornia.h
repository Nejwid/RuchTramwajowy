#pragma once
#include <unordered_map>
#include <vector>
#include <chrono>
#include <mutex>
#include <queue>
#include <future>
#include "Rozk�adJazdy.h"

class Tramwaj;
class Przystanek;
class Zajezdnia;

using namespace::std;

class Dyspozytornia { // singleton  
private:

	Dyspozytornia();
	
	static mutex mtx;
	
	static unique_ptr<Dyspozytornia> instance;

	Dyspozytornia(const Dyspozytornia&) = delete;

	Dyspozytornia& operator=(const Dyspozytornia&) = delete;

	unique_ptr<Rozk�adJazdy> rozk�adJazdy;

	unordered_map<int, vector<shared_ptr<Tramwaj>>> daneSymulacji; // przypisanie tramwaj�w do linii

	unordered_map<shared_ptr<Tramwaj>, chrono::milliseconds> czasyPrzejazdu; // czas przejazdu tramwaju 

	unordered_map<string, queue<pair<shared_ptr<Przystanek>, int>>> GUI_linie; // powi�zanie danych z GUI z rozk�adem jazdy

	vector<thread> ruchTramwaj�w; // ruch 

	promise<void> start; // mechanizm do r�wnoczesnego uruchomienia wszystkich w�tk�w

	shared_future<void> startSymulacji; // shared future pozwala wielu w�tkom pobrac stan promise

	void RozpocznijKurs(shared_ptr<Tramwaj> tramwaj, int czasOdjazdu, shared_future<void> future);

	void Utw�rzKurs(shared_ptr<Tramwaj> tram, int numerLinii, queue<pair<shared_ptr<Przystanek>, int>> rozk�ad, int czasOdjazdu);

	void GUI_Linie();

	unique_ptr<Zajezdnia> Borek, Gaj, O�bin;

	int wirtualnyNumerBoczny; // dla rozroznienia tramwajow w GUI

public:

	static Dyspozytornia* GetInstance();

	void Setup();

	void GUI_Setup(const string&tramwaj, const string&linia, int odjazd);

	void RealizujKursy();

	vector<string> Statystyki();
};

