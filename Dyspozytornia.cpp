#include "Dyspozytornia.h"
#include "Tramwaj.h"
#include "Przystanek.h"
#include "Rozk�adJazdy.h"
#include "Zajezdnia.h"

mutex Dyspozytornia::mtx;

unique_ptr<Dyspozytornia> Dyspozytornia::instance = nullptr;

Dyspozytornia* Dyspozytornia::GetInstance() { // logika singletona
    
    std::lock_guard<std::mutex> lock(mtx);
    
    instance.reset(new Dyspozytornia);
 
    return instance.get(); // zwr�cenie raw pointera na obiekt zarz�dzany przez unique ptr
}

Dyspozytornia::Dyspozytornia() : rozk�adJazdy(make_unique<Rozk�adJazdy>()), startSymulacji(start.get_future().share()) { 
    
    this->GUI_Linie(); 
    
    this->wirtualnyNumerBoczny = 0;
    
    this->Borek = make_unique<ZajezdniaBorek>();
    
    this->Gaj = make_unique<ZajezdniaGaj>();
   
    this->O�bin = make_unique<ZajezdniaO�bin>();
} // konstruktor

void Dyspozytornia::RozpocznijKurs(shared_ptr<Tramwaj> tramwaj, int czasOdjazdu, shared_future<void> future) { // dzi�ki future wszystkie w�tki rusz� w tym samym momencie
    
    future.get();
    
    this_thread::sleep_for(chrono::milliseconds(czasOdjazdu * 10)); // op�nienie symuluj�ce czas odjazu w stosunku do punktu zerowego czyli wywo�ania na promise<void> funkcji set_value()
    
    this->czasyPrzejazdu[tramwaj] = tramwaj->CzasPrzejazdu();
}

void Dyspozytornia::Utw�rzKurs(shared_ptr<Tramwaj> tramwaj, int numerLinii, queue<pair<shared_ptr<Przystanek>, int>> rozk�ad, int czasOdjazdu) { 

    this->daneSymulacji[numerLinii].push_back(tramwaj); 

    tramwaj->UstawKurs(rozk�ad);

    this->ruchTramwaj�w.push_back(thread(&Dyspozytornia::RozpocznijKurs, this, tramwaj, czasOdjazdu, ref(this->startSymulacji))); // tutaj jest tworzony w�tek kursu
}

void Dyspozytornia::RealizujKursy() {
    
    this->start.set_value(); // rozpoczynamy wszystkie kursy w symulacji
   
    for (auto& kurs : ruchTramwaj�w) {
        
        kurs.join(); // sprawdzamy zako�czenie ka�dego w�tku
    }
}

vector<string> Dyspozytornia::Statystyki() { // zwracanie danych w vektorze 
   
    vector<string> dane;
    
    for (auto& it : daneSymulacji) {
        
        for (auto& tramwaj : it.second) {
            
            string temp = tramwaj->ModelTramwaju() + " linia " + to_string(it.first) + " czas przejazdu " + to_string(czasyPrzejazdu[tramwaj].count());
            
            dane.push_back(temp);
        }
    }
   
    return dane;
}


