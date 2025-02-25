#pragma once
#include <unordered_map>
#include <vector>
#include <chrono>
#include <mutex>
#include <queue>
#include <future>
#include "Rozk³adJazdy.h"

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

	unique_ptr<Rozk³adJazdy> rozk³adJazdy;

	unordered_map<int, vector<shared_ptr<Tramwaj>>> daneSymulacji; // przypisanie tramwajów do linii

	unordered_map<shared_ptr<Tramwaj>, chrono::milliseconds> czasyPrzejazdu; // czas przejazdu tramwaju 

	unordered_map<string, queue<pair<shared_ptr<Przystanek>, int>>> GUI_linie; // powi¹zanie danych z GUI z rozk³adem jazdy

	vector<thread> ruchTramwajów; // ruch 

	promise<void> start; // mechanizm do równoczesnego uruchomienia wszystkich w¹tków

	shared_future<void> startSymulacji; // shared future pozwala wielu w¹tkom pobrac stan promise

	void RozpocznijKurs(shared_ptr<Tramwaj> tramwaj, int czasOdjazdu, shared_future<void> future);

	void UtwórzKurs(shared_ptr<Tramwaj> tram, int numerLinii, queue<pair<shared_ptr<Przystanek>, int>> rozk³ad, int czasOdjazdu);

	void GUI_Linie();

	unique_ptr<Zajezdnia> Borek, Gaj, O³bin;

	int wirtualnyNumerBoczny; // dla rozroznienia tramwajow w GUI

public:

	static Dyspozytornia* GetInstance();

	void Setup();

	void GUI_Setup(const string&tramwaj, const string&linia, int odjazd);

	void RealizujKursy();

	vector<string> Statystyki();
};

