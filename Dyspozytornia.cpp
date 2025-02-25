#include "Dyspozytornia.h"
#include "Tramwaj.h"
#include "Przystanek.h"
#include "Rozk³adJazdy.h"
#include "Zajezdnia.h"

mutex Dyspozytornia::mtx;

unique_ptr<Dyspozytornia> Dyspozytornia::instance = nullptr;

Dyspozytornia* Dyspozytornia::GetInstance() { // logika singletona
    
    std::lock_guard<std::mutex> lock(mtx);
    
    instance.reset(new Dyspozytornia);
 
    return instance.get(); // zwrócenie raw pointera na obiekt zarz¹dzany przez unique ptr
}

Dyspozytornia::Dyspozytornia() : rozk³adJazdy(make_unique<Rozk³adJazdy>()), startSymulacji(start.get_future().share()) { 
    
    this->GUI_Linie(); 
    
    this->wirtualnyNumerBoczny = 0;
    
    this->Borek = make_unique<ZajezdniaBorek>();
    
    this->Gaj = make_unique<ZajezdniaGaj>();
   
    this->O³bin = make_unique<ZajezdniaO³bin>();
} // konstruktor

void Dyspozytornia::RozpocznijKurs(shared_ptr<Tramwaj> tramwaj, int czasOdjazdu, shared_future<void> future) { // dziêki future wszystkie w¹tki rusz¹ w tym samym momencie
    
    future.get();
    
    this_thread::sleep_for(chrono::milliseconds(czasOdjazdu * 10)); // opóŸnienie symuluj¹ce czas odjazu w stosunku do punktu zerowego czyli wywo³ania na promise<void> funkcji set_value()
    
    this->czasyPrzejazdu[tramwaj] = tramwaj->CzasPrzejazdu();
}

void Dyspozytornia::UtwórzKurs(shared_ptr<Tramwaj> tramwaj, int numerLinii, queue<pair<shared_ptr<Przystanek>, int>> rozk³ad, int czasOdjazdu) { 

    this->daneSymulacji[numerLinii].push_back(tramwaj); 

    tramwaj->UstawKurs(rozk³ad);

    this->ruchTramwajów.push_back(thread(&Dyspozytornia::RozpocznijKurs, this, tramwaj, czasOdjazdu, ref(this->startSymulacji))); // tutaj jest tworzony w¹tek kursu
}

void Dyspozytornia::RealizujKursy() {
    
    this->start.set_value(); // rozpoczynamy wszystkie kursy w symulacji
   
    for (auto& kurs : ruchTramwajów) {
        
        kurs.join(); // sprawdzamy zakoñczenie ka¿dego w¹tku
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


