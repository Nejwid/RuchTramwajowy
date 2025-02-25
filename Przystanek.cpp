#include "Przystanek.h"
#include "Tramwaj.h"

Przystanek::Przystanek() : nazwa("") {}

Przystanek::Przystanek(const string&nazwa) : nazwa(nazwa) {}

void Przystanek::RealizujPrzystanek(int czas) { // blokujemy inne w¹tki mutexem symuluj¹c opóŸnienia
	lock_guard<mutex> lock(mtx); 
	this_thread::sleep_for(chrono::milliseconds(10 * czas));
}

string Przystanek::Nazwa() const { // getter
	return this->nazwa;
}

